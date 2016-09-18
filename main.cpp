#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>

using namespace std;

string nick, nazwisko, miasto;
int kasa, respekt, ktorydzien, iledni, cnarkotyk[6], inarkotyk[6], ile, ktory, hp;

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

void journey() //to other cities
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

void gotoxyd(int x, int y) //go to x/y dynamic
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

void gotoxys(int xx, int yy) //go to x/y static
{
    COORD c;
    c.X = xx-1;
    c.Y = yy-1;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

void gameover()
{
    system("cls");
    gotoxys(15, 1);cout<<" ----------------------------------------------"<<endl;
    gotoxys(15, 2);cout<<"|                UPLYNAL CZAS GRY              |"<<endl;
    gotoxys(15, 3);cout<<"| Twoj wynik zostal zapisany na liste rekordow |"<<endl;
    gotoxys(15, 4);cout<<"| Nick: "; csilver(); cout<<nick; gotoxys (62, 4); cnormal();  cout<<"|"<<endl;
    gotoxys(15, 5);cout<<"| Respekt: "; cgreen(); cout<<respekt; gotoxys (62,5); cnormal(); cout<<"|"<<endl;
    gotoxys(15, 6);cout<<"| Kasa: "; cgold(); cout<<kasa; gotoxys (62,6); cnormal(); cout<<"|"<<endl;
    gotoxys(15, 7);cout<<" ----------------------------------------------"<<endl;
    system("pause");
}

void yrdead()
{
    system("cls");
    gotoxys(15, 1);cout<<" ----------------------------------------------"<<endl;
    gotoxys(15, 2);cout<<"|                JESTES MARTWY                 |"<<endl;
    gotoxys(15, 3);cout<<"| Twoj wynik zostal zapisany na liste rekordow |"<<endl;
    gotoxys(15, 4);cout<<"| Nick: "; csilver(); cout<<nick; gotoxys (62, 4); cnormal();  cout<<"|"<<endl;
    gotoxys(15, 5);cout<<"| Respekt: "; cgreen(); cout<<respekt; gotoxys (62,5); cnormal(); cout<<"|"<<endl;
    gotoxys(15, 6);cout<<"| Kasa: "; cgold(); cout<<kasa; gotoxys (62,6); cnormal(); cout<<"|"<<endl;
    gotoxys(15, 7);cout<<" ----------------------------------------------"<<endl;
    system("pause");
}

void game() // JUZ PRZEFORMATOWANA
{
int x;


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
        cgreen(); cout<<"|Respekt - "<<respekt<<endl;
        cred(); cout<<"|Zdrowie -  "<<hp<<endl;
        cnormal();
        cout<<"|Ktory dzien: "<<ktorydzien<<endl;
        cout<<" ---------------"<<endl<<endl;
        cout<<"|Kup dragi - b "<<endl;
        cout<<"|Sprzedaj dragi - s "<<endl;
        cout<<"|Szpital - h"<<endl;
        cout<<"|Zmien miasto - c"<<endl;
        cout<<"|Sklep z przedmiotami - p"<<endl;
        cout<<"|Bank - f"<<endl;
        cout<<"|Pokaz ile masz dragow - i"<<endl;
        cout<<"|WYJDZ DO MENU - q"<<endl<<endl<<endl;
        wybor1=getch();

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
                    cout<<endl<<"Jaki towar opylasz? Masz "<<inarkotyk[ktory]<<" sztuk towaru"<<endl;
                    cout<<"Opylam ";
                    cin>>ile;
                    inarkotyk[ktory]= inarkotyk[ktory]-ile;
                    kasa= kasa+inarkotyk[ktory]*(cnarkotyk[ktory-1]);


                } break;

                case 'h': //SZPITAL
                {
                    if (hp==100)
                        {cout<<"Nie przesadzasz chlopie? Idz sie przejsc a mi dupy nie zawracaj!"; Sleep(2500); break;}
                    system("cls");
                    int hpplus;
                    char wybor2;
                    cred(); cout<<"Zdrowie - "<<hp<<endl; cnormal();
                    cgold(); cout<<"Kasa - "<<kasa<<endl; cnormal();
                    cout<<"Witaj w szpitalu, ile pk. zycie chcesz odzyskac? ( max 100 )"<<endl;
                    cout<<"Im bardziej znany jestes tym wiecej kosztowac bedzie operacja"<<endl;
                    cout<<"aktualny koszt za 1 pkt zdrowia; "<<2+(1*respekt)<<" zl"<<endl;
                    cin>>hpplus;
                    if (hp+hpplus>100)
                        {cout<<"Nie przesadzasz chlopie? Idz sie przejsc a mi dupy nie zawracaj!"; Sleep(2500); break;}
                    cout<<"Czy na pewno chcesz uleczyc "<<hpplus<<" pkt zycia za "<<hpplus*(2+(1*respekt))<<" zl? (t/n)"<<endl;
                    cout<<"|"; cin>>wybor2; cout<<"|"<<endl;
                    if (wybor2=='t')
                    {
                        hp=hp+hpplus;
                        kasa=kasa-hpplus*(2+(1*respekt));
                    }
                    else cout<<"jak nie to nie!"; Sleep(2500); break;

                } break;

                case 'c': //PODROZ
                {
                   journey();
                }break;

                case 'i': //STAN POSIADANIA
                {

                    cout<<endl<<"Sprawdzasz kieszenie..."<<endl;
                    cout<<" ----------------------"<<endl;
                    cout<<"Trawka - "<<inarkotyk[1]<<endl;
                    cout<<"Grzybki - "<<inarkotyk[2]<<endl;
                    cout<<"Kokaina - "<<inarkotyk[3]<<endl;
                    cout<<"Hash - "<<inarkotyk[4]<<endl;
                    cout<<"Amfetamina - "<<inarkotyk[5]<<endl<<endl;
                    system("pause");


                } break;

                case 'p': //SKLEP
                {
                    system("cls");
                    cout<<"Witaj w sklepie ! "<<endl;
                    cout<<"Wybierz przedmiot ktory chcesz kupic "<<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<"|1)   OGLOSZENIE:                         " <<endl;
                    cout<<"|2) Prosimy o cierpilowsc !               " <<endl;
                    cout<<"|3) Czekamy na dostawe czolgow i niedzwiedzi" <<endl;
                    cout<<"|4)                                       " <<endl;
                    cout<<"|5)                                       " <<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<"Jeszcze zamkniete ;) ";
                    system("pause");

                } break;

                case 'f': //BANK
                {
                    system("cls");
                    cout<<"Witaj w Banku Amber Gold L.T.D! "<<endl;
                    cout<<"...Tu na razie jest sciernisko, ale bedzie san francisco... "<<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<"|1)   OGLOSZENIE:                         " <<endl;
                    cout<<"|2) Zamkniete bo tak.                     " <<endl;
                    cout<<"|3)                                       " <<endl;
                    cout<<"|4)                                       " <<endl;
                    cout<<"|5)                                       " <<endl;
                    cout<<" -----------------------------------------"<<endl;
                    cout<<"Jeszcze zamkniete ;) ";
                    system("pause");

                } break;

                case 'q': //WYJSCIE DO MENU
                {
                } break;

                case 'x': //DEVELOPER MENU
                {
                    cout<<"Menu Developerskie, jesli jestes graczem to pogratuluj sobie"<<endl;
                    cout<<"Aktualnie masz "<< hp<<" pkt zrowia"<<endl;
                    cout<<"zmien ilosc hp"<<endl;
                    cin>>hp;
                    cout<<"Aktualnie masz "<< kasa<<" zl w kieszeni"<<endl;
                    cout<<"zmien ilosc kasy"<<endl;
                    cin>>kasa;
                    cout<<"Aktualnie jest "<<ktorydzien<<" dzien gry"<<endl;
                    cout<<"Zmien dzien"<<endl;
                    cin>>ktorydzien;
                    cout<<"Aktualnie masz "<<respekt<<" respektu"<<endl;
                    cout<<"Zmien ilosc respektu"<<endl;
                    cin>>respekt;

                }break;

                default: //WYBIERZ POPRAWNA OPCJE
                {
                    cout<<endl<< "wybierz poprawna opcje!"<<endl;
                    Sleep(2000);
                    system("cls");
                }break;
            }


            if (hp<=0)
                {
                yrdead();
                wybor1='q';
                }

            if (iledni-ktorydzien<=0)
                {
                gameover();
                wybor1='q';
                }
            system("cls");
        }while (wybor1!='q');
}

