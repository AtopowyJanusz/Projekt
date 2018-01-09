#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void menu()
{
    int znakAscii, szerokoscZnaku, wysokoscZnaku;
 cout<<"Witam w programie rysowania znakami ASCII :)"<<endl;
 cout<<"Najpierw kilka zasad: "<<endl;
 cout<<"*Mozesz przesuwaæ figure strzalkami(lewo,prawo,gora,dol)"<<endl;
 cout<<"*Mozesz pomniejszac lub powiekszac firuge znakiem + lub -"<<endl;
 cout<<"UWAGA! figura bedzie poruszala sie tylko w obszarze twojego ekranu"<<endl;
 cout<<"Zacznijmy zabawe!"<<endl;
 cout<<"Najpierw podaj znak ASCII, ktorym bedziemy rysowac"<<endl;
 cin>>znakAscii;
 cout<<"Teraz podaj wymiar poczatkowy znaku "<<endl;
 cout<<"Szerokosc:";
 cin>>szerokoscZnaku;
 cout<<"Wysokosc:";
 cin>>wysokoscZnaku;
 cout<<endl; 
}

int main()
{
    menu();
    getchar();
    return EXIT_SUCCESS;
}