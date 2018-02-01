#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

// Podczas pisania aplikacji korzystalam miedzy innymi z pomocy z nastepujacych stron internetowych:
// http://www.cplusplus.com/forum/general/58945/
// https://stackoverflow.com/questions/15575799/c-how-to-restrict-input-to-one-char-at-a-time
// https://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer

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

void wczytajZnakASCII()
{
    string wejscie;

    do {
        getline(cin,wejscie);
        if(wejscie.length() != 1)
        {
            cout << "Bledna wartosc. Podaj ponownie: ";
        }
        else {
            znakAscii = wejscie[0];
        }
    } while (wejscie.length() != 1);
}

int wczytajRozmiarFigury()
{
    int rozmiarFigury;

    do {
        cin >> rozmiarFigury;
        
        if((cin.fail()) || (rozmiarFigury < 0) || (rozmiarFigury > wysokoscEkranu)) 
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Bledna wartosc rozmiaru figury. Podaj ponownie: ";
        }
        else 
        {
            return rozmiarFigury;
        }
    } while ((cin.fail()) || (rozmiarFigury < 0) || (rozmiarFigury > wysokoscEkranu));
}

void wczytajPrzycisk(int rozmiarFigury)
{
    int przesunieciePoziome = 0,
        przesunieciePionowe = 0;

    char przycisk;

    do
    {
        system("cls");
        rysujFigure(rozmiarFigury,przesunieciePoziome,przesunieciePionowe);
        przycisk = _getch();

        switch(przycisk)
        {
            case '+':
                if(czyMogeWykonacRuch(rozmiarFigury + 1,przesunieciePoziome,przesunieciePionowe))
                    rozmiarFigury++;
                break;
            case '-':
                if(czyMogeWykonacRuch(rozmiarFigury - 1,przesunieciePoziome,przesunieciePionowe))
                    rozmiarFigury--;
                break;
            case 'a':
            case 75:    // w lewo
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome - 1,przesunieciePionowe))
                    przesunieciePoziome--;
                break;
            case 's':
            case 80:    // w dol
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome,przesunieciePionowe + 1))
                    przesunieciePionowe++; // dodajemy poniewaz rosnie w dol
                break;
            case 'w':
            case 72:    // w gore
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome,przesunieciePionowe - 1))
                    przesunieciePionowe--; // odejmujemy poniewaz maleje w gore
                break;
            case 'd':
            case 77:    // w prawo
                if(czyMogeWykonacRuch(rozmiarFigury,przesunieciePoziome + 1,przesunieciePionowe))
                    przesunieciePoziome++;
                break;
            default:
                break;
        }
    } while(przycisk != ESCAPE);
}

int main()
{
    int rozmiarFigury;
    
    // Pobranie szerokosci i wysokosci ekranu
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console,&csbi);
    szerokoscEkranu = csbi.dwSize.X;
    wysokoscEkranu = csbi.dwSize.Y;

    wypiszZasady();

    cout << "Najpierw podaj znak ASCII, ktorym bedziemy rysowac: ";
    wczytajZnakASCII();

    cout << "Teraz podaj poczatkowy rozmiar figury: ";
    rozmiarFigury = wczytajRozmiarFigury();

    wczytajPrzycisk(rozmiarFigury);  

    return EXIT_SUCCESS;
}