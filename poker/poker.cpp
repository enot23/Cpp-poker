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
int moneyo = 1000, moneyu = 1000, bank = 0, karu[2][5],karo[2][2],karm[2][2],color;	
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
int logic(int);
int logic2(int);
void you_win();
void you_lose();
void all_in();
void who_is_winer(int,int);

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
int  main() {

	system("mode con cols=200 lines=50");
	system("color 1f");
	
	Sleep(4000);
	int i, j, nk;
	ifstream f1("zzz.txt", std::ios::binary);
	for (int i = 0; i < 4; i++) {
		f1.read((char*)& m[i], sizeof(mast));

	}
	f1.close();
	//зчитування можливих мастей
	srand(time(NULL));
	bool vsee,fold,call;

	
	for (int pravo_hodu = 0 ; moneyo > 0 && moneyu > 0;pravo_hodu++) {
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
				if ((karo[0][j] == karm[0][nk]) && (karo[1][j] == karm[1][nk]))
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

			for (j = 0; j < nk + 1; j++) {
				if ((karo[0][j] == karu[0][nk]) && (karo[1][j] == karu[1][nk]))
					vsee = true;
			}

			if (vsee) {
				nk--;
				continue;
			}

			for (j = 0; j < nk + 1; j++) {
				if ((karm[0][j] == karu[0][nk]) && (karm[1][j] == karu[1][nk]))
					vsee = true;
			}

			if (vsee) {
				nk--;
				continue;
			}



		}
		//Роздача карт на столі, первірка на повторення між собою, картами супротивника і картами юзера


		if (moneyo > 50) {
			bank = 50;
			moneyo -=50;
		}
		else {
			bank = moneyo;
			moneyo = 0;
		}
		if (moneyu > 50) {
			bank += 50;
			moneyu -= 50; 
		}
		else {
			bank += moneyu;
			moneyu = 0;
		}

		int power_m = scan_combination(pkaru, pkarm);
		int power_o = scan_combination(pkaru, pkaro),l;
		for (;;) {
			l = (pravo_hodu % 2 == 1) ? logic2(0) : logic(0);
			if (l == 1) {
				moneyo += bank;
				bank = 0;
				break;
			}
			else if (l == 2) {
				moneyu += bank;
				bank = 0;	break;
			}

			//дії перед флопом 
			l = (pravo_hodu % 2 == 1) ? logic2(1) : logic(1);
			if (l == 1) {
				moneyo += bank;
				bank = 0;
				break;
			}
			else if (l == 2) {
				moneyu += bank;
				bank = 0;	break;
			}

			//дії  флопу

			l = (pravo_hodu % 2 == 1) ? logic2(2) : logic(2);

			if (l == 1) {
				moneyo += bank;
				bank = 0;
				break;
			}
			else if (l == 2) {
				moneyu += bank;
				bank = 0;	break;
			}
			//дії  тьорну

			l = (pravo_hodu % 2 == 1) ? logic2(3) : logic(3);
			if (l == 1) {
				moneyo += bank;
				bank = 0;
				break;
			}
			else if (l == 2) {
				moneyu += bank;
				bank = 0;	break;
			}
			//дії рівер
			break;
		}
		showdown();
		Sleep(3000);
		if (l == 0) {
			who_is_winer(power_m, power_o);
		}
	}
 		return 0;
}
void vvidcart1(){
	vvidscore();
	
	cout << "    ___________                                                                                                 ___________   ___________" << endl;
	cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(0, 1); cout << "                                                                                                 ";   SetColor(15, 4); cout << "|%%%%%%%%%|";SetColor(15, 1);  cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "                                                                                                 ";  SetColor(15, 4); cout << "|%%%%%%%%%|";SetColor(15, 1);  cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "                                                                                                 ";  SetColor(15, 4); cout << "|%%%%%%%%%|";SetColor(15, 1);  cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "                                                                                                 ";  SetColor(15, 4); cout << "|%%%%%%%%%|";SetColor(15, 1);  cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "                                                                                                 ";  SetColor(15, 4); cout << "|%%%%%%%%%|";SetColor(15, 1);  cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "                                                                                                 ";  SetColor(15, 4); cout << "|%%%%%%%%%|";SetColor(15, 1);  cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;

	for (int i = 0; i < 4; i++) {
		if (i == 1) {
			cout << endl;
			cout <<                              "    ___________";                  SetColor(15,1); cout << "                                          ";SetColor(0,7);cout<<"++++++" << endl; SetColor(15,1);
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); SetColor(15,1); cout << "                                        ";SetColor(0,7);cout<<"++      ++" << endl; SetColor(15, 1);
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); SetColor(15,1); cout << "                                      ";SetColor(0,7);cout<<"++          ++" << endl; SetColor(15,1);
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); SetColor(15,1); cout << "                                     ";SetColor(0,7);cout<<"+     " << bank<<"     +"<< endl; SetColor(15,1);
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); SetColor(15,1); cout << "                                      ";SetColor(0,7);cout<<"++          ++" << endl; SetColor(15,1);
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); SetColor(15,1); cout << "                                        ";SetColor(0,7);cout<<"++      ++" << endl; SetColor(15,1);
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); SetColor(15,1); cout << "                                          ";SetColor(0,7);cout<<"++++++" << endl; SetColor(15,1);
		}
		//перевірка де виводити банк
		else {
			cout << endl;
			cout << "    ___________   " << endl;
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
			cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
		}
	}
	vvidcartm();
}
void vvidcartm() {
    cout << endl;
	cout << "                                                                                                               "; color = (karm[1][0] == 1 || karm[1][0] == 2) ? 0 : 4; SetColor(color,7);cout << m[karm[1][0]].l1                                            ; SetColor(15,1);cout<<"  " ; color = (karm[1][1] == 1|| karm[1][1] == 2)? 0 : 4; SetColor(color,7);cout << m[karm[1][1]].l1 << endl;                                            SetColor(15,1);
	cout << "                                                                                                               "; color = (karm[1][0] == 1 || karm[1][0] == 2) ? 0 : 4; SetColor(color,7);cout << m[karm[1][0]].l2                                            ; SetColor(15,1);cout<<"  " ; color = (karm[1][1] == 1|| karm[1][1] == 2)? 0 : 4; SetColor(color,7);cout << m[karm[1][1]].l2 << endl;                                            SetColor(15,1);
	cout << "                                                                                                               "; color = (karm[1][0] == 1 || karm[1][0] == 2) ? 0 : 4; SetColor(color,7);cout << m[karm[1][0]].l3                                            ; SetColor(15,1);cout<<"  " ; color = (karm[1][1] == 1|| karm[1][1] == 2)? 0 : 4; SetColor(color,7);cout << m[karm[1][1]].l3 << endl;                                            SetColor(15,1);
	cout << "                                                                                                               "; color = (karm[1][0] == 1 || karm[1][0] == 2) ? 0 : 4; SetColor(color,7);cout << m[karm[1][0]].l41<< karty[karm[0][0]] << m[karm[1][0]].l42  ; SetColor(15,1);cout<<"  " ; color = (karm[1][1] == 1|| karm[1][1] == 2)? 0 : 4; SetColor(color,7);cout << m[karm[1][1]].l41 << karty[karm[0][1]] << m[karm[1][1]].l42 << endl; SetColor(15,1);
	cout << "                                                                                                               "; color = (karm[1][0] == 1 || karm[1][0] == 2) ? 0 : 4; SetColor(color,7);cout << m[karm[1][0]].l5                                            ; SetColor(15,1);cout<<"  " ; color = (karm[1][1] == 1|| karm[1][1] == 2)? 0 : 4; SetColor(color,7);cout << m[karm[1][1]].l5 << endl;                                            SetColor(15,1);
	cout << "                                                                                                               "; color = (karm[1][0] == 1 || karm[1][0] == 2) ? 0 : 4; SetColor(color,7);cout << m[karm[1][0]].l6                                            ; SetColor(15,1);cout<<"  " ; color = (karm[1][1] == 1|| karm[1][1] == 2)? 0 : 4; SetColor(color,7);cout << m[karm[1][1]].l6 << endl;                                            SetColor(15,1);
	cout << "                                                                                                               "; color = (karm[1][0] == 1 || karm[1][0] == 2) ? 0 : 4; SetColor(color,7);cout << m[karm[1][0]].l7                                            ; SetColor(15,1);cout<<"  " ; color = (karm[1][1] == 1|| karm[1][1] == 2)? 0 : 4; SetColor(color,7);cout << m[karm[1][1]].l7 << endl;                                            SetColor(15,1);

	cout << "                                                                                                               __________________________\n";
	cout << "                                                                                                                 Your money:" << moneyu << "$\n";
	cout << "                                                                                                               __________________________\n";
}
void flop( int r) {
	vvidscore();
	vvivid_verhnogo_rady();
	for (int i = 1; i <= r; i++) {
		if (i == 2) {
			cout << endl;
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l1                                               ;SetColor(15,1); cout << "                                          ";SetColor(0,7);cout<<"++++++" << endl; SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l2                                               ;SetColor(15,1); cout << "                                        ";SetColor(0,7);cout<<"++      ++" << endl; SetColor(15, 1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l3                                               ;SetColor(15,1); cout << "                                      ";SetColor(0,7);cout<<"++          ++" << endl; SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42    ;SetColor(15,1); cout << "                                     ";SetColor(0,7);cout<<"+     " << bank<<"     +"<< endl; SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l5                                               ;SetColor(15,1); cout << "                                      ";SetColor(0,7);cout<<"++          ++" << endl; SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l6                                               ;SetColor(15,1); cout << "                                        ";SetColor(0,7);cout<<"++      ++" << endl; SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l7                                               ;SetColor(15,1); cout << "                                          ";SetColor(0,7);cout<<"++++++" << endl; SetColor(15,1);
		}					  												         
		else {				  												         
			cout << endl; 	 												         
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l1 << endl;SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l2 << endl;SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l3 << endl;SetColor(15,1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42 << endl; SetColor(15, 1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l5 << endl; SetColor(15, 1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l6 << endl; SetColor(15, 1);
			cout << "   ";  color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;      SetColor(color,7);cout << m[karu[1][i]].l7 << endl; SetColor(15, 1);
		}
	}
	for (int i = ++r; i < 5; i++) {
		cout << endl;
		cout << "    ___________   " << endl;
		cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
		cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
		cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
		cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
		cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
		cout << "    "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   " << endl;
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
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][0]].l1; SetColor(15, 1); cout << "                                                                                                 ";												color = (karo[1][0] == 1 || karo[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][0]].l1;												SetColor(15, 1); cout << "  ";	color = (karo[1][1] == 1 || karo[1][1] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][1]].l1 << endl; ; SetColor(15, 1);
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][0]].l2; SetColor(15, 1); cout << "                                                                                                 ";												color = (karo[1][0] == 1 || karo[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][0]].l2;												SetColor(15, 1); cout << "  ";	color = (karo[1][1] == 1 || karo[1][1] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][1]].l2 << endl; ; SetColor(15, 1);
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][0]].l3; SetColor(15, 1); cout << "                                                                                                 ";												color = (karo[1][0] == 1 || karo[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][0]].l3;												SetColor(15, 1); cout << "  ";	color = (karo[1][1] == 1 || karo[1][1] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][1]].l3 << endl; ; SetColor(15, 1);
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][0]].l41 << karty[karu[0][0]] << m[karu[1][0]].l42; SetColor(15, 1); cout << "                                                                                                 ";		color = (karo[1][0] == 1 || karo[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][0]].l41 << karty[karo[0][0]] << m[karo[1][0]].l42;	SetColor(15, 1); cout << "  ";	color = (karo[1][1] == 1 || karo[1][1] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][1]].l41 << karty[karo[0][1]] << m[karo[1][1]].l42 << endl;; SetColor(15, 1);
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][0]].l5; SetColor(15, 1); cout << "                                                                                                 ";												color = (karo[1][0] == 1 || karo[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][0]].l5;												SetColor(15, 1); cout << "  ";	color = (karo[1][1] == 1 || karo[1][1] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][1]].l5 << endl; ; SetColor(15, 1);
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][0]].l6; SetColor(15, 1); cout << "                                                                                                 ";												color = (karo[1][0] == 1 || karo[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][0]].l6;												SetColor(15, 1); cout << "  ";	color = (karo[1][1] == 1 || karo[1][1] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][1]].l6 << endl; ; SetColor(15, 1);
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][0]].l7; SetColor(15, 1); cout << "                                                                                                 ";												color = (karo[1][0] == 1 || karo[1][0] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][0]].l7;												SetColor(15, 1); cout << "  ";	color = (karo[1][1] == 1 || karo[1][1] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karo[1][1]].l7 << endl; ; SetColor(15, 1);

	for (int i = 1; i < 5; i++) {
		if (i == 2) {
			cout << endl;
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l1; SetColor(15, 1); cout << "                                          "; SetColor(0, 7); cout << "++++++" << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l2; SetColor(15, 1); cout << "                                        "; SetColor(0, 7); cout << "++      ++" << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l3; SetColor(15, 1); cout << "                                      "; SetColor(0, 7); cout << "++          ++" << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42; SetColor(15, 1); cout << "                                     "; SetColor(0, 7); cout << "+     " << bank << "     +" << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l5; SetColor(15, 1); cout << "                                      "; SetColor(0, 7); cout << "++          ++" << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l6; SetColor(15, 1); cout << "                                        "; SetColor(0, 7); cout << "++      ++" << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l7; SetColor(15, 1); cout << "                                          "; SetColor(0, 7); cout << "++++++" << endl; SetColor(15, 1);
		}
		else {
			cout << endl;
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l1 << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l2 << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l3 << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l41 << karty[karu[0][i]] << m[karu[1][i]].l42 << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l5 << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l6 << endl; SetColor(15, 1);
			cout << "   ";	color = (karu[1][i] == 1 || karu[1][i] == 2) ? 0 : 4;	SetColor(color, 7); cout << m[karu[1][i]].l7 << endl; SetColor(15, 1);
		}
	}

	vvidcartm();
}
void vvidscore() {
	cout << "                                                                                                               __________________________\n";
	cout << "                                                                                                                Money opponent:" << moneyo << "$\n";
	cout << "                                                                                                               __________________________\n";
}
void vvivid_verhnogo_rady() {
	cout << endl;
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color,7);cout << m[karu[1][0]].l1 ; SetColor(15, 1); cout<< "                                                                                                 ___________   ___________"<<endl;
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color,7);cout << m[karu[1][0]].l2 ; SetColor(15, 1); cout<< "                                                                                                 "                                           ; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color,7);cout << m[karu[1][0]].l3 ; SetColor(15, 1); cout<< "                                                                                                 "                                           ; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color,7);cout << m[karu[1][0]].l41<< karty[karu[0][0]] << m[karu[1][0]].l42; SetColor(15, 1); cout  << "                                                                                                 "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color,7);cout << m[karu[1][0]].l5 ; SetColor(15, 1); cout<< "                                                                                                 "                                           ; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;	
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color,7);cout << m[karu[1][0]].l6 ; SetColor(15, 1); cout<< "                                                                                                 "                                           ; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
	cout << "   ";	color = (karu[1][0] == 1 || karu[1][0] == 2) ? 0 : 4;	SetColor(color,7);cout << m[karu[1][0]].l7 ; SetColor(15, 1); cout<< "                                                                                                 "                                           ; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << "   "; SetColor(15, 4); cout << "|%%%%%%%%%|"; SetColor(15, 1); cout << endl;
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
int  logic(int z) {
	int power_o = scan_combination(pkaru, pkaro), raise;
	char hid;
	bool pas=false;
	int ret=0;
	for (;;) {


		z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);

		//перевірка частини гри
		cout << "raise(z)/chek(x)";
		cin >> hid;
		if (hid == 'z') {
			cout << "vvedit na skiki pidv:";
			cin >> raise;

			if (raise <= moneyu) {
				bank += raise;
				moneyu -= raise;
				
				if (moneyu == 0) { all_in(); Sleep(1500);
				}
				z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
				int rer;

				rer = rand() % 4;
				rer = (rer == 0) ? 0 : 1;


				if (vibir_comp(power_o) == 0) {
					Sleep(2000);
					cout << "I am pass" << endl;
					Sleep(1000);
					moneyu += bank;
					bank = 0;
					pas = true;
					ret = 2;
					break;

				}
				//логіка  на фолд
				else if (vibir_comp(power_o) == 1 || rer == 1 || moneyo < raise) {
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
					if (moneyo == 0) { all_in(); Sleep(1500); }
					//перевірка  чи хватає грошей для колу
					break;
				}
				//логіка на кол
				else if (rer == 0) {
					Sleep(2000);
					int rereys = (moneyo - raise) > 50 ? ((moneyo - raise) * 0.1) : moneyo - raise;
					cout << "I am reraise:" << rereys + raise << endl;
					Sleep(1000);

					if (moneyo > raise + rereys) {
						moneyo -= raise + rereys;
						bank += raise + rereys;
					}
					else if (moneyo > raise && moneyo < raise + rereys) {
						moneyo -= raise;
						bank += raise;
					}
					else {
						bank += moneyo;
						moneyo = 0;

					}
					if (moneyo == 0) {
						all_in(); Sleep(1500);
						//перевірка чи є в комп*ютера достатньо грошей
						for (;;) {
							z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
							cout << "pass(c)/call(x) :";
							cin >> hid;
							if (hid == 'x') {
								moneyu -= rereys;
								bank += rereys;
								break;
								if (moneyu == 0) {
									all_in(); Sleep(1500);
								}

							}
							else if (hid == 'c') {
								moneyo += bank;
								bank = 0;
								pas = true;
								ret = 1;
								
								break;
								
							}
							else {
								cout << "Error, Please repeat" << endl;
								Sleep(2000);
							}
							
						}
						if (pas == true) {
								break;
						}

					}
					//логіка на ререйс
					z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
					Sleep(2000);
					break;
				}
				else
				{
					cout << "You do not have so much money" << endl;
					Sleep(3000);
					continue;
				}
			}if (pas == true) {
			break;
		    }
		}
		
			//логіка на рейс
		else if (hid == 'x') {

				if (vibir_comp(power_o) == 0 || vibir_comp(power_o) == 1 || moneyo == 0) {
					Sleep(2000);
					cout << "I am сheck" << endl;
					Sleep(1000);
				}
				//логіка  чеку
				else {
					Sleep(2000);

					raise = moneyo > 50 ? (moneyo * 0.1) : moneyo;
					cout << "I am raise :" << raise << endl;
					Sleep(1000);
					bank += raise;
					moneyo -= raise;

					for (;;) {
						z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
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
								
									all_in(); Sleep(1500);
								
							}
							break;
						}
						else if (hid == 'c') {
							moneyo += bank;
							bank = 0;
							pas = true;
							ret = 1;
							break;
						}
						else {
							cout << "Error, Please repeat" << endl;
							Sleep(2000);
						}
					}
					if (pas == true) {
						break;
					}
					//вибір юзера
				}
				z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
				Sleep(3000);
				break;
		}
		
			//логіка на кол
		else {
				cout << "Error, Please repeat" << endl;
				Sleep(2000);

		}
		
	}
	
	
	return ret;
}
int logic2(int z) {
	int power_o = scan_combination(pkaru, pkaro), raise;
	char hid;
	bool pas = false, treba_hid = true;;
	int ret = 0;

	for (;;) {
		z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
		//перевірка частини гри

		if (vibir_comp == 0) {
			Sleep(2000);
			cout << "I am pass" << endl;
			pas = true;
			ret = 2;
			Sleep(1500);
			break;
		}
		else if ( vibir_comp(power_o) == 1 || moneyo == 0) {
			Sleep(2000);
			cout << "I am сheck" << endl;
			Sleep(1500);
		}
		//логіка  чеку
		else {
			

			raise = moneyo > 50 ? (moneyo * 0.1) : moneyo;
			cout << "I am raise :" << raise << endl;
			Sleep(1500);
			treba_hid = false;
			bank += raise;
			moneyo -= raise;

			for (;;) {
				z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
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

						all_in(); Sleep(1500);

					}
					break;
				}
				else if (hid == 'c') {
					moneyo += bank;
					bank = 0;
					pas = true;
					ret = 1;
					break;
				}
				else {
					cout << "Error, Please repeat" << endl;
					Sleep(2000);
					z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
				}
			}
			if (pas == true) {
				break;
			}
			//вибір компютера

		}
		Sleep(1500);
		

	
		break;
	}
	if (treba_hid && !pas) {
		
		for (;;) {
			cout << "raise(z)/chek(x)";
		    cin >> hid;
			if (hid == 'z') {
				cout << "vvedit na skiki pidv:";
				cin >> raise;

				if (raise <= moneyu) {
					bank += raise;
					moneyu -= raise;

					if (moneyu == 0) {
						all_in(); Sleep(1500);
					}
					z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
				




					if (vibir_comp(power_o) == 0) {
						Sleep(2000);
						cout << "I am pass" << endl;
						Sleep(1500);
						moneyu += bank;
						bank = 0;
						pas = true;
						ret = 2;
						break;


					}
					//логіка  на фолд
					else if (vibir_comp(power_o) == 1 || vibir_comp(power_o) == 2 ) {
						Sleep(2000);
						cout << "I am call" << endl;
						Sleep(1500);
						if (moneyo > raise) {
							moneyo -= raise;
							bank += raise;
						}
						else {
							bank += moneyo;
							moneyo = 0;

						}
						if (moneyo == 0) { all_in(); Sleep(1500); }
						//перевірка  чи хватає грошей для колу
						break;
					}
					//логіка на кол
					
				}
				else
				{
						cout << "You do not have so much money" << endl;
						Sleep(3000);
						continue;
				}
				if (pas == true) {
					break;
				}
			}
			if (hid == 'x') {
				Sleep(3000);
				break;
			}
			else {
				cout << "Error, Please repeat" << endl;
				Sleep(2000);
				z == 0 ? vvidcart1() : z == 1 ? flop(2) : z == 2 ? flop(3) : flop(4);
			}
		}
		
	}

	return ret;
}
void you_win() {
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"\t\t\t\t	▄▄▄    ▄▄▄                              ▄▄      ▄▄  ▄▄▄▄▄▄   ▄▄▄   ▄▄     ▄▄ "<<endl;
cout<<"\t\t\t\t	 ██▄  ▄██                               ██      ██  ▀▀██▀▀   ███   ██     ██ "<<endl;
cout<<"\t\t\t\t	  ██▄▄██    ▄████▄   ██    ██           ▀█▄ ██ ▄█▀    ██     ██▀█  ██     ██ "<<endl;
cout<<"\t\t\t\t	   ▀██▀    ██▀  ▀██  ██    ██            ██ ██ ██     ██     ██ ██ ██     ██ "<<endl;
cout<<"\t\t\t\t	    ██     ██    ██  ██    ██            ███▀▀███     ██     ██  █▄██     ▀▀ "<<endl;
cout<<"\t\t\t\t	    ██     ▀██▄▄██▀  ██▄▄▄███            ███  ███   ▄▄██▄▄   ██   ███        "<<endl;
cout<<"\t\t\t\t	    ▀▀       ▀▀▀▀     ▀▀▀▀ ▀▀            ▀▀▀  ▀▀▀   ▀▀▀▀▀▀   ▀▀   ▀▀▀     ▀▀ "<<endl;
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
}
void you_lose() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t	▄▄▄    ▄▄▄                               ▄▄          ▄▄▄▄      ▄▄▄▄    ▄▄▄▄▄▄▄▄" << endl;
	cout << "\t\t\t\t	 ██▄  ▄██                                ██         ██▀▀██   ▄█▀▀▀▀█   ██▀▀▀▀▀▀" << endl;
	cout << "\t\t\t\t	  ██▄▄██    ▄████▄   ██    ██            ██        ██    ██  ██▄       ██      " << endl;
	cout << "\t\t\t\t	   ▀██▀    ██▀  ▀██  ██    ██            ██        ██    ██   ▀████▄   ███████ " << endl;
	cout << "\t\t\t\t	    ██     ██    ██  ██    ██            ██        ██    ██       ▀██  ██      " << endl;
	cout << "\t\t\t\t	    ██     ▀██▄▄██▀  ██▄▄▄███            ██▄▄▄▄▄▄   ██▄▄██   █▄▄▄▄▄█▀  ██▄▄▄▄▄▄" << endl;
	cout << "\t\t\t\t	    ▀▀       ▀▀▀▀     ▀▀▀▀ ▀▀            ▀▀▀▀▀▀▀▀    ▀▀▀▀     ▀▀▀▀▀    ▀▀▀▀▀▀▀▀" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}
