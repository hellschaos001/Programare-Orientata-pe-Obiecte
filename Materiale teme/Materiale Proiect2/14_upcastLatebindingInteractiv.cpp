#include <iostream>
#include <stdlib.h> ///permite executia functiei system(...)
using namespace std;
class persoana
{
protected: ///membri protected pentru ca facem mostenire
    string cnp;
    string nume_persoana;

    static int n; ///Variabila statica folosita pentru a numara cate persoane avem declarate.

public:
    persoana (string, string);
    virtual ~persoana(); ///destructor virtual - late binding
    virtual void citire(istream &in);  ///citire virtuala - late binding
    virtual void afisare(ostream &out); ///afisare virtuala - late binding
    friend istream& operator>>(istream&, persoana&);
    friend ostream& operator<<(ostream&, persoana&);
    static void numarObiecte(){ /// metoda statica de afisare a numarului de obiecte
        cout<<n;
    }
};
int persoana::n; ///declaram variabila

persoana::persoana (string c="",string numep=""){
    n++; ///incrementam in constructor
    try ///exemplu de try ... catch => nu este obligatoriu sa tratati exceptiile cu try catch la proiectul 2
    {
        for (unsigned int i=0;i<c.length();i++)
            if (c[i]<'0'||c[i]>'9')
                throw 1; ///arunca un int
        cnp=c; ///atribuirea pe string
        nume_persoana=numep; ///atribuire pe string
    }
    catch(int i)///prinde int
    {
        cout<<"Eroare constructor, CNP-ul persoanei poate contine doar cifre.\n";
        exit(EXIT_FAILURE); ///exit
    }
}
persoana::~persoana(){
    cnp="";
    nume_persoana="";
}
void persoana::citire(istream &in){
    try
    {
        string x;
        cout<<"CNP:";
        in>>x;
        for (unsigned int i=0;i<x.length();i++)
            if (x[i]<'0'||x[i]>'9')
                throw 1;
        cnp=x;
        cout<<"Nume:";
        in.get();
        string z;
        getline(in,z); ///citire string pana la enter (permite sa avem spatii)
        nume_persoana=z;
    }
    catch(int i)
    {
        cout<<"Eroare constructor, CNP-ul persoanei poate contine doar cifre.\n";
        exit(EXIT_FAILURE);
    }
}
void persoana::afisare(ostream &out){
    out<<"CNP: "<<cnp<<"\n";
    out<<"Nume: "<<nume_persoana<<"\n";
}
istream& operator>>(istream& in,persoana& p){
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, persoana& p){
    p.afisare(out);
    return out;
}
///---------------------------------------------------
class personal:public persoana
{
protected: ///protected pentru ca mai derivam o data
    double procent_incasari;
public:
    personal(string, string,double);
    ~personal(); ///dupa cate observati nu este nevoie sa avem virtual in derivata (doar daca e cazul)

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, personal&);
    friend ostream& operator<<(ostream&, personal&);
};
personal::personal(string c="",string numep="",double procent=0):persoana(c,numep){ ///apelam constructorul din baza
    procent_incasari=procent; ///adaugam ce e de adaugat
}
personal::~personal(){
}
void personal::citire(istream &in){
    persoana::citire(in);
    cout<<"Dati procent incasari: ";
    in>>procent_incasari;
}
void personal::afisare(ostream &out){
    persoana::afisare(out);
    out<<"Procent incasari: ";
    out<<procent_incasari<<"\n";
}
istream& operator>>(istream& in,personal& p){
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, personal& p){
    p.afisare(out);
    return out;
}

///-------------------------------------------------
class regizor:public personal
{///aici avem membri privati
    double suma_fixa;
public:
    regizor(string, string, double, double);
    ~regizor();

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, regizor&);
    friend ostream& operator<<(ostream&, regizor&);
};
regizor::regizor(string c="",string numep="",double procent=0,double suma=0):personal(c,numep,procent){
    suma_fixa=suma;

}
regizor::~regizor(){
}
void regizor::citire(istream &in){
    personal::citire(in);
    cout<<"Dati suma fixa: ";
    in>>suma_fixa;
}
void regizor::afisare(ostream &out){
    personal::afisare(out);
    out<<"Suma fixa: ";
    out<<suma_fixa<<"\n";
}
istream& operator>>(istream& in,regizor& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, regizor& p)
{
    p.afisare(out);
    return out;
}
///-------------------------------------------------
class actor:public personal
{///aici avem membrii privati
    bool principal;
public:
    actor(string, string, double, bool);
    ~actor();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, actor&);
    friend ostream& operator<<(ostream&, actor&);
};
actor::actor(string c="",string numep="",double procent=0,bool princ=0):personal(c,numep,procent){
    principal=princ;
}
actor::~actor(){

}
void actor::citire(istream &in)
{
    personal::citire(in);
    cout<<"Actor principal? (1 / 0): ";
    in>>principal;
}
void actor::afisare(ostream &out)
{
    personal::afisare(out);
    out<<"Principal: ";
    out<<principal<<"\n";
}
istream& operator>>(istream& in,actor& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, actor& p)
{
    p.afisare(out);
    return out;
}

void tip(personal *&p, int &i) {
    string s;
    cout<<"\n";
    cout<<"Introduceti postul personalului "<<i+1<<": ";
    cin>>s;
    try{
        if(s=="regizor"){
                p=new regizor;
                cin>>*p;
                i++;
        }
        else
            if(s=="actor"){
                p=new actor;
                cin>>*p;
                i++;
            }
            else
                if (s=="personal"){
                    p=new personal;
                    cin>>*p;
                    i++;
                }
                else
                    throw 10;
    }
    catch (bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus un post valid. Incercati regizor, actor sau personal.\n ";
    }
}


int main()
{   /**
    actor a1;
    regizor a2;
    persoane::numarObiecte(); ///apelarea metodei statice
    ///dupa cate se poate observa, desii nu am creeat un obiect de tip persoana,
    ///s-a apelat constructorul persoanei de doua ori si s-a actualizat numarul de persoane
    ///obiectele noastre fiind de fapt actor si regizor.


    cout<<"\n";
    ///Upcastul & Downcastul nu trebuiesc tratate / intelese ca un simplu cast
    ///(pot aparea confuzii)
    ///Upcastul si Downcastul nu schimba obiectul, il eticheteaza

    ///upcast
    personal *x=new actor;
    cin>>*x;
    cout<<*x;
    ///end upcast

    cout<<"\n";

    ///downcast
    actor *a=(actor*)new personal;
    cin>>*a;
    cout<<*a;
    ///end downcast
    cout<<"\n";

    ///mai afisam o data numarul de persoane
    persoane::numarObiecte();
    */

    personal **v; ///vezi mai jos pentru a intelege
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;

    try{
        v=new personal*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
                                                                                                                            /// sau il pot face regizor/actor)
        for(int i=0;i<n;)
            tip(v[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa
        cout<<"\nAfisam personalul citit anterior:\n";
        for(int i=0;i<n;i++){
            cout<<"\n"<<*v[i]; ///afisez personalul de pe pozitia i
            cout<<"--------------------------\n";
        }
    }
    catch (bad_alloc var){
        cout<<"Numarul introdus trebuie sa fie pozitiv. Bad Alloc!\n";
        exit(EXIT_FAILURE);
    }
    return 0;

}
