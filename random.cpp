#include <iostream>
#include <list>
#include <bits/stdc++.h>
using namespace std;
ofstream g("test.out");

class produse
{
protected:
    int pret;
    string denumire;
    string producator;
public:
    produse(int, string, string);
    virtual ~produse();
    produse(const produse &);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    int get_pret(){return pret;}

    friend ostream& operator<<(ostream& out, produse&);
    friend istream& operator>>(istream& in, produse&);
};

produse::produse(int pret=0, string denumire="", string producator="")
{
    this->pret = pret;
    this->denumire = denumire;
    this->producator = producator;
}

produse::~produse()
{
    pret=0;
    denumire="";
    producator="";
}
produse::produse(const produse& p)
{
    pret=p.pret;
    denumire=p.denumire;
    producator=p.producator;
}

istream& operator>>(istream& in ,produse& p)
{
    p.citire(in);
    return in;
}
void produse::citire(istream& in)
{
    cout<<"Pret:";
    in>>pret;
    cout<<"Denumire:";
    in.get();
    string z;
    getline(in,z);
    denumire=z;
    cout<<"Producator:";
    in>>producator;
}

ostream& operator<<(ostream& out,produse& p)
{
    p.afisare(out);
    return out;
}
void produse::afisare(ostream& out)
{
    out<<"Pretul:"<<pret<<endl;
    out<<"Denumirea:"<<denumire<<endl;
    out<<"Producator:"<<producator<<endl;
}

///==============================================
class laptop:public produse
{
protected:
    int greutate;
    string componente;
public:
    laptop(int,string,string,int,string);
    ~laptop();
    laptop(const laptop&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, laptop&);
    friend istream& operator>>(istream& in, laptop&);
};
laptop::laptop(int pret=0, string denumire="", string producator="", int greutate=0, string componente=""):produse(pret,denumire,producator)
{
    this->greutate=greutate;
    this->componente=componente;
}

laptop::~laptop()
{
    greutate=0;
    componente="";
}
laptop::laptop(const laptop &l)
{
    greutate=l.greutate;
    componente=l.componente;
}

void laptop::citire(istream &in){
    produse::citire(in);

    cout<<"Greutatea laptopului:";
    in>>greutate;

    cout<<"Componentele laptopului:";
    in.get();
    string z;
    getline(in,z);
    componente=z;
}
istream& operator>>(istream &in ,laptop& l){
    l.citire(in);
    return in;
}

void laptop::afisare(ostream &out){
    produse::afisare(out);

    out<<"Greutatea laptopului:"<<greutate<<endl;
    out<<"Componentele laptopului:"<<componente<<endl;
}
ostream& operator<<(ostream &out ,laptop& a){
    a.afisare(out);
    return out;
}
///----------------------------------------------
class laptopGaming:public laptop
{
private:
    string performanta;
public:
    laptopGaming(int,string,string,int,string,string);
    ~laptopGaming();
    laptopGaming(const laptopGaming&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, laptopGaming&);
    friend istream& operator>>(istream& in, laptopGaming&);
};

laptopGaming::laptopGaming(int pret=0, string denumire="", string producator="", int greutate=0, string componente="",string performanta=""):laptop(pret,denumire,producator,greutate,componente)
{
    this->performanta=performanta;
}

laptopGaming::~laptopGaming()
{
    performanta="";
}

laptopGaming::laptopGaming(const laptopGaming &l)
{
    performanta=l.performanta;
}

void laptopGaming::citire(istream &in){
    laptop::citire(in);

    cout<<"Performanta laptopului:";

    string z;
    getline(in,z);
    performanta=z;
}
istream& operator>>(istream &in ,laptopGaming& l){
    l.citire(in);
    return in;
}

void laptopGaming::afisare(ostream &out){
    laptop::afisare(out);

    out<<"Performanta laptopului:"<<performanta<<endl;
}

ostream& operator<<(ostream &out,laptopGaming& l)
{
    l.afisare(out);
    return out;
}
///----------------------------------------------

