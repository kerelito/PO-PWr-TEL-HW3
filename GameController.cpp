#include "GameController.h"
#include <iostream>
#include <fstream>
using namespace std;

GameController::GameController(GameModel& model, GameView& view) : model(model), view(view) {}

void GameController::launch() {
    GameView::printStartHeader();
    char input;
    cout << "Czy chcesz wczytac stan gry z pliku? (T/N): ";
    cin >> input;
    if (toupper(input) == 'T') {
        cout << "Podaj nazwe pliku do wczytania: ";
        string filename;
        cin >> filename;
        if (!model.loadGame(filename)) {
            cout << "Nie udalo sie wczytac stanu gry z pliku.\n";
        }
    } else {
        cout << "Nowa gra rozpoczeta.\n";
    }

    while (true) {
        view.printData(model.getPoints(), model.getLevel());
        input = GameView::getUserInput();
        const char addPointCondition = 'b';
        const char exitCondition = 'e';
        const char saveCondition = 's';
        const char loadCondition = 'l';
        if (input == addPointCondition) {
            model.addPoint();
            if (model.nextLevel()) {
                model.setLevel(model.getLevel() + 1);
            }
        } else if (input == exitCondition) {
            cout << "Program zakonczony.\n";
            break;
        } else if (input == saveCondition) {
            cout << "Podaj nazwe pliku do zapisu: ";
            string filename;
            cin >> filename;
            model.saveGame(filename);
            cout << "Stan gry zapisany.\n";
        } else if (input == loadCondition) {
            cout << "Podaj nazwe pliku do wczytania: ";
            string filename;
            cin >> filename;
            if (model.loadGame(filename)) {
                cout << "Stan gry wczytany.\n";
            } else {
                cout << "Nie udalo sie wczytac stanu gry z pliku.\n";
            }
        } else {
            cout << "Wprowadzono nieobslugiwane wejscie. Akceptowane pola wyboru to 'b', 'e', 's' oraz 'l'.\n";
        }
    }
}
