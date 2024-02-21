#include <cmath>
#include <iostream>
#include <vector>
//TODO verändere hier die for schleifen zu "range-for loops" - bereichsbasierte for schleife  ist eine Funktion in C++, die mit dem C++11-Standard eingeführt wurde. Quelle ChatGpt DataAnalysis

void fill_vector(std::vector<double> &vectr)
{
    for (int i = 0; auto &vec : vectr) //hier eine temporäre variable um werte "aufsteigend" zu befüllen
    {
        vec = static_cast<double>(i);
        i++;
    }
}

void print_vector(
    std::vector<double> &
        PVectr) // eine konstante referenz weil hier nur gelesen werden soll, eine referenz um unnötig viele kopien zu vermeiden (man nutzt das bestehende objekt)
{
    for (const auto &vec : PVectr)
    {
        std::cout
            << " Vector: " << vec
            << '\n'; // eine Kopie hätte es hier auch getan (const auto vec : PVectr) da der wert hier nur ausgegeben werden soll "std::cout"
    }
    std::cout << std::endl;
}

void exp_vector(
    std::vector<double> &
        ExpVectr) // hier wird sowieso eine Funktion genutzt die werte zurückgibt und desshalb keine temporäre variable genutzt werden muss wie oben!
{
    for (auto &vec : ExpVectr)
    {
        vec = std::exp(vec);
    }
}

void log_vector(std::vector<double> &LogVectr) // hier auch eine Funktion
{
    for (auto &vec : LogVectr)
    {
        vec = std::log(vec);
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
