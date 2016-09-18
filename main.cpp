#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

string nick, nazwisko, miasto;
int kasa, punkty, ktorydzien, wybor, iledni, cnarkotyk[6], inarkotyk[6], nrsave, ile, ktory, hp;

//kolory

void csilver() //srebrny
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
}

void cgold() //zloty jasny
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
}

void cgreen() //jasno zielony
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
}

void cred() //jasno czerwony
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
}

void cnormal() //szary
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  );
}

//FUNKCJE GRY

void smierc()
{
    system("cls");
    cout<<"      -------------------------------------------- "<<endl;
    cout<<"     |               JESTES MARTWY                |"<<endl;
    cout<<"     |         twoj wynik zostal zapisany         |"<<endl;
    cout<<"      -------------------------------------------- "<<endl;
    system("pause");
}

void podroz()
{
string miastobuf;
    while(true)
        {
            cout<<"Jestes w "<<miasto<<", wybierz dokand chcesz sie udac"<<endl;
            miastobuf.insert( 0, miasto, 0, 8 );
            //test - cout<<"bufor miasta to "<<miastobuf<<endl<<endl;
            cin>>miasto;
            if (miastobuf==miasto)
                {
                    cout<<"przeciez juz jestes w "<<miasto<<" baranie!"<<endl;
                    Sleep(2000);
                    miastobuf.erase( 0, 8 ); //Kasujemy od zerowej pozycji (czyli jedenastego znaku) osiem znakÛw
                }
            else
                {
                    ktorydzien=ktorydzien+1;
                    kasa=kasa-5;
                    miastobuf=="zero";
                    break;
                }
        }
}

