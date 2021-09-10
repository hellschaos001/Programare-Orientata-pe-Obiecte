#include <iostream>
#include <stdlib.h>
using namespace std;

class contract{
protected:
    int nrContract;
    int anul;
    string beneficiar;
    string furnizor;
    int valoare;

    static int n;
public:
    contract(int, int, string, string, int);
    contract(contract&);
    virtual ~contract();

    virtual void citire(istream &in); /// citire virtuala - late binding
    virtual void afisare(ostream &out); /// afisare virtuala - late binding

    friend istream& operator>>(istream&, contract&); /// supraincarcarea pe >>
    friend ostream& operator<<(ostream&, contract&); /// supraincarcarea pe <<
    contract& operator=(contract &c); /// supraincarcarea operatorului de atribuire

    static int numar_Contracte()
    {
        return n;
    }
};
int contract::n;

///-------------------------------------
///constructor initializare cu parametrii
contract::contract(int nrContract=0, int anul=0, string beneficiar="", string furnizor="", int valoare=0)
{
    n++;
    nrContract=nrContract;
    anul=anul;
    beneficiar=beneficiar;
    furnizor=furnizor;
    valoare=valoare;
}

///--------------------------------------
///destructor
contract::~contract()
{
    nrContract=0;
    anul=0;
    beneficiar="";
    furnizor="";
    valoare=0;
}

///---------------------------------------
///constructor copiere
contract::contract(contract &c)
{
    nrContract=c.nrContract;
    anul=c.anul;
    beneficiar=c.beneficiar;
    furnizor=c.furnizor;
    valoare=c.valoare;
}


///----------------------------------------
///citire contract
istream& operator>>(istream& in, contract& c)
{
    c.citire(in);
    return in;
}
void contract::citire(istream &in)
{
    cout<<"numar contract:";
    in>>nrContract;
    cout<<endl;

    cout<<"anul semnarii contractului de cumparare:";
    in>>anul;
    cout<<endl;

    cout<<"numele cumparatorului/beneficiarului:";
    in.get();
    getline(in,beneficiar);
    cout<<endl;

    cout<<"numele vanzatorului/ofertant/furnizor:";
    getline(in,furnizor);
    cout<<endl;

    cout<<"valoarea totala a produsului:";
    in>>valoare;
    cout<<endl;
}

///-------------------------------------
///afisare contract
ostream& operator<<(ostream& out,contract& c)
{
    c.afisare(out);
    return out;
}
void contract::afisare(ostream &out)
{
    out<<"----------------------------------------------------"<<endl;
    out<<"numar contract:"<<nrContract<<endl;
    out<<"anul semnarii contractului de cumparare:"<<anul<<endl;
    out<<"numele cumparatorului/beneficiarului:"<<beneficiar<<endl;
    out<<"numele vanzatorului/ofertant/furnizor:"<<furnizor<<endl;
    out<<"valoarea totala a produsului:"<<valoare<<endl;
}

///------------------------------------------------------------------
///supraincarcarea operatorului de atribuire
contract& contract::operator=(contract &c)
{
    nrContract=c.nrContract;
    anul=c.anul;
    beneficiar=c.beneficiar;
    furnizor=c.furnizor;
    valoare=c.valoare;
}
class contractInchiriere:public contract{
protected:
    int perioada;
    static int n;
public:
    contractInchiriere(int, int, string, string, int, int); ///constructor de initializare cu parametrii
    ~contractInchiriere();  ///destructor
    contractInchiriere(contractInchiriere&);    ///contructor copiere

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, contractInchiriere&);
    friend ostream& operator<<(ostream&, contractInchiriere&);
    contractInchiriere& operator=(contractInchiriere &c);

    static int numar_contracteInchirere()
    {
        return n;
    }

    int get_perioada(){return this->perioada;}
    int get_valoare(){return this->valoare;}
    int get_nrContract(){return this->nrContract;}
};
int contractInchiriere::n;

///-----------------------------------------
///constructor de initializare cu parametrii
contractInchiriere::contractInchiriere(int nrContract=0, int anul=0, string beneficiar="", string furnizor="", int valoare=0, int perioada=0):contract(nrContract,anul,beneficiar,furnizor,valoare)
{
    n++;
    perioada=perioada;
}

///-----------------------------------------
///destructor

contractInchiriere::~contractInchiriere(){
}

///-----------------------------------------
///constructor copiere
contractInchiriere::contractInchiriere(contractInchiriere &c)
{
    nrContract=c.nrContract;
    anul=c.anul;
    beneficiar=c.beneficiar;
    furnizor=c.furnizor;
    valoare=c.valoare;
    perioada=c.perioada;
}

