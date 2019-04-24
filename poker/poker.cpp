#include "pch.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <ctime>
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
void vvidcartm(int(*)[2]);
void flop(int(*)[5], int, int);
void torn(int(*)[5], int, int);
void river(int(*)[5], int, int);
int scan_combination(int(*)[5],int,int, int(*)[2],int,int);
void showdown(mast[4],int (*)[2],int (*)[5]);


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
	int power_m = (pkaru,5,2, pkarm,2,2);
	
	for (;;) {
		vvidcart1();
		
		cout << "raise(z)/call(x)";
		cin >> hid;
		if (hid == 'z') {
			cout << "vvedit na skiki pidv:";
			cin >> raise;
			if (raise < moneyu) {
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
	}
	//дії перед флопом 
	for(;;){
	flop(pkaru, 2, 5);
	
	cout << "raise(z)/call(x)";
	cin >> hid;
	if (hid == 'z') {
		cout << "vvedit na skiki pidv:";
		cin >> raise;
		if (raise < moneyu) {
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
	scan_combination(pkaru, 2, 5, pkarm, 2, 2);
	}

	//дії  флопу
	
	for(;;){
		torn(pkaru, 2, 5);
	
		cout << "raise(z)/call(x)";
		cin >> hid;
		if (hid == 'z') {
			cout << "vvedit na skiki pidv:";
			cin >> raise;
			if (raise < moneyu) {
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
	}

	//дії  тьорну
	
	for (;;){
		river(pkaru, 2, 5);
		
		cout << "raise(z)/call(x)";
		cin >> hid;
		if (hid == 'z') {
			cout << "vvedit na skiki pidv:";
			cin >> raise;
			if (raise < moneyu) {
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
	}
	//дії рівер
	{
		cout << scan_combination(pkaru, 2, 5, pkarm, 2, 2);
		cout << "▄▄▄    ▄▄▄                             ▄▄      ▄▄  ▄▄▄▄▄▄   ▄▄▄   ▄▄     ▄▄    " << endl;
		cout << " ██▄  ▄██                               ██      ██  ▀▀██▀▀   ███   ██     ██    " << endl;
		cout << "  ██▄▄██    ▄████▄   ██    ██           ▀█▄ ██ ▄█▀    ██     ██▀█  ██     ██    " << endl;
		cout << "   ▀██▀    ██▀  ▀██  ██    ██            ██ ██ ██     ██     ██ ██ ██     ██    " << endl;
		cout << "    ██     ██    ██  ██    ██            ███▀▀███     ██     ██  █▄██     ▀▀    " << endl;
		cout << "    ██     ▀██  ██▀  ██▄▄▄███            ███  ███   ▄▄██▄▄   ██   ███           " << endl;
		cout << "    ▀▀       ▀▀▀▀     ▀▀▀▀ ▀▀            ▀▀▀  ▀▀▀   ▀▀▀▀▀▀   ▀▀   ▀▀▀     ▀▀    " << endl;
	}

	showdown(m, pkaro, pkaru);


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
	vvidcartm(pkarm);
}
void vvidcartm(int karu[][2]) {
    cout << endl;
	cout << "                                                                                                            " << m[karu[1][0]].l1 << m[karu[1][1]].l1 << endl;
	cout << "                                                                                                            " << m[karu[1][0]].l2 << m[karu[1][1]].l2 << endl;
	cout << "                                                                                                            " << m[karu[1][0]].l3 << m[karu[1][1]].l3 << endl;
	cout << "                                                                                                            " << m[karu[1][0]].l41 << karty[karu[0][0]] << m[karu[1][0]].l42 << m[karu[1][1]].l41 << karty[karu[0][1]] << m[karu[1][1]].l42 << endl;
	cout << "                                                                                                            " << m[karu[1][0]].l5 << m[karu[1][1]].l5 << endl;
	cout << "                                                                                                            " << m[karu[1][0]].l6 << m[karu[1][1]].l6 << endl;
	cout << "                                                                                                            " << m[karu[1][0]].l7 << m[karu[1][1]].l7 << endl;

	cout << "                                                                                                            __________________________\n";
	cout << "                                                                                                              Your money:" << moneyu << "$\n";
	cout << "                                                                                                            __________________________\n";
}
void flop	  (int karu[][5], int r, int s) {
	vvidscore();

	vvidcartm(pkarm);
}
void torn	  (int karu[][5], int r, int s) {
	vvidscore();
	
	vvidcartm(pkarm);
}
void river	  (int karu[][5], int r, int s) {
	vvidscore();
	
	vvidcartm(pkarm);
}
int scan_combination(int kart[][5], int s1, int r1, int karu[][2], int s2, int r2) {
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
void showdown(mast m[4], int kart_komp[][2], int kart_stoli[][5]) {
	vvidscore();
	cout << endl;  
	cout << "   " << m[kart_stoli[1][0]].l1 << "                                                                                              " << m[kart_komp[1][0]].l1 << m[kart_komp[1][1]].l1 << endl;
	cout << "   " << m[kart_stoli[1][0]].l2 << "                                                                                              " << m[kart_komp[1][0]].l2 << m[kart_komp[1][1]].l2 << endl;
	cout << "   " << m[kart_stoli[1][0]].l3 << "                                                                                              " << m[kart_komp[1][0]].l3 << m[kart_komp[1][1]].l3 << endl;
	cout << "   " << m[kart_stoli[1][0]].l41<< karty[kart_stoli[0][0]] << m[kart_stoli[1][0]].l42<<"                                                                                              " << m[kart_komp[1][0]].l41 <<karty[kart_komp[0][0]]<< m[kart_komp[1][0]].l42 << m[kart_komp[1][1]].l41<< karty[kart_komp[0][1]] << m[kart_komp[1][1]].l42<<endl;
	cout << "   " << m[kart_stoli[1][0]].l5 << "                                                                                              " << m[kart_komp[1][0]].l5 << m[kart_komp[1][1]].l5 << endl;
	cout << "   " << m[kart_stoli[1][0]].l6 << "                                                                                              " << m[kart_komp[1][0]].l6 << m[kart_komp[1][1]].l6 << endl;
	cout << "   " << m[kart_stoli[1][0]].l7 << "                                                                                              " << m[kart_komp[1][0]].l7 << m[kart_komp[1][1]].l7 << endl;

	for (int i = 1; i < 5; i++) {
		if (i == 2) {
			cout << endl;
			cout << "   " << m[kart_stoli[1][i]].l1 << "                                          ++++++    " << endl;
			cout << "   " << m[kart_stoli[1][i]].l2 << "                                        ++      ++  " << endl;
			cout << "   " << m[kart_stoli[1][i]].l3 << "                                      ++          ++"<<endl;
			cout << "   " << m[kart_stoli[1][i]].l41 << karty[kart_stoli[0][i]] << m[kart_stoli[1][i]].l42 << "                                      +   "<<bank<< endl;
			cout << "   " << m[kart_stoli[1][i]].l5 << "                                      ++          ++ " << endl;
			cout << "   " << m[kart_stoli[1][i]].l6 << "                                        ++      ++   " << endl;
			cout << "   " << m[kart_stoli[1][i]].l7 << "                                          ++++++     "<< endl;
		}
		else {
			cout << endl;
			cout << "   " << m[kart_stoli[1][i]].l1 << endl;
			cout << "   " << m[kart_stoli[1][i]].l2 << endl;
			cout << "   " << m[kart_stoli[1][i]].l3 << endl;
			cout << "   " << m[kart_stoli[1][i]].l41 << karty[kart_stoli[0][i]] << m[kart_stoli[1][i]].l42 << endl;
			cout << "   " << m[kart_stoli[1][i]].l5 << endl;
			cout << "   " << m[kart_stoli[1][i]].l6 << endl;
			cout << "   " << m[kart_stoli[1][i]].l7 << endl;
		}
	}

	vvidcartm(pkarm);
}
void vvidscore() {
	cout << "                                                                                                            __________________________\n";
	cout << "                                                                                                             Money opponent:" << moneyo << "$\n";
	cout << "                                                                                                            __________________________\n";
}