#include <iostream>
#include <fstream>
using namespace std;
ifstream f("tari.txt");
int st[50],i,k,j,n,a[50][50],as,ev,sol,nrv[50],nrc,t[50],asd;
void tipar()
{
    for(int i=1;i<=n;i++)
        cout<<"Tara "<<i<<" este colorata cu culoarea "<<st[i]<<endl;
    cout<<endl;
}
void sortare_desc()         // Actualizam un vector al tarilor t[] astfel incat ele sunt ordonate descrescator dupa numarul de culori
{
    int aux;
    for(i=1;i<=n;i++)
        t[i]=i;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (nrv[i] > nrv[j])
            {
                aux = nrv[i];
                nrv[i] = nrv[j];
                nrv[j] = aux;
                aux=t[i];
                t[i]=t[j];
                t[j]=aux;
            }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        nrv[i]=0;
        for(int j=1;j<=n;j++)
        {
            f>>a[i][j];
            if(a[i][j]==1)
                nrv[i]++;
        }
    }
    for(i=1;i<=n;i++)
        st[i]=0;
    sortare_desc();
    for(i=1;i<=n;i++)
        cout<<t[i];
    nrc=0;
    k=1;
    while(nrc<n)
    {
        st[t[k]]=1;
        do
        {
            ev=1;
            for(i=1;i<=n;i++)
            {
                if(st[i]!=0)
                    if(st[i]==st[k]&&a[i][k]==1)
                        ev=0;
            }
            cout<<"t[k]="<<t[k]<<"st[t[k]]: "<<st[t[k]]<<"valid: "<<ev<<endl;
            cin>>asd;
            if(ev==0)
                st[t[k]]++;
        }while(ev==0);  //ii dam alta culoare (st trebuie sa creasca)
        k++;
        nrc++;
    }
    tipar();
    cout<<"S-au gasit "<<sol<<" (de) solutii.";
    return 0;
}
