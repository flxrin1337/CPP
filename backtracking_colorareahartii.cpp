/*  Se da un numar intreg de la tastatura n>0. 
    Se cer toate posibilitatile de a colora o harta avand n tari astfel incat orice doua tari vecine sa fie colorate diferit.
    Precizare: S-a demonstrat ca numarul minim de culori necesar este 4
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("tari.txt");
int st[50],k,n,a[50][50],as,ev,sol;
void init()
{
    st[k]=0;
}
void succesor()
{
    if(st[k]<4)
    {
        as=1;
        st[k]++;
    }
    else
        as=0;
}
void valid()
{
    int i;ev=1;
    for(i=1;i<k;i++)
        if(st[i]==st[k]&&a[i][k]==1)
            ev=0;
}
int solutie()
{
    return k==n;
}
void tipar()
{
    for(int i=1;i<=n;i++)
        cout<<"Tara "<<i<<" este colorata cu culoarea "<<st[i]<<endl;
    cout<<endl;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            f>>a[i][j];
            a[j][i]=a[i][j];
        }
    k=1;
    init();
    while(k>0)
    {
        do
        {
            succesor();
            if(as)
            {
                valid();
            }
               
        } while (as && !ev);
        if(as)
            if(solutie())
            {
                tipar();
                sol++;
            }
                
            else
            {
                k++;
                init();
            }
        else
            k--;
    }
    cout<<"S-au gasit "<<sol<<" (de) solutii.";
    return 0;
}