void newprofile()
{
    string miasto1;
    cout<<endl<<endl;
    cout<<"   NOWY PROFIL"<<endl;
    cout<<"----------------"<<endl;
    cout<< "Podaj nick: "; cin>>nick;
    cout<< "Wpisz liczbe dni gry "; cin>>iledni;

    fstream plik; //nazwa pliku "zmienna plikowa"
    plik.open("save.txt", ios::out); //. "." mowi o tym ze funkcja opend dotyczy pliku
    //ios::out wyprowadü z programu do pliku
    hp =100;
    kasa=500;
    respekt=0;
    ktorydzien=1;
    miasto1="Wroclaw";
    plik<<nick<<endl;
    plik<<kasa<<endl;
    plik<<respekt<<endl;
    plik<<ktorydzien<<endl;
    plik<<iledni<<endl;
    plik<<miasto1<<endl;
    plik<<hp<<endl;
    plik.close(); // zamkniecie pliku

    cout<<endl<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"          PROFIL ZOSTAL UTWORZONY!          "<<endl;
    cout<<"                 MILEJ GRY !                "<<endl;
    cout<<"--------------------------------------------"<<endl<<endl<<endl;
    system("pause");
    system("cls");
    game();
}

void prices() //na razie puste
{

}

void load()
{


    fstream plikceny;
    plikceny.open("ceny.txt", ios::in);
    if(plikceny.good()==false)
    {
       cout<<"plik nie dziala, najlepiej stworz nowy!";
       Sleep(2000);
       exit (0);
    }
    else{
    plikceny>>cnarkotyk[0];
    plikceny>>cnarkotyk[1];
    plikceny>>cnarkotyk[2];
    plikceny>>cnarkotyk[3];
    plikceny>>cnarkotyk[4];
    plikceny.close();
    }
    fstream plik;
    plik.open("save.txt", ios::in);

    if(plik.good()==false)
    {
       cout<<"plik nie dziala, najlepiej stworz nowy!";
       Sleep(2000);
    }
    else{
    plik>>nick;
    plik>>kasa;
    plik>>respekt;
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
    game();
    }system("cls");
}

