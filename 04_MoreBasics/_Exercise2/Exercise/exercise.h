#pragma once
#include <iostream>


enum class Alliance
{

    ALLIED,
    ENEMY,
};

struct PlayerData
{

    uint32_t id = 0;
    float x_pos = 0;
    float y_pos = 0;
    uint32_t health = 0;
    uint32_t energy = 0;
    Alliance alliance;
    // team : e[ALLIED, ENEMY]
    void PlayerPos(float xin, float yon);
    void printReg();
};
