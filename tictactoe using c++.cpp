#include<iostream>				
#include<iomanip>				// for setw() function
#include<Windows.h>				// for coloring and x,y coordinates for consol

using namespace std;			//declaration of cout<</cin>>
HANDLE hConsole;

//---------- X,Y Co-Ordinates Function ---------------//
void gotoxy(int x, int y) { 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

///***************Global Variables***************///
int startgame;
int isdraw;
int position;
char name1[20];
char name2[20];
bool isgame = true;
char box[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
///*********************************************///



///*************Function Declaration**************///
void initialized();
void giveinput();
void printboard();
void updateinput();
void checkwin();
void checkdraw();
void welcomescreen();
void instruction();
///**********************************************///

int main() {
	isdraw = 0;
	welcomescreen();
	system("cls");				//for clear screen
//	instruction();
//	Sleep(10000);				//next screen start in 10 sec automatically
	system("cls");
	initialized();
	system("cls");
	printboard();
	while (isgame == true) {
		giveinput();
		isdraw++;
		if(isdraw == 13) {
			cout<<"\nMatch Is Draw: \n";
			break;
		}
		else {
		 	checkwin();
			updateinput();
			isdraw++;
			checkwin();
			isdraw++;
			
			if(isdraw == 13) {
				cout<<"\nMatch Is Draw: \n";
				isgame = false;
				}
		}
		

	}
	system("pause");
	return 0;
}
void welcomescreen() {
	HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            system("cls");
            SetConsoleTextAttribute(hConsole, 480);        //Yellow Color Code=480
            gotoxy(23,0);
            cout<<"   Indus University (FEST)   \n"; 
            cout<<"\n";
            SetConsoleTextAttribute(hConsole, 47);     //Green & White Color Code=47
            gotoxy(19,2);
            cout<<"      A Tic Tac Toe Game using C++      "; 
            SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
            for (int i=6; i<18; i++) {
                gotoxy(43,i);
                cout<<'\xB3';
            }
            gotoxy(28,3);
            SetConsoleTextAttribute(hConsole, 27);             //Blue Color Code=27
            cout<<"  Semester Project  ";
            SetConsoleTextAttribute(hConsole, 12);           //Red Color Code=12
            gotoxy(1,7);
            cout<<"Submitted By: ";
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(46,8);
            cout<<"Submitted To: ";
            SetConsoleTextAttribute(hConsole, 11);          //Light Blue Color Code=11
            gotoxy(48,10);
            cout<<"Ms. Saima Sipy";
            SetConsoleTextAttribute(hConsole, 15);              //White Color Code=15
            gotoxy(1,10);
            cout<<"(Group Leader)";
            SetConsoleTextAttribute(hConsole, 3);           //Dark Blue-Green Color Code=3
            gotoxy(16,10);
            cout<<"Aminullah Taj Muhammad";
            SetConsoleTextAttribute(hConsole, 6);            //Dark Yellow Color Code=6
            gotoxy(38,8);
            SetConsoleTextAttribute(hConsole, 15);            //White Color Code=15
            gotoxy(47,8);
            SetConsoleTextAttribute(hConsole, 3);              //Dark Blue Color Code=3
            gotoxy(16,12);
            cout<<"Asad Ali Tagar";
            SetConsoleTextAttribute(hConsole, 6);            //Dark Yellow Color Code=6
            gotoxy(38,10);
            SetConsoleTextAttribute(hConsole, 3);              //Dark Blue Color Code=3
            gotoxy(16,14);
            cout<<"Zeeshan Anwar";
            SetConsoleTextAttribute(hConsole, 3);              //Dark Blue Color Code=3
            gotoxy(16,16);
            cout<<"Syed Abrar Rizvi";
            
            
			SetConsoleTextAttribute(hConsole, 8);            //Dark Yellow Color Code=8
            for (int i=0; i<79; i++) {
                gotoxy(i,18);
                cout<< char(196);
            }
            SetConsoleTextAttribute(hConsole, 8);            //Dark Yellow Color Code=8
            for (int i=0; i<79; i++) {
                gotoxy(i,6);
                cout<<char(196);
            }
           	SetConsoleTextAttribute(hConsole, 7);             //Light White Color Code=7
            gotoxy(1,20);
            cout<<"Press Any Number to Play: ";
            cin>>startgame;
}
void instruction() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(19,1);
	SetConsoleTextAttribute(hConsole, 480);
	cout<<"Game Instructure"<<endl;
	gotoxy(15,4);
	SetConsoleTextAttribute(hConsole, 10);
	cout << setw(4) << "1" << "\t|" << setw(4) << "2" << "\t|" << setw(4) << "3" << endl;
	gotoxy(15,5);
	cout << " ------------------------" << endl;
	gotoxy(15,6);
	cout << setw(4) << "4" << "\t|" << setw(4) << "5" << "\t|" << setw(4) << "6" << endl;
	gotoxy(15,7);
	cout << " ------------------------" << endl;
	gotoxy(15,8);
	cout << setw(4) << "7" << "\t|" << setw(4) << "8" << "\t|" << setw(4) << "9" << endl;
		SetConsoleTextAttribute(hConsole, 11);
}
void initialized(){
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Enter First Player Name: ";
	cin >> name1;
	cout << "Enter Secong Player Name: ";
	cin >> name2;
}
void printboard() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	gotoxy(10,2);
	cout << setw(4) << box[1] << "\t|" << setw(4) << box[2] << "\t|" << setw(4) << box[3];
	gotoxy(6,3);
	cout << " ----------------------------";
	gotoxy(10,4);
	cout << setw(4) << box[4] << "\t|" << setw(4) << box[5] << "\t|" << setw(4) << box[6];
	gotoxy(6,5);
	cout << " ----------------------------";
	gotoxy(10,6);
	cout << setw(4) << box[7] << "\t|" << setw(4) << box[8] << "\t|" << setw(4) << box[9];
	SetConsoleTextAttribute(hConsole, 7);
}
void giveinput() {
	xyz:
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(1,8);
	cout << "X player turn:";
	gotoxy(1,9);
	cout << "Enter Position in numbers: ";
	cin >> position;
	if (position == 1) {
		if (box[1] == ' ') {
			box[1] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 8);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	else if (position == 2) {
		if (box[2] == ' ') {
			box[2] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 7);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	else if (position == 3) {
		if (box[3] == ' ') {
			box[3] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 9);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	if (position == 4) {
		if (box[4] == ' ') {
			box[4] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 10);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	if (position == 5) {
		if (box[5] == ' ') {
			box[5] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 11);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	if (position == 6) {
		if (box[6] == ' ') {
			box[6] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 12);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	if (position == 7) {
		if (box[7] == ' ') {
			box[7] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 13);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	if (position == 8) {
		if (box[8] == ' ') {
			box[8] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 14);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	if (position == 9) {
		if (box[9] == ' ') {
			box[9] = 'X';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 15);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto xyz;
		}
	}
	printboard();
}



void updateinput() {
abc:
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(1,12);
	cout << "O player turn: ";
	gotoxy(1,13);
	cout << "Enter Position in numbers: ";
	cin >> position;
	if (position == 1) {
		if (box[1] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[1] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 7);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	else if (position == 2) {
		if (box[2] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[2] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 8);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	else if (position == 3) {
		if (box[3] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[3] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 9);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	if (position == 4) {
		if (box[4] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[4] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 10);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	if (position == 5) {
		if (box[5] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[5] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 11);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	if (position == 6) {
		if (box[6] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[6] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 12);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	if (position == 7) {
		if (box[7] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[7] = 'O';		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 13);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	if (position == 8) {
		if (box[8] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[8] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 14);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	if (position == 9) {
		if (box[9] == ' ') {
			SetConsoleTextAttribute(hConsole, 10);
			box[9] = 'O';
		}
		else {
			gotoxy(1, 18);
			SetConsoleTextAttribute(hConsole, 15);
			cout << "This position is filled enter empty position: \n\n";
			SetConsoleTextAttribute(hConsole, 15);
			goto abc;
		}
	}
	SetConsoleTextAttribute(hConsole, 7);
	printboard();
}
void checkwin() {
	if (box[1] == 'X' && box[2] == 'X' && box[3] == 'X' || box[4] == 'X' && box[5] == 'X' && box[6] == 'X' ||
		box[7] == 'X' && box[8] == 'X' && box[9] == 'X' || box[1] == 'X' && box[4] == 'X' && box[7] == 'X' ||
		box[2] == 'X' && box[5] == 'X' && box[8] == 'X' || box[3] == 'X' && box[6] == 'X' && box[9] == 'X' ||
		box[1] == 'X' && box[5] == 'X' && box[9] == 'X' || box[3] == 'X' && box[5] == 'X' && box[7] == 'X') {
		
		gotoxy(1, 20);
		cout << "X player Wins Means " << name1 << " Wins: " << endl;
		isgame = false;
		exit(1);
		}

	else if(box[1] == 'O' && box[2] == 'O' && box[3] == 'O' || box[4] == 'O' && box[5] == 'O' && box[6] == 'O' ||
			box[7] == 'O' && box[8] == 'O' && box[9] == 'O' || box[1] == 'O' && box[4] == 'O' && box[7] == 'O' ||
			box[2] == 'O' && box[5] == 'O' && box[8] == 'O' || box[3] == 'O' && box[6] == 'O' && box[9] == 'O' ||
			box[1] == 'O' && box[5] == 'O' && box[9] == 'O' || box[3] == 'O' && box[5] == 'O' && box[7] == 'O') {
			gotoxy(1, 20);
			cout << "O player Wins Means " << name2 << " Wins: " << endl;
			isgame = false;
		}
}
