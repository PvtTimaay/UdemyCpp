#include "exercise.h"
#include <iostream>
#include <iterator>
#include <string>

// Exercise 2
std::string_view get_oldest_friend(const Friends &friends)
{
    std::string_view tempFriend = "";
    int tempAlter = 0;

    for (const auto &[key, valhalla] : friends) //NOTE structured binding mit [] direkt entpacken
    {
        if (valhalla.first > tempAlter)
        {
            tempFriend = key;
            tempAlter = valhalla.first;
        }
    }
    return tempFriend;
}

std::string_view get_heaviest_friend(const Friends &friends)
{
    std::string_view tempFriend {""};
    int tempHeavy = 0;

    for (const auto &item : friends)
    {
        if (item.second.second > tempHeavy)
        {
            tempFriend = item.first;
            tempHeavy = item.second.second;
        }
    }
    return tempFriend;
}