void all_in(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t	    ▄▄     ▄▄        ▄▄                   ▄▄▄▄▄▄   ▄▄▄   ▄▄ " << endl;
	cout << "\t\t\t\t	   ████    ██        ██                   ▀▀██▀▀   ███   ██ " << endl;
	cout << "\t\t\t\t	   ████    ██        ██                     ██     ██▀█  ██ " << endl;
	cout << "\t\t\t\t	  ██  ██   ██        ██                     ██     ██ ██ ██ " << endl;
	cout << "\t\t\t\t	  ██████   ██        ██         █████       ██     ██  █▄██ " << endl;
	cout << "\t\t\t\t	 ▄██  ██▄  ██▄▄▄▄▄▄  ██▄▄▄▄▄▄             ▄▄██▄▄   ██   ███ " << endl;
	cout << "\t\t\t\t	 ▀▀    ▀▀  ▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀             ▀▀▀▀▀▀   ▀▀   ▀▀▀ " << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}
void who_is_winer(int power_m,int power_o) {
	if (power_m > power_o) {
		moneyu += bank;
		bank = 0;
		you_win();
		Sleep(4000);
	}
	else if (power_m == power_o) {
		moneyo += bank / 2;
		moneyu += bank / 2;
		bank = 0;
		Sleep(4000);
	}
	else {
		moneyo += bank;
		bank = 0;
		you_lose();
		Sleep(4000);
	}
	showdown();
	Sleep(5000);
}