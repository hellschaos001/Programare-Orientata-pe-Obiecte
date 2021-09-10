#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class dezinfectant
{
protected:
    int organisme_ucise;
    vector<string>ingrediente;
    vector<string>tip_suprafata;
public:
    dezinfectant(int, vector<string>, vector<string>);
    virtual ~dezinfectant();
    dezinfectant(const dezinfectant&);

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    friend istream& operator>>(istream&, dezinfectant&);
    friend ostream& operator<<(ostream&, dezinfectant&);

virtual float eficienta()
    {
        return organisme_ucise/pow(10.0,9.0);
    }
};

dezinfectant::dezinfectant(int organisme_ucise=0, vector<string>ingrediente=vector<string>(),vector<string>tip_suprafata=vector<string>())
{
    this->organisme_ucise=organisme_ucise;
    this->ingrediente=ingrediente;
    this->tip_suprafata=tip_suprafata;
}
dezinfectant::~dezinfectant()
{
    organisme_ucise=0;
    ingrediente.clear();
    tip_suprafata.clear();
}
dezinfectant::dezinfectant(const dezinfectant &d)
{
    organisme_ucise=d.organisme_ucise;
    ingrediente=d.ingrediente;
    tip_suprafata=d.tip_suprafata;
}
istream& operator>>(istream& in ,dezinfectant& d)
{
    d.citire(in);
    return in;
}
void dezinfectant::citire(istream &in)
{
    cout<<"Organisme ucise: ";
    in>>organisme_ucise;
    int n;
    cout<<"Numar ingrediente:";

    in>>n;
    string comp;
    for(auto i=0; i<n; i++)
    {
        cout<<"---";
        in>>comp;
        ingrediente.push_back(comp);
    }
    int m;
    cout<<"Tipurile de suprafata:";
    in>>m;
    string supr;
    for(auto i=0; i<m; i++)
    {
        cout<<"---";
        in>>supr;
        tip_suprafata.push_back(supr);
    }
}

ostream& operator<<(ostream& out,dezinfectant& v)
{
    v.afisare(out);
    return out;
}
void dezinfectant::afisare(ostream &out)
{
    out<<"Numarul de specii de organisme ce for fi ucise: "<<organisme_ucise<<endl;

    out<<"Ingredientele folosite:"<<endl;
    for(auto i=ingrediente.begin(); i!=ingrediente.end(); i++)
    {
        out<<"---"<<(*i)<<endl;
    }
    out<<"Tipurile de suprafata aplicabila:"<<endl;
    for(auto i=tip_suprafata.begin(); i!=tip_suprafata.end(); i++)
    {
        out<<"---"<<(*i)<<endl;
    }
}
///--------------------------------------------------------
class DezinfectantBacterii:public dezinfectant
{
private:
public:
    DezinfectantBacterii(int, vector<string>, vector<string>);
    ~DezinfectantBacterii();
    DezinfectantBacterii(const DezinfectantBacterii &);

    float eficienta()
    {
        return organisme_ucise/pow(10.0,9.0);
    }

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator >>(istream &in, DezinfectantBacterii&);
    friend ostream& operator <<(ostream &out, DezinfectantBacterii&);


};

DezinfectantBacterii::DezinfectantBacterii(int organisme_ucise=0, vector<string>ingrediente=vector<string>(),vector<string>tip_suprafata=vector<string>()):dezinfectant(organisme_ucise,ingrediente,tip_suprafata)
{

}
DezinfectantBacterii::~DezinfectantBacterii()
{

}
DezinfectantBacterii::DezinfectantBacterii(const DezinfectantBacterii &d)
{
    organisme_ucise=d.organisme_ucise;
    ingrediente=d.ingrediente;
    tip_suprafata=d.tip_suprafata;
}

istream& operator>>(istream& in ,DezinfectantBacterii& v)
{
    v.citire(in);
    return in;
}
void DezinfectantBacterii::citire(istream& in)
{
    dezinfectant::citire(in);

}
ostream& operator<<(ostream& out, DezinfectantBacterii &v)
{
    v.afisare(out);
    return out;
}
void DezinfectantBacterii::afisare(ostream& out)
{
    dezinfectant::afisare(out);
}
///---------------------------------------------------------------

