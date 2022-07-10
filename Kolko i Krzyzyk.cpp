#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void rysuj_plansze(char tab[3][3]) {
	for (int i = 0; i <= 2; i++){
		cout << "\t " << tab[i][0] << "|" << tab[i][1] << "|" << tab[i][2] << endl;
		if(i<2)cout << "\t-------" << endl;
	}
}

void fullfill(char tab[3][3]) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			tab[i][j] = (char)' ';
		}
	}
}

void wpisz_miejsce(char tab[3][3]) {
	int x, y;
	int w = 0;
	while (w==0) {
	cout << "Gdzie chcesz umiescic X?\nPodaj kolumne (pionowo)\n";
	cin >> x;
	cout << "Teraz podaj szereg (poziomo)\n";
	cin >> y;
	x = x - 1;
	y = y - 1;
	if (tab[y][x] == 'O' or tab[y][x] == 'X') {
		cout << "Nie mozesz tu postawic X\n";
	}
	else {
		tab[y][x] = 'X';
			w = 1;
	}
	}
}

void ruch_komputera(char tab[3][3]) {
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

bool sprawdz_wygranaX(char tab[3][3]) {//sprawdzamy wygraną jest 8 możliwości wygranej
	bool win=false;
	if (tab[0][0] == 'X' && tab[0][1] == 'X' && tab[0][2] == 'X')  win = true;  //szereg pierwszy
	if (tab[1][0] == 'X' && tab[1][1] == 'X' && tab[1][2] == 'X')  win = true;  //szereg drugi
	if (tab[2][0] == 'X' && tab[2][1] == 'X' && tab[2][2] == 'X')  win = true;  //szereg trzeci
	if (tab[0][0] == 'X' && tab[1][0] == 'X' && tab[2][0] == 'X')  win = true;  //kolumna pierwsza
	if (tab[0][1] == 'X' && tab[1][1] == 'X' && tab[2][1] == 'X')  win = true;  //kolmuna druga
	if (tab[0][2] == 'X' && tab[1][2] == 'X' && tab[2][2] == 'X')  win = true;  //kolumna trzecia
	if (tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X')  win = true;  //skos pierwszy
	if (tab[0][2] == 'X' && tab[1][1] == 'X' && tab[2][0] == 'X')  win = true;  //skos drugi
	if (win == true) {
		return win = true;
	}
	else {
		return win = false;
	}
}

bool sprawdz_wygranaO(char tab[3][3]) {//sprawdzamy wygraną jest 8 możliwości wygranej
	bool win = false;
	if (tab[0][0] == 'O' && tab[0][1] == 'O' && tab[0][2] == 'O')  win = true;  //szereg pierwszy
	if (tab[1][0] == 'O' && tab[1][1] == 'O' && tab[1][2] == 'O')  win = true;  //szereg drugi
	if (tab[2][0] == 'O' && tab[2][1] == 'O' && tab[2][2] == 'O')  win = true;  //szereg trzeci
	if (tab[0][0] == 'O' && tab[1][0] == 'O' && tab[2][0] == 'O')  win = true;  //kolumna pierwsza
	if (tab[0][1] == 'O' && tab[1][1] == 'O' && tab[2][1] == 'O')  win = true;  //kolmuna druga
	if (tab[0][2] == 'O' && tab[1][2] == 'O' && tab[2][2] == 'O')  win = true;  //kolumna trzecia
	if (tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O')  win = true;  //skos pierwszy
	if (tab[0][2] == 'O' && tab[1][1] == 'O' && tab[2][0] == 'O')  win = true;  //skos drugi
	if (win == true) {
		return win = true;
	}
	else {
		return win = false;
	}
}

int main()
{
	srand(time(NULL));
	cout << "\t=== Witaj w grze w kolko i krzyzyk ===" << endl;
	cout << "Aby rozpoczac gre nacisnij przycisk...";
	getchar();
	bool win = false;
	bool lose = false;
	bool draw = false;
	int i = 0;
	char pole[3][3];
	fullfill(pole);
	while (win == false && lose == false && draw == false) {
		system("cls");
		rysuj_plansze(pole);
		wpisz_miejsce(pole);
		win = sprawdz_wygranaX(pole);
		ruch_komputera(pole);
		lose = sprawdz_wygranaO(pole);
		i++;
		if (i >= 5) {
			draw = true;
		}
	}
	system("cls");
	if (win == true) {
		cout << "Brawo Wygrana!!!\n";
	}
	else if (lose == true) {
		cout << "Niestety Przegrana.\n";
	}
	else if (draw == true) {
		cout << "Remis.\n";
	}
	rysuj_plansze(pole);
}
