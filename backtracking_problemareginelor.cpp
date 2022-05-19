#include <iostream>
#include <cmath>
int tb[500],i,ev,as,j,k,n,sol;
using namespace std;

void init(int tb[100], int k)
{
    tb[k]=0;
}
int solutie()
{
    return k==n;
}
void afisare()
{
    for(i=1;i<=k;i++)
        cout<<tb[i]<<" ";
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<tb[i]-1;j++)
            cout<<" ";
        cout<<"R";
        for(j=tb[i]+1;j<n;j++)
            cout<<tb[i];
        cout<<endl;
    }
            cout<<endl;
}
int valid(int tb[100], int k)
{
    ev=1;
    for(i=1;i<=k-1;i++)
    {
        if(tb[k]==tb[i])
            ev=0;
            if(abs(k-i)==abs(tb[k]-tb[i]))
                ev=0;
    }

    return ev;
}
int succesor(int tb[100], int k)
{
    as=0;
    if(tb[k]<n)
    {
        tb[k]++;
        as=1;
    }
    return as;
}
int main()
{
    cin>>n;
    k=1;
    init(tb,k);
    while(k>0)
    {
        do
        {
            as=succesor(tb,k);
            if(as)
                ev=valid(tb,k);
        }while(as && !ev);
        if(as)
            if(solutie())
            {
                afisare();
                sol++;
            }
                
            else
            {
                k++;
                init(tb,k);
            }
        else
            k--;
        //cout<<"\n"; afisare();
    }
    cout<<sol;
    return 0;
}
