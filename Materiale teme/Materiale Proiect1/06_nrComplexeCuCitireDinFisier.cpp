#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

///Obiect = instanta a clasei (i.e. declarare a unei variabile de tipul clasei pe care am definit-o ulterior)
///clasa este DEFINITA si obiectele sunt DECLARATE
///clasa = tip definit de programator
class complex {
private:
    ///Date membre:
    double real;
    double imaginar;
public:
    ///Metode:

    ///(Constructor = prima metoda care se apeleaza atunci cand este declarat un obiect)
    complex ();                 ///constructor de initializare FARA parametrii
    complex (double, double);   ///constructor initializare CU parametrii
    complex (complex&);                     ///constructor copiere
    ~complex ();                            ///destructor
    ///destructorul este metoda care se apeleaza atunci cand un obiect nu mai este "folosit"
    void set_real(double);                     ///set
    void set_imaginar(double);                 ///set
    double get_real(){return real;};           ///get
    double get_imag(){return imaginar;};       ///get
    void afisare(ostream &out);
    void citire(istream &in);
    void citireFisier (ifstream& in);           ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CITIRE DIN FISIER
    friend istream& operator>>(istream &in, complex& z);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, complex& z); ///supraincarcare pe <<
    friend ifstream& operator>>(ifstream& in, complex& z);  ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CITIRE DIN FISIER
    double modul(); ///functia modul
    complex& operator=(complex &z); ///supraincarcarea operatorului de atribuire (doar ca metoda nu ca functie friend)
    friend complex& operator+(complex& z1, complex& z2); ///supraincarcare operator +
    friend complex& operator*(complex& z1, complex& z2); ///supraincarcare operator *
    friend complex& operator/(complex& z1, complex& z2); ///supraincarcare operator /
};
///MET1 pentru a scrie Constructori de initializare
complex::complex(){
    this->real = 0;
    this->imaginar = 0;
}

complex::complex(double real, double imaginar){
    this->real = real;
    this->imaginar = imaginar;
}
///Met2 pt a scrie constructori de initializare
/**
///constructor de initializare cu PARAMETRII IMPLICITI
complex::complex(double real=0, double imaginar=0){
    this->real = real;
    this->imaginar = imaginar;
}
*/
complex::complex(complex &z){
    this->real = z.real;
    this->imaginar = z.imaginar;
}
complex::~complex(){
    this->real=0;
    this->imaginar=0;
}
///implementarea unei functii in afara clasei
///TIPUL_FUNCTIEI NUMELE_CLASEI :: NUMELE_FUNCTIEI (PARAMETRII)
void complex::set_real(double x){
    real = x;
}
void complex::set_imaginar(double y){
    imaginar=y;
}
void complex::citire(istream &in){
    cout<<"Cititi partea reala: ";
    in>>real;
    cout<<"Cititi partea imaginara: ";
    in>>imaginar;
}
istream& operator>>(istream& in,complex& z){
    z.citire(in);
    return in;
}
void complex::citireFisier(ifstream &in){             ///!!!!!!!!!!!!!!!!! METODA PENTUR CITIRE DIN FISIER
    in>>real;
    in>>imaginar;
}
ifstream& operator>>(ifstream& in, complex& z){     ///!!!!!!!!!!!!!!!!!!!!! SUPRAINCARCARE PE CITIRE DIN FISIER
    z.citireFisier(in);
    return in;
}
void complex::afisare(ostream &out){
    if (imaginar==0) {
        out<<real;
    }
    else{
        if (imaginar < 0){
            out<<real<<imaginar<<"*i";
        }
        else{
            out<<real<<"+"<<imaginar<<"*i";
        }
    }
}
ostream& operator<<(ostream& out, complex& z){
    z.afisare(out);
    return out;
}
double complex::modul(){
    return sqrt(real*real+imaginar*imaginar);
}
complex& complex::operator=(complex &z){
    real=z.real;
    imaginar=z.imaginar;
}
inline complex& operator+(complex &z1, complex& z2){
    complex *z = new complex;
    z->real = z1.real + z2.real;
    z->imaginar = z1.imaginar + z2.imaginar;
    return *z;
}
inline complex& operator*(complex &z1, complex& z2){
    complex *z=new complex;
    z->real = z1.real * z2.real - z1.imaginar * z2.imaginar;
    z->imaginar = z1.real * z2.imaginar + z2.real * z1.imaginar;
    return *z;
}
complex& operator/(complex &z1, complex &z2){
    complex *z=new complex;
    z->real = (z1.real*z2.real + z1.imaginar * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    z->imaginar = (z2.real * z1.imaginar - z1.real * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    return *z;
}
int main()
{
    ifstream f("date.in");
    complex a,b;
    f>>a;
    f>>b;
    cout<<a<<endl<<b<<endl;
    f.close();
    return 0;
}






