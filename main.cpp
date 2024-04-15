#include <iostream>
#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"

int main() {
    GameModel model;
    GameView view;
    GameController controller(model, view);

    controller.launch();

    return 0;
}
