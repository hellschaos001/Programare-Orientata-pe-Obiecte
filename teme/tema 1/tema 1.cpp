#include <iostream>
#include <string.h>

using namespace std;

class student{
private:
    string nume;
    int anul_nasterii;
    int numar_credite;
    double medie_generala;
public:
    ///citesc informatia despre fiecare obiect din clasa
    void citire(istream &in);

    ///getteri
    string get_nume(){return nume;};
    int get_anul_nasterii(){return anul_nasterii;};
    int get_numar_credite(){return numar_credite;};
    double get_medie_generala(){return medie_generala;};
    ///setteri
    void set_nume(string a){
        nume=a;
    };
    void set_anul_nasterii(int a){
        anul_nasterii=a;
    }
    void set_numar_credite(int a){
        numar_credite=a;
    }
    void set_medie_generala(int a){
        medie_generala=a;
    }
    ///afiseaza un obiect
    void afisare(ostream &out);
    ///constructor
    student();
    ///destructor
    ~student();

    friend istream& operator>>(istream &in, student& s);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, student& s);  ///supraincarcare pe <<
    ///clasa prieten grupa
    friend class grupa;
};

class grupa{
private:
    int nr_studenti;
    student *s;
    double media_grupei;
public:
    ///constructor de initializare
    grupa();
    ///destructor
    ~grupa();
    void citire();
    void afisare();
    void eliminare_student();
    void adaugare_student();
    void verificare_student();
    void calculare_media_grupei();
};
grupa::grupa()
{
    nr_studenti=0;
    media_grupei=0;
    s = new student[0];
}
grupa::~grupa()
{
    nr_studenti = 0;
    media_grupei = 0;
    delete []s;
}

void grupa::citire()
{
    cout<<"numarul de studenti:";cin>>nr_studenti;cout<<endl;
    s = new student[nr_studenti]; /// alocare dinamica
    for(int i=0;i<nr_studenti;i++)
        cin>>s[i];
}

void grupa::afisare()
{
    cout<<"numarul de studenti:"<<nr_studenti<<endl;
    calculare_media_grupei();
    cout<<"media generala a grupei:"<<media_grupei<<endl<<endl;
    for(int i=0;i<nr_studenti;i++)
        cout<<"studentul nr "<<i+1<<endl<<s[i];
}
void grupa::calculare_media_grupei()
{
    int suma=0;
    for(int i=0;i<nr_studenti;i++)
    {
        suma=suma+s[i].medie_generala;
    }
    media_grupei=suma/nr_studenti;
}
void grupa::eliminare_student()
{
    int k=0;
    string a;
    cout<<"numele studentului eliminat:";cin>>a;
    student *s1=new student[nr_studenti];
    student stud;
    stud.set_nume(a);
    for(int i=0;i<nr_studenti;i++)
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
    nr_studenti--;
    s=new student[nr_studenti];
    for(int i=0;i<nr_studenti;i++)
        s[i]=s1[i];
}
void grupa::adaugare_student()
{
    student *s2=new student[nr_studenti+1];
    student stud2;
    cin>>stud2;
    for(int i=0;i<nr_studenti;i++)
        s2[i]=s[i];
    s2[nr_studenti]=stud2;

    delete []s;
    nr_studenti++;
    s=new student[nr_studenti];
    for(int i=0;i<nr_studenti;i++)
        s[i]=s2[i];
    delete []s2;
}
void grupa::verificare_student()
{
    student stud3;
    string b;
    cout<<"introduceti numele studentului caruia vreti sa ii verificati existenta: ";cin>>b;
    stud3.set_nume(b);
    int k=0;
    for(int i=0;i<nr_studenti;i++)
        if(stud3.nume==s[i].nume)
            k++;

    if(k!=0)
        cout<<"exista student cu acest nume"<<endl;
    else
        cout<<"nu exista student cu acest nume"<<endl;
}
void student::citire(istream &in)
{
    cout<<"numele studentului:";cin>>nume;cout<<endl;
    cout<<"anul nasterii:";cin>>anul_nasterii;cout<<endl;
    cout<<"numar credite:";cin>>numar_credite;cout<<endl;
    cout<<"media generala:";cin>>medie_generala;cout<<endl;
    cout<<"---------------------------------------------------"<<endl;
}
istream& operator>>(istream& in,student& s){
    s.citire(in);
    return in;
}
void student::afisare(ostream &out)
{
    cout<<"numele studentului:"<<nume<<endl;
    cout<<"anul nasterii:"<<anul_nasterii<<endl;
    cout<<"numar credite:"<<numar_credite<<endl;
    cout<<"media generala:"<<medie_generala<<endl;
    cout<<"---------------------------------------------------"<<endl;
}
ostream& operator<<(ostream& out,student& s){
    s.afisare(out);
    return out;
}
student::student(){
    nume='\n';
    anul_nasterii=0;
    numar_credite=0;
    medie_generala=0;
}
student::~student(){
    nume='\n';
    anul_nasterii=0;
    numar_credite=0;
    medie_generala=0;
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
            g.citire();
        }
        if (option==2)
        {
            g.afisare();
        }
        if (option==3)
        {
            g.eliminare_student();
        }
        if (option==4)
        {
            g.adaugare_student();
        }
        if (option==5)
        {
            g.verificare_student();
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

int main()
{
    menu();
    return 0;
}
