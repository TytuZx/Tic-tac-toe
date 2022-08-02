#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void draw_board(char tab[3][3]) { //Drawing a board and chars in game.
	for (int i = 0; i <= 2; i++){
		cout << "\t " << tab[i][0] << "|" << tab[i][1] << "|" << tab[i][2] << endl;
		if(i<2)cout << "\t-------" << endl;
	}
}

void fullfill(char tab[3][3]) { //Fullfilling array
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			tab[i][j] = (char)' ';
		}
	}
}

void player_move(char tab[3][3]) { //Player move. Choosing where to place X.
	int x, y;
	int w = 0;
	while (w==0) {
	cout << "Where you want to place X?\nSpecify column (vertical)\n";
	cin >> x;
	cout << "Now specify row (horizontal)\n";
	cin >> y;
	x = x - 1;
	y = y - 1;
	if (tab[y][x] == 'O' or tab[y][x] == 'X') {
		cout << "Can't place X here\n";
	}
	else {
		tab[y][x] = 'X';
			w = 1;
	}
	}
}

void Computer_move(char tab[3][3]) { //Computer move. Randomly placing O.
	int x, y;
	int w = 0;
	while (w < 100) {
		x = (rand() % 3) + 0;
		y = (rand() % 3) + 0;
	if (tab[y][x] == 'O' or tab[y][x] == 'X') {
		w++;
	}
	else {
		tab[y][x] = 'O';
			w = 100;
	}
}
}

bool check_win_X(char tab[3][3]) {//Checking Win for X
	bool win=false;
	if (tab[0][0] == 'X' && tab[0][1] == 'X' && tab[0][2] == 'X')  win = true;  //first row
	if (tab[1][0] == 'X' && tab[1][1] == 'X' && tab[1][2] == 'X')  win = true;  //second row
	if (tab[2][0] == 'X' && tab[2][1] == 'X' && tab[2][2] == 'X')  win = true;  //third row
	if (tab[0][0] == 'X' && tab[1][0] == 'X' && tab[2][0] == 'X')  win = true;  //first column
	if (tab[0][1] == 'X' && tab[1][1] == 'X' && tab[2][1] == 'X')  win = true;  //second column
	if (tab[0][2] == 'X' && tab[1][2] == 'X' && tab[2][2] == 'X')  win = true;  //third column
	if (tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X')  win = true;  //first cross
	if (tab[0][2] == 'X' && tab[1][1] == 'X' && tab[2][0] == 'X')  win = true;  //second cross
	if (win == true) {
		return win = true;
	}
	else {
		return win = false;
	}
}

bool check_win_O(char tab[3][3]) { //Checking Win for O
	bool win = false;
	if (tab[0][0] == 'O' && tab[0][1] == 'O' && tab[0][2] == 'O')  win = true;  //first row
	if (tab[1][0] == 'O' && tab[1][1] == 'O' && tab[1][2] == 'O')  win = true;  //second row
	if (tab[2][0] == 'O' && tab[2][1] == 'O' && tab[2][2] == 'O')  win = true;  //third row
	if (tab[0][0] == 'O' && tab[1][0] == 'O' && tab[2][0] == 'O')  win = true;  //first column
	if (tab[0][1] == 'O' && tab[1][1] == 'O' && tab[2][1] == 'O')  win = true;  //second column
	if (tab[0][2] == 'O' && tab[1][2] == 'O' && tab[2][2] == 'O')  win = true;  //third column
	if (tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O')  win = true;  //first cross
	if (tab[0][2] == 'O' && tab[1][1] == 'O' && tab[2][0] == 'O')  win = true;  //second cross
	if (win == true) {
		return win = true;
	}
	else {
		return win = false;
	}
}

int main()  //main program
{
	srand(time(NULL));
	cout << "\t=== Welcome to tic-tac-toe ===" << endl; //welcoming
	cout << "Press any key to begin";
	getchar();
	bool win = false;
	bool lose = false;
	bool draw = false;
	int i = 0;
	char field[3][3];
	fullfill(field);
	while (win == false && lose == false && draw == false) { //loop for the game.
		system("cls"); //clearing screen
		draw_board(field);
		player_move(field);
		win = check_win_X(field);
		Computer_move(field);
		lose = check_win_O(field);
		i++;
		if (i >= 5) { //condition to check draw
			draw = true;
		}
	}
	system("cls");
	if (win == true) {
		cout << "Congratulations!!! You win!!!\n";
	}
	else if (lose == true) {
		cout << "Unfortunately you lose. Better luck next time.\n";
	}
	else if (draw == true) {
		cout << "Draw.\n";
	}
	draw_board(field);
}
