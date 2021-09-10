#include <iostream>
using namespace std;

class persoana{ ///clasa ABSTRACTA pentru ca are CEL PUTIN o functie virtuala pura
public:
    virtual void lucreaza()=0; ///functie virtuala pura
};
class angajat:public persoana{
protected:
    string nume;
    double salariu;
public:
    angajat(string nume="", double salariu=0){
        this->nume=nume;
        this->salariu=salariu;
    }
    void lucreaza(){
    cout<<"Lucrez";}

    virtual void citeste(istream &in){
        cout<<"Nume=";
        getline(in,this->nume);
        cout<<"Salariu=";
        in>>this->salariu;
    }
    virtual void afiseaza(ostream& out){
        out<<"Nume=";
        out<<this->nume;
        out<<"\n";
        out<<"Salariu=";
        out<<this->salariu;
        out<<"\n";
    }
    friend istream& operator>>(istream& in, angajat& x){
        x.citeste(in);
        return in;
    }
    friend ostream& operator<<(ostream& out, angajat& x){
        x.afiseaza(out);
        return out;
    }
};

class angajatDepartamentHr:public angajat{
protected:
    int numarTicketeZilnice;
public:
    angajatDepartamentHr(string nume="", double salariu=0, int numarTicketeZilnice=0):angajat(nume,salariu){
        this->numarTicketeZilnice=numarTicketeZilnice;
    }
    void lucreaza(){
        cout<<"Lucrez in departamentul HR.\n";
    }
    void citeste(istream& in){
        angajat::citeste(in);
        cout<<"Dati numar tickete:";
        in>>this->numarTicketeZilnice;
    }
    void afiseaza(ostream& out){
        angajat::afiseaza(out);
        out<<"Numar tickete:"<<this->numarTicketeZilnice<<"\n";
    }
};

class angajatDepartamentTehnic:public angajat{
protected:
    int oreSuplimentare;
    double plataOreSuplimentare;
public:
    angajatDepartamentTehnic(string nume="", double salariu=0, int oreSuplimentare=0, double plataOreSuplimentare=0):angajat(nume,salariu){
        this->oreSuplimentare=oreSuplimentare;
        this->plataOreSuplimentare=plataOreSuplimentare;
    }
    void lucreaza(){
        cout<<"Lucrez in departamentul TEHNIC.\n";
    }
    void citeste(istream& in){
        angajat::citeste(in);
        cout<<"Dati numarul de ore suplimentare:";
        in>>this->oreSuplimentare;
        cout<<"Dati plata pentru orele suplimentare:";
        in>>this->plataOreSuplimentare;
    }
    void afiseaza(ostream& out){
        angajat::afiseaza(out);
        out<<"Numar ore suplimentare:"<<this->oreSuplimentare<<"\n";
        out<<"Plata pentru orele suplimentare:"<<this->plataOreSuplimentare<<"\n";
    }
};


int main()
{
    /**
    persoana a;
    cin>>a;
    ///NU MERGE pentru ca nu pot lucra cu obiecte dintr-o clasa abstracta
    ///pot in schimb sa declar pointer si sa fac upcast
    persoana *b=new angajat;
    cin>>*b;///asta merge pt ca a fost etichetat in urma unui upcast
    ///daca am
    persoana *c=new persoana;
    cin>>*c;
    ///nu merge pentru ca ajung la primul caz
    */
    angajat x;
    cin>>x;
    return 0;
}
