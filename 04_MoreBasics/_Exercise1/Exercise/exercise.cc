#include <cstdint>
#include <iostream>

#include "exercise.h"

namespace computation
{

// Exercise 1
double mean_array_value(int *array, const std::size_t length)
{
    int sum = 0;
    for (std::size_t i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / length;
}
//  NOTE                                                                           Gemacht am 28.10.2023 um 18:52 Uhr
double mean_array_value(double *array, const std::size_t length)
{
    double sum = 0;
    for (std::size_t i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / length;
}

} // namespace computation
