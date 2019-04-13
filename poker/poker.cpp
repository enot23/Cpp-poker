
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
const string karty[9] = { "6","7","8","9","10","J","Q","K","T" };
int moneyo = 1000, moneyu = 1000, bank = 0;
void vvidcart1();
void vvidcartm(int(*)[2], int, int);
void flop(int(*)[5], int, int);
void torn(int(*)[5], int, int);
void river(int(*)[5], int, int);
int scan_combination(int(*)[5],int,int, int(*)[2],int,int);

int  main() {
	int i, j, nk;

	srand(time(NULL));
	int karu[2][5];
	int karo[2][2];
	int karm[2][2];
	bool vsee,fold,call;
	int raise;
	char hid;
	
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

	int(*pkaru)[5] = karu;
	int(*pkarm)[2] = karm;
	int(*pkaro)[2] = karo;

	bank = 100;
	moneyo -= bank / 2;
	moneyu -= bank / 2;
	int power_m = (pkaru,5,2, pkarm,2,2);
	
	for (;;) {
		vvidcart1();
		vvidcartm(pkarm, 2, 2);
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
	vvidcartm(pkarm, 2, 2);
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
		vvidcartm(pkarm, 2, 2);
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
		vvidcartm(pkarm, 2, 2);
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

		return 0;
}
void vvidcart1(){
	cout << "                                                                                                            __________________________\n";
	cout << "                                                                                                             Money opponent:" << moneyo << "$\n";
	cout << "                                                                                                            __________________________\n";

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

}
void vvidcartm(int karu[][2], int r, int s) {

	if(karty[karu[0][0]]=="10" && karty[karu[0][1]] != "10") {
		if (karu[1][0] == 0 && karu[1][1] == 0) {
			cout << "\n";
			cout << "                                                                                                              __   __         __   __         " << endl;
			cout << "                                                                                                             /  \\_/  \\       /  \\_/  \\    " << endl;
			cout << "                                                                                                             |       |       |       |        " << endl;
			cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /       \\   " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                              \\     /         \\     /       " << endl;
			cout << "                                                                                                               \\   /           \\   /        " << endl;
			cout << "                                                                                                                \\ /             \\ /         " << endl;

		}
		else if (karu[1][0] == 0 && karu[1][1] == 1) {
			cout << "\n";
			cout << "                                                                                                              __   __            / \\    " << endl;
			cout << "                                                                                                             /  \\_/  \\          /   \\   " << endl;
			cout << "                                                                                                             |       |         /     \\  " << endl;
			cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /        /   " << karty[karu[0][1]] << "   \\ " << endl;
			cout << "                                                                                                              \\     /         |   _   |  " << endl;
			cout << "                                                                                                               \\   /          \\__/^\\__/" << endl;
			cout << "                                                                                                                \\ /              /_\\    " << endl;
		}
		else if (karu[1][0] == 0 && karu[1][1] == 2) {
			cout << "\n";
			cout << "                                                                                                              __   __             _      " << endl;
			cout << "                                                                                                             /  \\_/  \\           ( )     " << endl;
			cout << "                                                                                                             |       |         __/ \\__  " << endl;
			cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /        (__ " << karty[karu[0][1]] << " __)" << endl;
			cout << "                                                                                                              \\     /            \\ /     " << endl;
			cout << "                                                                                                               \\   /             / \\    " << endl;
			cout << "                                                                                                                \\ /             /___\\    " << endl;
		}
		else if (karu[1][0] == 0 && karu[1][1] == 3) {
			cout << "\n";
			cout << "                                                                                                              __   __            / \\     " << endl;
			cout << "                                                                                                             /  \\_/  \\          /   \\    " << endl;
			cout << "                                                                                                             |       |         /     \\    " << endl;
			cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /        /   " << karty[karu[0][1]] << "   \\ " << endl;
			cout << "                                                                                                              \\     /         \\       /  " << endl;
			cout << "                                                                                                               \\   /           \\     /   " << endl;
			cout << "                                                                                                                \\ /             \\   /    " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                / \\          __   __    " << endl;
			cout << "                                                                                                               /   \\        /  \\_/  \\ " << endl;
			cout << "                                                                                                              /     \\       |       |" << endl;
			cout << "                                                                                                             /  " << karty[karu[0][0]] << "   \\      \\   " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                             |   _   |       \\     /" << endl;
			cout << "                                                                                                             \\__/^\\__/        \\   / " << endl;
			cout << "                                                                                                                /_\\            \\ /   " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                / \\             / \\    " << endl;
			cout << "                                                                                                               /   \\           /   \\  " << endl;
			cout << "                                                                                                              /     \\         /     \\  " << endl;
			cout << "                                                                                                             /  " << karty[karu[0][0]] << "   \\       /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                             |   _   |       |   _   |  " << endl;
			cout << "                                                                                                             \\__/^\\__/       \\__/^\\__/" << endl;
			cout << "                                                                                                                /_\\             /_\\    " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                / \\              _      " << endl;
			cout << "                                                                                                               /   \\            ( )  " << endl;
			cout << "                                                                                                              /     \\         __/ \\__" << endl;
			cout << "                                                                                                             /  " << karty[karu[0][0]] << "   \\       (__ " << karty[karu[0][1]] << " __) " << endl;
			cout << "                                                                                                             |   _   |          \\ /    " << endl;
			cout << "                                                                                                             \\__/^\\__/          / \\  " << endl;
			cout << "                                                                                                                /_\\            /___\\   " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                / \\               / \\    " << endl;
			cout << "                                                                                                               /   \\             /   \\   " << endl;
			cout << "                                                                                                              /     \\           /     \\   " << endl;
			cout << "                                                                                                             / " << karty[karu[0][0]] << "    \\         /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                             |   _   |         \\       / " << endl;
			cout << "                                                                                                             \\__/^\\__/          \\     /" << endl;
			cout << "                                                                                                                /_\\              \\   / " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                 _           __   __    " << endl;
			cout << "                                                                                                                ( )         /  \\_/  \\ " << endl;
			cout << "                                                                                                              __/ \\__       |       |" << endl;
			cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)      \\   " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                                \\ /          \\     /" << endl;
			cout << "                                                                                                                / \\           \\   / " << endl;
			cout << "                                                                                                               /___\\           \\ /  " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                 _              / \\   " << endl;
			cout << "                                                                                                                ( )            /   \\ " << endl;
			cout << "                                                                                                              __/ \\__         /     \\ " << endl;
			cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)       /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                                \\ /          |   _   |  " << endl;
			cout << "                                                                                                                / \\          \\__/^\\__/" << endl;
			cout << "                                                                                                               /___\\            /_\\     " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                 _               _    " << endl;
			cout << "                                                                                                                ( )             ( ) " << endl;
			cout << "                                                                                                              __/ \\__         __/ \\__" << endl;
			cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)       (__ " << karty[karu[0][1]] << " __) " << endl;
			cout << "                                                                                                                \\ /             \\ / " << endl;
			cout << "                                                                                                                / \\             / \\ " << endl;
			cout << "                                                                                                               /___\\           /___\\ " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                 _                / \\ " << endl;
			cout << "                                                                                                                ( )              /   \\ " << endl;
			cout << "                                                                                                              __/ \\__           /     \\ " << endl;
			cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)         /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                                \\ /            \\       /" << endl;
			cout << "                                                                                                                / \\             \\     / " << endl;
			cout << "                                                                                                               /___\\             \\   /" << endl;
		}
		else if (karu[1][0] == 3 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                / \\          __   __  " << endl
				<< "                                                                                                               /   \\        /  \\_/  \\ " << endl
				<< "                                                                                                              /     \\       |       |" << endl
				<< "                                                                                                             /  " << karty[karu[0][0]] << "   \\      \\   " << karty[karu[0][1]] << "   /    " << endl
				<< "                                                                                                             \\       /       \\     / " << endl
				<< "                                                                                                              \\     /         \\   /" << endl
				<< "                                                                                                               \\   /           \\ /" << endl;

		}
		else if (karu[1][0] == 3 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                / \\          / \\  " << endl
				<< "                                                                                                               /   \\        /   \\" << endl
				<< "                                                                                                              /     \\      /     \\" << endl
				<< "                                                                                                             /  " << karty[karu[0][0]] << "   \\    /   " << karty[karu[0][1]] << "   \\  " << endl
				<< "                                                                                                             \\       /    |   _   |   " << endl
				<< "                                                                                                              \\     /     \\__/^\\__/ " << endl
				<< "                                                                                                               \\   /         /_\\  " << endl;


		}
		else if (karu[1][0] == 3 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                / \\              _   " << endl
				<< "                                                                                                               /   \\            ( ) " << endl
				<< "                                                                                                              /     \\         __/ \\__ " << endl
				<< "                                                                                                             /  " << karty[karu[0][0]] << "   \\       (__ " << karty[karu[0][1]] << " __) " << endl
				<< "                                                                                                             \\       /          \\ / " << endl
				<< "                                                                                                              \\     /           / \\" << endl
				<< "                                                                                                               \\   /           /___\\ " << endl;

		}
		else if (karu[1][0] == 3 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                / \\            / \\   " << endl
				<< "                                                                                                               /   \\          /   \\ " << endl
				<< "                                                                                                              /     \\        /     \\    " << endl
				<< "                                                                                                             /  " << karty[karu[0][0]] << "   \\      /   " << karty[karu[0][1]] << "   \\  " << endl
				<< "                                                                                                             \\       /      \\       / " << endl
				<< "                                                                                                              \\     /        \\     / " << endl
				<< "                                                                                                               \\   /          \\   / " << endl;


		}
	}

	else if (karty[karu[0][0]] != "10" && karty[karu[0][1]] == "10") {
		if (karu[1][0] == 0 && karu[1][1] == 0) {
			cout << "\n";
			cout << "                                                                                                              __   __         __   __         " << endl;
			cout << "                                                                                                             /  \\_/  \\       /  \\_/  \\    " << endl;
			cout << "                                                                                                             |       |       |       |        " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /       \\  " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                              \\     /         \\     /       " << endl;
			cout << "                                                                                                               \\   /           \\   /        " << endl;
			cout << "                                                                                                                \\ /             \\ /         " << endl;

		}
		else if (karu[1][0] == 0 && karu[1][1] == 1) {
			cout << "\n";
			cout << "                                                                                                              __   __            / \\    " << endl;
			cout << "                                                                                                             /  \\_/  \\          /   \\   " << endl;
			cout << "                                                                                                             |       |         /     \\  " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /        /  " << karty[karu[0][1]] << "   \\ " << endl;
			cout << "                                                                                                              \\     /         |   _   |  " << endl;
			cout << "                                                                                                               \\   /          \\__/^\\__/" << endl;
			cout << "                                                                                                                \\ /              /_\\    " << endl;
		}
		else if (karu[1][0] == 0 && karu[1][1] == 2) {
			cout << "\n";
			cout << "                                                                                                              __   __             _      " << endl;
			cout << "                                                                                                             /  \\_/  \\           ( )     " << endl;
			cout << "                                                                                                             |       |         __/ \\__  " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /        (__" << karty[karu[0][1]] << " __)" << endl;
			cout << "                                                                                                              \\     /            \\ /     " << endl;
			cout << "                                                                                                               \\   /             / \\    " << endl;
			cout << "                                                                                                                \\ /             /___\\    " << endl;
		}
		else if (karu[1][0] == 0 && karu[1][1] == 3) {
			cout << "\n";
			cout << "                                                                                                              __   __            / \\     " << endl;
			cout << "                                                                                                             /  \\_/  \\          /   \\    " << endl;
			cout << "                                                                                                             |       |         /     \\    " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /        /  " << karty[karu[0][1]] << "   \\ " << endl;
			cout << "                                                                                                              \\     /         \\       /  " << endl;
			cout << "                                                                                                               \\   /           \\     /   " << endl;
			cout << "                                                                                                                \\ /             \\   /    " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                / \\          __   __    " << endl;
			cout << "                                                                                                               /   \\        /  \\_/  \\ " << endl;
			cout << "                                                                                                              /     \\       |       |" << endl;
			cout << "                                                                                                             /   " << karty[karu[0][0]] << "   \\      \\  " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                             |   _   |       \\     /" << endl;
			cout << "                                                                                                             \\__/^\\__/        \\   / " << endl;
			cout << "                                                                                                                /_\\            \\ /   " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                / \\             / \\    " << endl;
			cout << "                                                                                                               /   \\           /   \\  " << endl;
			cout << "                                                                                                              /     \\         /     \\  " << endl;
			cout << "                                                                                                             /   " << karty[karu[0][0]] << "   \\       /  " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                             |   _   |       |   _   |  " << endl;
			cout << "                                                                                                             \\__/^\\__/       \\__/^\\__/" << endl;
			cout << "                                                                                                                /_\\             /_\\    " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                / \\              _      " << endl;
			cout << "                                                                                                               /   \\            ( )  " << endl;
			cout << "                                                                                                              /     \\         __/ \\__" << endl;
			cout << "                                                                                                             /   " << karty[karu[0][0]] << "   \\       (__" << karty[karu[0][1]] << " __) " << endl;
			cout << "                                                                                                             |   _   |          \\ /    " << endl;
			cout << "                                                                                                             \\__/^\\__/          / \\  " << endl;
			cout << "                                                                                                                /_\\            /___\\   " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                / \\               / \\    " << endl;
			cout << "                                                                                                               /   \\             /   \\   " << endl;
			cout << "                                                                                                              /     \\           /     \\   " << endl;
			cout << "                                                                                                             /  " << karty[karu[0][0]] << "    \\         /  " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                             |   _   |         \\       / " << endl;
			cout << "                                                                                                             \\__/^\\__/          \\     /" << endl;
			cout << "                                                                                                                /_\\              \\   / " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                 _           __   __    " << endl;
			cout << "                                                                                                                ( )         /  \\_/  \\ " << endl;
			cout << "                                                                                                              __/ \\__       |       |" << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)      \\  " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                                \\ /          \\     /" << endl;
			cout << "                                                                                                                / \\           \\   / " << endl;
			cout << "                                                                                                               /___\\           \\ /  " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                 _              / \\   " << endl;
			cout << "                                                                                                                ( )            /   \\ " << endl;
			cout << "                                                                                                              __/ \\__         /     \\ " << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)       /  " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                                \\ /          |   _   |  " << endl;
			cout << "                                                                                                                / \\          \\__/^\\__/" << endl;
			cout << "                                                                                                               /___\\            /_\\     " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                 _               _    " << endl;
			cout << "                                                                                                                ( )             ( ) " << endl;
			cout << "                                                                                                              __/ \\__         __/ \\__" << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)       (__" << karty[karu[0][1]] << " __) " << endl;
			cout << "                                                                                                                \\ /             \\ / " << endl;
			cout << "                                                                                                                / \\             / \\ " << endl;
			cout << "                                                                                                               /___\\           /___\\ " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                 _                / \\ " << endl;
			cout << "                                                                                                                ( )              /   \\ " << endl;
			cout << "                                                                                                              __/ \\__           /     \\ " << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)         /  " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                                \\ /            \\       /" << endl;
			cout << "                                                                                                                / \\             \\     / " << endl;
			cout << "                                                                                                               /___\\             \\   /" << endl;
		}
		else if (karu[1][0] == 3 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                / \\          __   __  " << endl
				<< "                                                                                                               /   \\        /  \\_/  \\ " << endl
				<< "                                                                                                              /     \\       |       |" << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\      \\  " << karty[karu[0][1]] << "   /    " << endl
				<< "                                                                                                             \\       /       \\     / " << endl
				<< "                                                                                                              \\     /         \\   /" << endl
				<< "                                                                                                               \\   /           \\ /" << endl;

		}
		else if (karu[1][0] == 3 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                / \\          / \\  " << endl
				<< "                                                                                                               /   \\        /   \\" << endl
				<< "                                                                                                              /     \\      /     \\" << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\    /  " << karty[karu[0][1]] << "   \\  " << endl
				<< "                                                                                                             \\       /    |   _   |   " << endl
				<< "                                                                                                              \\     /     \\__/^\\__/ " << endl
				<< "                                                                                                               \\   /         /_\\  " << endl;


		}
		else if (karu[1][0] == 3 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                / \\              _   " << endl
				<< "                                                                                                               /   \\            ( ) " << endl
				<< "                                                                                                              /     \\         __/ \\__ " << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\       (__" << karty[karu[0][1]] << " __) " << endl
				<< "                                                                                                             \\       /          \\ / " << endl
				<< "                                                                                                              \\     /           / \\" << endl
				<< "                                                                                                               \\   /           /___\\ " << endl;

		}
		else if (karu[1][0] == 3 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                / \\            / \\   " << endl
				<< "                                                                                                               /   \\          /   \\ " << endl
				<< "                                                                                                              /     \\        /     \\    " << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\       /  " << karty[karu[0][1]] << "   \\  " << endl
				<< "                                                                                                             \\       /      \\       / " << endl
				<< "                                                                                                              \\     /        \\     / " << endl
				<< "                                                                                                               \\   /          \\   / " << endl;


		}
		   
	}
	

	else if (karty[karu[0][0]] == "10" && karty[karu[0][1]] == "10")                         {
	if (karu[1][0] == 0 && karu[1][1] == 0) {
		cout << "\n";
		cout << "                                                                                                              __   __         __   __         " << endl;
		cout << "                                                                                                             /  \\_/  \\       /  \\_/  \\    " << endl;
		cout << "                                                                                                             |       |       |       |        " << endl;
		cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /       \\  " << karty[karu[0][1]] << "   /    " << endl;
		cout << "                                                                                                              \\     /         \\     /       " << endl;
		cout << "                                                                                                               \\   /           \\   /        " << endl;
		cout << "                                                                                                                \\ /             \\ /         " << endl;

	}
	else if (karu[1][0] == 0 && karu[1][1] == 1) {
		cout << "\n";
		cout << "                                                                                                              __   __            / \\    " << endl;
		cout << "                                                                                                             /  \\_/  \\          /   \\   " << endl;
		cout << "                                                                                                             |       |         /     \\  " << endl;
		cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /        /  " << karty[karu[0][1]] << "   \\ " << endl;
		cout << "                                                                                                              \\     /         |   _   |  " << endl;
		cout << "                                                                                                               \\   /          \\__/^\\__/" << endl;
		cout << "                                                                                                                \\ /              /_\\    " << endl;
	}
	else if (karu[1][0] == 0 && karu[1][1] == 2) {
		cout << "\n";
		cout << "                                                                                                              __   __             _      " << endl;
		cout << "                                                                                                             /  \\_/  \\           ( )     " << endl;
		cout << "                                                                                                             |       |         __/ \\__  " << endl;
		cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /        (__" << karty[karu[0][1]] << " __)" << endl;
		cout << "                                                                                                              \\     /            \\ /     " << endl;
		cout << "                                                                                                               \\   /             / \\    " << endl;
		cout << "                                                                                                                \\ /             /___\\    " << endl;
	}
	else if (karu[1][0] == 0 && karu[1][1] == 3) {
		cout << "\n";
		cout << "                                                                                                              __   __            / \\     " << endl;
		cout << "                                                                                                             /  \\_/  \\          /   \\    " << endl;
		cout << "                                                                                                             |       |         /     \\    " << endl;
		cout << "                                                                                                             \\  " << karty[karu[0][0]] << "   /        /  " << karty[karu[0][1]] << "   \\ " << endl;
		cout << "                                                                                                              \\     /         \\       /  " << endl;
		cout << "                                                                                                               \\   /           \\     /   " << endl;
		cout << "                                                                                                                \\ /             \\   /    " << endl;
	}
	else if (karu[1][0] == 1 && karu[1][1] == 0) {
		cout << endl;
		cout << "                                                                                                                / \\          __   __    " << endl;
		cout << "                                                                                                               /   \\        /  \\_/  \\ " << endl;
		cout << "                                                                                                              /     \\       |       |" << endl;
		cout << "                                                                                                             /  " << karty[karu[0][0]] << "   \\      \\  " << karty[karu[0][1]] << "   /    " << endl;
		cout << "                                                                                                             |   _   |       \\     /" << endl;
		cout << "                                                                                                             \\__/^\\__/        \\   / " << endl;
		cout << "                                                                                                                /_\\            \\ /   " << endl;
	}
	else if (karu[1][0] == 1 && karu[1][1] == 1) {
		cout << endl;
		cout << "                                                                                                                / \\             / \\    " << endl;
		cout << "                                                                                                               /   \\           /   \\  " << endl;
		cout << "                                                                                                              /     \\         /     \\  " << endl;
		cout << "                                                                                                             /  " << karty[karu[0][0]] << "   \\       /  " << karty[karu[0][1]] << "   \\  " << endl;
		cout << "                                                                                                             |   _   |       |   _   |  " << endl;
		cout << "                                                                                                             \\__/^\\__/       \\__/^\\__/" << endl;
		cout << "                                                                                                                /_\\             /_\\    " << endl;
	}
	else if (karu[1][0] == 1 && karu[1][1] == 2) {
		cout << endl;
		cout << "                                                                                                                / \\              _      " << endl;
		cout << "                                                                                                               /   \\            ( )  " << endl;
		cout << "                                                                                                              /     \\         __/ \\__" << endl;
		cout << "                                                                                                             /  " << karty[karu[0][0]] << "   \\       (__" << karty[karu[0][1]] << " __) " << endl;
		cout << "                                                                                                             |   _   |          \\ /    " << endl;
		cout << "                                                                                                             \\__/^\\__/          / \\  " << endl;
		cout << "                                                                                                                /_\\            /___\\   " << endl;
	}
	else if (karu[1][0] == 1 && karu[1][1] == 3) {
		cout << endl;
		cout << "                                                                                                                / \\               / \\    " << endl;
		cout << "                                                                                                               /   \\             /   \\   " << endl;
		cout << "                                                                                                              /     \\           /     \\   " << endl;
		cout << "                                                                                                             /  " << karty[karu[0][0]] << "    \\         /  " << karty[karu[0][1]] << "   \\  " << endl;
		cout << "                                                                                                             |   _   |         \\       / " << endl;
		cout << "                                                                                                             \\__/^\\__/          \\     /" << endl;
		cout << "                                                                                                                /_\\              \\   / " << endl;
	}
	else if (karu[1][0] == 2 && karu[1][1] == 0) {
		cout << endl;
		cout << "                                                                                                                 _           __   __    " << endl;
		cout << "                                                                                                                ( )         /  \\_/  \\ " << endl;
		cout << "                                                                                                              __/ \\__       |       |" << endl;
		cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)      \\  " << karty[karu[0][1]] << "   /    " << endl;
		cout << "                                                                                                                \\ /          \\     /" << endl;
		cout << "                                                                                                                / \\           \\   / " << endl;
		cout << "                                                                                                               /___\\           \\ /  " << endl;
	}
	else if (karu[1][0] == 2 && karu[1][1] == 1) {
		cout << endl;
		cout << "                                                                                                                 _              / \\   " << endl;
		cout << "                                                                                                                ( )            /   \\ " << endl;
		cout << "                                                                                                              __/ \\__         /     \\ " << endl;
		cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)       /  " << karty[karu[0][1]] << "   \\  " << endl;
		cout << "                                                                                                                \\ /          |   _   |  " << endl;
		cout << "                                                                                                                / \\          \\__/^\\__/" << endl;
		cout << "                                                                                                               /___\\            /_\\     " << endl;
	}
	else if (karu[1][0] == 2 && karu[1][1] == 2) {
		cout << endl;
		cout << "                                                                                                                 _               _    " << endl;
		cout << "                                                                                                                ( )             ( ) " << endl;
		cout << "                                                                                                              __/ \\__         __/ \\__" << endl;
		cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)       (__" << karty[karu[0][1]] << " __) " << endl;
		cout << "                                                                                                                \\ /             \\ / " << endl;
		cout << "                                                                                                                / \\             / \\ " << endl;
		cout << "                                                                                                               /___\\           /___\\ " << endl;
	}
	else if (karu[1][0] == 2 && karu[1][1] == 3) {
		cout << endl;
		cout << "                                                                                                                 _                / \\ " << endl;
		cout << "                                                                                                                ( )              /   \\ " << endl;
		cout << "                                                                                                              __/ \\__           /     \\ " << endl;
		cout << "                                                                                                             (__" << karty[karu[0][0]] << " __)         /  " << karty[karu[0][1]] << "   \\  " << endl;
		cout << "                                                                                                                \\ /            \\       /" << endl;
		cout << "                                                                                                                / \\             \\     / " << endl;
		cout << "                                                                                                               /___\\             \\   /" << endl;
	}
	else if (karu[1][0] == 3 && karu[1][1] == 0) {
		cout << endl;
		cout << "                                                                                                                / \\          __   __  " << endl
			<< "                                                                                                               /   \\        /  \\_/  \\ " << endl
			<< "                                                                                                              /     \\       |       |" << endl
			<< "                                                                                                             / " << karty[karu[0][0]] << "   \\      \\  " << karty[karu[0][1]] << "   /    " << endl
			<< "                                                                                                             \\       /       \\     / " << endl
			<< "                                                                                                              \\     /         \\   /" << endl
			<< "                                                                                                               \\   /           \\ /" << endl;

	}
	else if (karu[1][0] == 3 && karu[1][1] == 1) {
		cout << endl;
		cout << "                                                                                                                / \\          / \\  " << endl
			<< "                                                                                                               /   \\        /   \\" << endl
			<< "                                                                                                              /     \\      /     \\" << endl
			<< "                                                                                                             /  " << karty[karu[0][0]] << "   \\    /  " << karty[karu[0][1]] << "   \\  " << endl
			<< "                                                                                                             \\       /    |   _   |   " << endl
			<< "                                                                                                              \\     /     \\__/^\\__/ " << endl
			<< "                                                                                                               \\   /         /_\\  " << endl;


	}
	else if (karu[1][0] == 3 && karu[1][1] == 2) {
		cout << endl;
		cout << "                                                                                                                / \\              _   " << endl
			<< "                                                                                                               /   \\            ( ) " << endl
			<< "                                                                                                              /     \\         __/ \\__ " << endl
			<< "                                                                                                             /  " << karty[karu[0][0]] << "   \\       (__" << karty[karu[0][1]] << " __) " << endl
			<< "                                                                                                             \\       /          \\ / " << endl
			<< "                                                                                                              \\     /           / \\" << endl
			<< "                                                                                                               \\   /           /___\\ " << endl;

	}
	else if (karu[1][0] == 3 && karu[1][1] == 3) {
		cout << endl;
		cout << "                                                                                                                / \\            / \\   " << endl
			<< "                                                                                                               /   \\          /   \\ " << endl
			<< "                                                                                                              /     \\        /     \\    " << endl
			<< "                                                                                                             /  " << karty[karu[0][0]] << "   \\      /  " << karty[karu[0][1]] << "   \\  " << endl
			<< "                                                                                                             \\       /      \\       / " << endl
			<< "                                                                                                              \\     /        \\     / " << endl
			<< "                                                                                                               \\   /          \\   / " << endl;


	}
	}
	
	else {
		if (karu[1][0] == 0 && karu[1][1] == 0) {
			cout << "\n";
			cout << "                                                                                                              __   __         __   __         " << endl;
			cout << "                                                                                                             /  \\_/  \\       /  \\_/  \\    " << endl;
			cout << "                                                                                                             |       |       |       |        " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /       \\   " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                              \\     /         \\     /       " << endl;
			cout << "                                                                                                               \\   /           \\   /        " << endl;
			cout << "                                                                                                                \\ /             \\ /         " << endl;

		}
		else if (karu[1][0] == 0 && karu[1][1] == 1) {
			cout << "\n";
			cout << "                                                                                                              __   __            / \\    " << endl;
			cout << "                                                                                                             /  \\_/  \\          /   \\   " << endl;
			cout << "                                                                                                             |       |         /     \\  " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /        /   " << karty[karu[0][1]] << "   \\ " << endl;
			cout << "                                                                                                              \\     /         |   _   |  " << endl;
			cout << "                                                                                                               \\   /          \\__/^\\__/" << endl;
			cout << "                                                                                                                \\ /              /_\\    " << endl;
		}
		else if (karu[1][0] == 0 && karu[1][1] == 2) {
			cout << "\n";
			cout << "                                                                                                              __   __             _      " << endl;
			cout << "                                                                                                             /  \\_/  \\           ( )     " << endl;
			cout << "                                                                                                             |       |         __/ \\__  " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /        (__ " << karty[karu[0][1]] << " __)" << endl;
			cout << "                                                                                                              \\     /            \\ /     " << endl;
			cout << "                                                                                                               \\   /             / \\    " << endl;
			cout << "                                                                                                                \\ /             /___\\    " << endl;
		}
		else if (karu[1][0] == 0 && karu[1][1] == 3) {
			cout << "\n";
			cout << "                                                                                                              __   __            / \\     " << endl;
			cout << "                                                                                                             /  \\_/  \\          /   \\    " << endl;
			cout << "                                                                                                             |       |         /     \\    " << endl;
			cout << "                                                                                                             \\   " << karty[karu[0][0]] << "   /        /   " << karty[karu[0][1]] << "   \\ " << endl;
			cout << "                                                                                                              \\     /         \\       /  " << endl;
			cout << "                                                                                                               \\   /           \\     /   " << endl;
			cout << "                                                                                                                \\ /             \\   /    " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                / \\          __   __    " << endl;
			cout << "                                                                                                               /   \\        /  \\_/  \\ " << endl;
			cout << "                                                                                                              /     \\       |       |" << endl;
			cout << "                                                                                                             /   " << karty[karu[0][0]] << "   \\      \\   " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                             |   _   |       \\     /" << endl;
			cout << "                                                                                                             \\__/^\\__/        \\   / " << endl;
			cout << "                                                                                                                /_\\            \\ /   " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                / \\             / \\    " << endl;
			cout << "                                                                                                               /   \\           /   \\  " << endl;
			cout << "                                                                                                              /     \\         /     \\  " << endl;
			cout << "                                                                                                             /   " << karty[karu[0][0]] << "   \\       /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                             |   _   |       |   _   |  " << endl;
			cout << "                                                                                                             \\__/^\\__/       \\__/^\\__/" << endl;
			cout << "                                                                                                                /_\\             /_\\    " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                / \\              _      " << endl;
			cout << "                                                                                                               /   \\            ( )  " << endl;
			cout << "                                                                                                              /     \\         __/ \\__" << endl;
			cout << "                                                                                                             /   " << karty[karu[0][0]] << "   \\       (__ " << karty[karu[0][1]] << " __) " << endl;
			cout << "                                                                                                             |   _   |          \\ /    " << endl;
			cout << "                                                                                                             \\__/^\\__/          / \\  " << endl;
			cout << "                                                                                                                /_\\            /___\\   " << endl;
		}
		else if (karu[1][0] == 1 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                / \\               / \\    " << endl;
			cout << "                                                                                                               /   \\             /   \\   " << endl;
			cout << "                                                                                                              /     \\           /     \\   " << endl;
			cout << "                                                                                                             /  " << karty[karu[0][0]] << "    \\         /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                             |   _   |         \\       / " << endl;
			cout << "                                                                                                             \\__/^\\__/          \\     /" << endl;
			cout << "                                                                                                                /_\\              \\   / " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                 _           __   __    " << endl;
			cout << "                                                                                                                ( )         /  \\_/  \\ " << endl;
			cout << "                                                                                                              __/ \\__       |       |" << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)      \\   " << karty[karu[0][1]] << "   /    " << endl;
			cout << "                                                                                                                \\ /          \\     /" << endl;
			cout << "                                                                                                                / \\           \\   / " << endl;
			cout << "                                                                                                               /___\\           \\ /  " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                 _              / \\   " << endl;
			cout << "                                                                                                                ( )            /   \\ " << endl;
			cout << "                                                                                                              __/ \\__         /     \\ " << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)       /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                                \\ /          |   _   |  " << endl;
			cout << "                                                                                                                / \\          \\__/^\\__/" << endl;
			cout << "                                                                                                               /___\\            /_\\     " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                 _               _    " << endl;
			cout << "                                                                                                                ( )             ( ) " << endl;
			cout << "                                                                                                              __/ \\__         __/ \\__" << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)       (__ " << karty[karu[0][1]] << " __) " << endl;
			cout << "                                                                                                                \\ /             \\ / " << endl;
			cout << "                                                                                                                / \\             / \\ " << endl;
			cout << "                                                                                                               /___\\           /___\\ " << endl;
		}
		else if (karu[1][0] == 2 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                 _                / \\ " << endl;
			cout << "                                                                                                                ( )              /   \\ " << endl;
			cout << "                                                                                                              __/ \\__           /     \\ " << endl;
			cout << "                                                                                                             (__ " << karty[karu[0][0]] << " __)         /   " << karty[karu[0][1]] << "   \\  " << endl;
			cout << "                                                                                                                \\ /            \\       /" << endl;
			cout << "                                                                                                                / \\             \\     / " << endl;
			cout << "                                                                                                               /___\\             \\   /" << endl;
		}
		else if (karu[1][0] == 3 && karu[1][1] == 0) {
			cout << endl;
			cout << "                                                                                                                / \\          __   __  " << endl
				<< "                                                                                                               /   \\        /  \\_/  \\ " << endl
				<< "                                                                                                              /     \\       |       |" << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\      \\   " << karty[karu[0][1]] << "   /    " << endl
				<< "                                                                                                             \\       /       \\     / " << endl
				<< "                                                                                                              \\     /         \\   /" << endl
				<< "                                                                                                               \\   /           \\ /" << endl;

		}
		else if (karu[1][0] == 3 && karu[1][1] == 1) {
			cout << endl;
			cout << "                                                                                                                / \\          / \\  " << endl
				<< "                                                                                                               /   \\        /   \\" << endl
				<< "                                                                                                              /     \\      /     \\" << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\    /   " << karty[karu[0][1]] << "   \\  " << endl
				<< "                                                                                                             \\       /    |   _   |   " << endl
				<< "                                                                                                              \\     /     \\__/^\\__/ " << endl
				<< "                                                                                                               \\   /         /_\\  " << endl;


		}
		else if (karu[1][0] == 3 && karu[1][1] == 2) {
			cout << endl;
			cout << "                                                                                                                / \\              _   " << endl
				<< "                                                                                                               /   \\            ( ) " << endl
				<< "                                                                                                              /     \\         __/ \\__ " << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\       (__ " << karty[karu[0][1]] << " __) " << endl
				<< "                                                                                                             \\       /          \\ / " << endl
				<< "                                                                                                              \\     /           / \\" << endl
				<< "                                                                                                               \\   /           /___\\ " << endl;

		}
		else if (karu[1][0] == 3 && karu[1][1] == 3) {
			cout << endl;
			cout << "                                                                                                                / \\            / \\   " << endl
				<< "                                                                                                               /   \\          /   \\ " << endl
				<< "                                                                                                              /     \\        /     \\    " << endl
				<< "                                                                                                             /   " << karty[karu[0][0]] << "   \\      /   " << karty[karu[0][1]] << "   \\  " << endl
				<< "                                                                                                             \\       /      \\       / " << endl
				<< "                                                                                                              \\     /        \\     / " << endl
				<< "                                                                                                               \\   /          \\   / " << endl;


		}
	}
			cout << "                                                                                                            __________________________\n";
			cout << "                                                                                                              Your money:" << moneyu << "$\n";
			cout << "                                                                                                            __________________________\n";
}
void flop	  (int karu[][5], int r, int s) {
		   cout << "                                                                                                            __________________________\n";
	       cout << "                                                                                                             Money opponent:" << moneyo << "$\n";
		   cout << "                                                                                                            __________________________\n";
	if (karty[karu[0][0]] == "10") {
		if (karu[1][0] ==0) {
			cout << endl;
			cout << "     __   __                                                                                               ___________   ___________" << endl;
			cout << "    /  \\_/  \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |       |                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\  " << karty[karu[0][0]] << "   /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 1) {
			cout << endl;
			cout << "       / \\                                                                                                  ___________   ___________" << endl;
			cout << "      /   \\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /     \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    /  " << karty[karu[0][0]] << "   \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |   _   |                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\__/^\\__/                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       /_\\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 2) {
			cout << endl;
			cout << "        _                                                                                                   ___________   ___________" << endl;
			cout << "       ( )                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     __/ \\__                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    (__" << karty[karu[0][0]] << " __)                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       / \\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /___\\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 3) {
			cout << endl;
			cout << "        / \\                                                                                                 ___________   ___________" << endl;
			cout << "       /   \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /     \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /  " << karty[karu[0][0]] << "   \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\       /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
	}
	else {
		if (karu[1][0] == 0) {
			cout << endl;
			cout << "     __   __                                                                                               ___________   ___________" << endl;
			cout << "    /  \\_/  \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |       |                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\   " << karty[karu[0][0]] << "   /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 1) {
			cout << endl;
			cout << "       / \\                                                                                                  ___________   ___________" << endl;
			cout << "      /   \\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /     \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    /   " << karty[karu[0][0]] << "   \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |   _   |                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\__/^\\__/                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       /_\\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 2) {
			cout << endl;
			cout << "        _                                                                                                   ___________   ___________" << endl;
			cout << "       ( )                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     __/ \\__                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    (__ " << karty[karu[0][0]] << " __)                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       / \\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /___\\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 3) {
			cout << endl;
			cout << "        / \\                                                                                                 ___________   ___________" << endl;
			cout << "       /   \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /     \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /   " << karty[karu[0][0]] << "   \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\       /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
	}
	for (int i = 1; i < 3; i++) {
		if (karty[karu[0][i]] == "10") {
			if (i == 1) {


				if (karu[1][i] == 0) {
					cout << endl;
					cout << "     __   __                                        ++++++          " << endl;
					cout << "    /  \\_/  \\                                     ++      ++        " << endl;
					cout << "    |       |                                   ++          ++      " << endl;
					cout << "    \\   " << karty[karu[0][i]] << "  /                                   +    " << bank << " " << endl;
					cout << "     \\     /                                    ++          ++      " << endl;
					cout << "      \\   /                                       ++      ++        " << endl;
					cout << "       \\ /                                          ++++++          " << endl;
				}
				else if (karu[1][i] == 1) {
					cout << endl;
					cout << "       / \\                                           ++++++         " << endl;
					cout << "      /   \\                                        ++      ++       " << endl;
					cout << "     /     \\                                     ++          ++     " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\                                    +    " << bank << "" << endl;
					cout << "    |   _   |                                    ++          ++     " << endl;
					cout << "    \\__/^\\__/                                      ++      ++       " << endl;
					cout << "       /_\\                                           ++++++         " << endl;
				}
				else if (karu[1][i] == 2) {
					cout << endl;
					cout << "        _                                            ++++++         " << endl;
					cout << "       ( )                                         ++      ++       " << endl;
					cout << "     __/ \\__                                     ++          ++     " << endl;
					cout << "    (__" << karty[karu[0][i]] << " __)                                    +    " << bank << "" << endl;
					cout << "       \\ /                                       ++          ++     " << endl;
					cout << "       / \\                                         ++      ++       " << endl;
					cout << "      /___\\                                          ++++++         " << endl;
				}
				else if (karu[1][i] == 3) {
					cout << endl;
					cout << "       / \\                                           ++++++          " << endl;
					cout << "      /   \\                                        ++      ++        " << endl;
					cout << "     /     \\                                     ++          ++      " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\                                    +    " << bank << " " << endl;
					cout << "    \\       /                                    ++          ++      " << endl;
					cout << "     \\     /                                       ++      ++        " << endl;
					cout << "      \\   /                                          ++++++          " << endl;
				}
				
			}
			//перевірка де виводити банк
			else
			{


				if (karu[1][i] == 0) {
					cout << endl;
					cout << "     __   __                                   " << endl;
					cout << "    /  \\_/  \\                                " << endl;
					cout << "    |       |                                   " << endl;
					cout << "    \\   " << karty[karu[0][i]] << "  /         " << endl;
					cout << "     \\     /                                   " << endl;
					cout << "      \\   /                                    " << endl;
					cout << "       \\ /                                     " << endl;
				}
				else if (karu[1][i] == 1) {
					cout << endl;
					cout << "       / \\                                     " << endl;
					cout << "      /   \\                                    " << endl;
					cout << "     /     \\                                   " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\         " << endl;
					cout << "    |   _   |                                   " << endl;
					cout << "    \\__/^\\__/                                 " << endl;
					cout << "       /_\\                                     " << endl;
				}
				else if (karu[1][i] == 2) {
					cout << endl;
					cout << "        _                                       " << endl;
					cout << "       ( )                                      " << endl;
					cout << "     __/ \\__                                   " << endl;
					cout << "    (__" << karty[karu[0][i]] << " __)          " << endl;
					cout << "       \\ /                                     " << endl;
					cout << "       / \\                                     " << endl;
					cout << "      /___\\                                    " << endl;
				}
				else if (karu[1][i] == 3) {
					cout << endl;
					cout << "       / \\                                    " << endl;
					cout << "      /   \\                                   " << endl;
					cout << "     /     \\                                  " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\        " << endl;
					cout << "    \\       /                                 " << endl;
					cout << "     \\     /                                  " << endl;
					cout << "      \\   /                                   " << endl;
				}
			}
		}
		else {
			if (i == 1) {


				if (karu[1][i] == 0) {
					cout << endl;
					cout << "     __   __                                        ++++++          " << endl;
					cout << "    /  \\_/  \\                                     ++      ++        " << endl;
					cout << "    |       |                                   ++          ++      " << endl;
					cout << "    \\    " << karty[karu[0][i]] << "  /                                   +    " << bank << " " << endl;
					cout << "     \\     /                                    ++          ++      " << endl;
					cout << "      \\   /                                       ++      ++        " << endl;
					cout << "       \\ /                                          ++++++          " << endl;
				}
				else if (karu[1][i] == 1) {
					cout << endl;
					cout << "       / \\                                           ++++++         " << endl;
					cout << "      /   \\                                        ++      ++       " << endl;
					cout << "     /     \\                                     ++          ++     " << endl;
					cout << "    /   " << karty[karu[0][i]] << "   \\                                    +    " << bank << "" << endl;
					cout << "    |   _   |                                    ++          ++     " << endl;
					cout << "    \\__/^\\__/                                      ++      ++       " << endl;
					cout << "       /_\\                                           ++++++         " << endl;
				}
				else if (karu[1][i] == 2) {
					cout << endl;
					cout << "        _                                            ++++++         " << endl;
					cout << "       ( )                                         ++      ++       " << endl;
					cout << "     __/ \\__                                     ++          ++     " << endl;
					cout << "    (__ " << karty[karu[0][i]] << " __)                                    +    " << bank << "" << endl;
					cout << "       \\ /                                       ++          ++     " << endl;
					cout << "       / \\                                         ++      ++       " << endl;
					cout << "      /___\\                                          ++++++         " << endl;
				}
				else if (karu[1][i] == 3) {
					cout << endl;
					cout << "       / \\                                           ++++++          " << endl;
					cout << "      /   \\                                        ++      ++        " << endl;
					cout << "     /     \\                                     ++          ++      " << endl;
					cout << "    /   " << karty[karu[0][i]] << "   \\                                    +    " << bank << " " << endl;
					cout << "    \\       /                                    ++          ++      " << endl;
					cout << "     \\     /                                       ++      ++        " << endl;
					cout << "      \\   /                                          ++++++          " << endl;
				}

			}
			//перевірка де виводити банк
			else {
			if (karu[1][i] == 0) {
				cout << endl;
				cout << "     __   __                                   " << endl;
				cout << "    /  \\_/  \\                                " << endl;
				cout << "    |       |                                   " << endl;
				cout << "    \\   " << karty[karu[0][i]] << "   /        " << endl;
				cout << "     \\     /                                   " << endl;
				cout << "      \\   /                                    " << endl;
				cout << "       \\ /                                     " << endl;
			}
			else if (karu[1][i] == 1) {
				cout << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /   \\                                    " << endl;
				cout << "     /     \\                                   " << endl;
				cout << "    /   " << karty[karu[0][i]] << "   \\        " << endl;
				cout << "    |   _   |                                   " << endl;
				cout << "    \\__/^\\__/                                 " << endl;
				cout << "       /_\\                                     " << endl;
			}
			else if (karu[1][i] == 2) {
				cout << endl;
				cout << "        _                                        " << endl;
				cout << "       ( )                                       " << endl;
				cout << "     __/ \\__                                    " << endl;
				cout << "    (__ " << karty[karu[0][i]] << " __)          " << endl;
				cout << "       \\ /                                      " << endl;
				cout << "       / \\                                      " << endl;
				cout << "      /___\\                                     " << endl;
			}
			else if (karu[1][i] == 3) {
				cout << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /   \\                                    " << endl;
				cout << "     /     \\                                   " << endl;
				cout << "    /   " << karty[karu[0][i]] << "   \\        " << endl;
				cout << "    \\       /                                  " << endl;
				cout << "     \\     /                                   " << endl;
				cout << "      \\   /                                    " << endl;
			}
			}
		}
	}
	for (int i = 0; i < 2; i++) {
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
void torn	  (int karu[][5], int r, int s) {
			cout << "                                                                                                            __________________________\n";
			cout << "                                                                                                             Money opponent:" << moneyo << "$\n";
			cout << "                                                                                                            __________________________\n";
	if (karty[karu[0][0]] == "10") {
		if (karu[1][0] == 0) {
			cout << endl;
			cout << "     __   __                                                                                               ___________   ___________" << endl;
			cout << "    /  \\_/  \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |       |                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\  " << karty[karu[0][0]] << "   /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 1) {
			cout << endl;
			cout << "       / \\                                                                                                  ___________   ___________" << endl;
			cout << "      /   \\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /     \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    /  " << karty[karu[0][0]] << "   \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |   _   |                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\__/^\\__/                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       /_\\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 2) {
			cout << endl;
			cout << "        _                                                                                                   ___________   ___________" << endl;
			cout << "       ( )                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     __/ \\__                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    (__" << karty[karu[0][0]] << " __)                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       / \\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /___\\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 3) {
			cout << endl;
			cout << "        / \\                                                                                                 ___________   ___________" << endl;
			cout << "       /   \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /     \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /  " << karty[karu[0][0]] << "   \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\       /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
	}
	else {
		if (karu[1][0] == 0) {
			cout << endl;
			cout << "     __   __                                                                                               ___________   ___________" << endl;
			cout << "    /  \\_/  \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |       |                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\   " << karty[karu[0][0]] << "   /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 1) {
			cout << endl;
			cout << "       / \\                                                                                                  ___________   ___________" << endl;
			cout << "      /   \\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /     \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    /   " << karty[karu[0][0]] << "   \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |   _   |                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\__/^\\__/                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       /_\\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 2) {
			cout << endl;
			cout << "        _                                                                                                   ___________   ___________" << endl;
			cout << "       ( )                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     __/ \\__                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    (__ " << karty[karu[0][0]] << " __)                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       / \\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /___\\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 3) {
			cout << endl;
			cout << "        / \\                                                                                                 ___________   ___________" << endl;
			cout << "       /   \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /     \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /   " << karty[karu[0][0]] << "   \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\       /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
	}
	for (int i = 1; i < 4; i++) {
		if (karty[karu[0][i]] == "10") {
			if (i == 1) {


				if (karu[1][i] == 0) {
					cout << endl;
					cout << "     __   __                                        ++++++          " << endl;
					cout << "    /  \\_/  \\                                     ++      ++        " << endl;
					cout << "    |       |                                   ++          ++      " << endl;
					cout << "    \\   " << karty[karu[0][i]] << "  /                                   +    " << bank << " " << endl;
					cout << "     \\     /                                    ++          ++      " << endl;
					cout << "      \\   /                                       ++      ++        " << endl;
					cout << "       \\ /                                          ++++++          " << endl;
				}
				else if (karu[1][i] == 1) {
					cout << endl;
					cout << "       / \\                                           ++++++         " << endl;
					cout << "      /   \\                                        ++      ++       " << endl;
					cout << "     /     \\                                     ++          ++     " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\                                    +    " << bank << "" << endl;
					cout << "    |   _   |                                    ++          ++     " << endl;
					cout << "    \\__/^\\__/                                      ++      ++       " << endl;
					cout << "       /_\\                                           ++++++         " << endl;
				}
				else if (karu[1][i] == 2) {
					cout << endl;
					cout << "        _                                            ++++++         " << endl;
					cout << "       ( )                                         ++      ++       " << endl;
					cout << "     __/ \\__                                     ++          ++     " << endl;
					cout << "    (__" << karty[karu[0][i]] << " __)                                    +    " << bank << "" << endl;
					cout << "       \\ /                                       ++          ++     " << endl;
					cout << "       / \\                                         ++      ++       " << endl;
					cout << "      /___\\                                          ++++++         " << endl;
				}
				else if (karu[1][i] == 3) {
					cout << endl;
					cout << "       / \\                                           ++++++          " << endl;
					cout << "      /   \\                                        ++      ++        " << endl;
					cout << "     /     \\                                     ++          ++      " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\                                    +    " << bank << " " << endl;
					cout << "    \\       /                                    ++          ++      " << endl;
					cout << "     \\     /                                       ++      ++        " << endl;
					cout << "      \\   /                                          ++++++          " << endl;
				}

			}
			//перевірка де виводити банк
			else {
				if (karu[1][i] == 0) {
				cout << endl;
				cout << "     __   __                                   " << endl;
				cout << "    /  \\_/  \\                                " << endl;
				cout << "    |       |                                   " << endl;
				cout << "    \\   " << karty[karu[0][i]] << "  /         " << endl;
				cout << "     \\     /                                   " << endl;
				cout << "      \\   /                                    " << endl;
				cout << "       \\ /                                     " << endl;
			}
				else if (karu[1][i] == 1) {
				cout << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /   \\                                    " << endl;
				cout << "     /     \\                                   " << endl;
				cout << "    /  " << karty[karu[0][i]] << "   \\         " << endl;
				cout << "    |   _   |                                   " << endl;
				cout << "    \\__/^\\__/                                 " << endl;
				cout << "       /_\\                                     " << endl;
			}
				else if (karu[1][i] == 2) {
				cout << endl;
				cout << "        _                                       " << endl;
				cout << "       ( )                                      " << endl;
				cout << "     __/ \\__                                   " << endl;
				cout << "    (__" << karty[karu[0][i]] << " __)          " << endl;
				cout << "       \\ /                                     " << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /___\\                                    " << endl;
			}
				else if (karu[1][i] == 3) {
				cout << endl;
				cout << "       / \\                                    " << endl;
				cout << "      /   \\                                   " << endl;
				cout << "     /     \\                                  " << endl;
				cout << "    /  " << karty[karu[0][i]] << "   \\        " << endl;
				cout << "    \\       /                                 " << endl;
				cout << "     \\     /                                  " << endl;
				cout << "      \\   /                                   " << endl;
			}
			}
		}
		else {
			if (i == 1) {


				if (karu[1][i] == 0) {
					cout << endl;
					cout << "     __   __                                        ++++++          " << endl;
					cout << "    /  \\_/  \\                                     ++      ++        " << endl;
					cout << "    |       |                                   ++          ++      " << endl;
					cout << "    \\    " << karty[karu[0][i]] << "  /                                   +    " << bank << " " << endl;
					cout << "     \\     /                                    ++          ++      " << endl;
					cout << "      \\   /                                       ++      ++        " << endl;
					cout << "       \\ /                                          ++++++          " << endl;
				}
				else if (karu[1][i] == 1) {
					cout << endl;
					cout << "       / \\                                           ++++++         " << endl;
					cout << "      /   \\                                        ++      ++       " << endl;
					cout << "     /     \\                                     ++          ++     " << endl;
					cout << "    /   " << karty[karu[0][i]] << "   \\                                    +    " << bank << "" << endl;
					cout << "    |   _   |                                    ++          ++     " << endl;
					cout << "    \\__/^\\__/                                      ++      ++       " << endl;
					cout << "       /_\\                                           ++++++         " << endl;
				}
				else if (karu[1][i] == 2) {
					cout << endl;
					cout << "        _                                            ++++++         " << endl;
					cout << "       ( )                                         ++      ++       " << endl;
					cout << "     __/ \\__                                     ++          ++     " << endl;
					cout << "    (__ " << karty[karu[0][i]] << " __)                                    +    " << bank << "" << endl;
					cout << "       \\ /                                       ++          ++     " << endl;
					cout << "       / \\                                         ++      ++       " << endl;
					cout << "      /___\\                                          ++++++         " << endl;
				}
				else if (karu[1][i] == 3) {
					cout << endl;
					cout << "       / \\                                           ++++++          " << endl;
					cout << "      /   \\                                        ++      ++        " << endl;
					cout << "     /     \\                                     ++          ++      " << endl;
					cout << "    /   " << karty[karu[0][i]] << "   \\                                    +    " << bank << " " << endl;
					cout << "    \\       /                                    ++          ++      " << endl;
					cout << "     \\     /                                       ++      ++        " << endl;
					cout << "      \\   /                                          ++++++          " << endl;
				}

			}
			//перевірка де виводити банк
			 else {
				if (karu[1][i] == 0) {
				 cout << endl;
				 cout << "     __   __                                   " << endl;
				 cout << "    /  \\_/  \\                                " << endl;
				 cout << "    |       |                                   " << endl;
				 cout << "    \\   " << karty[karu[0][i]] << "   /        " << endl;
				 cout << "     \\     /                                   " << endl;
				 cout << "      \\   /                                    " << endl;
				 cout << "       \\ /                                     " << endl;
			 }
				else if (karu[1][i] == 1) {
				 cout << endl;
				 cout << "       / \\                                     " << endl;
				 cout << "      /   \\                                    " << endl;
				 cout << "     /     \\                                   " << endl;
				 cout << "    /   " << karty[karu[0][i]] << "   \\        " << endl;
				 cout << "    |   _   |                                   " << endl;
				 cout << "    \\__/^\\__/                                 " << endl;
				 cout << "       /_\\                                     " << endl;
			 }
				else if (karu[1][i] == 2) {
				 cout << endl;
				 cout << "        _                                        " << endl;
				 cout << "       ( )                                       " << endl;
				 cout << "     __/ \\__                                    " << endl;
				 cout << "    (__ " << karty[karu[0][i]] << " __)          " << endl;
				 cout << "       \\ /                                      " << endl;
				 cout << "       / \\                                      " << endl;
				 cout << "      /___\\                                     " << endl;
			 }
				else if (karu[1][i] == 3) {
				 cout << endl;
				 cout << "       / \\                                     " << endl;
				 cout << "      /   \\                                    " << endl;
				 cout << "     /     \\                                   " << endl;
				 cout << "    /   " << karty[karu[0][i]] << "   \\        " << endl;
				 cout << "    \\       /                                  " << endl;
				 cout << "     \\     /                                   " << endl;
				 cout << "      \\   /                                    " << endl;
			 }
			 }
		}
	}
	cout << endl;
	cout << "    ___________   " << endl;
	cout << "    |%%%%%%%%%|   " << endl;
	cout << "    |%%%%%%%%%|   " << endl;
	cout << "    |%%%%%%%%%|   " << endl;
	cout << "    |%%%%%%%%%|   " << endl;
	cout << "    |%%%%%%%%%|   " << endl;
	cout << "    |%%%%%%%%%|   " << endl;
}
void river	  (int karu[][5], int r, int s) {
			cout << "                                                                                                            __________________________\n";
			cout << "                                                                                                             Money opponent:" << moneyo << "$\n";
			cout << "                                                                                                            __________________________\n";
	if (karty[karu[0][0]] == "10") {
		if (karu[1][0] == 0) {
			cout << endl;
			cout << "     __   __                                                                                               ___________   ___________" << endl;
			cout << "    /  \\_/  \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |       |                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\  " << karty[karu[0][0]] << "   /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 1) {
			cout << endl;
			cout << "       / \\                                                                                                  ___________   ___________" << endl;
			cout << "      /   \\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /     \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    /  " << karty[karu[0][0]] << "   \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |   _   |                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\__/^\\__/                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       /_\\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 2) {
			cout << endl;
			cout << "        _                                                                                                   ___________   ___________" << endl;
			cout << "       ( )                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     __/ \\__                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    (__" << karty[karu[0][0]] << " __)                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       / \\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /___\\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 3) {
			cout << endl;
			cout << "        / \\                                                                                                 ___________   ___________" << endl;
			cout << "       /   \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /     \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /  " << karty[karu[0][0]] << "   \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\       /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
	}
	else {
		if (karu[1][0] == 0) {
			cout << endl;
			cout << "     __   __                                                                                               ___________   ___________" << endl;
			cout << "    /  \\_/  \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |       |                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\   " << karty[karu[0][0]] << "   /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 1) {
			cout << endl;
			cout << "       / \\                                                                                                  ___________   ___________" << endl;
			cout << "      /   \\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /     \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    /   " << karty[karu[0][0]] << "   \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    |   _   |                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    \\__/^\\__/                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       /_\\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 2) {
			cout << endl;
			cout << "        _                                                                                                   ___________   ___________" << endl;
			cout << "       ( )                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     __/ \\__                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "    (__ " << karty[karu[0][0]] << " __)                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\ /                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       / \\                                                                                                  |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /___\\                                                                                                 |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
		else if (karu[1][0] == 3) {
			cout << endl;
			cout << "        / \\                                                                                                 ___________   ___________" << endl;
			cout << "       /   \\                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      /     \\                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     /   " << karty[karu[0][0]] << "   \\                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "     \\       /                                                                                              |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "      \\     /                                                                                               |%%%%%%%%%|   |%%%%%%%%%|" << endl;
			cout << "       \\   /                                                                                                |%%%%%%%%%|   |%%%%%%%%%|" << endl;
		}
	}

	for (int i = 1; i < 5; i++) {
		if (karty[karu[0][i]] == "10") {
			if (i == 1) {


				if (karu[1][i] == 0) {
					cout << endl;
					cout << "     __   __                                        ++++++          " << endl;
					cout << "    /  \\_/  \\                                     ++      ++        " << endl;
					cout << "    |       |                                   ++          ++      " << endl;
					cout << "    \\   " << karty[karu[0][i]] << "  /                                   +    " << bank << " " << endl;
					cout << "     \\     /                                    ++          ++      " << endl;
					cout << "      \\   /                                       ++      ++        " << endl;
					cout << "       \\ /                                          ++++++          " << endl;
				}
				else if (karu[1][i] == 1) {
					cout << endl;
					cout << "       / \\                                           ++++++         " << endl;
					cout << "      /   \\                                        ++      ++       " << endl;
					cout << "     /     \\                                     ++          ++     " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\                                    +    " << bank << "" << endl;
					cout << "    |   _   |                                    ++          ++     " << endl;
					cout << "    \\__/^\\__/                                      ++      ++       " << endl;
					cout << "       /_\\                                           ++++++         " << endl;
				}
				else if (karu[1][i] == 2) {
					cout << endl;
					cout << "        _                                            ++++++         " << endl;
					cout << "       ( )                                         ++      ++       " << endl;
					cout << "     __/ \\__                                     ++          ++     " << endl;
					cout << "    (__" << karty[karu[0][i]] << " __)                                    +    " << bank << "" << endl;
					cout << "       \\ /                                       ++          ++     " << endl;
					cout << "       / \\                                         ++      ++       " << endl;
					cout << "      /___\\                                          ++++++         " << endl;
				}
				else if (karu[1][i] == 3) {
					cout << endl;
					cout << "       / \\                                           ++++++          " << endl;
					cout << "      /   \\                                        ++      ++        " << endl;
					cout << "     /     \\                                     ++          ++      " << endl;
					cout << "    /  " << karty[karu[0][i]] << "   \\                                    +    " << bank << " " << endl;
					cout << "    \\       /                                    ++          ++      " << endl;
					cout << "     \\     /                                       ++      ++        " << endl;
					cout << "      \\   /                                          ++++++          " << endl;
				}

			}
			else {

				if (karu[1][i] == 0) {
				cout << endl;
				cout << "     __   __                                   " << endl;
				cout << "    /  \\_/  \\                                " << endl;
				cout << "    |       |                                   " << endl;
				cout << "    \\   " << karty[karu[0][i]] << "  /         " << endl;
				cout << "     \\     /                                   " << endl;
				cout << "      \\   /                                    " << endl;
				cout << "       \\ /                                     " << endl;
			}
				else if (karu[1][i] == 1) {
				cout << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /   \\                                    " << endl;
				cout << "     /     \\                                   " << endl;
				cout << "    /  " << karty[karu[0][i]] << "   \\         " << endl;
				cout << "    |   _   |                                   " << endl;
				cout << "    \\__/^\\__/                                 " << endl;
				cout << "       /_\\                                     " << endl;
			}
				else if (karu[1][i] == 2) {
				cout << endl;
				cout << "        _                                       " << endl;
				cout << "       ( )                                      " << endl;
				cout << "     __/ \\__                                   " << endl;
				cout << "    (__" << karty[karu[0][i]] << " __)          " << endl;
				cout << "       \\ /                                     " << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /___\\                                    " << endl;
			}
				else if (karu[1][i] == 3) {
				cout << endl;
				cout << "       / \\                                    " << endl;
				cout << "      /   \\                                   " << endl;
				cout << "     /     \\                                  " << endl;
				cout << "    /  " << karty[karu[0][i]] << "   \\        " << endl;
				cout << "    \\       /                                 " << endl;
				cout << "     \\     /                                  " << endl;
				cout << "      \\   /                                   " << endl;
			}
			}
		}
		else {
			if (i == 1) {


				if (karu[1][i] == 0) {
					cout << endl;
					cout << "     __   __                                        ++++++          " << endl;
					cout << "    /  \\_/  \\                                     ++      ++        " << endl;
					cout << "    |       |                                   ++          ++      " << endl;
					cout << "    \\    " << karty[karu[0][i]] << "  /                                   +    " << bank << " " << endl;
					cout << "     \\     /                                    ++          ++      " << endl;
					cout << "      \\   /                                       ++      ++        " << endl;
					cout << "       \\ /                                          ++++++          " << endl;
				}
				else if (karu[1][i] == 1) {
					cout << endl;
					cout << "       / \\                                           ++++++         " << endl;
					cout << "      /   \\                                        ++      ++       " << endl;
					cout << "     /     \\                                     ++          ++     " << endl;
					cout << "    /   " << karty[karu[0][i]] << "   \\                                    +    " << bank << "" << endl;
					cout << "    |   _   |                                    ++          ++     " << endl;
					cout << "    \\__/^\\__/                                      ++      ++       " << endl;
					cout << "       /_\\                                           ++++++         " << endl;
				}
				else if (karu[1][i] == 2) {
					cout << endl;
					cout << "        _                                            ++++++         " << endl;
					cout << "       ( )                                         ++      ++       " << endl;
					cout << "     __/ \\__                                     ++          ++     " << endl;
					cout << "    (__ " << karty[karu[0][i]] << " __)                                    +    " << bank << "" << endl;
					cout << "       \\ /                                       ++          ++     " << endl;
					cout << "       / \\                                         ++      ++       " << endl;
					cout << "      /___\\                                          ++++++         " << endl;
				}
				else if (karu[1][i] == 3) {
					cout << endl;
					cout << "       / \\                                           ++++++          " << endl;
					cout << "      /   \\                                        ++      ++        " << endl;
					cout << "     /     \\                                     ++          ++      " << endl;
					cout << "    /   " << karty[karu[0][i]] << "   \\                                    +    " << bank << " " << endl;
					cout << "    \\       /                                    ++          ++      " << endl;
					cout << "     \\     /                                       ++      ++        " << endl;
					cout << "      \\   /                                          ++++++          " << endl;
				}

			}
			//перевірка де виводити банк
			else {
				if (karu[1][i] == 0) {
				cout << endl;
				cout << "     __   __                                   " << endl;
				cout << "    /  \\_/  \\                                " << endl;
				cout << "    |       |                                   " << endl;
				cout << "    \\   " << karty[karu[0][i]] << "   /        " << endl;
				cout << "     \\     /                                   " << endl;
				cout << "      \\   /                                    " << endl;
				cout << "       \\ /                                     " << endl;
			}
				else if (karu[1][i] == 1) {
				cout << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /   \\                                    " << endl;
				cout << "     /     \\                                   " << endl;
				cout << "    /   " << karty[karu[0][i]] << "   \\        " << endl;
				cout << "    |   _   |                                   " << endl;
				cout << "    \\__/^\\__/                                 " << endl;
				cout << "       /_\\                                     " << endl;
			}
				else if (karu[1][i] == 2) {
				cout << endl;
				cout << "        _                                        " << endl;
				cout << "       ( )                                       " << endl;
				cout << "     __/ \\__                                    " << endl;
				cout << "    (__ " << karty[karu[0][i]] << " __)          " << endl;
				cout << "       \\ /                                      " << endl;
				cout << "       / \\                                      " << endl;
				cout << "      /___\\                                     " << endl;
			}
				else if (karu[1][i] == 3) {
				cout << endl;
				cout << "       / \\                                     " << endl;
				cout << "      /   \\                                    " << endl;
				cout << "     /     \\                                   " << endl;
				cout << "    /   " << karty[karu[0][i]] << "   \\        " << endl;
				cout << "    \\       /                                  " << endl;
				cout << "     \\     /                                   " << endl;
				cout << "      \\   /                                    " << endl;
			}
			}
		}
	}
}
int scan_combination(int kart[][5], int s1, int r1, int karu[][2], int s2, int r2) {
	int power,i,j, povtor_mast, max_m = 0, per_str, k, mas_flesh[5], bulca_i, bulca_j;
	bool zn, strit_flesh = true;
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
				}
			}
			
		}
		
		//перевірка на стріт
	}
	//перевірка на стріт,флеш,стріт-флеш
	if (strit_flesh==false) {
		power=mas_flesh[0] + 60;
	}
	else if (povtor1 == 6) {
			power = max + 55;
	 }
	else if (povtor1 == 4) {
			power = max + 46;
	}
	else if (povtor_mast >= 5) {
		 power = max_m + 37;
	 }
	else if (per_str == 4) {
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
