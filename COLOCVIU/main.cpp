/*Preda Alexandru-Florin, grupa 253
CodeBlock 20.03
Tutore laborator: Gusatu Marian*/


#include <bits/stdc++.h>
using namespace std;

class jucarie
{
protected:
    string denumire;
    int dimensiune;
    string tip;
public:
    jucarie(string, int, string);
    virtual ~jucarie();
    jucarie(const jucarie&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, jucarie&);
    friend istream& operator>>(istream& in, jucarie&);
};

jucarie::jucarie(string denumire="", int dimensiune=0, string tip="")
{
    this->denumire = denumire;
    this->dimensiune = dimensiune;
    this->tip = tip;
}

jucarie::~jucarie()
{
    denumire="";
    dimensiune=0;
    tip="";
}

jucarie::jucarie(const jucarie &j)
{
    denumire=j.denumire;
    dimensiune=j.dimensiune;
    tip=j.tip;
}

istream& operator>>(istream& in ,jucarie& j)
{
    j.citire(in);
    return in;
}
void jucarie::citire(istream& in)
{
    cout<<"Denumire:";
    in>>denumire;
    cout<<"Dimensiune:";
    in>>dimensiune;
    cout<<"Tip:";
    in>>tip;
}

ostream& operator<<(ostream& out,jucarie& l)
{
    l.afisare(out);
    return out;
}
void jucarie::afisare(ostream& out)
{
    out<<"Denumirea jucariei:"<<denumire<<endl;
    out<<"Dimensiunea jucariei:"<<dimensiune<<endl;
    out<<"Tipul jucariei:"<<tip<<endl;
}
///------------------------------------------------------------------------
class jucarieClasica:public jucarie
{
private:
    string material;
    string culoare;
public:
    jucarieClasica(string, int, string, string, string);
    ~jucarieClasica();
    jucarieClasica(const jucarieClasica&);

        virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, jucarieClasica&);
    friend istream& operator>>(istream& in, jucarieClasica&);
};

jucarieClasica::jucarieClasica(string denumire="", int dimensiune=0, string tip="", string material="", string culoare=""):jucarie(denumire,dimensiune,tip)
{
    this->material=material;
    this->culoare=culoare;
}

jucarieClasica::~jucarieClasica()
{
    material="";
    culoare="";
}
jucarieClasica::jucarieClasica(const jucarieClasica &j)
{
    material=j.material;
    culoare=j.culoare;
}

void jucarieClasica::citire(istream &in){
    jucarie::citire(in);
    cout<<"Material jucariei clasice:";
    in>>material;

    cout<<"Culoarea jucariei clasice:";
    in>>culoare;
}
istream& operator>>(istream &in ,jucarieClasica& a){
    a.citire(in);
    return in;
}

void jucarieClasica::afisare(ostream &out){
    jucarie::afisare(out);

    cout<<"Materialul jucariei clasice:"<<material<<endl;
    cout<<"Culoarea jucariei clasice:"<<culoare<<endl;
}
ostream& operator<<(ostream &out ,jucarieClasica& a){
    a.afisare(out);
    return out;
}
///-------------------------------------------------------------
class jucarieEducativa:public virtual jucarie
{
protected:
    string abilitate_dezvoltata;
public:
    jucarieEducativa(string, int, string, string);
    virtual ~jucarieEducativa();
    jucarieEducativa(const jucarieEducativa&);

        virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, jucarieEducativa&);
    friend istream& operator>>(istream& in, jucarieEducativa&);
};

jucarieEducativa::jucarieEducativa(string denumire="", int dimensiune=0, string tip="", string abilitate_dezvoltata=""):jucarie(denumire,dimensiune,tip)
{
    this->abilitate_dezvoltata=abilitate_dezvoltata;

}
jucarieEducativa::~jucarieEducativa()
{
    abilitate_dezvoltata="";
}
jucarieEducativa::jucarieEducativa(const jucarieEducativa &j)
{
    abilitate_dezvoltata=j.abilitate_dezvoltata;
}

void jucarieEducativa::citire(istream &in){
    jucarie::citire(in);
    cout<<"Abilitatea dezvoltata de jucaria educativa:";
    in.get();
    string z;
    getline(in,z);
    abilitate_dezvoltata=z;
}
istream& operator>>(istream &in ,jucarieEducativa& a){
    a.citire(in);
    return in;
}

