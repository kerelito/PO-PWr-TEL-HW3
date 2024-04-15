#include "GameModel.h"

GameModel::GameModel() : points(0), level(1) {}

void GameModel::addPoint() {
    points++;
}

void GameModel::setPoints(int newPoints) {
    points = newPoints;
}

int GameModel::getPoints() const {
    return points;
}

void GameModel::setLevel(int newLevel) {
    level = newLevel;
}

int GameModel::getLevel() const {
    return level;
}

bool GameModel::nextLevel() const {
    return (points % 5 == 0);
}

void GameModel::saveGame(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        file << points << endl;
        file << level << endl;
        file.close();
    } else {
        cout << "Nie udalo sie zapisac stanu gry do pliku.\n";
    }
}

bool GameModel::loadGame(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        int loadedPoints, loadedLevel;
        file >> loadedPoints >> loadedLevel;
        setPoints(loadedPoints);
        setLevel(loadedLevel);
        file.close();
        return true;
    } else {
        return false;
    }
}
