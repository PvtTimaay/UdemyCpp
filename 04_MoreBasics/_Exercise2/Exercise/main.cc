#include <iostream>

#include "exercise.h"

int main()
{

    PlayerData Arnold{.id = 105,
                      .x_pos = 33.34,
                      .y_pos = 45.44,
                      .health = 100,
                      .energy = 80,
                      .alliance = Alliance::ALLIED};
    PlayerData Heinz{.id = 1051,
                     .x_pos = 24.21,
                     .y_pos = 54.12,
                     .health = 100,
                     .energy = 88,
                     .alliance = Alliance::ENEMY};
    ;

    Arnold.printReg();
    Heinz.printReg();

    return 0;
}
