#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "exercise.h"

// Exercise 2
std::vector<bool> shuffle_till_equal(const BinaryArray &target,
                                     BinaryArray input)
{
    if (target.size() == input.size())
    {
        auto gen = std::mt19937();
        bool tempBool = false;
        do
        {
            tempBool = std::equal(target.begin(), target.end(), input.begin());
            if (tempBool == false)
            {
                std::shuffle(input.begin(), input.end(), gen);
            }
        } while (tempBool == false);

    }
    else
    {
        return {};
    }

    std::vector<bool> tempVec {};
    std::copy(input.begin(), input.end(), std::back_inserter(tempVec));
    return tempVec;
}

// Exercise 3
std::vector<bool> smart_shuffle_till_equal(const BinaryArray &target,
                                           BinaryArray input)
{
        if (target.size() == input.size())
    {
        auto gen = std::mt19937();
        bool tempBool = false;
        do
        {
            tempBool = std::equal(target.begin(), target.end(), input.begin());
            // Iteratoren an den ersten Unterschied zwischen target und input
            auto [first_mismatch_target, first_mismatch_input] = std::mismatch(target.begin(), target.end(), input.begin());
            if (tempBool == false)
            {
                std::shuffle(first_mismatch_input, input.end(), gen);
            }
        } while (tempBool == false);

    }
    else
    {
        return {};
    }

    std::vector<bool> tempVec {};
    std::copy(input.begin(), input.end(), std::back_inserter(tempVec));
    return tempVec;
}