void jucarieEducativa::afisare(ostream &out){
    jucarie::afisare(out);

    cout<<"Abilitatea dezvoltata de jucaria educativa:"<<abilitate_dezvoltata<<endl;
}
ostream& operator<<(ostream &out ,jucarieEducativa& a){
    a.afisare(out);
    return out;
}
///----------------------------------------

class jucarieElectronica:public virtual jucarie
{
protected:
    int nr_baterii;
public:
    jucarieElectronica(string, int, string, int);
    virtual ~jucarieElectronica();
    jucarieElectronica(jucarieElectronica&);

        virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, jucarieElectronica&);
    friend istream& operator>>(istream& in, jucarieElectronica&);
};

jucarieElectronica::jucarieElectronica(string denumire="", int dimensiune=0, string tip="", int nr_baterii=0):jucarie(denumire,dimensiune,tip)
{
    this->nr_baterii=nr_baterii;
}
jucarieElectronica::~jucarieElectronica()
{
    nr_baterii=0;
}
jucarieElectronica::jucarieElectronica(jucarieElectronica &j)
{
    nr_baterii=j.nr_baterii;
}

void jucarieElectronica::citire(istream &in){
    jucarie::citire(in);
    cout<<"Numarul de baterii al jucariei electronice:";
    in>>nr_baterii;
}
istream& operator>>(istream &in ,jucarieElectronica& a){
    a.citire(in);
    return in;
}

void jucarieElectronica::afisare(ostream &out){
    jucarie::afisare(out);

    cout<<"Numarul de baterii al jucariei electronice:"<<nr_baterii<<endl;
}
ostream& operator<<(ostream &out ,jucarieElectronica& a){
    a.afisare(out);
    return out;
}
///------------------------------------------------------------------

class jucarieModerna:public jucarieEducativa,jucarieElectronica
{
private:
    string brand;
    string model;
    const int nr_baterii=1;
    const string abilitate_dezvoltata="generală";
public:
    jucarieModerna(string, int, string, string, string, int, string );
    virtual ~jucarieModerna();
    jucarieModerna(jucarieModerna&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, jucarieModerna&);
    friend istream& operator>>(istream& in, jucarieModerna&);
};

jucarieModerna::jucarieModerna(string denumire="", int dimensiune=0, string tip="", string brand="", string model="", int nr_baterii=0, string abilitate_dezvoltata=""):jucarie(denumire,dimensiune,tip),jucarieEducativa(denumire,dimensiune,tip,abilitate_dezvoltata),jucarieElectronica(denumire,dimensiune,tip,nr_baterii)
{
    this->brand=brand;
    this->model=model;
}
jucarieModerna::~jucarieModerna()
{
    brand="";
    model="";
}
jucarieModerna::jucarieModerna(jucarieModerna &j)
{
    brand=j.brand;
    model=j.model;
}

void jucarieModerna::citire(istream &in){
    jucarie::citire(in);

    cout<<"Bradul jucariei moderne:";
    in>>brand;

    cout<<"Modelul jucariei moderne:";
    in>>model;
}
istream& operator>>(istream &in ,jucarieModerna& a){
    a.citire(in);
    return in;
}

void jucarieModerna::afisare(ostream &out){
    jucarie::afisare(out);
    out<<"Numarul bateriilor:"<<nr_baterii<<endl;

    out<<"Abilitatea dezvoltata:"<<abilitate_dezvoltata<<endl;

    out<<"Bradul jucariei moderne:"<<brand<<endl;

    out<<"Modelul jucariei moderne:"<<model<<endl;


}
ostream& operator<<(ostream &out ,jucarieModerna& a){
    a.afisare(out);
    return out;
}

///======================================================================


class copii
{
protected:
    static int id;
    string nume;
    string prenume;
    string adresa;
    int varsta;
    int fapte_bune;
    vector<jucarie*> jucarii;
public:
    copii(string, string, string, int, int,vector<jucarie>);
    virtual ~copii();
    copii(const copii&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, jucarie&);
    friend istream& operator>>(istream& in, jucarie&);