class laptopUltraportabil:public laptop
{
private:
    int durabilitate_baterie;
public:
    laptopUltraportabil(int,string,string,int,string,int);
    ~laptopUltraportabil();
    laptopUltraportabil(const laptopUltraportabil&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, laptopUltraportabil&);
    friend istream& operator>>(istream& in, laptopUltraportabil&);
};
laptopUltraportabil::laptopUltraportabil(int pret=0, string denumire="", string producator="", int greutate=0, string componente="",int durabilitate_baterie=0):laptop(pret,denumire,producator,greutate,componente)
{
    this->durabilitate_baterie=durabilitate_baterie;
}

laptopUltraportabil::~laptopUltraportabil()
{
    durabilitate_baterie=0;
}

laptopUltraportabil::laptopUltraportabil(const laptopUltraportabil &l)
{
    durabilitate_baterie=l.durabilitate_baterie;
}

void laptopUltraportabil::citire(istream &in){
    laptop::citire(in);

    cout<<"Autonomia bateriei laptopului(numar de ore):";
    in>>durabilitate_baterie;
}
istream& operator>>(istream &in ,laptopUltraportabil& l){
    l.citire(in);
    return in;
}

void laptopUltraportabil::afisare(ostream &out){
    laptop::afisare(out);

    out<<"Autonomia bateriei laptopului(numar de ore):"<<durabilitate_baterie<<endl;
}
ostream& operator<<(ostream &out,laptopUltraportabil& l)
{
    l.afisare(out);
    return out;
}





///----------------------------------------------
class laptopHome:public laptop
{
private:
    int capacitate_stocare;
public:
    laptopHome(int,string,string,int,string,int);
    ~laptopHome();
    laptopHome(const laptopHome&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, laptopHome&);
    friend istream& operator>>(istream& in, laptopHome&);
};
laptopHome::laptopHome(int pret=0, string denumire="", string producator="", int greutate=0, string componente="",int capacitate_stocare=0):laptop(pret,denumire,producator,greutate,componente)
{
    this->capacitate_stocare=capacitate_stocare;
}

laptopHome::~laptopHome()
{
    capacitate_stocare=0;
}

laptopHome::laptopHome(const laptopHome &l)
{
    capacitate_stocare=l.capacitate_stocare;
}

void laptopHome::citire(istream &in){
    laptop::citire(in);

    cout<<"Capacitate de stocare(Gb):";
    in>>capacitate_stocare;
}
istream& operator>>(istream &in ,laptopHome& l){
    l.citire(in);
    return in;
}

void laptopHome::afisare(ostream &out){
    laptop::afisare(out);

    out<<"Capacitate de stocare(Gb):"<<capacitate_stocare<<endl;
}
ostream& operator<<(ostream &out,laptopHome& l)
{
    l.afisare(out);
    return out;
}

///===================================================

class tastatura:public produse
{
private:
    bool taste_iluminate;
    string culoare;
public:
    tastatura(int,string,string,bool,string);
    ~tastatura();
    tastatura(const tastatura&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, tastatura&);
    friend istream& operator>>(istream& in, tastatura&);
};
tastatura::tastatura(int pret=0, string denumire="", string producator="", bool taste_iluminate=false ,string culoare=""):produse(pret,denumire,producator)
{
    this->taste_iluminate=taste_iluminate;
    this->culoare=culoare;
}

tastatura::~tastatura()
{
    taste_iluminate=false;
    culoare="";
}

tastatura::tastatura(const tastatura &l)
{
    taste_iluminate=l.taste_iluminate;
    culoare=l.culoare;
}

void tastatura::citire(istream &in){
    produse::citire(in);

    cout<<"Tastatura iluminata?(da/nu):";
    string aux;
    in>>aux;
        if(aux=="da")
        taste_iluminate=true;
    else
        taste_iluminate=false;

    cout<<"Culoare tastatura:";
    in>>culoare;
}
istream& operator>>(istream &in ,tastatura& l){
    l.citire(in);
    return in;
}

