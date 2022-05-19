/*  Se dă o tablă dreptunghiulară formată din n linii și m coloane, definind n*m zone, unele dintre ele fiind libere, altele conținând obstacole.
    În zona aflată la poziția is, js se află un șoarece care se poate deplasa pe tablă trecând din zona curentă în zona învecinată cu aceasta pe linie sau pe coloană.
    Scopul sau este să ajungă la o bucată de brânză aflată în zona de la poziția ib, jb, fără a părăsi tabla, fără a trece prin zone care conțin obstacole și fără a trece de două ori prin aceeași zonă.
    Determinați toate modalitățile prin care șoarecele poate ajunge de la poziția inițială la cea a bucății de brânză există.
*/
#include <iostream>
#include <fstream>
#include <conio.h>
ifstream f("labirint_liniisicoloane.txt");
ofstream g("labirint.txt");
using namespace std;
int a[50][50], n, m, i, k, j, is, js, ib, jb, as;
int toN()
{
    a[is][js];
}
int main()
{
    f >> n;
    f >> m;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            f >> a[i][j];
    do
    {
        cin >> is >> js;
    } while (a[is][js] == 1);
    do
    {
        cin >> ib >> jb;
    } while (a[ib][jb] == 1);
    return 0;
}