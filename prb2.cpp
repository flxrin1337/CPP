#include <iostream>
using namespace std;
int v[100], n, prim = 0;
void estePrim(int a)
{
    int contor = 1;
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            contor = 0;
    }
    if (contor == 1)
        prim++;
    cout << prim << endl;
}
int divide(int i, int j)
{
    int a, b;
    if (i == j)
        return v[i];
    else
    {
        a = divide(i, (i + j) / 2);
        b = divide((i + j) / 2 + 1, j);
        estePrim(a);
        estePrim(b);
    }
}
int main()
{
    cout << "marimea sirului x[n]=";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "elementul v[" << i << "]=";
        cin >> v[i];
    }
    divide(0, n - 1);
    cout << "exista " << prim << " nr prime";
}