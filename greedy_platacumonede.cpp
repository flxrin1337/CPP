#include <iostream>
int m[50], n, i, j, S, nr[50];
using namespace std;
int sortare_desc()
{
    int aux;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (m[i] < m[j])
            {
                aux = m[i];
                m[i] = m[j];
                m[j] = aux;
            }
    return aux;
}
void init()
{
    for (i = 1; i < n; i++)
        nr[i] = 0;
}
void tipar()
{
    cout << endl;
    for (i = 0; i < n; i++)
        cout << nr[i] << " monede cu valoarea " << m[i] << endl;
}
int main()
{
    cout << "Introduceti suma necesara calculului: ";
    cin >> S;
    cout << "Introduceti numarul de monede folosite: ";
    cin >> n;
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Valoarea monedei de tipul " << i << " este: ";
        cin >> m[i];
    }
    cout << endl;
    sortare_desc();
    init();
    i = 0;
    while (S > 0 && i <= n)
    {
        if (m[i] <= S)
        {
            nr[i] = S / m[i];
            S %= m[i];
        }
        i++;
    }
    tipar();
    return 0;
}