void tastatura::afisare(ostream &out){
    produse::afisare(out);

    if(taste_iluminate==true)
        out<<"Tastatura ESTE iluminata"<<endl;
    else
        out<<"Tastatura NU ESTE iluminata"<<endl;

    out<<"Culoare tastatura:"<<culoare<<endl;
}
ostream& operator<<(ostream &out,tastatura& l)
{
    l.afisare(out);
    return out;
}
///--------------------------------------------------
class tastaturaMultimedia:public tastatura
{
private:
    int nr_taste_programabile;
public:
    tastaturaMultimedia(int,string,string,bool,string,int);
     ~tastaturaMultimedia();
    tastaturaMultimedia(const tastaturaMultimedia&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, tastaturaMultimedia&);
    friend istream& operator>>(istream& in, tastaturaMultimedia&);
};
tastaturaMultimedia::tastaturaMultimedia(int pret=0, string denumire="", string producator="", bool taste_iluminate=false ,string culoare="", int nr_taste_programabile=0):tastatura(pret,denumire,producator,taste_iluminate,culoare)
{
    this->nr_taste_programabile=nr_taste_programabile;
}

tastaturaMultimedia::~tastaturaMultimedia()
{
    nr_taste_programabile=0;
}

tastaturaMultimedia::tastaturaMultimedia(const tastaturaMultimedia &l)
{
    nr_taste_programabile=l.nr_taste_programabile;
}

void tastaturaMultimedia::citire(istream &in){
    tastatura::citire(in);

    cout<<"Numar taste programabile:";
    in>>nr_taste_programabile;
}
istream& operator>>(istream &in ,tastaturaMultimedia& l){
    l.citire(in);
    return in;
}

void tastaturaMultimedia::afisare(ostream &out){
    tastatura::afisare(out);

    out<<"Numar taste programabile:"<<nr_taste_programabile<<endl;
}
ostream& operator<<(ostream &out,tastaturaMultimedia& l)
{
    l.afisare(out);
    return out;
}
///---------------------------------------------------------
class tastaturaTouch:public tastatura
{
private:
    int dimensiune_touch;
public:
    tastaturaTouch(int,string,string,bool,string,int);
    ~tastaturaTouch();
    tastaturaTouch(const tastaturaTouch&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, tastaturaTouch&);
    friend istream& operator>>(istream& in, tastaturaTouch&);
};
tastaturaTouch::tastaturaTouch(int pret=0, string denumire="", string producator="", bool taste_iluminate=false ,string culoare="", int dimensiune_touch=0):tastatura(pret,denumire,producator,taste_iluminate,culoare)
{
    this->dimensiune_touch=dimensiune_touch;
}

tastaturaTouch::~tastaturaTouch()
{
    dimensiune_touch=0;
}

tastaturaTouch::tastaturaTouch(const tastaturaTouch &l)
{
    dimensiune_touch=l.dimensiune_touch;
}

void tastaturaTouch::citire(istream &in){
    tastatura::citire(in);

    cout<<"Numar taste programabile:";
    in>>dimensiune_touch;
}
istream& operator>>(istream &in ,tastaturaTouch& l){
    l.citire(in);
    return in;
}

void tastaturaTouch::afisare(ostream &out){
    tastatura::afisare(out);

    out<<"Numar taste programabile:"<<dimensiune_touch<<endl;
}
ostream& operator<<(ostream &out,tastaturaTouch& l)
{
    l.afisare(out);
    return out;
}
///===============================================
class mouse:public produse
{
private:
    bool iluminare;
    bool design;
    int greutate;
public:
    mouse(int,string,string,bool,bool,int);
    ~mouse();
    mouse(const mouse&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, mouse&);
    friend istream& operator>>(istream& in, mouse&);
};
mouse::mouse(int pret=0, string denumire="", string producator="", bool iluminare=false ,bool design=false, int greutate=0):produse(pret,denumire,producator)
{
    this->iluminare=iluminare;
    this->design=design;
    this->greutate=greutate;
}

mouse::~mouse()
{
    iluminare=false;
    design=false;
    greutate=0;
}

mouse::mouse(const mouse &l)
{
    iluminare=l.iluminare;
    design=l.design;
    greutate=l.greutate;
}

