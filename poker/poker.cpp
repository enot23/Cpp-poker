#include "pch.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;
const string karty[9] = { " 6"," 7"," 8"," 9","10"," J"," Q"," K"," T" };
int moneyo = 1000, moneyu = 1000, bank = 0, karu[2][5],karo[2][2],karm[2][2];	
int(*pkaru)[5] = karu;
	int(*pkarm)[2] = karm;
	int(*pkaro)[2] = karo;
struct mast {
	char l1[15];
	char l2[15];
	char l3[15];
	char l41[15];
	char l42[15];
	char l5[15];
	char l6[15];
	char l7[15];

};
mast m[4];mast pm = m[4]; 

void vvidcart1();
void vvidscore();
void vvidcartm();
void flop( int);
int scan_combination(int(*)[5], int(*)[2]);
void showdown();
void vvivid_verhnogo_rady();
int vibir_comp(int);


int  main() {
	int i, j, nk, raise;
	;char hid;
	ifstream f1("zzz.txt", std::ios::binary);
	for (int i = 0; i < 4; i++) {
		f1.read((char*)& m[i], sizeof(mast));

	}
	f1.close();
	//зчитування можливих мастей
	srand(time(NULL));
	bool vsee,fold,call;
	for (nk = 0; nk < 2; nk++) {
		vsee = false;
		karo[0][nk] = rand() % 9;
		karo[1][nk] = rand() % 4;

		for (i = 0; i < 1; i++) {
			for (j = 0; j < nk; j++) {
				if ((karo[i][j] == karo[i][nk]) && (karo[i + 1][j] == karo[i + 1][nk]))
					vsee = true;
			}
		}
		if (vsee) {
			nk--;
			continue;
		}
	}
	//Роздача карт супротивника, перевірка на повторення в своєму масиві
	for (nk = 0; nk < 2; nk++) {
		vsee = false;
		karm[0][nk] = rand() % 9;
		karm[1][nk] = rand() % 4;

		
				if ((karm[0][0] == karm[0][1]) && (karm[1][0] == karm[1][1]))
					vsee = true;
			
		
		if (vsee) {
			nk--;
			continue;
		}

		
			for (j = 0; j < 2; j++) {
				if ((karo[0][j] == karm[0][nk]) && (karo[ 1][j] == karm[1][nk]))
					vsee = true;
			}
		
		if (vsee) {
			nk--;
			continue;
		}

	}
	//Роздача карт юзера, перевірка на повторення між собою і картами супотивника
	for (nk = 0; nk < 5; nk++) {
		vsee = false;
		karu[0][nk] = rand() % 9;
		karu[1][nk] = rand() % 4;

		for (i = 0; i < 1; i++) {
			for (j = 0; j < nk; j++) {
				if ((karu[i][j] == karu[i][nk]) && (karu[i + 1][j] == karu[i + 1][nk]))
					vsee = true;
			}
		}
				 if (vsee) {
				   nk--;
				   continue;
				 }

			for (j = 0; j < nk+1; j++) {
				if ((karo[0][j] == karu[0][nk]) && (karo[1][j] == karu[1][nk]))
					vsee = true;
			}
		
		        if (vsee) {
		        	nk--;
		        	continue;
		        }

				for (j = 0; j < nk+1; j++) {
					if ((karm[0][j] == karu[0][nk]) && (karm[1][j] == karu[1][nk]))
						vsee = true;
				}

				if (vsee) {
					nk--;
					continue;
				}
		        


	}
	//Роздача карт на столі, первірка на повторення між собою, картами супротивника і картами юзера

	

	bank = 100;
	moneyo -= bank / 2;
	moneyu -= bank / 2;
	int power_m = scan_combination(pkaru, pkarm);
	int power_o= scan_combination(pkaru, pkaro);

	
	for (;;) {
		vvidcart1();
		
		cout << "raise(z)/call(x)";
		cin >> hid;
		if (hid == 'z') {
			cout << "vvedit na skiki pidv:";
			cin >> raise;
			if (raise <= moneyu) {
				bank += raise;
				moneyu -= raise;
				
				vvidcart1();
				int rer; 
				
			    rer = rand() % 4;
			    rer=(rer == 0)? 0 : 1;
					
				
			    if (vibir_comp(power_o) == 0) {
					Sleep(2000);
					cout << "I am pass" << endl;
					Sleep(1000);
					moneyu += bank;
					bank = 0;
					
				}
				//логіка  на фолд
				else if (vibir_comp(power_o) == 1 || rer==1|| moneyo<raise) {
					Sleep(2000);
					cout << "I am call" << endl;
					Sleep(1000);
					if (moneyo > raise) {
						moneyo -= raise;
						bank += raise;
					}
					else {
						bank += moneyo;
						moneyo = 0;
						
					}
					//перевірка  чи хватає грошей для колу
				}
				//логіка на кол
			    else if (rer==0) {
					Sleep(2000);
					int rereys = (moneyo-raise) > 50 ? ((moneyo-raise) * 0.1) : moneyo-raise;
					cout << "I am reraise:"<< rereys+raise << endl;
					Sleep(1000);
					
					if (moneyo > raise+rereys) {
						moneyo -= raise+rereys;
						bank += raise+rereys;
					}
					else if (moneyo > raise && moneyo< raise + rereys) {
						moneyo -= raise;
						bank += raise;
					}
					else {
						bank += moneyo;
						moneyo = 0;

					}
					//перевірка чи є в комп*ютера достатньо грошей
					for (;;) {
						vvidcart1();
						cout << "pass(c)/call(x) :";
						cin >> hid;
						if (hid == 'x') {
							moneyu -= rereys;
							bank += rereys;
							break;

						}
						else if (hid == 'c') {
							moneyo += bank;
							bank = 0;
							break;
						}
						else {
							cout << "Error, Please repeat" << endl;
							Sleep(2000);
						}
					}

				}
				//логіка на ререйс
				vvidcart1();
				Sleep(2000);
				break;
			}
			else
			{
				cout << "You do not have so much money" << endl;
				Sleep(3000);
				continue;
			}
		}
		//логіка на рейс
		else if (hid == 'x') {

			if (vibir_comp(power_o) == 0 || vibir_comp(power_o) == 1||moneyo==0) {
				Sleep(2000);
				cout << "I am сheck" << endl;
				Sleep(1000);
			}
			//логіка  чеку
			else {
				Sleep(2000);

				raise = moneyo > 50 ? (moneyo * 0.1):moneyo;
				cout << "I am raise :" << raise << endl;
				Sleep(1000);
				bank += raise;
				moneyo -= raise;
				
				for (;;) {
					vvidcart1();
					cout << "pass(c)/call(x) :";
					cin >> hid;
					if (hid == 'x') {
						if (moneyu > raise) {
							moneyu -= raise;
							bank += raise;
						}
						else {
							bank += moneyu;
							moneyu = 0;
						}
						break;
					}
					else if (hid == 'c') {
						moneyo += bank;
						bank = 0;
						break;
					}
					else {
						cout << "Error, Please repeat" << endl;
						Sleep(2000);
					}
				}
				//вибір юзера
			}
			vvidcart1;
			Sleep(1000);
			break;
		}
		//логіка на кол
		else {
			cout << "Error, Please repeat" << endl;
				Sleep(2000);
				
		}
	}
	//дії перед флопом 
	for(;;){
	flop(2);
	
	cout << "raise(z)/call(x)";
	cin >> hid;
	if (hid == 'z') {
		cout << "vvedit na skiki pidv:";
		cin >> raise;
		if (raise <= moneyu) {
			bank += raise;
			moneyu -= raise;
			break;
		}
		else
		{
			continue;
		}
	}
	else if (hid == 'x') {
		cout << endl;
		break;
	}
	else {
		cout << "Error, Please repeat" << endl;
		Sleep(2000);

	}
	
	}

	//дії  флопу
	
	for(;;){
		flop( 3);
	
		cout << "raise(z)/call(x)";
		cin >> hid;
		if (hid == 'z') {
			cout << "vvedit na skiki pidv:";
			cin >> raise;
			if (raise <= moneyu) {
				bank += raise;
				moneyu -= raise;
				break;
			}
			else
			{
				continue;
			}
		}
		else if (hid == 'x') {
			cout << endl;
			break;
		}
		else {
			cout << "Error, Please repeat" << endl;
			Sleep(2000);

		}
	}


	//дії  тьорну
	
	for (;;){
		flop( 4);
		
		cout << "raise(z)/call(x)";
		cin >> hid;
		if (hid == 'z') {
			cout << "vvedit na skiki pidv:";
			cin >> raise;
			if (raise <= moneyu) {
				bank += raise;
				moneyu -= raise;
				break;
			}
			else
			{
				continue;
			}
		}
		else if (hid == 'x') {
			cout << endl;
			break;
		}
		else {
			cout << "Error, Please repeat" << endl;
			Sleep(2000);

		}
	}
	//дії рівер
	{
		cout << scan_combination(pkaru, pkarm);
		cout << "▄▄▄    ▄▄▄                             ▄▄      ▄▄  ▄▄▄▄▄▄   ▄▄▄   ▄▄     ▄▄    " << endl;
		cout << " ██▄  ▄██                               ██      ██  ▀▀██▀▀   ███   ██     ██    " << endl;
		cout << "  ██▄▄██    ▄████▄   ██    ██           ▀█▄ ██ ▄█▀    ██     ██▀█  ██     ██    " << endl;
		cout << "   ▀██▀    ██▀  ▀██  ██    ██            ██ ██ ██     ██     ██ ██ ██     ██    " << endl;
		cout << "    ██     ██    ██  ██    ██            ███▀▀███     ██     ██  █▄██     ▀▀    " << endl;
		cout << "    ██     ▀██  ██▀  ██▄▄▄███            ███  ███   ▄▄██▄▄   ██   ███           " << endl;
		cout << "    ▀▀       ▀▀▀▀     ▀▀▀▀ ▀▀            ▀▀▀  ▀▀▀   ▀▀▀▀▀▀   ▀▀   ▀▀▀     ▀▀    " << endl;
	}

	showdown();


 		return 0;
}
void vvidcart1(){
	vvidscore();

	cout << "    ___________                                                                                              ___________   ___________" << endl;
	cout << "    |%%%%%%%%%|                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
	cout << "    |%%%%%%%%%|                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
	cout << "    |%%%%%%%%%|                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
	cout << "    |%%%%%%%%%|                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
	cout << "    |%%%%%%%%%|                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
	cout << "    |%%%%%%%%%|                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;

	for (int i = 0; i < 4; i++) {
		if (i == 1) {
			cout << endl;
			cout << "    ___________                                          ++++++                                                    " << endl;
			cout << "    |%%%%%%%%%|                                        ++      ++                                                  " << endl;
			cout << "    |%%%%%%%%%|                                      ++          ++                                                " << endl;
			cout << "    |%%%%%%%%%|                                      +    "<<bank<<"                                               " << endl;
			cout << "    |%%%%%%%%%|                                      ++          ++                                                " << endl;
			cout << "    |%%%%%%%%%|                                        ++      ++                                                  " << endl;
			cout << "    |%%%%%%%%%|                                          ++++++                                                    " << endl;
		}
		//перевірка де виводити банк
		else {
			cout << endl;
			cout << "    ___________   " << endl;
			cout << "    |%%%%%%%%%|   " << endl;
			cout << "    |%%%%%%%%%|   " << endl;
			cout << "    |%%%%%%%%%|   " << endl;
			cout << "    |%%%%%%%%%|   " << endl;
			cout << "    |%%%%%%%%%|   " << endl;
			cout << "    |%%%%%%%%%|   " << endl;
		}
	}
	vvidcartm();
}
void vvidcartm() {
    cout << endl;
	cout << "                                                                                                            " << m[karm[1][0]].l1 << m[karm[1][1]].l1 << endl;
	cout << "                                                                                                            " << m[karm[1][0]].l2 << m[karm[1][1]].l2 << endl;
	cout << "                                                                                                            " << m[karm[1][0]].l3 << m[karm[1][1]].l3 << endl;
	cout << "                                                                                                            " << m[karm[1][0]].l41 << karty[karm[0][0]] << m[karm[1][0]].l42 << m[karm[1][1]].l41 << karty[karm[0][1]] << m[karm[1][1]].l42 << endl;
	cout << "                                                                                                            " << m[karm[1][0]].l5 << m[karm[1][1]].l5 << endl;
	cout << "                                                                                                            " << m[karm[1][0]].l6 << m[karm[1][1]].l6 << endl;
	cout << "                                                                                                            " << m[karm[1][0]].l7 << m[karm[1][1]].l7 << endl;

	cout << "                                                                                                            __________________________\n";
	cout << "                                                                                                              Your money:" << moneyu << "$\n";
	cout << "                                                                                                            __________________________\n";
}
void flop( int r) {
	vvidscore();
	vvivid_verhnogo_rady();
	for (int i = 1; i <= r; i++) {
		if (i == 2) {
			cout << endl;
			cout << "   " << m[karu[1][i]].l1 << "                                          ++++++    " << endl;
			cout << "   " << m[karu[1][i]].l2 << "                                        ++      ++  " << endl;
			cout << "   " << m[karu[1][i]].l3 << "                                      ++          ++" << endl;
			cout << "   " << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42 << "                                      +   " << bank << endl;
			cout << "   " << m[karu[1][i]].l5 << "                                      ++          ++ " << endl;
			cout << "   " << m[karu[1][i]].l6 << "                                        ++      ++   " << endl;
			cout << "   " << m[karu[1][i]].l7 << "                                          ++++++     " << endl;
		}
		else {
			cout << endl;
			cout << "   " << m[karu[1][i]].l1 << endl;
			cout << "   " << m[karu[1][i]].l2 << endl;
			cout << "   " << m[karu[1][i]].l3 << endl;
			cout << "   " << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42 << endl;
			cout << "   " << m[karu[1][i]].l5 << endl;
			cout << "   " << m[karu[1][i]].l6 << endl;
			cout << "   " << m[karu[1][i]].l7 << endl;
		}
	}
	for (int i = ++r; i < 5; i++) {
		cout << endl;
		cout << "    ___________   " << endl;
		cout << "    |%%%%%%%%%|   " << endl;
		cout << "    |%%%%%%%%%|   " << endl;
		cout << "    |%%%%%%%%%|   " << endl;
		cout << "    |%%%%%%%%%|   " << endl;
		cout << "    |%%%%%%%%%|   " << endl;
		cout << "    |%%%%%%%%%|   " << endl;
	}
	vvidcartm();
}
int scan_combination(int kart[][5], int karu[][2]) {
	int power,i,j, povtor_mast, max_m = 0, per_str, k, mas_flesh[5], bulca_i, bulca_j;
	bool zn, strit_flesh = true, strit = false, flesh = false;
	int scan_mas[2][7];
	{
	for ( i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			scan_mas[i][j] = kart[i][j];
		}
	}
	for ( i = 0; i < 2; i++) {
		for (int j = 5; j < 7; j++) {
			scan_mas[i][j] = karu[i][j - 5];
		}
	}
	
	} 
	//збиваня карт в один масив
	

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (scan_mas[0][j] > scan_mas[0][j+1]) {
				bulca_i = scan_mas[0][j];
				bulca_j = scan_mas[1][j];
				scan_mas[0][j] = scan_mas[0][j+1];
				scan_mas[1][j] = scan_mas[1][j+1];
				scan_mas[0][j+1] = bulca_i;
				scan_mas[1][j+1] = bulca_j;
			}
		}
	}

	//сортування карт по зростанню
	
	int povtor1=0,max=0,visch_karta=scan_mas[0][6];

	
	for (i = 0; i < 7; i++) {
		j = i + 1;
		for (j; j < 7; j++) {
			if (scan_mas[0][i] == scan_mas[0][j]) {
				povtor1++;
				if (scan_mas[0][i] > max) {
					max = scan_mas[0][i];
				}

			}
		}
    }
	//пошук повторення 

	if (povtor1 < 4) {
		
		for (i = 0; i < 4; i++) {
			povtor_mast = 0;
			max_m = 0;
			for (j = 6; j >=0; j--) {

				if (scan_mas[1][j] == i) {
					mas_flesh[povtor_mast] = scan_mas[0][j];
					povtor_mast++;
					if (max_m < scan_mas[0][j]) {
						max_m = scan_mas[0][j];

					}

				}

				if (povtor_mast == 5) {
					break;
				}
			}
			if (povtor_mast == 5) {
				break;
				flesh = true;

			}


		}
		
		//перевірка на флеш

		if ((mas_flesh[0]) == (mas_flesh[1]+1)&& (mas_flesh[0]) == (mas_flesh[2]+2)  && (mas_flesh[0])==(mas_flesh[3]+3) && (mas_flesh[0]) == (mas_flesh[4]+4) ) {
			strit_flesh = false;
		}
		//перевірка на стріт-флеш
		
		
		if (povtor_mast < 5 && strit_flesh==false) {

			for (k = 6; k > 3; k--) {
				per_str = 0;
				i = k;
				for (; ; ) {
					zn = false;

					for (j = i - 1; j >= 0; j--) {

						if (scan_mas[0][i] == (scan_mas[0][j] + 1)) {
							per_str++;

							i = j;
							zn = true;
							break;

						}

					}
					if (zn) {
						if (per_str == 4) {
							break;
						}
						if (i <= 0) {
							break;
						}
					}
					else {
						break;
					}
				}
				if (per_str == 4) {
					break;
					strit = true;
				}
			}
			
		}
		
		//перевірка на стріт
	}
	//перевірка на стріт,флеш,стріт-флеш
	if (strit_flesh==false) {
		power=mas_flesh[0] + 60;
	}
	else if (povtor1 >= 6) {
			power = max + 55;
	 }
	else if (povtor1 >= 4) {
			power = max + 46;
	}
	else if (flesh) {
		 power = max_m + 37;
	 }
	else if (strit) {
		power= scan_mas[0][k]+32;
	 }
	else if (povtor1 == 3) {
			power = max + 27;
	}
	else if (povtor1 == 2) {
			power=max + 18;
	}
	else if (povtor1 == 1) {
			power = max + 9;
	}
	else if (povtor1 == 0) {
		 power = visch_karta;
	}
	
	
	
	return power;

}
void showdown() {
	vvidscore();
	cout << endl;  
	cout << "   " << m[karu[1][0]].l1 << "                                                                                              " << m[karo[1][0]].l1 << m[karo[1][1]].l1 << endl;
	cout << "   " << m[karu[1][0]].l2 << "                                                                                              " << m[karo[1][0]].l2 << m[karo[1][1]].l2 << endl;
	cout << "   " << m[karu[1][0]].l3 << "                                                                                              " << m[karo[1][0]].l3 << m[karo[1][1]].l3 << endl;
	cout << "   " << m[karu[1][0]].l41<< karty[karu[0][0]] << m[karu[1][0]].l42<<"                                                                                              " << m[karo[1][0]].l41 <<karty[karo[0][0]]<< m[karo[1][0]].l42 << m[karo[1][1]].l41<< karty[karo[0][1]] << m[karo[1][1]].l42<<endl;
	cout << "   " << m[karu[1][0]].l5 << "                                                                                              " << m[karo[1][0]].l5 << m[karo[1][1]].l5 << endl;
	cout << "   " << m[karu[1][0]].l6 << "                                                                                              " << m[karo[1][0]].l6 << m[karo[1][1]].l6 << endl;
	cout << "   " << m[karu[1][0]].l7 << "                                                                                              " << m[karo[1][0]].l7 << m[karo[1][1]].l7 << endl;

	for (int i = 1; i < 5; i++) {
		if (i == 2) {
			cout << endl;
			cout << "   " << m[karu[1][i]].l1 << "                                          ++++++    " << endl;
			cout << "   " << m[karu[1][i]].l2 << "                                        ++      ++  " << endl;
			cout << "   " << m[karu[1][i]].l3 << "                                      ++          ++"<<endl;
			cout << "   " << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42 << "                                      +   "<<bank<< endl;
			cout << "   " << m[karu[1][i]].l5 << "                                      ++          ++ " << endl;
			cout << "   " << m[karu[1][i]].l6 << "                                        ++      ++   " << endl;
			cout << "   " << m[karu[1][i]].l7 << "                                          ++++++     "<< endl;
		}
		else {
			cout << endl;
			cout << "   " << m[karu[1][i]].l1 << endl;
			cout << "   " << m[karu[1][i]].l2 << endl;
			cout << "   " << m[karu[1][i]].l3 << endl;
			cout << "   " << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42 << endl;
			cout << "   " << m[karu[1][i]].l5 << endl;
			cout << "   " << m[karu[1][i]].l6 << endl;
			cout << "   " << m[karu[1][i]].l7 << endl;
		}
	}

	vvidcartm();
}
void vvidscore() {
	cout << "                                                                                                            __________________________\n";
	cout << "                                                                                                             Money opponent:" << moneyo << "$\n";
	cout << "                                                                                                            __________________________\n";
}
void vvivid_verhnogo_rady() {
	cout << endl;
	cout << "   " << m[karu[1][0]].l1 << "                                                                                              ___________   ___________"<<endl;
	cout << "   " << m[karu[1][0]].l2 << "                                                                                              |%%%%%%%%%|   |%%%%%%%%%|"<<endl;
	cout << "   " << m[karu[1][0]].l3 << "                                                                                              |%%%%%%%%%|   |%%%%%%%%%|"<<endl;
	cout << "   " << m[karu[1][0]].l41 << karty[karu[0][0]] << m[karu[1][0]].l42 << "                                                                                              |%%%%%%%%%|   |%%%%%%%%%|"<<endl;
	cout << "   " << m[karu[1][0]].l5 << "                                                                                              |%%%%%%%%%|   |%%%%%%%%%|"<<endl;
	cout << "   " << m[karu[1][0]].l6 << "                                                                                              |%%%%%%%%%|   |%%%%%%%%%|"<<endl;
	cout << "   " << m[karu[1][0]].l7 << "                                                                                              |%%%%%%%%%|   |%%%%%%%%%|"<<endl;
}
int vibir_comp(int power) {
	int ret;srand(time(NULL));
	if (power < 8) {
		ret = rand() % 4;
		if (ret == 0) {
			ret = 0;
		}
		else {
			ret = 1;
		}
	}
	else if (power < 17) {
		ret = rand() % 15;
		if (ret == 0) {
			ret = 0;
		}
		else if(ret<5){
			ret = 2;
		}
		else {
			ret = 1;
		}

	}
	else if (power < 42) {
		ret = rand() & 30;
		if (ret == 0) {
			ret = 0;
		}
		else if (ret < 20) {
			ret = 1;
		}
		else {
			ret = 2;
		}
	}
	else if (power < 50) {
		ret = rand() & 50;
		if (ret == 0) {
			ret = 0;
		}
		else if (ret < 20) {
			ret = 1;
		}
		else {
			ret = 2;
		}
	}
	else if (power < 67) {
		ret = rand() & 90;
		if (ret == 0) {
			ret = 0;
		}
		else if (ret < 20) {
			ret = 1;
		}
		else {
			ret = 2;
		}
	}
	else{
		ret = rand() & 100;
		
		if (ret < 20) {
			ret = 1;
		}
		else {
			ret = 2;
		}
	}
	return ret;
}