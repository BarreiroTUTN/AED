#include <map>
#include <iostream>
#include <array>

using namespace std;

int main()
{
    int vendedor[12]{};

    map<int, array<int, 12>> regions;

    int r{};
    for (cout << "Inserte número de región: "; cin >> r; cout << "Inserte número de región: ")
    {
        cout << "Inserte número de vendedor: ";

        int vendedor;
        cin >> vendedor;

        cout << "Inserte mes: ";
        int mes;
        cin >> mes;

        cout << "Inserte importe neto: ";
        int data;
        cin >> data;

        if (regions.at(r))
        {
            regions.emplace(r, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
        }
    }
}