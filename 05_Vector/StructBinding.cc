#include <iostream>
#include <vector>

struct Data //NOTE <-Benutzerdefinierter Datentyp
{
    float x;
    float y;
};

int main()
{
    std::vector<Data> vec1{Data{1.0F, 2.0F}, Data{4.0F, 6.0F}}; // <- Alternative Syntax?
                                                                // Structured Binding
    auto vec = std::vector<Data>{Data{1.0F, 2.0F},
                                 Data{4.0F, 6.0F}}; //<-Mehrere Objekte??Datentypen in einer std::vector definition
    //entweder wie hier direkt entpacken mit [alias, alias] oder als temporäre variable z.B. (const auto &s : vec)
    for (const auto &[x_, y_] : vec) //
    {
        //und dann hier mit dem . operator auf jeweilige attribute zugreifen  << s.x << " " << s.y << '\n'
        std::cout << x_ << " " << y_ << '\n';
    }

    std::cout << vec1.size() << '\n';
    std::cout << vec1.capacity() << '\n';


    return 0;
}
