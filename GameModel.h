#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class GameModel {
private:
    int points;
    int level;

public:
    GameModel();

    void addPoint();
    void setPoints(int newPoints);
    int getPoints() const;
    void setLevel(int newLevel);
    int getLevel() const;
    bool nextLevel() const;
    void saveGame(const string& filename) const;
    bool loadGame(const string& filename);
};

#endif