void gotoxyd(int x, int y) //DYNAMICZNE
{

    if (iledni>=100)
        {
            x=x-1;
               /* if (iledni>=100)
                    {
                        x=x-1;
                    }*/
        }
    COORD c;
    c.X = x-1;
    c.Y = y-1;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

void gotoxys(int xx, int yy) //STATYCZNE
{
    COORD c;
    c.X = xx-1;
    c.Y = yy-1;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

void gra() // JUZ PRZEFORMATOWANA
{
bool wyjscie;
int x;
if (hp<=0)
{
    smierc();
}
HANDLE hOut;
hOut = GetStdHandle( STD_OUTPUT_HANDLE );


char wybor1;

        do
        {
        cout<<" --------------";
        csilver(); gotoxys(58, 1); cout<<"-------------------"<<endl;
        cout<<"|Nick - "<<nick;
        gotoxyd(58, 2); cout<<"Do konca gry "<<iledni-ktorydzien<<" dni|"<<endl;
        cgold(); cout<<"|KASA - "<<kasa;
        csilver(); gotoxys(61, 3); cout<<"Miasto - "<<miasto<<endl;
        cgreen(); cout<<"|Punkty - "<<punkty<<endl;
        cred(); cout<<"|Zdrowie -  "<<hp<<endl;
        cnormal();
        cout<<"|Ktory dzien: "<<ktorydzien<<endl;
        cout<<" ---------------"<<endl<<endl;
        cout<<"|Kup dragi - b "<<endl;
        cout<<"|Sprzedaj dragi - s "<<endl;
        cout<<"|Zmien HP (bedzie szpital) - h"<<endl;
        cout<<"|Zmien miasto - c"<<endl;
        cout<<"|Sklep z przedmiotami - p"<<endl;
        cout<<"|Pokaz ile masz dragow - i"<<endl;
        cout<<"|WYJDZ DO MENU - q"<<endl<<endl<<endl;
        cout<<"wybieram  "; cin>>wybor1;



            switch(wybor1)
            {
                case 'b': //KUPNO
                {
                    system("cls");
                    cout<<"Wybierz drag do kupienia "<<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<"|1) Trawka - "<<cnarkotyk[0]<<" zl" <<endl;
                    cout<<"|2) Grzybki - "<<cnarkotyk[1]<<" zl"<<endl;
                    cout<<"|3) Kokaina - "<<cnarkotyk[2]<<" zl"<<endl;
                    cout<<"|4) Hash - "<<cnarkotyk[3]<<" zl"<<endl;
                    cout<<"|5) Amfetamina - "<<cnarkotyk[4]<<" zl"<<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<endl<<"wpisz ktory narkotyk chcesz kupic  ";
                    cin>>ktory;
                    cout<<"wpisz ilosc do kupienia, masz "<<inarkotyk[ktory]<<" sztuk"<<endl;
                    cin>>ile;

                    inarkotyk[ktory]= inarkotyk[ktory]+ile;
                    kasa= kasa-inarkotyk[ktory]*(cnarkotyk[ktory-1]);
                    Sleep(2000);
                }break;

                case 's': //SPRZEDAZ
                {
                    system("cls");
                    cout<<"Wybierz drag do sprzedania "<<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<"|1) Trawka - "<<cnarkotyk[0]<<" zl" <<endl;
                    cout<<"|2) Grzybki - "<<cnarkotyk[1]<<" zl"<<endl;
                    cout<<"|3) Kokaina - "<<cnarkotyk[2]<<" zl"<<endl;
                    cout<<"|4) Hash - "<<cnarkotyk[3]<<" zl"<<endl;
                    cout<<"|5) Amfetamina - "<<cnarkotyk[4]<<" zl"<<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<"wpisz ktory narkotyk chcesz sprzedac  ";
                    cin>>ktory;
                    cout<<endl<<"Jaki towar opylasz? Masz "<<inarkotyk[ktory]<<" sztuk towaru";
                    cout<<"Opylam ";
                    cin>>ile;
                    inarkotyk[ktory]= inarkotyk[ktory]-ile;
                    kasa= kasa+inarkotyk[ktory]*(cnarkotyk[ktory-1]);
                    Sleep(2000);

                } break;

                case 'h': //ZYCIE
                {
                    cout<<"Zmieniasz HP"<<endl;
                    cin>>hp;
                } break;

                case 'c': //PODROZ
                {
                   podroz();
                }break;

                case 'i': //STAN POSIADANIA
                {
                    cout<<"Sprawdzasz kieszenie..."<<endl;
                    cout<<"Trawka - "<<inarkotyk[1]<<endl;
                    cout<<"Grzybki - "<<inarkotyk[2]<<endl;
                    cout<<"Kokaina - "<<inarkotyk[3]<<endl;
                    cout<<"Hash - "<<inarkotyk[4]<<endl;
                    cout<<"Amfetamina - "<<inarkotyk[5]<<endl;
                    Sleep(3000);


                } break;

                case 'p': //SKLEP
                {
                    cout<<"Tu bedzie sklep"<<endl;
                    Sleep(2000);
                } break;

                 case 'q': //WYJSCIE DO MENU
                {
                  wyjscie==true;
                } break;

                default: //WYBIERZ POPRAWNA OPCJE
                {
                    cout<<endl<< "wybierz poprawna opcje!"<<endl;
                    Sleep(2000);
                    system("cls");
                }break;
            }
            if (hp<=0)
            {
                    smierc();
            }
            system("cls");
        }while (wyjscie==true);
}

void zapisz()
{
    string miasto1;
    cout<<endl<<endl;
    cout<<"----------------"<<endl;
    cout<< "Podaj nick: "; cin>>nick;
    cout<< "Wpisz liczbe dni gry "; cin>>iledni;

    fstream plik; //nazwa pliku "zmienna plikowa"
    plik.open("save.txt", ios::out); //. "." mowi o tym ze funkcja opend dotyczy pliku
    //ios::out wyprowadü z programu do pliku
    hp =100;
    kasa=500;
    punkty=0;
    ktorydzien=1;
    miasto1="Wroclaw";
    plik<<nick<<endl;
    plik<<kasa<<endl;
    plik<<punkty<<endl;
    plik<<ktorydzien<<endl;
    plik<<iledni<<endl;
    plik<<miasto1<<endl;
    plik<<hp<<endl;
    plik.close(); // zamkniecie pliku

    /*cout<<endl<<endl<<"nick - "<<nick<<endl;
    cout<<"kasa - "<<kasa<<endl;
    cout<<"punkty - "<<punkty<<endl;
    cout<<"dlogosc gry w dniach: "<<iledni<<endl;*/

    cout<<endl<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"          PROFIL ZOSTAL UTWORZONY!          "<<endl;
    cout<<"                 MILEJ GRY !                "<<endl;
    cout<<"--------------------------------------------"<<endl<<endl<<endl;
    system("pause");
    system("cls");
    gra();
}

void ceny()
{

}

void wczytaj()
{


    fstream plikceny;
    plikceny.open("ceny.txt", ios::in);
    if(plikceny.good()==false)
    {
       cout<<"plik nie dziala, najlepiej stworz nowy!";
       Sleep(2000);
       exit (0);
    }

    plikceny>>cnarkotyk[0];
    plikceny>>cnarkotyk[1];
    plikceny>>cnarkotyk[2];
    plikceny>>cnarkotyk[3];
    plikceny>>cnarkotyk[4];
    plikceny.close();

    fstream plik;
    plik.open("save.txt", ios::in);

    if(plik.good()==false)
    {
       cout<<"plik nie dziala, najlepiej stworz nowy!";
       Sleep(2000);
       exit (0);
    }

    plik>>nick;
    plik>>kasa;
    plik>>punkty;
    plik>>ktorydzien;
    plik>>iledni;
    plik>>miasto;
    plik>>hp;
    plik.close(); // zamkniecie pliku

    cout<<endl<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"           GRA ZOSTALA WCZYTANA!            "<<endl;
    cout<<"                 MILEJ GRY !                "<<endl;
    cout<<"--------------------------------------------"<<endl<<endl<<endl;

    system("pause");
    system("cls");
    gra();
}

void intro()
{

   cout<<" ##::::'##::::'###::::'##::::'##:'########::'####:'##::::::'##::::::::::'###:::"<<endl; Sleep(200);
   cout<<" ###::'###:::'## ##:::. ##::'##:: ##.... ##:. ##:: ##:::::::##:::::::::'## ##::"<<endl; Sleep(200);
   cout<<" ####'####::'##:. ##:::. ##'##::: ##:::: ##:: ##:: ##:::::::##::::::::'##:. ##:"<<endl; Sleep(200);
   cout<<" ## ### ##:'##:::. ##:::. ###:::: ##:::: ##:: ##:: ##:::::::##:::::::'##:::. ##"<<endl; Sleep(200);
   cout<<" ##. #: ##: #########::: ## ##::: ##:::: ##:: ##:: ##:::::::##::::::: #########"<<endl; Sleep(200);
   cout<<" ##:.:: ##: ##.... ##:: ##:. ##:: ##:::: ##:: ##:: ##:::::::##::::::: ##.... ##"<<endl; Sleep(200);
   cout<<" ##:::: ##: ##:::: ##: ##:::. ##: ########::'####: ########:########: ##:::: ##"<<endl; Sleep(200);
    gotoxys(64, 25); cout<<"by Bearshire";
   Sleep(4000);
   system("cls");
}

int main() // JUZ PRZEFORMATOWANA
{
intro();
    while(true)
    {

        cout<<"------------------------------------------------------"<<endl;
        cout<<"Witaj w MAXDILLA ver. 0.3.5 uposledzona by";
        cgold();
        cout<<" Bearshire"<<endl;
        cnormal();
        cout<<"------------------------------------------------------"<<endl<<endl;

        cout<<"Menu"<<endl;
        cout<<"1. Nowa gra"<<endl;
        cout<<"2. Kontynuj gre"<<endl;
        cout<<"3. Zasady"<<endl;
        cout<<"4. O grze"<<endl;
        cout<<"5. Wyjdz z gry"<<endl;
        cout<<"wybieram  "; cin>>wybor;
        cout<<endl;

        switch(wybor)
        {
            case 1:
            {
                zapisz();
            }break;

            case 2:
            {
                wczytaj();
            } break;

            case 3:
            {
                cout<<endl<<"Witaj, wiesz co jest celem gry? Wzbogacenie sie oczywiscie - byles za glupi by dostac sie na studia, a jednoczesnie za leniwy by zdobyc dobry fach.";
                cout<<" Jestes zatem dilerem, - zakala spoleczenstwa.";
                cout<<" Nie przejmuj sie jednak - jesli przezyjesz i bedziesz wystarczajaco sprytny to zostaniesz";
                cout<<" bardzo bogata i wplywowa zakala spoleczenstwa."<<endl<<endl;

                cout<<"Twoja robota jest prosta, jak powiedzial Wielki Kurwin - kupuj tanio, sprzedawaj drogo. ";
                cout<<" Z czasem, w wraz ze wzrostem zarabianej kasy, rosnac bedzie wskaznik wkurwienia.";
                cout<<"W koncu w kraju sporo jest zawistnikow, nie? Wystaw im imprezke, daj na koks a uspokoisz";
                cout<<"nastroje spoleczne, jesli w dupie masz wszystko, kup se niedzwiedzia lub czolg, lub jedno i drugie!"<<endl;
                cout<<"W takim przypadku, mimo wkurwienia nikt cie nie ruszy."<<endl<<endl;
                system("pause");
                system("cls");
            }break;

            case 4:
            {
                cout<<"Po pierwsze dzieki dla Miroslawa Zelenta, jak i wielu nieocenioncych ludzi w "<<endl;
                cout<<"internecie ktorzy poswiecali czas by przekazywac wiedze o programowaniu."<<endl;
                cout<<"Prace nad nia zaczely sie 3 wrzesnia, wieksze zmiany wprowadzono 17 wrzesnia"<<endl;
                cout<<"17.09.2016 - ver. 0.3"<<endl;
                cout<<"Dodana glowna czesc gry"<<endl;
                cout<<"-opcja kupowania i sprzedazy dragow"<<endl;
                cout<<"-naprawa bledu wczytywania gry"<<endl;
                cout<<"-wczytywanie stanu poczatkowego cen przy starcie gry"<<endl;
                cout<<"-system hp"<<endl;
                cout<<"-wyjscie do MENU"<<endl<<endl<<endl;
                cout<<"Gra wzorowana jest na starej grze maxxdilla z r. 2000, ta odmiana robiona jest w";
                cout<<"ramach nauki programowaniania przez Lew/BearShire, ktory niedzwiedzie uwielbia ";
                cout<<"calym soba. Jest ona oczywiscie skopana konceptualnie, zapewnie kiedys przepisze"<<endl;
                cout<<"ja obiektowo, optymalizujac, i dodajac opcje, a nastepnie przenoszac na"<<endl;
                cout<<"androida z ladna grafike i wrzucajac na google play za darmo"<<endl;
                system("pause");
                system("cls");
            }break;

            case 5:
            {
                return 0;
            }

            default:
            {
                cout<<endl<< "wybierz poprawna opcje!"<<endl;
                Sleep(2000);
                system("cls");
            }break;
        }
    }
}
