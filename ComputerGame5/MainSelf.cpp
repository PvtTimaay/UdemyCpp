#include <iostream>

void printMap(char map[15][15], char start, char end, char player)
{
    // Prints the map to the console.
    //
    // Args:
    //   map: The map to print.
    //   start: The character representing the start position.
    //   end: The character representing the end position.
    //   player: The character representing the player.
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (i == 0 || i == 14 || j == 0 || j == 14)
            {
                std::cout << "-";
            }
            else if (map[i][j] == start)
            {
                std::cout << start;
            }
            else if (map[i][j] == end)
            {
                std::cout << end;
            }
            else if (map[i][j] == player)
            {
                std::cout << player;
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    char map[15][15] = {
        {'|', '|', '|', '|', '|'},
        {'|', '.', '.', '.', '|'},
        {'|', '.', 'S', '.', '|'},
        {'|', '.', '.', '.', '|'},
        {'|', '|', '|', '|', '|'},
    };

    printMap(map, 'S', 'E', 'P');

    return 0;
}
