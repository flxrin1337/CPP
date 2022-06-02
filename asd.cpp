#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int cel_mai_mic_divizor(int x)
{
    int i, divizor = x;
    for (i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
        {
            divizor = i;
            break;
        }
    }
    return divizor;
}
int main()
{
    int n, max = 0, x, div, div2;
    ifstream fin("numere.in");
    fin >> n;
    while (n > 0)
    {
        fin >> x;
        div = cel_mai_mic_divizor(x);
        div2 = x / div;
        if (div2 > 1 && div2 == cel_mai_mic_divizor(div2))
        {
            if (max < x)
            {
                max = x;
            }
        }
        n--;
    }
    if (max == 0)
    {
        cout << "NU";
    }
    else
    {
        cout << "DA" << " " << max;
    }
    return 0;
}