    string get_nume(){return nume;}
    int get_varsta(){return varsta;}

    bool operator<(copii &z)
    {
        return varsta<z.get_varsta();
    }
};

copii::copii(string nume="",string prenume="",string adresa="",int varsta=0,int fapte_bune=0, vector<jucarie> jucarii= vector<jucarie>())
{
    this->nume=nume;
    this->prenume=prenume;
    this->adresa=adresa;
    this->varsta=varsta;
    this->fapte_bune=fapte_bune;
//    this->jucarii=jucarii;
}
copii::~copii()
{
    nume="";
    prenume="";
    adresa="";
    varsta=0;
    fapte_bune=0;
    jucarii.clear();
}

copii::copii(const copii &c)
{
    nume=c.nume;
    prenume=c.prenume;
    adresa=c.adresa;
    varsta=c.varsta;
    fapte_bune=c.fapte_bune;
    jucarii=c.jucarii;
}


istream& operator>>(istream& in ,copii& c)
{
    c.citire(in);
    return in;
}
void copii::citire(istream& in)
{
    cout<<"Numele copilului:";
    in>>nume;

    cout<<"Prenumele copilului:";
    in>>prenume;

    cout<<"Adresa copilului:";
    in.get();
    string z;
    getline(in,z);
    adresa=z;

    cout<<"Varsta copilului:";
    in>>varsta;
    try
    {
    cout<<"Numarul de fapte bune facute de copil:";
    in>>fapte_bune;
    if(fapte_bune<10)
        throw 1;
    }
    catch(int j)
    {
        cout<<"Un copil trebuie sa aiba minim 10 fapte bune facute, introduceti o valoare mai mare de 10.";
    }


    cout<<"jucariile primite:";
    for(int i=0;i<fapte_bune;i++)
    {
        cout<<"Tipul jucariei primite:"<<endl;
        cout<<"(1)-jucarie clasica,(2)-jucarie educativa,(3)-jucarie electronica,(4)-jucarie moderna"<<endl;
        int k;
        in>>k;
        jucarie *aux;

            if(k==1)
            {
                aux = new jucarie;
                cin>>*aux;
                jucarii.push_back(*&aux);
            }
            else
                if(k==2)
            {
                aux=new jucarieEducativa ;
                cin>>*aux;
                jucarii.push_back(aux);
            }
            else
                if(k==3)
            {
                aux = new jucarieElectronica;
                cin>>*aux;
                jucarii.push_back(*&aux);
            }
            else
                if(k==4)
            {
                aux = new jucarieModerna;
                cin>>*aux;
                jucarii.push_back(*&aux);
            }
            else
                cout<<"Nu ati introdus in tip de data existenta, incerca 1, 2, 3 sau 4"<<endl;
    }
}

bool compare(const copii& a, const copii& b)
{
//    return a.get_varsta()<b.get_varsta();
}
ostream& operator<<(ostream& out,copii& c)
{
    c.afisare(out);
    return out;
}
void copii::afisare(ostream& out)
{
    out<<"Numele copilului: "<<nume<<endl;
    out<<"Prenumele copilului:"<<prenume<<endl;
    out<<"Adresa copilului:"<<adresa<<endl;
    out<<"Varsta copilului:"<<varsta<<endl;
    out<<"Numarul de fapte bune facute de copil:"<<fapte_bune<<endl;
    out<<"Jucarii primite:"<<endl;
    for(auto i=jucarii.begin();i!=jucarii.end();i++)
        out<<(**i);
}
///----------------------------------------------
class copiiCuminti:public copii
{
private:
    int nr_dulciuri;
public:
    copiiCuminti(string, string, string, int, int,vector<jucarie>, int);
    ~copiiCuminti();
    copiiCuminti(const copiiCuminti&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, copiiCuminti&);
    friend istream& operator>>(istream& in, copiiCuminti&);
};

copiiCuminti::copiiCuminti(string nume="",string prenume="",string adresa="",int varsta=0,int fapte_bune=0, vector<jucarie> jucarii= vector<jucarie>(),int nr_dulciuri=0):copii(nume,prenume,adresa,varsta,fapte_bune,jucarii)
{
    this->nr_dulciuri=nr_dulciuri;
}
copiiCuminti::~copiiCuminti()
{
    nr_dulciuri=nr_dulciuri;
}

