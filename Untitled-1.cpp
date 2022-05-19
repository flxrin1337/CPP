/*Se citesc n numere pana la inatlanirea valorii 0, sa se numere cate perechi de numere consecutive sunt prime intrel ele.*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");

int cmmdc(int n, int m)
{
    int r;
    while (m != 0)
    {
        r = n % m;
        n = m;
        m = r;
    }
    return n;
}

bool prime(int n, int m)
{ // n si m sunt prime intre ele daca nu au nici un divizor comun(cmmdc (m,n) =1).
    if (m > n)
    {
        int aux = m;
        m = n;
        n = aux;
    }
    if (cmmdc(n, m) == 1)
        return true;
    else
        return false;
}
int nr_perechi()
{
    int a, b, nr = 0;
    cout << "Introduceti introduceti un sir de numere pana la valoarea 0" << endl;
    cin >> a;
    while (a != 0)
    {
        cin >> b;
        if (b != 0)
        {
            if (prime(a, b) == true)
                nr++;
        }
        a = b;
    }
    return nr;
}

int nr_perechi_file()
{
    ifstream f("numere.txt");
    int a, b, nr = 0;
    f >> a;
    // cout<<a;
    while (a != 0)
    {
        f >> b;
        // cout<<b;
        if (b != 0)
        {
            if (prime(a, b) == true)
                nr++;
        }
        a = b;
    }
    f.close();
    return nr;
}

int main()
{

    cout << "Sunt " << nr_perechi_file() << " perechi numere prime intre ele";
    return 0;
}