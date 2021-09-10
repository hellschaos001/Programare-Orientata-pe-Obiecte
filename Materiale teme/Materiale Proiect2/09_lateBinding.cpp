#include<iostream>
using namespace std;
class baza
{
public:
    virtual void functie() { cout<<"In baza \n"; }
};

class derivata: public baza
{
public:
    void functie() { cout<<"In derivata \n"; }
    virtual void metoda(){cout<<"hehe";}
};
class derivata2: public derivata{
public:
    void functie() {cout<<"derivata2222";}
    void metoda(){cout<<"derivata2";}

};

int main(void)
{
    derivata *x = new derivata2;
    x->functie();//runtime;
    cout<<endl;
    x->metoda();//runtime;
    return 0;
}
