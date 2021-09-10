#include <iostream>

using namespace std;

int main()
{
    int n,x[100],aux=0,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>x[i];
    for(i=1;i<=n/2;i++)
    {
        aux=x[i];
        x[i]=x[n+1-i];
        x[n+1-i]=aux;
    }
    for(i=1;i<=n;i++)
        cout<<x[i];
    return 0;
}
