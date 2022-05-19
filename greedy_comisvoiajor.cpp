#include <iostream>
#include <fstream>
using namespace std;
int n,i,j,o,A[50][50];
ifstream f ("matrice.txt");
int main()
{
    f>>n;
    if(n<2)
        cout<<"Nu exista harta";
    else
    {
        f>>o;   //orasul de start
        if(o<0 || o >= n)
            cout<<"Orasul de start nu este valid";
        else
        {
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    f>>A[i][j];
            //Traseu: 
            bool vizitat[50];
            for(i=0;i<n;i++)
                vizitat[i]=false;
            int t[50];
            t[0]=o;
            vizitat[o]=true;
            int k=1;    //Urmatoarea pozitie din traseu
            while(k<n)  //Cat timp solutia nu este completa, parcurgem urmatorul oras:
            {
                //Alegem ca urmatorul orasul sa fie cel mai apropiat de t[k-1]
                i=0;
                int x=t[k-1];
                int minim=100,ominim=0;
                while(i<n)
                {
                    if(vizitat[i]==false&&A[x][i]<minim)
                    {
                        minim=A[x][i];
                        ominim=i;
                    }
                    i++;
                }
                t[k]=ominim;
                vizitat[ominim]=true;
                k++;
            }
            if(A[t[k-1]][t[0]]>0)
                t[k]=t[0];
            int S=0;
            for(k=0;k<n;k++)
                S+=A[t[k]][t[k+1]];
            cout<<"Traseul gasit este: ";
            for(i=0;i<=n;i++)
                cout<<t[i]+1<<" ";
            cout<<endl;
            cout<<"Lungimea traseului este de "<<S<<" kilometri.";
        }
    }
    return 0;
}