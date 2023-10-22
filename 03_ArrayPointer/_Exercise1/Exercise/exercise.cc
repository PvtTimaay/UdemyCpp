#include <cstdint>
#include <iostream>

#include "exercise.h"

// Exercise 1
double array_sum(const double *p_array, const std::size_t length)
{
    double sum;
    for(int i = 0; i < length; i++) {
        sum += p_array[i];
    }
    return sum;
}

// Exercise 2
 std::int32_t *array_constructor(const std::int32_t &value,
                              const std::size_t length)
{
std::int32_t *Array12 = new std::int32_t [length]; // <- Hiermit erstellst du ein Dynamisches Array, dass auf dem Heap angelegt wird!
    for(int i = 0; i < length; i++) {
        Array12[i] = value;

    }
return Array12;
delete[] Array12;


}