void intro()
{
   cout<<" ##::::'##::::'###::::'##::::'##:'########::'####:'##::::::'##::::::::::'###:::"<<endl; Sleep(100);
   cout<<" ###::'###:::'## ##:::. ##::'##:: ##.... ##:. ##:: ##:::::::##:::::::::'## ##::"<<endl; Sleep(100);
   cout<<" ####'####::'##:. ##:::. ##'##::: ##:::: ##:: ##:: ##:::::::##::::::::'##:. ##:"<<endl; Sleep(100);
   cout<<" ## ### ##:'##:::. ##:::. ###:::: ##:::: ##:: ##:: ##:::::::##:::::::'##:::. ##"<<endl; Sleep(100);
   cout<<" ##. #: ##: #########::: ## ##::: ##:::: ##:: ##:: ##:::::::##::::::: #########"<<endl; Sleep(100);
   cout<<" ##:.:: ##: ##.... ##:: ##:. ##:: ##:::: ##:: ##:: ##:::::::##::::::: ##.... ##"<<endl; Sleep(100);
   cout<<" ##:::: ##: ##:::: ##: ##:::. ##: ########::'####: ########:########: ##:::: ##"<<endl; Sleep(100);
    gotoxys(64, 25); cout<<"by Bearshire";
   Sleep(3000);
   system("cls");
}

int main() // JUZ PRZEFORMATOWANA
{
char wybor;
intro();
    while(true)
    {

        cout<<"------------------------------------------------------"<<endl;
        cout<<"Witaj w MAXDILLA ver. 0.4 uposledzona by";
        cgold(); cout<<" Bearshire"<<endl; cnormal();
        cout<<"------------------------------------------------------"<<endl<<endl;

        cout<<"Menu"<<endl;
        cout<<"1. Nowa gra"<<endl;
        cout<<"2. Kontynuj gre"<<endl;
        cout<<"3. Zasady"<<endl;
        cout<<"4. O grze"<<endl;
        cout<<"5. TOP 10"<<endl;
        cout<<"6. Wyjdz z gry"<<endl;
        wybor=getch();

        switch(wybor)
        {
            case '1':
            {
                newprofile();
            }break;

            case '2':
            {
                load();
            } break;

            case '3':
            {
                system("cls");
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

            case '4':
            {
                system("cls");
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

            case '5':
            {
                system("cls");
                gotoxys(31,1); cout<<"Tutaj bedzie top 10"<<endl;
                Sleep(2000);
                system("cls");
            }break;

            case '6':
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