void mouse::citire(istream &in){
    produse::citire(in);

    cout<<"Mouse iluminat?(da/nu):";
    string aux1;
    in>>aux1;
        if(aux1=="da")
        iluminare=true;
    else
        iluminare=false;

    cout<<"Design?(stangaci/dreptaci):";
    string aux2;
    in>>aux2;
        if(aux2=="dreptaci")
        design=true;
    else
        design=false;

    cout<<"Greutate mouse:";
    in>>greutate;
}
istream& operator>>(istream &in ,mouse& l){
    l.citire(in);
    return in;
}
void mouse::afisare(ostream &out){
    produse::afisare(out);

    if(iluminare==true)
        out<<"Mouse-ul ESTE iluminat."<<endl;
    else
        out<<"Mouse-ul NU ESTE iluminat."<<endl;

    if(design==true)
        out<<"Mouse-ul este pentru DREPTACI."<<endl;
    else
        out<<"Mouse-ul este pentru STANGACI."<<endl;


    out<<"Greutatea mouse-ului:"<<greutate<<endl;
}
ostream& operator<<(ostream &out,mouse& l)
{
    l.afisare(out);
    return out;
}
///--------------------------------------------------
class mouseUSB:public mouse
{
private:
    int lungime;
public:
    mouseUSB(int,string,string,bool,bool,int,int);
    ~mouseUSB();
    mouseUSB(const mouseUSB&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, mouseUSB&);
    friend istream& operator>>(istream& in, mouseUSB&);
};
mouseUSB::mouseUSB(int pret=0, string denumire="", string producator="", bool iluminare=false ,bool design=false, int greutate=0, int lungime=0):mouse(pret,denumire,producator,iluminare,design,greutate)
{
    this->lungime=lungime;
}

mouseUSB::~mouseUSB()
{
    lungime=0;
}

mouseUSB::mouseUSB(const mouseUSB &l)
{
    lungime=l.lungime;
}

void mouseUSB::citire(istream &in){
    mouse::citire(in);

    cout<<"Lungimea firului mouse-ului:";
    in>>lungime;
}
istream& operator>>(istream &in ,mouseUSB& l){
    l.citire(in);
    return in;
}
void mouseUSB::afisare(ostream &out){
    mouse::afisare(out);

    out<<"Lungimea firului mouse-ului:"<<lungime<<endl;
}
ostream& operator<<(ostream &out,mouseUSB& l)
{
    l.afisare(out);
    return out;
}
///----------------------------------------------------
class mouseBluetooth:public mouse
{
private:
    int raza;
public:
    mouseBluetooth(int,string,string,bool,bool,int,int);
    ~mouseBluetooth();
    mouseBluetooth(const mouseBluetooth&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, mouseBluetooth&);
    friend istream& operator>>(istream& in, mouseBluetooth&);
};
mouseBluetooth::mouseBluetooth(int pret=0, string denumire="", string producator="", bool iluminare=false ,bool design=false, int greutate=0, int raza=0):mouse(pret,denumire,producator,iluminare,design,greutate)
{
    this->raza=raza;
}

mouseBluetooth::~mouseBluetooth()
{
    raza=0;
}

mouseBluetooth::mouseBluetooth(const mouseBluetooth &l)
{
    raza=l.raza;
}

void mouseBluetooth::citire(istream &in){
    mouse::citire(in);

    cout<<"Raza de conexiune a mouse-ului:";
    in>>raza;
}
istream& operator>>(istream &in ,mouseBluetooth& l){
    l.citire(in);
    return in;
}
void mouseBluetooth::afisare(ostream &out){
    mouse::afisare(out);

    out<<"Raza de conexiune a mouse-ului:"<<raza<<endl;
}
ostream& operator<<(ostream &out,mouseBluetooth& l)
{
    l.afisare(out);
    return out;
}
///============================================================
class vanzari
{
private:
    int zi;
    int luna;
    int an;
    vector<produse*>produs;
    vector<produse*>produs_returnat;
public:
    vanzari(int, int ,int,vector<produse*>, vector<produse*>);
    ~vanzari();
    vanzari(const vanzari&);

    virtual void afisare(ostream &out);
    virtual void citire(istream &in);

    friend ostream& operator<<(ostream& out, vanzari&);
    friend istream& operator>>(istream& in, vanzari&);

    void adaugare(produse *x);
    void adaugare_retur(produse *x);
    void anulare(int x);
    void profit();
    static void profit_luna(vector<vanzari*>);
    static void profit_an(vector<vanzari*>);
    int castig();
    int pierdere();

    int get_zi(){return zi;}
    int get_luna(){return luna;}
    int get_an(){return an;}
};

vanzari::vanzari(int zi=0, int luna=0,int an=0,vector<produse*>produs=vector<produse*>(), vector<produse*>produs_returnat=vector<produse*>())
{
    this->zi = zi;
    this->luna = luna;
    this->an = an;
    this->produs=produs;
    this->produs_returnat=produs_returnat;
}

