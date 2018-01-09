#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

char znakAscii;

void wypiszZasady()
{
    
    cout<<"Witam w programie rysowania znakami ASCII :)"<<endl;
    cout<<"Najpierw kilka zasad: "<<endl;
    cout<<"*Mozesz przesuwaæ figure strzalkami(lewo,prawo,gora,dol)"<<endl;
    cout<<"*Mozesz pomniejszac lub powiekszac firuge znakiem + lub -"<<endl;
    cout<<"UWAGA! figura bedzie poruszala sie tylko w obszarze twojego ekranu"<<endl;
    cout<<"Zacznijmy zabawe!"<<endl;
     
}

int main()
{
    int szerokoscZnaku, wysokoscZnaku;
    wypiszZasady();
    cout<<"Najpierw podaj znak ASCII, ktorym bedziemy rysowac"<<endl;
    cin>>znakAscii;
    cout<<"Teraz podaj wymiar poczatkowy znaku "<<endl;
    cout<<"Szerokosc:";
    cin>>szerokoscZnaku;
    cout<<"Wysokosc:";
    cin>>wysokoscZnaku;
    cout<<endl; 
    cout<<endl;
    cout<<endl;
    cout<<wysokoscZnaku<<endl;
    cout<<szerokoscZnaku<<endl;
    cout<<znakAscii<<endl;


    getch();
    return EXIT_SUCCESS;
}