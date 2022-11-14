
#include <iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;

using Cubo = array<array<array<int, 12>, 3>, 4>;

void ReadInput(Cubo &);
void PrintResult(Cubo &);
array<int, 4> MaxSale(Cubo &);
void PrintMaxSale(Cubo &);

int main()
{
    Cubo total{};
    ReadInput(total);
    PrintResult(total);
    PrintMaxSale(total);
}

void ReadInput(Cubo &total)
{
    ifstream in;
    in.open("importes.txt", ios::in);
    int mes, vendedor, region{0};
    for (int imp{0}; in >> imp >> mes >> vendedor >> region;)
        total.at(region).at(vendedor - 1).at(mes - 1) += imp;
    in.close();
}

void PrintResult(Cubo &total)
{
    ofstream out;
    out.open("salida.txt", ios::out);

    array<string, 12> NombreMes{
        "Enero",
        "Febrero",
        "Marzo",
        "Abril",
        "Mayo",
        "Junio",
        "Julio",
        "Agosto",
        "Septiembre",
        "Octumbre",
        "Noviembre",
        "Diciembre",
    };

    for (int i{0}; i < 4; i++)
    {
        cout << "-"
             << "REGION " << i << "- "
             << ":" << endl;
        for (int k{1}; k < 4; k++)
        {
            cout << "VENDEDOR " << k << ":" << endl;
            for (int j{0}; j < 12; j++)
                cout << "ventas en " << NombreMes.at(j) << ": $" << total.at(i).at(k - 1).at(j) << endl;
        }
        cout << endl;
    }

    out.write(reinterpret_cast<const char *>(&total), sizeof(total));
    out.close();
}

array<int, 4> MaxSale(Cubo &total)
{
    array<int, 4> max{-1, -1, -1, -1};

    for (int i{0}; i < 4; i++)
    {
        for (int k{0}; k < 3; k++)
            for (int mes{0}; mes < 12; mes++)
            {
                int venta = total.at(i).at(k).at(mes);
                if (venta > max.at(3))
                    max = {i, k, mes, venta};
            }
    }

    return max;
}

void PrintMaxSale(Cubo &total)
{
    array<int, 4> max = MaxSale(total);

    cout << "La venta máxima fue en la región: " << max.at(0) << ". Por el vendedor: " << max.at(1) << ". En el mes: " << max.at(2) << ". Y fue de: " << max.at(3) << '.';
}