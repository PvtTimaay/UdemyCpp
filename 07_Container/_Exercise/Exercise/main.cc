#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <ranges>

#include "exercise.h"

int main()
{
    // Exercise 1
    auto aliasFriends = Friends{};
    std::map<std::string, std::pair<std::int32_t, std::int32_t>> friends;
    friends["Hans"] = std::make_pair(70, 80);
    friends["Harald"] = std::make_pair(72, 81);
    friends["Muecke"] = std::make_pair(55, 90);
    // ...


    // Exercise 2
    const auto oldest_friend = get_oldest_friend(friends);
    const auto heaviest_friend = get_heaviest_friend(friends);

    std::cout << "My oldest friend: " << oldest_friend << '\n';
    std::cout << "My heaviest friend: " << heaviest_friend << '\n';

    return 0;
}