///-----------------------------------------
///citire contract inchiriere
istream& operator>>(istream& in,contractInchiriere& c)
{
    c.citire(in);
    return in;
}
void contractInchiriere::citire(istream& in)
{
    contract::citire(in);
    cout<<"perioada contractului exprimata in numar de luni:";
    in>>perioada;
}

///------------------------------------------
///afisare contract inchiriere
ostream& operator<<(ostream& out,contractInchiriere& c)
{
    c.afisare(out);
    return out;
}
void contractInchiriere::afisare(ostream& out)
{
    contract::afisare(out);
    out<<"perioada contractului exprimata in numar de luni:"<<perioada<<endl;
    out<<"----------------------------------------------------"<<endl;
}

///----------------------------------------
///supraincarcarea operatorului de atribuire
contractInchiriere& contractInchiriere::operator=(contractInchiriere &c)
{
    nrContract=c.nrContract;
    anul=c.anul;
    beneficiar=c.beneficiar;
    furnizor=c.furnizor;
    valoare=c.valoare;
    perioada=c.perioada;
}

class dosar{
private:
    int nr_contracteDosar;
    contractInchiriere *(*d);


public:
    dosar(int);
    ~dosar();
    dosar(dosar&);

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream &in, dosar& d);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, dosar& d);  ///supraincarcare pe <<
    dosar& operator=(dosar &d);

    int get_total(int i)
    {
        return d[i]->get_valoare() * d[i]->get_perioada();
    }
    int get_nrContract(int i)
    {
        return d[i]->get_nrContract();
    }
};
dosar::dosar(int nr_contracteDosar=0)
{
    nr_contracteDosar=nr_contracteDosar;
    d = nullptr;
}
dosar::~dosar()
{
    nr_contracteDosar=0;
    delete []d;
}
dosar::dosar(dosar &c)
{
    nr_contracteDosar=c.nr_contracteDosar;
    for(int i=0;i<nr_contracteDosar;i++)
        d[i]=c.d[i];
}

istream& operator>>(istream& in, dosar& d)
{
    d.citire(in);
    return in;
}
void dosar::citire(istream &in)
{
    cout<<"numar contracte intr-un dosar:";
    cin>>nr_contracteDosar;
    cout<<endl;

    d=new contractInchiriere* [nr_contracteDosar];
    for(int i=0; i<nr_contracteDosar; i++)
    {
        d[i] = new contractInchiriere;
        cin>> *(d[i]);
    }
}

ostream& operator<<(ostream& out, dosar& d)
{
    d.afisare(out);
    return out;
}
void dosar::afisare(ostream& out)
{
    for(int i=0; i<nr_contracteDosar; i++)
    {
        cout<< *(d[i]);
    }
}
dosar& dosar::operator=(dosar &c)
{
    nr_contracteDosar=c.nr_contracteDosar;
    for(int i=0;i<nr_contracteDosar;i++)
        d[i]=c.d[i];
}
///-------------------------------------------------
///meniul preluat de la lab.
void menu_output(){
    cout<<"\n Nume Prenume Grupa - Proiect - Nume proiect: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Cititi contractele de inchiriere din dosar"; cout<<"\n";
    cout<<"2. Afisati contractele de inchiriere din dosar"; cout<<"\n";
    cout<<"3. Calculati valoarea incasata pentru fiecare contract in functie de perioada, respectiv valoarea totala incasata"; cout<<"\n";
    cout<<"4. Verificati numarul de contracte de inchiriere"; cout<<"\n";
    cout<<"5. Exemplu upcasting"<<endl;
    cout<<"6. Exemplu downcasting"<<endl;
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    dosar d;
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            cin>>d;
        }
        if (option==2)
        {
            cout<<d;
        }
        if (option==3)
        {
            for(int i=0;i<contractInchiriere::numar_contracteInchirere();i++)
                cout<<"valoarea totala incasata a contractului cu id-ul "<<d.get_nrContract(i)<<" este "<<d.get_total(i)<<endl;
        }
        if (option==4)
        {
            cout<<"exista "<<contractInchiriere::numar_contracteInchirere()<<" contracte de inchiriere"<<endl;
        }
        if (option==5)
        {
            contract *x=new contractInchiriere;
            cin>>*x;
            cout<<*x;
        }
        if (option==6)
        {
            contractInchiriere *x=(contractInchiriere*)new contract;
            cin>>*x;
            cout<<*x;
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
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