vanzari::~vanzari()
{
    zi=0;
    luna=0;
    an=0;
    for(auto i=produs.begin();i<produs.end();i++)
        delete (*i);
    for(auto i=produs_returnat.begin();i<produs_returnat.end();i++)
        delete (*i);
}
vanzari::vanzari(const vanzari& p)
{
    zi=p.zi;
    luna=p.luna;
    an=p.an;
    this->produs=p.produs;
    this->produs_returnat=p.produs_returnat;
}

istream& operator>>(istream& in ,vanzari& p)
{
    p.citire(in);
    return in;
}
void vanzari::citire(istream& in)
{
    cout<<"Data curenta(zi luna an):";
    in>>zi>>luna>>an;
    produse *p;
    int n;
    string tip;
    cout<<"Dati numarul vanzari:";
    in>>n;
    for(int i=0;i<n;i++)
        {
            cout<<"Ce tip de data vreti sa introduceti?"<<endl;
            in.get();
            string z;
            getline(cin,z);
            tip=z;
            if(tip=="laptop gaming")
            {
                p = new laptopGaming;
                in>>*p;
                produs.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="laptop ultraportabil")
            {
                p = new laptopUltraportabil;
                in>>*p;
                produs.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="laptop Home")
            {
                p = new laptopHome;
                in>>*p;
                produs.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="tastatura multimedia")
            {
                p = new tastaturaMultimedia;
                in>>*p;
                produs.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="tastatura cu touch pad")
            {
                p = new tastaturaTouch;
                in>>*p;
                produs.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="mouse cu conexiune USB")
            {
                p = new mouseUSB;
                in>>*p;
                produs.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="mouse cu conexiune Bluetooth")
            {
                p = new mouseBluetooth;
                in>>*p;
                produs.push_back(p);
                cout<<"--------------------"<<endl;
            }
        }
    cout<<"Dati numarul de produse returnate:";
    in>>n;
    for(int i=0;i<n;i++)
        {
            cout<<"Ce tip de data vreti sa introduceti?"<<endl;
            in.get();
            string z;
            getline(cin,z);
            tip=z;
            if(tip=="laptop gaming")
            {
                p = new laptopGaming;
                in>>*p;
                produs_returnat.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="laptop ultraportabil")
            {
                p = new laptopUltraportabil;
                in>>*p;
                produs_returnat.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="laptop Home")
            {
                p = new laptopHome;
                in>>*p;
                produs_returnat.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="tastatura multimedia")
            {
                p = new tastaturaMultimedia;
                in>>*p;
                produs_returnat.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="tastatura cu touch pad")
            {
                p = new tastaturaTouch;
                in>>*p;
                produs_returnat.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="mouse cu conexiune USB")
            {
                p = new mouseUSB;
                in>>*p;
                produs_returnat.push_back(p);
                cout<<"--------------------"<<endl;
            }
            else if(tip=="mouse cu conexiune Bluetooth")
            {
                p = new mouseBluetooth;
                in>>*p;
                produs_returnat.push_back(p);
                cout<<"--------------------"<<endl;
            }
        }
}

ostream& operator<<(ostream& out,vanzari& p)
{
    p.afisare(out);
    return out;
}
void vanzari::afisare(ostream& out)
{
    int nr = 0;
    out<<"Data curenta:"<<zi<<" "<<luna<<" "<<an<<endl;
    for(auto i=produs.begin();i<produs.end();i++)
    {
        nr++;
        out<<"Id comanda:"<<nr<<'\n';
        out<<(**i);
    }
    for(auto i=produs_returnat.begin();i<produs_returnat.end();i++)
    {
        out<<(**i);
    }
    out<<"----------------------"<<endl;
}

void vanzari::adaugare(produse *x)
{
    produs.push_back(x);
}

void vanzari::adaugare_retur(produse *x)
{
    produs_returnat.push_back(x);
}

void vanzari::anulare(int it)
{
    this->produs.erase(produs.begin() + it - 1);
}

