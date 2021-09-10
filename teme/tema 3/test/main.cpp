#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

class locuinta{
protected:
    string nume_client;
    int suprafata_utila;
    int discount;
public:
    locuinta(string ,int ,int);

    string get_nume_client() const{
        return nume_client;
    }
    int get_suprafata_utila() const{
        return suprafata_utila;
    }
    int get_discout() const{
        return discount;
    }

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, locuinta&);
    friend istream& operator>>(istream& in, locuinta&);

};
locuinta::locuinta(string nume="" ,int suprafata=0 ,int discount=0)
{
    nume_client=nume;
    suprafata_utila=suprafata;
    discount=discount;
}

istream& operator>>(istream& in ,locuinta& l)
{
    l.citire(in);
    return in;
}
void locuinta::citire(istream& in)
{
    cout<<"Numele clientului: ";
    in>>nume_client;
    cout<<"Suprafata utila: ";
    in>>suprafata_utila;
    cout<<"Discount: ";
    in>>discount;
}

ostream& operator<<(ostream& out,locuinta& l)
{
    l.afisare(out);
    return out;
}
void locuinta::afisare(ostream& out)
{
    out<<"Numele clientului este: "<<nume_client<<endl;
    out<<"Suprafata utila este: "<<suprafata_utila<<endl;
    out<<"Discountul este: "<<discount<<endl;

}

///-----------------------------------------------------

class apartament:public locuinta{
protected:
    int etajul_apartamentului;
public:
    apartament(string ,int ,int ,int);

    void afisare(ostream &out);
    void citire(istream &in);

    friend ostream& operator<<(ostream& out ,apartament&);
    friend istream& operator>>(istream& in ,apartament&);

};

apartament::apartament(string nume="" ,int suprafata=0 ,int discount=0 ,int etaj=0):locuinta(nume,suprafata,discount){
    etaj=etajul_apartamentului;
}

void apartament::citire(istream &in){
    locuinta::citire(in);
    cout<<"Etajul aparatamentului:";
    in>>etajul_apartamentului;
}
istream& operator>>(istream &in ,apartament& a){
    a.citire(in);
    return in;
}

void apartament::afisare(ostream &out){
    locuinta::afisare(out);
    out<<"Etajul apartamentului este:"<<etajul_apartamentului<<endl;
}
ostream& operator<<(ostream &out ,apartament& a){
    a.afisare(out);
    return out;
}

///-------------------------------------------
class casa:public locuinta{
protected:
    int suprafata_curte;
    int nr_etaje;
    int* suprafata_etaje;
public:
    casa(string ,int ,int ,int, int, int*);

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream& in, casa&);
    friend ostream& operator<<(ostream& out, casa&);

};

casa::casa(string nume="" ,int suprafata=0 ,int discount=0 ,int suprafata_curte=0 ,int nr_etaje=0 ,int* suprafata_etaje = 0):locuinta(nume,suprafata,discount)
{
    int i;
    suprafata_curte=suprafata_curte;
    nr_etaje=nr_etaje;
    suprafata_etaje = new int[nr_etaje];
    for(i = 0; i < nr_etaje; i++)
        suprafata_etaje[i] = suprafata_etaje[i];
}

void casa::citire(istream& in){
    int i;
    locuinta::citire(in);
    cout<<"Suprafata curte:";
    in>>suprafata_curte;
    cout<<"Numar etaje:";
    in>>nr_etaje;
    suprafata_etaje = new int[nr_etaje];
    for(i = 0; i < nr_etaje; i++)
    {
        cout<<"Suprafata etaj "<<i+1;
        in>>suprafata_etaje[i];
    }
}
istream& operator>>(istream& in, casa& c){
    c.citire(in);
    return in;
}

void casa::afisare(ostream& out){
    locuinta::afisare(out);
    out<<"Suprafata curte:"<<suprafata_curte<<endl;
    out<<"Numar etaje:"<<nr_etaje<<endl;
    out<<"Suprafata etaje"<<suprafata_etaje<<suprafata_etaje+1<<suprafata_etaje+2<<endl;
}

void tip(locuinta *&p, int &i, list<locuinta*> &l){
    string s;
    cout<<"\nIntroduceti tipul locuintei "<<i+1<<": ";
    cin>>s;
    try
    {
        if(s=="casa")
        {
            p=new casa;
            cin>>*p;
            l.push_back(*&p);
            i++;
        }
        else
            if(s=="apartament")
        {
            p=new apartament;
            cin>>*p;
            l.push_back(*&p);
            i++;
        }
            else
                throw 10;
    }
    catch(bad_alloc var)
    {
        cout<< "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus un tip valid. Incercati locuinta sau apartament.\n ";
    }
}

int main()
{
    list <locuinta*> agentie;
    locuinta **v;
    int n;
    cout<<"Dati nr de obiecte:";
    cin>>n;
    v=new locuinta*[n];
    for(int i=0;i<n;)
        tip(v[i],i,agentie);


    list<locuinta*>::iterator i;
    cout<<"--------------------------\n";

    for(i=agentie.begin(); i!=agentie.end(); i++)
    {
        cout<<(**i);
        cout<<"----------------------------------------"<<endl;
    }



    return 0;
}

