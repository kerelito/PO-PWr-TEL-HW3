#include "GameView.h"
#include "Utils.h" // Dodajemy dołączenie pliku nagłówkowego Utils.h
#include <iostream>
using namespace std;

void GameView::printStartHeader() {
    cout << "Program typu kliker!" << endl;
    cout << "Uzytkowniku, aby naliczac kolejne punkty nalezy podac do wejscia litere 'b'." << endl;
    cout << "Punkty oraz poziomy beda naliczane automatycznie." << endl;
    cout << "Aby zakonczyc dzialanie programu nalezy wcisnac 'e'." << endl;
    cout << "W kazdym momencie trwania programu można zapis progres - 's', bądź go wczytać - 'l'" << endl;
    cout << "Milego klikania!.\n" << endl;
}

void GameView::printData(int points, int level) {
    cout << "Level: " << Utils::convertToRoman(level) << endl; // Wywołujemy funkcję convertToRoman z Utils
    cout << "Points: " << points << endl;
}

char GameView::getUserInput() {
    char input;
    cin >> input;
    return input;
}
