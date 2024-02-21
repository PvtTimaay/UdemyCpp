#include <cmath>
#include <iostream>
#include <vector>

void fill_vector(std::vector<double> &vectr)
{
    for (size_t i = 0; i < vectr.size(); i++)
    {
        vectr[i] = static_cast<double>(i);
    }
}

void print_vector(std::vector<double> &PVectr)
{
    for (size_t i = 0; i < size(PVectr); i++)
    {
        std::cout << " Vector: " << PVectr[i] << '\n';
    }
    std::cout << std::endl;
}

void exp_vector(std::vector<double> &ExpVectr)
{
    for (size_t i = 0; i < size(ExpVectr); i++)
    {
        ExpVectr[i] = std::exp(ExpVectr[i]);
    }
}

void log_vector(std::vector<double> &LogVectr)
{
    for (size_t i = 0; i < size(LogVectr); i++)
    {
        LogVectr[i] = std::log(LogVectr[i]);
    }
}

// Exercise:
// 1.) Schreibe eine Function, die einen Vector mit aufsteigenden Werten befüllt
//     void fill_vector(std::vector<double> &vec)
// 2.) Schreibe eine Function, die die Werte eines Vectors ausgibt
//      void print_vector(const std::vector<double> &vec)
// 3.) Schreibe Funktionen, die die:
// - Exponential
// - Natural Logarithm
// Werte von einem double-Vector berechnet
//      void double_vector_exp(std::vector<double> &vec)
// verwendet std::exp, std::log aus <cmath>
// [exp(0.0), exp(1.0), ...]
// [log(0.0), log(1.0), ...]
int main()
{
    auto my_vector = std::vector<double>(3, 0.0);

    fill_vector(my_vector);
    print_vector(my_vector);

    exp_vector(my_vector);
    print_vector(my_vector);

    log_vector(my_vector);
    print_vector(my_vector);

    return 0;
}