class DezinfectantVirusuri:public dezinfectant
{
private:
public:
    DezinfectantVirusuri(int, vector<string>, vector<string>);
    ~DezinfectantVirusuri();
    DezinfectantVirusuri(const DezinfectantVirusuri&);

    float eficienta()
    {
        return organisme_ucise / (1.5 * pow(10.0,6.0))  ;
    }

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator >>(istream &in, DezinfectantVirusuri&);
    friend ostream& operator <<(ostream &out, DezinfectantVirusuri&);


};

DezinfectantVirusuri::DezinfectantVirusuri(int organisme_ucise=0, vector<string>ingrediente=vector<string>(),vector<string>tip_suprafata=vector<string>()):dezinfectant(organisme_ucise,ingrediente,tip_suprafata)
{

}
DezinfectantVirusuri::~DezinfectantVirusuri()
{

}
DezinfectantVirusuri::DezinfectantVirusuri(const DezinfectantVirusuri &d)
{
    organisme_ucise=d.organisme_ucise;
    ingrediente=d.ingrediente;
    tip_suprafata=d.tip_suprafata;
}

istream& operator>>(istream& in ,DezinfectantVirusuri& v)
{
    v.citire(in);
    return in;
}
void DezinfectantVirusuri::citire(istream& in)
{
    dezinfectant::citire(in);

}
ostream& operator<<(ostream& out, DezinfectantVirusuri &v)
{
    v.afisare(out);
    return out;
}
void DezinfectantVirusuri::afisare(ostream& out)
{
    dezinfectant::afisare(out);
}




///------------------------------------------------------
class DezinfectantFungi:public dezinfectant
{
private:
public:
    DezinfectantFungi(int, vector<string>, vector<string>);
    ~DezinfectantFungi();
    DezinfectantFungi(const DezinfectantFungi&);

    float eficienta()
    {
        return organisme_ucise / pow(10.0,8.0)  ;
    }

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator >>(istream &in, DezinfectantFungi&);
    friend ostream& operator <<(ostream &out, DezinfectantFungi&);


};

DezinfectantFungi::DezinfectantFungi(int organisme_ucise=0, vector<string>ingrediente=vector<string>(),vector<string>tip_suprafata=vector<string>()):dezinfectant(organisme_ucise,ingrediente,tip_suprafata)
{

}
DezinfectantFungi::~DezinfectantFungi()
{

}
DezinfectantFungi::DezinfectantFungi(const DezinfectantFungi &d)
{
    organisme_ucise=d.organisme_ucise;
    ingrediente=d.ingrediente;
    tip_suprafata=d.tip_suprafata;
}

istream& operator>>(istream& in ,DezinfectantFungi& v)
{
    v.citire(in);
    return in;
}
void DezinfectantFungi::citire(istream& in)
{
    dezinfectant::citire(in);

}
ostream& operator<<(ostream& out, DezinfectantFungi &v)
{
    v.afisare(out);
    return out;
}
void DezinfectantFungi::afisare(ostream& out)
{
    dezinfectant::afisare(out);
}
///=====================================================================

class masca
{
protected:
    string tip;
public:
    masca(string);
    virtual ~masca();
    masca(masca&);

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream &in, masca&);
    friend ostream& operator<<(ostream &out, masca&);


};
masca::masca(string tip="")
{
    tip=tip;
}
masca::~masca()
{
    tip="";
}
masca::masca(masca &v)
{
    tip=v.tip;
}

istream& operator>>(istream& in ,masca& v)
{
    v.citire(in);
    return in;
}
void masca::citire(istream& in)
{
    cout<<"Tipul de protectie:";
    in>>tip;
}
ostream& operator<<(ostream& out, masca &v)
{
    v.afisare(out);
    return out;
}
void masca::afisare(ostream& out)
{
    cout<<"Tipul de protectie: "<<tip<<endl;
}

