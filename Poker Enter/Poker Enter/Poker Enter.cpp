
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int  welcome();
void main() {
	
	//system("mode con cols=190 lines=40");
	system("color 17");Sleep(3000);
	setlocale(LC_CTYPE, "ukr");
	//system("start poker.exe");
	welcome();
}

 int welcome() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tLOAT:██"; for (int i = 0; i < 26; i++) {
		Sleep(50);
		cout << " ██";
	}
	cout << "\n\n\t\t\t\t\t";Sleep(100);cout<< " ██	  ▄▄      ▄▄ ▄▄▄▄▄▄▄▄  ▄▄           ▄▄▄▄     ▄▄▄▄    ▄▄▄  ▄▄▄  ▄▄▄▄▄▄▄▄  ██ " << endl;
	cout << "\t\t\t\t\t";Sleep(100); cout << " ██	  ██      ██ ██▀▀▀▀▀▀  ██         ██▀▀▀▀█   ██▀▀██   ███  ███  ██▀▀▀▀▀▀  ██ " << endl;
	cout << "\t\t\t\t\t";Sleep(100); cout << " ██	  ▀█▄ ██ ▄█▀ ██        ██        ██▀       ██    ██  ████████  ██        ██ " << endl;
	cout << "\t\t\t\t\t";Sleep(100); cout << " ██	   ██ ██ ██  ███████   ██        ██        ██    ██  ██ ██ ██  ███████   ██ " << endl;
	cout << "\t\t\t\t\t";Sleep(100); cout << " ██	   ███▀▀███  ██        ██        ██▄       ██    ██  ██ ▀▀ ██  ██        ██ " << endl;
	cout << "\t\t\t\t\t";Sleep(100); cout << " ██        ███  ███  ██▄▄▄▄▄▄  ██▄▄▄▄▄▄   ██▄▄▄▄█   ██▄▄██   ██    ██  ██▄▄▄▄▄▄  ██ " << endl;
	cout << "\t\t\t\t\t";Sleep(100); cout << " ██        ▀▀▀  ▀▀▀  ▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀     ▀▀▀▀     ▀▀▀▀    ▀▀    ▀▀  ▀▀▀▀▀▀▀▀  ██ " << endl;
	cout << "\n\t\t\t\t\tLOAT:";
	for (int i = 0; i < 26; i++) {
		Sleep(50);
		cout << " ██";
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;


	
	Sleep(2000);
	bool ex=true;
	for (;;) {
		cout << "Select:";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t PLAY(0)" << endl;
		cout << "\t\t\t\t " << endl;
		cout << "\t\t\t\t RULES(1)" << endl;
		cout << "\t\t\t\t" << endl;
		cout << "\t\t\t\t DEVELOPERS(2)" << endl;
		cout << "\t\t\t\t" << endl;
		cout << "\t\t\t\t EXIT(3)" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nMake Your Choice" << endl;
		int choise;



		cin >> choise;

		switch (choise)
		{
		case 0:system("start poker.exe");
			return 0;

			break;
		case 1:
		{
			cout << "How Do You Win? \n" <<
				" Typically, the winner of each hand of poker is the player that holds the highest ranked hand when all cards are shown at the end of the hand –known as the ‘showdown’ – or the player that makes the last uncalled bet, thus winning without needing to reach a showdow\n" <<
				"\nNot sure whether a flush beats a straight ? Can’t remember how to make a full house ? You can find all the information you need to know about hand rankings in the table below(click here for more).The strongest hands are in the top row, running from left to right, with the weakest possible hand being simply a high card.\n" <<

				"1)Royal Flush" << endl <<

				"2)Royal FlushStraight Flush" << endl <<

				"3)Straight FlushFour of a Kind" << endl <<

				"4)Four of a KindFull House" << endl <<

				"5)Full House								" << endl <<

				"6)Flush									" << endl <<

				"7)FlushStraight							" << endl <<

				"8)StraightThree of a Kind					" << endl <<

				"9)Three of a KindTwo Pair					" << endl <<

				"10)Two Pair								" << endl <<

				"11)One Pair								" << endl <<

				"12)One PairHigh Card						" << endl <<

				"13)High Card								" << endl <<

				"Getting Started																																																																																						  " << endl <<
				"Poker games typically feature a forced bet, such as the Big Blindand Small Blind in Hold’emand Omaha or the Antes and Bring -"
				"\n In in Stud.These forced bets comprise the starting pot in any given hand of poker, which is the first incentive players have to win the hand.Action arising\n"
				"from the subsequent rounds of betting further increases the size of the pot." << endl <<

				"Dealing Cardsand Betting Rounds																																																																																		  " << endl <<
				"After any initial cards are dealt, players are usually called upon to act in turn, moving clockwise around the table.																																																													  " << endl <<

				"Each player can usually take one of the following actions when it is their turn to act :                                                                                                                                                                                                                                                                                " << endl <<

				"Check – To check is to decline the opportunity to open the betting.Players can only check when there is no bet during the current round, and the act of\n"
				"checking passes the action clockwise to the next person in the hand.If all active players check, those players remain in the handand the round is considered \n"
				"complete.																																																																																												" << endl <<
				"Bet – Players may bet if no other players have bet during the current round.Once a bet has been made, other players must ‘call’ by matching the amount bet, in order to remain in the hand.																																															" << endl <<
				"Fold – Players who fold forfeit their cardsand cannot win or act again during the current hand.																																																																						" << endl <<
				"Call – Players can call if other players have bet during the current round; this requires the calling player to match the highest bet made.																																																											" << endl <<
				"Raise – Players may raise if other players have bet during the current round; this requires the raising player to match the highest bet made, and then make a greater one.All subsequent players\n are required to call the raise or raise again(‘re - raise’) to stay in the hand.																									" << endl <<
				"Different variants of poker have different betting rounds, for example, most Stud games feature five rounds of betting, while 5 - card draw usually only has two.Texas Hold’em and Omaha are the\n two most popular poker games in the world and have identical betting structures, with four rounds of betting known as pre - flop, the flop, the turn and the river.				" << endl <<

				"The pre - flop betting round begins as soon as all players have received their hole cards, before any community cards have been dealt; betting on the flop occurs after the first three community\n cards are dealt; on the turn after the fourth community card; and on the river after the fifth and final community card.															" << endl <<

				"On each betting round, betting continues until every player has either matched the bets made or folded(if no bets are made, the round is complete when every player has checked).When the betting\n round is completed, the next dealing / betting round begins, or the hand is complete.																								" << endl <<

				"Here’s an example of a Texas Hold’em hand after all the cards have been dealt.As you can see, players may use any of their two hole cards with any of the five community cards to make the best five\n - card hand they can make - in this case, you can use both your hole cards and three of the shared community cards to make a straight.											" << endl <<

				"Table														" << endl <<
				"Your opponents’ hole cards								" << endl <<
				"Community Cards											" << endl <<
				"Your hole cards											" << endl <<
				"Showdown													" << endl <<
				"Once the last bet or raise has been called during the final round of betting, a showdown occurs; the remaining active players must show or ‘declare’ their hands, and the player(s) with the best ranking\n hand(s) win the pot.																																						" << endl <<

				"Players often show their hands in order, rather than all at the same time.Multiple players can share a single pot, with the pot divided in different ways depending on the game rules and how each player’s\n hand ranks against their opponents.																																		" << endl <<

				"Betting Limits																																																																																										" << endl <<
				"Betting limits refer to the amount players may open and raise.Typically, poker games are of the following types; no limit, pot limit or fixed limit.																																																									" << endl <<

				"No Limit – in poker games with a no limit betting structure, each player can bet or raise by any amount up to and including their full stack(the total number of chips they possess at any given time) in any\n betting round, whenever it is their turn to act.																														" << endl <<
				"Pot Limit – in poker games with a pot limit betting structure, each player can bet or raise by any amount up to and including the size of the total pot at that time.																																																					" << endl <<
				"Fixed Limit – in poker games with a fixed limit betting structure, each player can choose to call, bet or raise, but only by a fixed amount.The fixed amount for any given betting round is set in advance.																																											" << endl <<
				"For No Limit and Pot Limit games, the ‘Stakes’ column in the PokerStars lobby indicates the Small Blind and Big Blind in that game, while for Mixed Games like HORSE, the Stakes listed in the lobby are the \nbetting amounts for Limit games; in Pot Limit and No Limit rounds, the blinds are usually half of the blinds in limit games.											" << endl <<

				"Table Stakes and All - in																																																																																								" << endl <<
				"You may have seen a poker scene in a movie or on TV where a player is faced with a bet for more chips than they have at the table, and is forced to wager a watch, a car or some other possession in order to\n stay in the hand.This may make for good drama, but it is not generally the way poker is played in real life!															" << endl <<

				"All games on our site are played ‘table stakes’, meaning only the chips in play at the beginning of each hand can be used during the hand.The table stakes rule has an application called the ‘All - In’ rule,\n which states that a player cannot be forced to forfeit a poker hand because the player does not have enough chips to call a bet.										" << endl <<

				"A player who does not have enough chips to call a bet is declared All - In.The player is eligible for the portion of the pot up to the point of his final wager.All further action involving other players takes \nplace in a ‘side pot’, which the All - In player is not eligible to win.If more than one player goes All - In during a hand, there could be more than one side pot." << endl <<

				"Looking for more ? Check out PokerStars School, where players of all abilities can practice, learn and improve using a wealth of free resources." << endl <<

				"Now you’ve got the rules, what’s stopping you ? Download and play!																			  " << endl <<

				"If you need further help in learning poker basics for all our poker games, please do not hesitate to contact Support." << endl;

		}
			cout << "\n\n\npress any key to continue...";
			_getch();
			break;
		case 2:
			cout << "Develooers:";
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "\t\t\t\t " << endl;
			cout << "\t\t\t\tDeveloper: Maryniak Bogdan" << endl;
			cout << "\t\t\t\t******************************" << endl;
			cout << "\t\t\t\t" << endl;
			cout << "\t\t\t\tDesigner:  Kateruna Mukhailuk" << endl;
			cout << "\t\t\t\t******************************" << endl;
			cout << "\t\t\t\t" << endl;
			cout << "\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n press any key to continue...\n\n\nMake Your Choice" << endl;_getch();
			break;
		case 3:
			return 0;

		default:
			cout << "Error,Please repeat\n";
			Sleep(2000);
			
			break;
		}

	}
	
}