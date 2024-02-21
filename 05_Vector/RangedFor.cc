#include <iostream>
#include <vector>

// 1: auto val : vec => int val : vec
// 2: auto& val : vec => int& val : vec
// 3: const auto val : vec => const int val : vec
// 4: const auto& val : vec => const int& val : vec
int main()
{
    auto vec = std::vector<int>{1, 2, 3, 4, 5};
    vec.push_back(1); //alloc vector memory but outside of range-for loop parentheses (())
    for (auto val : vec)
    {
        std::cout << val << " "; //automatic memory (Automatic Storage Duration), val was deleted by end of local area
    }
    std::cout << '\n';

    for (auto &val : vec) //a reference of a vector can change the vector by Requirement
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    for (const auto val : vec) // const copy, cant change and copy`s was deleted by end of local area for() {->}<-
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    for (const auto &val : vec) // const reference, cant change vec with the val reference because it is const
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    return 0;
}
