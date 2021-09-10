#include <iostream>
#include <stdlib.h>
using namespace std;

void menu_output(){
    cout<<"\n Nume Prenume Grupa - Proiect - Nume proiect: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Actiune 1 din meniu"; cout<<"\n";
    cout<<"2. Actiune 2 din meniu"; cout<<"\n";
    cout<<"3. Actiune 3 din meniu"; cout<<"\n";
    cout<<"4. Actiune 4 din meniu"; cout<<"\n";
    cout<<"5. Actiune 5 din meniu"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;

    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            ///cod corespunzator pentru optiunea 1
        }
        if (option==2)
        {
            ///----||---- 2
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
