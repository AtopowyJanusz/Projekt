#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

// Podczas pisania aplikacji korzystalam miedzy innymi z pomocy z nastepujacych stron internetowych:
// http://www.cplusplus.com/forum/general/58945/

char znakAscii;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void wypiszZasady()
{
    cout<<"Witam w programie rysowania znakami ASCII :)"<<endl;
    cout<<"Najpierw kilka zasad: "<<endl;
    cout<<"*Mozesz przesuwaæ figure strzalkami(lewo,prawo,gora,dol)"<<endl;
    cout<<"*Mozesz pomniejszac lub powiekszac firuge znakiem + lub -"<<endl;
    cout<<"UWAGA! figura bedzie poruszala sie tylko w obszarze twojego ekranu"<<endl;
    cout<<"Zacznijmy zabawe!"<<endl;    
}

void rysujFigure( int rozmiarFigury)
{
    for (int wiersz = 0; wiersz < rozmiarFigury; wiersz++)
    {
        for(int kolumna = 0; kolumna < rozmiarFigury; kolumna++)
        {
            if(wiersz < rozmiarFigury/2)
            {
                if(wiersz == kolumna)
                {
                    cout << znakAscii;
                }
                else if(wiersz+kolumna == rozmiarFigury - 1)
                {
                    cout << znakAscii;
                }
                else
                {
                    cout << " ";
                }
            }
            else 
            {
                if(kolumna == rozmiarFigury/2)
                {
                    cout << znakAscii;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
    
int main()
{
    int rozmiarFigury,
        szerokoscEkranu,
        wysokoscEkranu;

    // Pobranie szerokosci i wysokosci ekranu
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console,&csbi);
    szerokoscEkranu = csbi.dwSize.X;
    wysokoscEkranu = csbi.dwSize.Y;

    wypiszZasady();

    cout << "Najpierw podaj znak ASCII, ktorym bedziemy rysowac" << endl;
    cin >> znakAscii;
    cout << "Teraz podaj poczatkowy rozmiar figury : ";
    cin >> rozmiarFigury;
   

    system("cls");

    rysujFigure(rozmiarFigury);





    getch();
    return EXIT_SUCCESS;
}