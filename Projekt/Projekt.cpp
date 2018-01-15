#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

// Podczas pisania aplikacji korzystalam miedzy innymi z pomocy z nastepujacych stron internetowych:
// http://www.cplusplus.com/forum/general/58945/

// stale
const int ESCAPE = 27;

// zmienne globalne
char znakAscii;
int szerokoscEkranu, wysokoscEkranu;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
	COORD cursorPosition;
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(console,cursorPosition);
}  

void wypiszZasady()
{
    cout<<"Witam w programie rysowania znakami ASCII :)"<<endl;
    cout<<"Najpierw kilka zasad: "<<endl;
    cout<<"*Mozesz przesuwaæ figure strzalkami(lewo,prawo,gora,dol)"<<endl;
    cout<<"*Mozesz pomniejszac lub powiekszac firuge znakiem + lub -"<<endl;
    cout<<"UWAGA! figura bedzie poruszala sie tylko w obszarze twojego ekranu"<<endl;
    cout<<"Zacznijmy zabawe!"<<endl;    
}

void wypiszBlad()
{
    system("cls");
    cout << "Przekroczyles zakres ekranu" << endl;
    cout << "Nacisnij klawisz aby sprobowac jeszcze raz";
    getch();
}

bool czyMogeWykonacRuch(int rozmiarFigury, int przesunieciePoziome, int przesunieciePionowe)
{
    if((szerokoscEkranu/2 - rozmiarFigury/2 + przesunieciePoziome < 0) || // lewa krawedz
       (wysokoscEkranu/2 - rozmiarFigury/2 + przesunieciePionowe < 0) || // gorna krawedz
       (szerokoscEkranu/2 + rozmiarFigury/2 + przesunieciePoziome >= szerokoscEkranu) || // prawa krawedz
       (wysokoscEkranu/2 + rozmiarFigury/2 + przesunieciePionowe >= wysokoscEkranu)) // dolna krawedz
    {    
        wypiszBlad();
        return false;
    }
    else
    {
        return true;
    }
}

void rysujFigure(int rozmiarFigury, int przesunieciePoziome, int przesunieciePionowe)
{
    for (int wiersz = 0; wiersz < rozmiarFigury; wiersz++)
    {
        gotoxy(szerokoscEkranu/2 - rozmiarFigury/2 + przesunieciePoziome,
                wysokoscEkranu/2 - rozmiarFigury/2 + wiersz + przesunieciePionowe);
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
                    if(rozmiarFigury % 2 == 0)
                    {
                        cout << " ";
                    }
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
    }
}

int main()
{
    int rozmiarFigury,
        przesunieciePoziome = 0,
        przesunieciePionowe = 0;
    char przycisk;

    // Pobranie szerokosci i wysokosci ekranu
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console,&csbi);
    szerokoscEkranu = csbi.dwSize.X;
    wysokoscEkranu = csbi.dwSize.Y;

    wypiszZasady();

    cout << "Najpierw podaj znak ASCII, ktorym bedziemy rysowac: ";
    cin >> znakAscii;
    cout << "Teraz podaj poczatkowy rozmiar figury: ";
    cin >> rozmiarFigury;

    do
    {
        system("cls");
        rysujFigure(rozmiarFigury,przesunieciePoziome,przesunieciePionowe);
        przycisk = _getch();

        switch(przycisk)
        {
            case '+':
                if(czyMogeWykonacRuch(rozmiarFigury+1,przesunieciePoziome,przesunieciePionowe))
                    rozmiarFigury++;
                break;
            case '-':
                if(czyMogeWykonacRuch(rozmiarFigury-1,przesunieciePoziome,przesunieciePionowe))
                    rozmiarFigury--;
                break;
            case 'a':
            case 75:    // w lewos
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome-1,przesunieciePionowe))
                    przesunieciePoziome--;
                break;
            case 's':
            case 80:    // w dol
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome,przesunieciePionowe+1))
                    przesunieciePionowe++; // dodajemy poniewaz rosnie w dol
                break;
            case 'w':
            case 72:    // w gore
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome,przesunieciePionowe-1))
                    przesunieciePionowe--; // odejmujemy poniewaz maleje w gore
                break;
            case 'd':
            case 77:    // w prawo
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome+1,przesunieciePionowe))
                    przesunieciePoziome++;
                break;
            default:
                break;
        }
    } while(przycisk != ESCAPE);

    return EXIT_SUCCESS;
}