copiiCuminti::copiiCuminti(const copiiCuminti &j)
{
    nr_dulciuri=nr_dulciuri;
}

void copiiCuminti::citire(istream &in){
    copii::citire(in);
    cout<<"Numarul de dulciuri primite de un copil cuminte:";
    in>>nr_dulciuri;
}
istream& operator>>(istream &in ,copiiCuminti& a){
    a.citire(in);
    return in;
}

void copiiCuminti::afisare(ostream &out){
    copii::afisare(out);

    cout<<"Numarul de dulciuri primite de un copil cuminte:"<<nr_dulciuri<<endl;
}
ostream& operator<<(ostream &out ,copiiCuminti& a){
    a.afisare(out);
    return out;
}
///---------------------------------------------------------------------------

class copiiNeastamparati:public copii
{
private:
    int nr_carbuni;
public:
    copiiNeastamparati(string, string, string, int, int,vector<jucarie>, int);
    ~copiiNeastamparati();
    copiiNeastamparati(const copiiNeastamparati&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, copiiNeastamparati&);
    friend istream& operator>>(istream& in, copiiNeastamparati&);
};

copiiNeastamparati::copiiNeastamparati(string nume="",string prenume="",string adresa="",int varsta=0,int fapte_bune=0, vector<jucarie> jucarii= vector<jucarie>(),int nr_carbuni=0):copii(nume,prenume,adresa,varsta,fapte_bune,jucarii)
{
    this->nr_carbuni=nr_carbuni;
}
copiiNeastamparati::~copiiNeastamparati()
{
    nr_carbuni=nr_carbuni;
}

copiiNeastamparati::copiiNeastamparati(const copiiNeastamparati &j)
{
    nr_carbuni=nr_carbuni;
}

void copiiNeastamparati::citire(istream &in){
    copii::citire(in);
    cout<<"Numarul de carbuni primiti de un copil cuminte:";
    in>>nr_carbuni;
}
istream& operator>>(istream &in ,copiiNeastamparati& a){
    a.citire(in);
    return in;
}

void copiiNeastamparati::afisare(ostream &out){
    copii::afisare(out);

    cout<<"Numarul de carbuni primiti de un copil cuminte:"<<nr_carbuni<<endl;
}
ostream& operator<<(ostream &out ,copiiNeastamparati& a){
    a.afisare(out);
    return out;
}













int main()
{
    vector<copii*>cp;
    copii* c;

    int x = 1;
    while(x != 0)
    {
        cout<<"Alegeti operatia pe care doriti sa o efectuati: "<<'\n';
        cout<<"0 - inchidere program"<<'\n';
        cout<<"1. Sa permita memorarea, citirea și afisarea a n copii (indiferent ca sunt cuminti sau neastamparati)."<<endl;
        cout<<"2. Sa permita pentru fiecare copil memorarea, citirea și afisarea a m jucării (indiferent de tipul acestora)"<<endl;
        cout<<"3. Sa permita mosului sa gaseasca un copil dupa nume."<<'\n';
        cout<<"4 "<<'\n';
        cin>>x;
        if(x == 1)
        {
            int n;
            cout<<"Dati numarul de copii:";
            cin>>n;
            for(int i=0;i<n;i++)
                {
                    c = new copii;
                    cin>>*c;
                    cp.push_back(c);
                    cout<<"--------------------------";
                    cout<<*c;
                }
        }
        else if(x == 2)
        {
            ///citirea si afisarea jucariilor este efectuata la pasul 1, o data cu copii
        }
        else if(x == 3)
        {
            for (int i = 0; i < cp.size(); i++)
            {
                copii* M1 = dynamic_cast<copii*>(cp[i]);

                string gasiti;
                cout<<"Introduceti copilul pe care vrei sa il cautati dupa nume:";
                cin>>gasiti;
                if(M1 && M1->get_nume()==gasiti)
                    cout << M1->get_nume()<<endl;
            }
        }

        else
            cout<<"Introduceti o valoare intre 0 si 4"<<'\n';
        system("pause");
        system("cls");

    }

    return 0;
}
