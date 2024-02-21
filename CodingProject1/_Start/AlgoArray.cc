#include <cmath>
#include <cstdlib>
#include <algorithm>

#include "AlgoArray.h"
#include "DynArray.h"

double sum(const DynamicArray &dynamic_array)
{
    auto tempSum = .0;
for (size_t i = 0; i < dynamic_array.m_length; i++)
{
    tempSum += dynamic_array.m_data[i];

}
return tempSum;
}

double mean(const DynamicArray &dynamic_array)
{
     return sum(dynamic_array) / static_cast<double>(dynamic_array.m_length);
}

double median(const DynamicArray &dynamic_array) {
    std::vector<double> temp(dynamic_array.m_data, dynamic_array.m_data + dynamic_array.m_length);
    std::sort(temp.begin(), temp.end());

    size_t n = temp.size();
    if (n % 2 == 0) {
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    } else {
        return temp[n / 2];
    }
}
