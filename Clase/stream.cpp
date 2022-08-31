#include <iostream>

using namespace std;

void output_numeric_stream(int);

int main()
{
    output_numeric_stream(1);
    output_numeric_stream(50);
    output_numeric_stream(100);
}

void output_numeric_stream(int n)
{
    // cout << "Output: " << n << "\n";
    for (int i = 0; i < n; i++)
        cout << i << "\n";
}