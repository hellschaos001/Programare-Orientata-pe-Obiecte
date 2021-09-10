#include <iostream>
#include <vector>
using namespace std;

class pacient
{
protected:
    string nume;
    string prenume;
    int varsta;
    string adresa;
    int colesterol;
    int tensiune;
    string data;
public:
    pacient(string, string, int, string, int, int, string);
    virtual ~pacient();
    pacient(pacient&);

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    friend istream& operator>>(istream&, pacient&);
    friend ostream& operator<<(ostream&, pacient&);

    get_colesterol(){return colesterol;}
};

pacient::pacient(string nume="", string prenume="", int varsta=0, string adresa="", int colesterol=0, int tensiune=0, string data="")
{
    this->nume = nume;
    this->prenume = prenume;
    this-> varsta = varsta;
    this-> adresa = adresa;
    this-> colesterol = colesterol;
    this->tensiune = tensiune;
    this->data = data;
}

pacient::~pacient()
{
    nume="";
    prenume="";
    varsta=0;
    adresa="";
    colesterol=0;
    tensiune=0;
    data="";
}
pacient::pacient(pacient &p)
{
    nume=p.nume;
    prenume=p.prenume;
    varsta=p.varsta;
    adresa=p.adresa;
    colesterol=p.colesterol;
    tensiune=p.tensiune;
    data=p.data;
}
istream& operator>>(istream& in, pacient& p)
{
    p.citire(in);
    return in;
}
void pacient::citire(istream &in)
{
    cout<<"Nume:";
    in>>nume;
    cout<<"Prenume:";
    in>>prenume;
    cout<<"Varsta:";
    in>>varsta;
    cout<<"Adresa:";
    in.get();
    string z;
    getline(in,z);
    adresa=z;
    cout<<"Colesterol:";
    in>>colesterol;
    cout<<"Tensiune:";
    in>>tensiune;
    cout<<"Data:";
    in>>data;
}

ostream& operator<<(ostream& out, pacient& p)
{
    p.afisare(out);
    return out;
}
void pacient::afisare(ostream& out)
{
    out<<"Nume:"<<nume<<endl;
    out<<"Prenume:"<<prenume<<endl;
    out<<"Varsta:"<<varsta<<endl;
    out<<"Adresa:"<<adresa<<endl;
    out<<"Colesterol:"<<colesterol<<endl;
    out<<"Tensiune:"<<tensiune<<endl;
    out<<"Data:"<<data<<endl;
}

///-----------------------------------------------------------

class pacient40:public pacient
{
private:
    bool fumator;
    string sedentarism;
public:
    pacient40(string, string, int, string, int, int, string, bool, string);
    ~pacient40();
    pacient40(pacient40&);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    friend istream& operator>>(istream&, pacient40&);
    friend ostream& operator<<(ostream&, pacient40&);

};

pacient40::pacient40(string nume="", string prenume="", int varsta=0, string adresa="", int colesterol=0, int tensiune=0, string data="", bool fumator=false, string sedentarism=""):pacient(nume,prenume,varsta,adresa,colesterol,tensiune,data)
{
    this->fumator=fumator;
    this->sedentarism=sedentarism;
}
pacient40::~pacient40()
{
    fumator=false;
    sedentarism="";
}
pacient40::pacient40(pacient40 &p)
{
    nume=p.nume;
    prenume=p.prenume;
    varsta=p.varsta;
    adresa=p.adresa;
    colesterol=p.colesterol;
    tensiune=p.tensiune;
    data=p.data;
    fumator=p.fumator;
    sedentarism=p.sedentarism;
}

istream& operator>>(istream& in,pacient40& p)
{
    p.citire(in);
    return in;
}
void pacient40::citire(istream& in)
{
    pacient::citire(in);
    cout<<"Pacientul este fumator?(da/nu)";
    string aux;
    in>>aux;
    if(aux=="da")
        fumator=true;
    else
        fumator=false;

    cout<<"Sedentarism?(scazut, mediu sau ridicat)";
    in>>sedentarism;
}

ostream& operator<<(ostream& out,pacient40& p)
{
    p.afisare(out);
    return out;
}

void pacient40::afisare(ostream& out)
{
    pacient::afisare(out);
    if(fumator==true)
        out<<"Pacientul este fumator"<<endl;
    else
        out<<"Pacientul Nu este fumator"<<endl;

    out<<"Sedenatarismul pacientului este:"<<sedentarism<<endl;
}
///--------------------------------------------------------------
class copii:public pacient
{
private:
    bool risc;
    string nume_tata;
    string nume_mama;
    float proteinaC;
public:
    copii(string, string, int, string, int, int, string, bool, string, string, float);
    ~copii();
    copii(copii&);

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    friend istream& operator>>(istream&, copii&);
    friend ostream& operator<<(ostream&, copii&);

