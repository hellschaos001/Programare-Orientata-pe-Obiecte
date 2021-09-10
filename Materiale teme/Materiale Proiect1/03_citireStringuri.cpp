#include <iostream>
using namespace std;

int main()
{
    char s[256], s2[256];
    cout<<"dati n:";
    int n;
    cin>>n; ///atunci cand citim ceva inainte apare problema pentru ca ramane ENTER in buffer
    ///folosim astfel cin.get() pt a elimina enterul din buffer
    cin.get();
    cout<<"Dati valoarea lui s:";
    cin.getline(s,256); ///daca foloseam cin.get(s,256) trebuia sa elimin iar din buffer ENTERUL (cin.getline face asta automat)
    cout<<"Dati un alt sir:";
    cin.getline(s2,256);
    cout<<s<<endl<<s2;


    string s3;
    getline(cin,s3);
    string s4;
    s4=s3;
    cout<<s4;

    return 0;
}
