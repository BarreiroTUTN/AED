#include <map>
#include <iostream>
#include <array>
#include <fstream>

using namespace std;

int main()
{
    int vendedor{};

    map<int, array<int, 12>> regions;

    ifstream in;
    in.open("importes_copy.txt", ios::in);

    int mes;
    int data;
    for (int vendedor{}; in >> vendedor >> mes >> data;)
    {
        regions.insert(std::pair<int, array<int, 12>>(vendedor, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
        regions.at(vendedor).at(mes) += data;
    }

    cout << "Printing";

    for (map<int, array<int, 12>>::iterator it = regions.begin(); it != regions.end(); ++it)
    {
        cout << "Vendedor: " << it->first << "\n";

        for (int i{}; i < 12; i++)
        {
            cout << it->second.at(i) << "\n";
        }
    }
}