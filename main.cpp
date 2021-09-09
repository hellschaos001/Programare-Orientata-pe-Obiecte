#include <iostream>
#include <string.h>

using namespace std;

class student{
private:
    string nume;
    int anulNasterii;
    int nrCredite;
    double medieGenerala;
public:
    ///getter
    string get_nume(){return nume;};
    int get_anulNasterii(){return anulNasterii;};
    int get_nrCredite(){return nrCredite;};
    double get_medieGenerala(){return medieGenerala;};
    ///setter
    void set_nume(string a){nume=a;}
    void set_anulNasterii(int a){anulNasterii=a;};
    void set_nrCredite(int a){nrCredite=a;};
    void set_medieGenerala(double a){medieGenerala=a;};

    ///constructor si destructor
    student();
    ~student();

    ///supraincarcarea pe operator >> si <<
    void citire(istream &in);
    friend istream& operator>>(istream &in, student& s);

    void afisare(ostream &out);
    friend ostream& operator<<(ostream &out, student& s);

    ///mostenire
    friend class grupa;
};
student::student() {
    this->nume = '\n';
    this->anulNasterii=0;
    this->nrCredite=0;
    this->medieGenerala=0;
}
student::~student() {
    this->nume = '\n';
    this->anulNasterii=0;
    this->nrCredite=0;
    this->medieGenerala=0;
}
istream& operator>>(istream &in, student &s){
    s.citire(in);
    return in;
}
void student::citire(istream &in){
    cout<<"Numele studentlui:";in>>nume;
    cout<<"Anul nasterii:";in>>anulNasterii;
    cout<<"Numarul de credite:";in>>nrCredite;
    cout<<"Media generala:";in>>medieGenerala;
}

ostream& operator<<(ostream &out, student &s){
    s.afisare(out);
    return out;
}
void student::afisare(ostream &out)
{
    out<<"Numele studentlui:"<<nume<<endl;
    out<<"Anul nasterii:"<<anulNasterii<<endl;
    out<<"Numarul de credite:"<<nrCredite<<endl;
    out<<"Media generala:"<<medieGenerala<<endl;
    out<<"--------------"<<endl;
}

class grupa{
private:
    student *s;
    int nrStudenti;
    double mediaGrupei;
public:
    ///constructor si destructor
    grupa();
    ~grupa();
    ///supraincarcarea pe operator >> si <<
    void citire(istream &in);
    friend istream& operator>>(istream &in, grupa& g);

    void afisare(ostream &out);
    friend ostream& operator<<(ostream &out, grupa& g);

    /// eliminare student din grupa
    void eliminareStudent();
    ///adaugare student in grupa
    void adaugareStudent();
    ///verificare student din grupa dupa nume
    void verificareStudent();
    ///Calculare media grupei
    void calculareMediaGrupei();
};
grupa::grupa(){
    this->nrStudenti = 0;
    this->mediaGrupei = 0;
    s = new student[0];///alocam dinamic un vector de studenti gol ( 0 -> numarul de elemente din vector )
}

grupa::~grupa() {
    this->nrStudenti = 0;
    this->mediaGrupei = 0;
    delete[] s;
}

istream& operator>>(istream &in, grupa& g){
    g.citire(in);
    return in;
}
void grupa::citire(istream &in){
    cout<<"Numarul de studenti:";in>>nrStudenti;
    s = new student[nrStudenti];
    for(int i=0;i<nrStudenti;i++)
        in>>s[i];
}

ostream& operator<<(ostream &out, grupa& g){
    g.afisare(out);
    return out;
}
void grupa::afisare(ostream &out){
    out<<"Numarul de studenti ai grupei:"<<nrStudenti<<endl;
    calculareMediaGrupei();
    out<<"Media generala a grupei:"<<mediaGrupei<<endl;
    for(int i=0;i<nrStudenti;i++)
        out<<"studentul nr "<<i+1<<endl<<s[i];
    out<<endl;
}


void grupa::calculareMediaGrupei() {
    int suma=0;
    for(int i=0;i<nrStudenti;i++)
        suma=suma+s[i].medieGenerala;
    mediaGrupei=suma/nrStudenti;
}

void grupa::eliminareStudent() {
    int k=0;
    string a;
    cout<<"numele studentului eliminat:";cin>>a;
    student *s1=new student[nrStudenti];
    student stud;
    stud.set_nume(a);
    for(int i=0;i<nrStudenti;i++)
        if(stud.nume!=s[i].nume)
        {
            s1[i-k]=s[i];
        }
        else
        {
            cout<<"ai eliminat"<<endl;
            k++;
        }
    if(k==0)
        cout<<"nu exista numele introdus";
    delete []s;
    nrStudenti-=k;
    s=new student[nrStudenti];
    for(int i=0;i<nrStudenti;i++)
        s[i]=s1[i];
}

void grupa::adaugareStudent() {
    student *s2=new student[nrStudenti+1];
    student stud2;
    cin>>stud2;
    for(int i=0;i<nrStudenti;i++)
        s2[i]=s[i];
    s2[nrStudenti]=stud2;

    delete []s;
    nrStudenti++;
    s=new student[nrStudenti];
    for(int i=0;i<nrStudenti;i++)
        s[i]=s2[i];
    delete []s2;
}
void grupa::verificareStudent() {
    student stud3;
    string b;
    cout<<"introduceti numele studentului caruia vreti sa ii verificati existenta: ";cin>>b;
    stud3.set_nume(b);
    int k=0;
    for(int i=0;i<nrStudenti;i++)
        if(stud3.nume==s[i].nume)
            k++;

    if(k!=0)
        cout<<"exista student cu acest nume"<<endl;
    else
        cout<<"nu exista student cu acest nume"<<endl;
}

void menu_output(){
    cout<<"\n Nume Prenume Grupa - Proiect - Nume proiect: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Cititi studentii din grupa"; cout<<"\n";
    cout<<"2. Afisati studentii din grupa"; cout<<"\n";
    cout<<"3. eliminare student din grupa"; cout<<"\n";
    cout<<"4. Adaugati student in grupa"; cout<<"\n";
    cout<<"5. Verificare existenta student dupa nume"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    grupa g;
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            cin>>g;
        }
        if (option==2)
        {
            cout<<g;
        }
        if (option==3)
        {
            g.eliminareStudent();
        }
        if (option==4)
        {
            g.adaugareStudent();
        }
        if (option==5)
        {
            g.verificareStudent();
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>5)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
int main() {
    menu();
    return 0;
}
