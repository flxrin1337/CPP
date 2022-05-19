#include <iostream>
int st[500],i,ev,as,j,k,n;
using namespace std;

void init(int st[100], int k)
{
    st[k]=0;
}
int solutie()
{
    return k==n;
}
void afisare()
{
    for(i=1;i<=k;i++)
        cout<<st[i]<<" ";
    cout<<endl;
}
int valid(int st[100], int k)
{
    ev=1;
    for(i=1;i<=k-1;i++)
        if(st[k]==st[i])
            ev=0;
    return ev;
}
int succesor(int st[100], int k)
{
    as=0;
    if(st[k]<n)
    {
        st[k]++;
        as=1;
    }
    return as;
}
int main()
{
    cin>>n;
    k=1;
    init(st,k);
    while(k>0)
    {
        do
        {
            as=succesor(st,k);
            if(as)
                ev=valid(st,k);
        }while(as && !ev);
        if(as)
            if(solutie())
                afisare();
            else
            {
                k++;
                init(st,k);
            }
        else
            k--;
        //cout<<"\n"; afisare();
    }
    return 0;
}
