#include <iostream>
#include <vector>


void printMap(std::vector<std::vector<char>> map, char start, char end, char player)
{
    // Prints the map to the console.
    //
    // Args:
    //   map: The map to print.
    //   start: The character representing the start position.
    //   end: The character representing the end position.
    //   player: The character representing the player.
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (i == 0 || i == map.size() - 1 || j == 0 || j == map[0].size() - 1)
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
    std::vector<std::vector<char>> map = {{'|', '|', '|', '|', '|'},
                                          {'|', '.', '.', '.', '|'},
                                          {'|', '.', 'S', '.', '|'},
                                          {'|', '.', '.', '.', '|'},
                                          {'|', '|', '|', '|', '|'}};

    printMap(map, 'S', 'E', 'P');

    return 0;
}
