#include <iostream>
#include <stdlib.h>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class locuinta{
protected:
    string nume_client;
    int suprafata_utila;
    int discount;
public:
    locuinta(string ,int ,int);
    locuinta(locuinta&);
    virtual ~locuinta();

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
    locuinta& operator=(locuinta &l);
};
locuinta::locuinta(string nume="" ,int suprafata=0 ,int discount=0)
{
    nume_client=nume;
    suprafata_utila=suprafata;
    discount=discount;
}

locuinta::~locuinta()
{
    nume_client="";
    suprafata_utila=0;
    discount=0;
}
locuinta::locuinta(locuinta &l)
{
    nume_client=l.nume_client;
    suprafata_utila=l.suprafata_utila;
    discount=l.discount;
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


locuinta& locuinta::operator=(locuinta &l)
{
    nume_client=l.nume_client;
    suprafata_utila=l.suprafata_utila;
    discount=l.discount;
}


///-----------------------------------------------------

class apartament:public locuinta{
protected:
    int etajul_apartamentului;
public:
    apartament(string ,int ,int ,int);
    ~apartament();
    apartament(apartament&);

    void afisare(ostream &out);
    void citire(istream &in);

    friend ostream& operator<<(ostream& out ,apartament&);
    friend istream& operator>>(istream& in ,apartament&);
    apartament& operator=(apartament &a);

};

apartament::apartament(string nume="" ,int suprafata=0 ,int discount=0 ,int etaj=0):locuinta(nume,suprafata,discount){
    etaj=etajul_apartamentului;
}

apartament::~apartament()
{
    etajul_apartamentului=0;
}
apartament::apartament(apartament &a)
{
    etajul_apartamentului=a.etajul_apartamentului;
}

apartament& apartament::operator=(apartament &a)
{
    nume_client=a.nume_client;
    suprafata_utila=a.suprafata_utila;
    discount=a.discount;
    etajul_apartamentului=a.etajul_apartamentului;
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
    ~casa(){delete []suprafata_etaje;}
    casa(casa&);

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream& in, casa&);
    friend ostream& operator<<(ostream& out, casa&);
    casa& operator=(casa &c);

    int get_suprafata_curte(){return suprafata_curte;}
    int get_nr_etaje(){return nr_etaje;}
    int get_suprafata_etaje(int i){return suprafata_etaje[i];}
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
casa::casa(casa &c)
{
    *this=c;
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
        if(i==0)
            {
            cout<<"Suprafata parter:";
            in>>suprafata_etaje[i];
            }
        else
            {
            cout<<"Suprafata etaj "<<i<<":";
            in>>suprafata_etaje[i];
            }
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

    for(int i=0;i<nr_etaje;i++)
        {
            if(i==0)
                {
                out<<"Suprafata parter:";
                out<<suprafata_etaje[i]<<endl;
                }
            else
                {
                out<<"Suprafata etaj "<<i<<":";
                out<<suprafata_etaje[i]<<endl;
                }
        }
}
ostream& operator<<(ostream& out, casa& c){
    c.afisare(out);
    return out;
}

casa& casa::operator=(casa &c)
{
    nume_client=c.nume_client;
    suprafata_utila=c.suprafata_utila;
    discount=c.discount;
    suprafata_curte=c.suprafata_curte;
    nr_etaje=c.nr_etaje;

    suprafata_etaje = new int[nr_etaje];

    for(int i=0;i<nr_etaje;i++)
        suprafata_etaje[i]=c.suprafata_etaje[i];
}


///-------------------------------------------------

template <class t> class Gestiune
{
    t *v;
    int nr;
public:
    Gestiune(t *p=NULL, int n=0)
    {
        nr=n;
        v=new t[n];
        for(int i=0;i<n;i++)
            v[i]=p[i];
    }
    Gestiune(Gestiune &a)
    {
        nr=a.nr;
        v=new t[nr];
        for(int i=0;i<nr;i++)
            v[i]=a.v[i];
    }
    ~Gestiune()
    {
        delete [] v;
    }

    int get_nr() {return nr;}
    t get_v(int i) {return v[i];}

    friend istream& operator>>(istream &in, Gestiune <t> &g)
    {
        cout<<"Introduceti numarul de locuinte implicate: ";
        in>>g.nr;
        g.v=new t[g.nr];
        cout<<"introduceti obiectele: \n";
        for(int i=0;i<g.nr;i++)
        {
           in>>g.v[i];
           cout<<"\n";
        }
        return in;
    }

    friend ostream& operator <<(ostream &out, Gestiune<t> &g)
    {
        out<<"In gestiune se gasesc urmatoarele "<<g.nr<<" locuinte implicate:"<<"\n";
        for(int i=0;i<g.nr;i++)
            out<<g.v[i]<<"\n";
        return out;
    }
    friend Gestiune& operator+=(Gestiune<t> &g,int adaug)
    {
        t* v2=new t[g.nr+adaug];
        for(int i=0;i<g.nr;i++)
                v2[i]=g.v[i];
        delete [] g.v;
        g.v=new t[g.nr+adaug];
        for(int i=g.nr;i<g.nr+adaug;i++)
                cin>>v2[i];
        g.nr+=adaug;
        for(int i=0;i<g.nr;i++)
            g.v[i]=v2[i];
        delete [] v2;
    }
};

template <> class Gestiune <casa>
{
    casa* v;
    int nr;
    int nr_case;
    float pret_metru;
    static float total_chirie;
public:

    void chirie()
    {
        float chirie;
        float chirie_casa;
        float chirie_curte;

        for(int j=0;j<nr;j++)
        {
        chirie_casa=0;
        chirie_curte=pret_metru * v[j].get_suprafata_curte();

        for(int i=0;i<v[j].get_nr_etaje();i++)
            {
                chirie_casa=chirie_casa + (pret_metru * v[j].get_suprafata_etaje(i));
            }
        chirie = chirie_casa + chirie_curte;

        total_chirie+=chirie;
        cout<<"Chiria pentru casa "<<j+1<<" este :"<<chirie<<endl;

        }
    }

    static void total(){
        cout<<total_chirie;
    }


    Gestiune(casa *p=NULL, int n=0)
    {
        n=n;
        v=new casa[n];
        for(int i=0;i<n;i++)
            {
                v[i]=p[i];
                nr_case++;
            }
    }
    Gestiune(Gestiune &a)
    {
        nr=a.nr;
        v=new casa[nr];
        for(int i=0;i<nr;i++)
            v[i]=a.v[i];

        nr_case=a.nr_case;
        pret_metru=a.pret_metru;
    }
    ~Gestiune()
    {
        delete [] v;
    }

    friend istream& operator>>(istream &in, Gestiune <casa> &g)
    {
        cout<<"Introduceti pretul pe metru patrat :";
        in>>g.pret_metru;


        cout<<"Introduceti numarul de case implicate: ";
        in>>g.nr;
        g.v=new casa[g.nr];
        cout<<"introduceti obiectele: \n";
        for(int i=0;i<g.nr;i++)
        {
           in>>g.v[i];
           cout<<"\n";
        }
        return in;
    }

    friend ostream& operator <<(ostream &out, Gestiune<casa> &g)
    {
        out<<"In gestiune se gasesc urmatoarele "<<g.nr<<" case implicate:"<<"\n";
        for(int i=0;i<g.nr;i++)
            out<<g.v[i]<<"\n";
        return out;
    }

        friend Gestiune& operator+=(Gestiune<casa> &g,int adaug)
    {
        casa* v2=new casa[g.nr+adaug];
        for(int i=0;i<g.nr;i++)
                v2[i]=g.v[i];
        delete [] g.v;
        g.v=new casa[g.nr+adaug];
        for(int i=g.nr;i<g.nr+adaug;i++)
                cin>>v2[i];
        g.nr+=adaug;
        for(int i=0;i<g.nr;i++)
            g.v[i]=v2[i];
        delete [] v2;
    }
};
float Gestiune <casa>::total_chirie;

///clasa specializare de facut + implementare functii STL
///---------------------------------------------------
void tip(locuinta *&p, int &i){
    string s;
    cout<<"\nIntroduceti tipul locuintei "<<i+1<<": ";
    cin>>s;
    try
    {
        if(s=="casa")
        {
            p=new casa;
            cin>>*p;
            i++;
        }
        else
            if(s=="apartament")
        {
            p=new apartament;
            cin>>*p;
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
        cout<<"Nu ati introdus un tip valid. Incercati casa sau apartament.\n ";
    }
}
///-------------------------------------

void menu_output()
{
    cout<<"\nPRODUCTIE CINEMATOGRAFICA\n";
    cout<<"\n\t\tMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste informatii despre locuintele implicate. --- UPCAST & LATE-BINDING";
    cout<<"\n";
    cout<<"2. Gestiune --- TEMPLATE (apartament).";
    cout<<"\n";
    cout<<"3. Gestiune --- TEMPLATE (casa).";
    cout<<"\n";
    cout<<"4. Contorizare locuinte --- DYNAMIC_CAST (DOWNCAST).";
    cout<<"\n";
    cout<<"5. Introduceti in Gestiune prin += ";
    cout<<"\n";
    cout<<"6. Introduceti date prin specializarea tipului casa .";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    int n=0;
    locuinta **v;
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {
            cout<<"Dati nr. de obiecte: ";
            cin>>n;
            v=new locuinta*[n];
            if (n>0)
            {
                for(int i=0;i<n;)
                    tip(v[i],i);
                cout<<"\nAfisam personalul citit anterior:\n";
                for(int i=0;i<n;i++)
                   {
                        cout<<"\n"<<*v[i];
                        cout<<"--------------------------\n";
                   }
            }
            else
                cout<<"Numarul introdus trebuie sa fie pozitiv.\n";
        }
        if (option==2)
        {
            Gestiune <apartament> x;
            cin>>x;
            cout<<x;
        }
        if(option==3)
        {
            Gestiune <casa> x;
            cin>>x;
            cout<<x;
        }
        if(option==4)
        {
            int nr_apartamente,nr_case;
            nr_apartamente=nr_case=0;
            if (n>0){
            for(int i=0;i<n;i++)
            {
                ///incerc cast catre apartament
                apartament *p1=dynamic_cast<apartament*>(v[i]);
                ///incerc cast catre casa
                casa *p2=dynamic_cast<casa*>(v[i]);
                ///daca sunt nenuli atunci incrementez corespunzator
                if (p1)
                    nr_apartamente++;
                if (p2)
                    nr_case++;
            }
            cout<<"Numarul de apartamente: "<<nr_apartamente<<"\n";
            cout<<"Numarul de case: "<<nr_case<<"\n";}
            else{
                cout<<"Nu s-au citit locuinte. Reveniti la actiunea 1.\n";
            }
        }
        if(option==5)
        {
            string s;
            cout<<"\nIntroduceti tipul de data pe care vreti sa il introduceti cu operatorul += :";
            cin>>s;
            try
            {
                if(s=="casa")
                {
                    Gestiune <casa> x;
                    cin>>x;
                    int numar;
                    cout<<"Introduceti numarul de elemente pe care il vreti sa il adaugati cu operatorul += ";
                    cin>>numar;
                    x+=numar;
                    cout<<x;
                }
                else
                    if(s=="apartament")
                {
                    Gestiune <apartament> x;
                    cin>>x;
                    int numar;
                    cout<<"Introduceti numarul de elemente pe care il vreti sa il adaugati cu operatorul += ";
                    cin>>numar;
                    x+=numar;
                    cout<<x;
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
                cout<<"Nu ati introdus un tip valid. Incercati casa sau apartament.\n ";
            }
        }
        if(option==6)
        {
            Gestiune <casa> x;
            cin>>x;

            x.chirie();
            cout<<endl;


            cout<<"Chirie totala ";
            Gestiune<casa>::total();
            cout<<endl;
        }
        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
        if (option<0||option>6)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
int main()
{

    menu();
    return 0;
}
