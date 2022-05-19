#include <iostream>
using namespace std;

int A[50],m,B[50],n,i,j,S;
int submultime();
int sortare_desc();
int main()
{
    cout<<"Cate elemente are multimea A?: ";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    sortare_desc();
    cout<<"Vectorul sortat este: "<<endl;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl<<"Introduceti cate elemente doriti sa aiba multimea B: ";
    cin>>m;
    submultime();

    cout<<"Pentru m = "<<m<<", solutia este B = { ";
        for(i=0;i<m;i++)
    cout<<B[i]<<" ";
    cout<<"}, cu suma maxima S = "<<S;
    return 0;
}

int submultime()
{
    S=0;
    for(i=0;i<m;i++)
    {
        B[i]=A[i];
        S+=B[i];
    } 
    return S;
}

int sortare_desc()
{
    int aux;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(A[i]<A[j])
            {
                aux=A[i];
                A[i]=A[j];
                A[j]=aux;
            }
    return aux;
}