///-------------------------------------------------------
class mascaChirurgicala:public masca
{
private:
    string culoare;
    int nr_pliuri;
public:
     mascaChirurgicala(string, string, int);
    ~mascaChirurgicala();
    mascaChirurgicala(mascaChirurgicala&);


    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream &in, mascaChirurgicala&);
    friend ostream& operator<<(ostream &out, mascaChirurgicala&);
    mascaChirurgicala& operator=(mascaChirurgicala& m);
};
mascaChirurgicala::mascaChirurgicala(string tip="", string culoare="", int nr_pliuri=0):masca(tip)
{
    culoare=culoare;
    nr_pliuri=nr_pliuri;
}
mascaChirurgicala::~mascaChirurgicala()
{
    culoare="";
    nr_pliuri=0;
}
mascaChirurgicala::mascaChirurgicala(mascaChirurgicala &v)
{
    culoare=v.culoare;
    nr_pliuri=nr_pliuri;
}

istream& operator>>(istream& in ,mascaChirurgicala& v)
{
    v.citire(in);
    return in;
}
void mascaChirurgicala::citire(istream& in)
{
    masca::citire(in);
    cout<<"Culoare:";
    in>>culoare;
    cout<<"Numar de pliuri:";
    in>>nr_pliuri;
}
ostream& operator<<(ostream& out, mascaChirurgicala &v)
{
    v.afisare(out);
    return out;
}
void mascaChirurgicala::afisare(ostream& out)
{
    masca::afisare(out);
    cout<<"Culoare: "<<culoare<<endl;
    cout<<"Numar de pliuri: "<<nr_pliuri<<endl;
}

mascaChirurgicala& mascaChirurgicala::operator =(mascaChirurgicala& m)
{
    this->culoare = m.culoare;
    this->nr_pliuri = m.nr_pliuri;

    return *this;
}

///--------------------------------------------------------

class mascaPolicarbonat:public masca
{
private:
    const string tip="ffp0";
    string prindere;
public:
     mascaPolicarbonat(string, string);
    ~mascaPolicarbonat();
    mascaPolicarbonat(mascaPolicarbonat&);


    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream &in, mascaPolicarbonat&);
    friend ostream& operator<<(ostream &out, mascaPolicarbonat&);

};
mascaPolicarbonat::mascaPolicarbonat(string tip="", string prindere="")
{
    tip=tip;
    prindere=prindere;
}
mascaPolicarbonat::~mascaPolicarbonat()
{
    prindere="";
}
mascaPolicarbonat::mascaPolicarbonat(mascaPolicarbonat &v)
{
    prindere=prindere;
}

istream& operator>>(istream& in ,mascaPolicarbonat& v)
{
    v.citire(in);
    return in;
}
void mascaPolicarbonat::citire(istream& in)
{
    cout<<"Prindere:";
    in>>prindere;
}
ostream& operator<<(ostream& out, mascaPolicarbonat &v)
{
    v.afisare(out);
    return out;
}
void mascaPolicarbonat::afisare(ostream& out)
{
    cout<<"Tip protectie: "<<tip<<endl;
    cout<<"Prindere: "<<prindere<<endl;
}

class achizitie
{
private:
    string data;
    string nume;
    vector<dezinfectant*> dezinfectanti;
    vector<masca*> masti;
    int total();
public:
    achizie();
    ~achizie();
    achizie(achizitie&);

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    friend istream& operator >>(istream &in, vaccin&);
    friend ostream& operator <<(ostream &out, vaccin&);




};













int main()
{
    /*dezinfectant *d=new DezinfectantFungi(140000, vector<string>({"Alkil Etil Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}), vector<string>({"sticla plastic"}));
    cin>>*d;
    cout<<"----------------------"<<endl;
    cout<<*d<<endl;
    cout<<"----------------------"<<endl;
    cout<<d->eficienta();
    */

    mascaPolicarbonat m;
    cin>>m;
    cout<<"----------------------"<<endl;

    cout<<m;
    return 0;
}
