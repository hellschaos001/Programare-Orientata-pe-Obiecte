#include <iostream>
using namespace std;

class angajat{
protected:
    string nume;
    double salariu;
    static int n;
public:
    angajat(string nume="", double salariu=0){
        n++;
        this->nume=nume;
        this->salariu=salariu;
    }
    virtual void lucreaza(){
        cout<<"Lucrez.\n";
    }
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
    static void numarObiecte(){
        cout<<n<<"\n";
    }
};
int angajat::n;

class angajatDepartamentHr:public virtual angajat{
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

class angajatDepartamentTehnic:public virtual angajat{
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

class manager: public angajatDepartamentHr, angajatDepartamentTehnic{
private:
    double comision;
public:
    manager(string nume="", double salariu=0, int numarTicketeZilnice=0, int oreSuplimentare=0, double plataOreSuplimentare=0, double comision=0)
                                            :angajat(nume,salariu),
                                            angajatDepartamentHr(nume,salariu,numarTicketeZilnice),
                                            angajatDepartamentTehnic(nume, salariu, oreSuplimentare, plataOreSuplimentare){
        this->comision=comision;
    }
    void lucreaza(){
        cout<<"Sunt manager.\n";
    }
    void citeste(istream& in){
        angajat::citeste(in);
        ///departamentHr::citeste(in);          ///---daca facem asta atunci o sa citeasca de mai multe ori pentru ca apeleaza
        ///departamentTehnic::citeste(in);      ///---citirea pentru angajat apelata in citirea pentru hr si tehnic
        ///------asadar, citim iar ce avem nevoie

        cout<<"Dati numar tickete:";
        in>>this->numarTicketeZilnice;
        cout<<"Dati numarul de ore suplimentare:";
        in>>this->oreSuplimentare;
        cout<<"Dati plata pentru orele suplimentare:";
        in>>this->plataOreSuplimentare;
        cout<<"Dati comisionul=";
        in>>this->comision;
    }
    void afiseaza(ostream& out){
        angajat::afiseaza(out);
        ///departamentHr::afiseaza(out);        ///---aceeasi discutie ca la citire, se v-a afisa de doua ori in plus numele si salariul
        ///departamentTehnic::afiseaza(out);

        out<<"Numar tickete:"<<this->numarTicketeZilnice<<"\n";
        out<<"Numar ore suplimentare:"<<this->oreSuplimentare<<"\n";
        out<<"Plata pentru orele suplimentare:"<<this->plataOreSuplimentare<<"\n";
        out<<"Comisionul este:";
        out<<this->comision<<"\n";
    }
};

int main()
{
    manager x;
    angajat::numarObiecte();    ///afisez numarul de obiecte
    ///Observati ca avem doar un obiect, deci nu apeleaza de 3 ori constructorul pentru angajat
    x.lucreaza();
    cin>>x;
    cout<<x;
    return 0;
}