    get_risc(){return risc;}
};

copii::copii(string nume="", string prenume="", int varsta=0, string adresa="", int colesterol=0, int tensiune=0, string data="",bool risc=false, string nume_tata="", string nume_mama="", float proteinaC=0):pacient(nume,prenume,varsta,adresa,colesterol,tensiune,data)
{
    this->risc=risc;
    this->nume_tata=nume_tata;
    this->nume_mama=nume_mama;
    this->proteinaC=proteinaC;
}
copii::~copii()
{
    risc=false;
    nume_tata="";
    nume_mama="";
    proteinaC=0;
}
copii::copii(copii &p)
{
    nume=p.nume;
    prenume=p.prenume;
    varsta=p.varsta;
    adresa=p.adresa;
    colesterol=p.colesterol;
    tensiune=p.tensiune;
    data=p.data;
    risc=p.risc;
    nume_tata=p.nume_tata;
    nume_mama=p.nume_mama;
    proteinaC=p.proteinaC;
}
istream& operator>>(istream& in,copii& p)
{
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, copii& p)
{
    p.afisare(out);
    return out;
}
void copii::afisare(ostream &out)
{
    pacient::afisare(out);
    if(risc==true)
        out<<"Exista precedent in familie cu o boala cardiovaculara"<<endl;
    else
        out<<"NU Exista precedent in familie cu o boala cardiovaculara"<<endl;

    out<<"Numele tatalui:"<<nume_tata<<endl;
    out<<"Numele mamei:"<<nume_mama<<endl;
    out<<"proteina c:"<<proteinaC<<endl;
}
void copii::citire(istream &in)
{
    pacient::citire(in);
    cout<<"Pacientul are precedent in familie cu o boala cardiovaculara?(da/nu)";
    string aux;
    in>>aux;
    if(aux=="da")
        risc=true;
    else
        risc=false;

    cout<<"Nume tata:";
    in.get();
    string z;
    getline(in,z);
    nume_tata=z;

    cout<<"Nume mama:";
    //in.get();
    string k;
    getline(in,k);
    nume_mama=k;

    cout<<"Proteina C:";
    in>>proteinaC;
}
void tip(pacient *&p, int &i)
{
    string s;
    cout<<"\n";
    cout<<"Introduceti tipul pacientului "<<i+1<<": ";
    cin>>s;
    try
    {

        if(s=="pacient40")
        {
            p=new pacient40;
            cin>>*p;
            i++;
        }
        else if(s=="copii")
        {
            p=new copii;
            cin>>*p;
            i++;
        }
        else if(s=="pacient")
        {
            p=new pacient;
            cin>>*p;
            i++;
        }
        else
            throw 10;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus un pacient valid. Incercati pacient40, copii sau pacient.\n ";
    }
}

int main()
{
    pacient **v;
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;

    try
    {
        v=new pacient*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
        /// sau il pot face regizor/actor)
        for(int i=0; i<n;)
            tip(v[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa
    }
    catch (bad_alloc var)
    {
        cout<<"Numarul introdus trebuie sa fie pozitiv. Bad Alloc!\n";
        exit(EXIT_FAILURE);
    }


    int x = 1;
    while(x != 0)
    {
        cout<<"Alegeti operatia pe care doriti sa o efectuati: "<<'\n';
        cout<<"0 - inchidere program"<<'\n';
        cout<<"1. A afisa infomatiile medicale pentru toti pacientii."<<'\n';
        cout<<"2. A afisa infomatiile medicale pentru toti pacientii adulti cu factor de risc cardiovascular ridicat."<<'\n';
        cout<<"3. A afișa infomațiile medicale pentru toți pacienții copii cu factor de risc cardiovascular"<<'\n';
        cout<<"4 "<<'\n';
        cin>>x;
        if(x == 1)
        {
            for(int i=0;i<n;i++){
            cout<<"\n"<<*v[i];
            cout<<"--------------------------\n";
        }
        }
        else if(x == 2)
        {
            for(int i=0;i<n;i++)
                if(v[i]->get_colesterol()>240)
                    cout<<*v[i];

        }
        else if(x == 3)
        {
            for(int i=0;i<n;i++)
                if(v[i]->get_risc()==true)
                    cout<<*v[i];
        }


        cout<<"Introduceti o valoare intre 0 si 4"<<'\n';
        system("pause");
        system("cls");

    }
    return 0;
}

