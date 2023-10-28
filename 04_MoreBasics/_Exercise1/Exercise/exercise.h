#pragma once

#include <cstdint>

namespace computation
{
// Exercise 1
double mean_array_value(int *array, const std::size_t length);
double mean_array_value(double *array, const std::size_t length);

// Exercise 2
struct Dataset
{
    int mean_array_a = 0;
    double mean_array_b = 0;
};

} // namespace computation
