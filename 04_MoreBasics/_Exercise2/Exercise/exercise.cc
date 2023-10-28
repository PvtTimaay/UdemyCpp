#include <iostream>

#include "exercise.h"


void PlayerData::PlayerPos(float xin, float yon)
{
    x_pos = xin;
    y_pos = yon;
    std::cout << "Current position is: " << std::endl << "x " << x_pos << std::endl;
    std::cout << "y " << y_pos << std::endl << std::endl;
};

void PlayerData::printReg()
{
    std::cout << "Player Information: " << this << std::endl;
    std::cout << id << std::endl;
    std::cout << x_pos << std::endl;
    std::cout << y_pos << std::endl;
    std::cout << health << std::endl;
    std::cout << energy << std::endl;
    // std::cout << alliance << std::endl;
}