void vanzari::profit()
{
    int castig = 0, pierdere = 0, total;
    for(auto i=produs.begin();i<produs.end();i++)
        castig += (*i)->get_pret();
    for(auto i=produs_returnat.begin();i<produs_returnat.end();i++)
        pierdere += (*i)->get_pret();
    total = castig - pierdere;
    cout<<"Castigul este de "<<castig<<", pierderea cauzata de retururi este de "<<pierdere<<'\n'<<"Totalul pentru zi este: "<<total<<'\n';
}

int vanzari::castig()
{
    int castig = 0, pierdere = 0, total;
    for(auto i=produs.begin();i<produs.end();i++)
        castig += (*i)->get_pret();
    for(auto i=produs_returnat.begin();i<produs_returnat.end();i++)
        pierdere += (*i)->get_pret();
    total = castig - pierdere;
    return castig;
}

int vanzari::pierdere()
{
    int castig = 0, pierdere = 0, total;
    for(auto i=produs.begin();i<produs.end();i++)
        castig += (*i)->get_pret();
    for(auto i=produs_returnat.begin();i<produs_returnat.end();i++)
        pierdere += (*i)->get_pret();
    total = castig - pierdere;
    return pierdere;
}

void vanzari::profit_luna(vector<vanzari*> v)
{
    int castig = 0, pierdere = 0, total;
    int b, c;
    cout<<"Dati luna si anul din care doriti sa calculati profitul: ";
    cin>>b>>c;
    for(auto i=v.begin();i<v.end();i++)
    {
        if(b == (*i)->get_luna() && c == (*i)->get_an())
        {
            castig += (*i)->castig();
            pierdere += (*i)->pierdere();
            total = total + castig - pierdere;
        }
    }
    cout<<"Castigul este de "<<castig<<", pierderea cauzata de retururi este de "<<pierdere<<'\n'<<"Totalul pentru luna este: "<<total<<'\n';
}

void vanzari::profit_an(vector<vanzari*> v)
{
    int castig = 0, pierdere = 0, total;
    int c;
    cout<<"Dati anul din care doriti sa calculati profitul: ";
    cin>>c;
    for(auto i=v.begin();i<v.end();i++)
    {
        if(c == (*i)->get_an())
        {
            castig += (*i)->castig();
            pierdere += (*i)->pierdere();
            total = total + castig - pierdere;
        }
    }
    cout<<"Castigul este de "<<castig<<", pierderea cauzata de retururi este de "<<pierdere<<'\n'<<"Totalul pentru an este: "<<total<<'\n';
}

