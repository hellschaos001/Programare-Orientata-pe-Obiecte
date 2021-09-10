#include <iostream>
#include <stdlib.h> ///folosit pentru functia system din meniu
#include <string.h>
using namespace std;

class persoana{
private:
    char *nume;
    int varsta;

public:
    persoana(char *num = NULL, int varsta=0)
    {
        if (num != NULL)    ///vrem sa ne asiguram ca num este diferit de NULL inainte de a aloca memorie
        {this->nume=new char[strlen(num)];  ///daca nu am fi facut verificarea am fi avut probleme la alocare cand apeleaza strlen(NULL)
        strcpy(nume,num);}
        else
            this->nume=num;

        this->varsta=varsta;
    }
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, persoana& z);
    friend ostream& operator<<(ostream &out, persoana& z);
};
void persoana::citire(istream &in){
    cout<<"Cititi numele: ";
    char *num = new char[256];  ///alocam memorie pentru o variabila suplimentara de tip sir de caractere (suficienta memorie care ne permite citirea unui nume)
    in.getline(num,256); ///citim numele in aceasta variabila
    this->nume=new char[strlen(num)]; ///alocam apoi memorie pentru data membru "nume" fix cat are numele persoanei, pentru a nu aloca spatiu inutil
    strcpy(nume,num); ///copiem cu strcpy
    cout<<"Varsta=";
    in>>varsta;
}
istream& operator>>(istream& in,persoana& z){
    z.citire(in);
    return in;
}
void persoana::afisare(ostream &out){
    out<<"Numele persoanei este:"<<nume;
    out<<"\n";
    out<<"Varsta persoanei este:"<<varsta;
    out<<"\n";
}
ostream& operator<<(ostream& out, persoana& z){
    z.afisare(out);
    return out;
}

void menu_output(){
    cout<<"\n Nume Prenume Grupa - Proiect - Nume proiect: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste n obiecte"; cout<<"\n";
    cout<<"2. Afiseaza cele n obiecte"; cout<<"\n";
    cout<<"3. Actiune 3 din meniu"; cout<<"\n";
    cout<<"4. Actiune 4 din meniu"; cout<<"\n";
    cout<<"5. Actiune 5 din meniu"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    int n=0;
    persoana *p;
    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
           cout<<"Dati numarul de obiecte";
           cin>>n;
           cin.get(); ///pentru a elimina ENTER-ul din buffer
           if (n>0){
                p=new persoana[n];
                for (int i=0;i<n;i++)
                    {cin>>p[i];cin.get();}

           }
           else
            cout<<"Valoarea n trebuie sa fie pozitiva";

        }
        if (option==2)
        {
            if (n!=0)
            {
                for (int i=0;i<n;i++)
                cout<<p[i];
            }
        }
        if (option==3)
        {
            ///----||---- 3
        }
        if (option==4)
        {
           ///----||---- 4
        }
        if (option==5)
        {
            ///----||---- 5
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
