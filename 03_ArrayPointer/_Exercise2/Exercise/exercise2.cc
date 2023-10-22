#include <cstdint>
#include <iostream>

#include "exercise2.h"

// Exercise 1
void push_back(std::int32_t *&input_array,
               const std::size_t size,
               const std::int32_t value)
{
    // Prüfen, ob der Speicher für das Array erweitert werden muss
    if (size == 0)
    {
        input_array = new int[1];
        input_array[0] = value;

    }
    else
    {
        // Speicher für das Array erweitern
        int *new_array = new int[size + 1];

        for (std::uint32_t i = 0; i < size; i++)
        {
            new_array[i] = input_array[i];
        }

        new_array[size] = value;

        // Alten Speicher freigeben
        delete[] input_array;

        // Neuen Speicher übernehmen
        input_array = new_array;


    }
}

// Exercise 2
void pop_back(std::int32_t *&input_array, const std::size_t size)
{
// Prüfen, ob das Array leer ist
    if (size == 0)
    {
        return;
    }

    // Letztes Element entfernen


    // Speicher für das Array verkleinern
    int *new_array = new int[size];

    for (std::uint32_t i = 0; i < size; i++)
    {
        new_array[i] = input_array[i];
    }

    // Alten Speicher freigeben
    delete[] input_array;

    // Neuen Speicher übernehmen
    input_array = new_array;
}