int main()
{

    vector<vanzari*> vanzare;
    vanzari* z;
    int x = 1;int n;
    while(x != 0)
    {
        cout<<"Alegeti operatia pe care doriti sa o efectuati: "<<'\n';
        cout<<"0 - inchidere program"<<'\n';
        cout<<"1. Sa se citeasca vanzarile efectuate."<<endl;
        cout<<"2. Sa se afiseze vanzarile efectuate."<<endl;
        cout<<"3. Adauga produse"<<'\n';
        cout<<"4. Adauga produse returnate."<<endl;
        cout<<"5. Anulare comanda."<<endl;
        cout<<"6. Total cheltuilei pentru o anumita data"<<'\n';
        cout<<"7. Total cheltuilei lunare"<<'\n';
        cout<<"8. Total cheltuilei anuale"<<'\n';
        cout<<"9. Afisare in fisier"<<'\n';
        cout<<"10. ---"<<'\n';
        cin>>x;
        if(x == 1)
        {
            cout<<"Introduceti numarul de zile de vanzari pe care vreti sa le inregistrati:";
            cin>>n;
            for(int i=0;i<n;i++)
                {
                    z = new vanzari;
                    cin>>*z;
                    vanzare.push_back(z);
                    cout<<"--------------------------";

                }
        }
        else if(x == 2)
        {
            for(auto i=vanzare.begin();i<vanzare.end();i++)
                    cout<<*z<<endl<<"-----------------"<<endl;
        }
        else if(x == 3)
        {
            cout<<"Introduceti ziua in care vreti sa adaugati produsele vandute(zi luna an):";
            int a,b,c;
            cin>>a>>b>>c;
            for(auto i=vanzare.begin();i<vanzare.end();i++)
                if(a == (*i)->get_zi() && b == (*i)->get_luna() && c == (*i)->get_an())
                {
                    produse *k;
                    cout<<"Ce tip de data vreti sa introduceti?"<<endl;
                    cin.get();
                    string z1;
                    getline(cin,z1);
                    if(z1=="laptop gaming")
                    {
                        k = new laptopGaming;
                        cin>>*k;
                        (*i)->adaugare(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="laptop ultraportabil")
                    {
                        k = new laptopUltraportabil;
                        cin>>*k;
                        (*i)->adaugare(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="laptop Home")
                    {
                        k = new laptopHome;
                        cin>>*k;
                        (*i)->adaugare(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="tastatura multimedia")
                    {
                        k = new tastaturaMultimedia;
                        cin>>*k;
                        (*i)->adaugare(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="tastatura cu touch pad")
                    {
                        k = new tastaturaTouch;
                        cin>>*k;
                        (*i)->adaugare(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="mouse cu conexiune USB")
                    {
                        k = new mouseUSB;
                        cin>>*k;
                        (*i)->adaugare(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="mouse cu conexiune Bluetooth")
                    {
                        k = new mouseBluetooth;
                        cin>>*k;
                        (*i)->adaugare(k);
                        cout<<"--------------------"<<endl;
                    }
                }
        }
        else if(x == 4)
        {
            cout<<"Introduceti ziua in care vreti sa adaugati produsele returnate(zi luna an):";
            int a,b,c;
            cin>>a>>b>>c;
            for(auto i=vanzare.begin();i<vanzare.end();i++)
                if(a == (*i)->get_zi() && b == (*i)->get_luna() && c == (*i)->get_an())
                {
                    produse *k;
                    cout<<"Ce tip de data vreti sa introduceti?"<<endl;
                    cin.get();
                    string z1;
                    getline(cin,z1);
                    if(z1=="laptop gaming")
                    {
                        k = new laptopGaming;
                        cin>>*k;
                        (*i)->adaugare_retur(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="laptop ultraportabil")
                    {
                        k = new laptopUltraportabil;
                        cin>>*k;
                        (*i)->adaugare_retur(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="laptop Home")
                    {
                        k = new laptopHome;
                        cin>>*k;
                        (*i)->adaugare_retur(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="tastatura multimedia")
                    {
                        k = new tastaturaMultimedia;
                        cin>>*k;
                        (*i)->adaugare_retur(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="tastatura cu touch pad")
                    {
                        k = new tastaturaTouch;
                        cin>>*k;
                        (*i)->adaugare_retur(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="mouse cu conexiune USB")
                    {
                        k = new mouseUSB;
                        cin>>*k;
                        (*i)->adaugare_retur(k);
                        cout<<"--------------------"<<endl;
                    }
                    else if(z1=="mouse cu conexiune Bluetooth")
                    {
                        k = new mouseBluetooth;
                        cin>>*k;
                        (*i)->adaugare_retur(k);
                        cout<<"--------------------"<<endl;
                    }
                }
        }
        else if(x == 5)
        {
            int it;
            int a, b, c;
            cout<<"Dati data din care doriti sa anulati comanda: ";
            cin>>a>>b>>c;
            cout<<"Dati numarul comenzii pe care doriti sa o anulati: ";
            cin>>it;
            for(auto i=vanzare.begin();i<vanzare.end();i++)
                if(a == (*i)->get_zi() && b == (*i)->get_luna() && c == (*i)->get_an())
                {
                    (*i)->anulare(it);
                    cout<<"Comanda a fost anulata cu succes! \n";
                    break;
                }
        }
        else if(x == 6)
        {
            int it;
            int a, b, c;
            cout<<"Dati data pentru care doriti sa calculati profitul: ";
            cin>>a>>b>>c;
            for(auto i=vanzare.begin();i<vanzare.end();i++)
                if(a == (*i)->get_zi() && b == (*i)->get_luna() && c == (*i)->get_an())
                {
                    (*i)->profit();
                }
        }
        else if(x == 7)
        {
            vanzari::profit_luna(vanzare);
        }
        else if(x == 8)
        {
            vanzari::profit_an(vanzare);
        }
        else if(x == 9)
        {
            for(auto i=vanzare.begin();i<vanzare.end();i++)
                    g<<*z<<endl<<"-----------------"<<endl;
        }
        else
            cout<<"Introduceti o valoare intre 0 si 4"<<'\n';
        system("pause");
        system("cls");

    }

    return 0;
}
