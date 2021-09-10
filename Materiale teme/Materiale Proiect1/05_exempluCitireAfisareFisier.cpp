#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int x=0;
    ifstream fin ("date.in");
    ofstream fout("date.out");
    if (fin)
        cout<<"da";
    else
        cout<<"nu";
    fin>>x;
    fout<<x;

    fin.close();
    fout.close();

    return 0;
}
