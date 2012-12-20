#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
string koduj(string wyraz, string haslo);
string dekoduj(string wyraz, string haslo);
int main()
{
    vector<string> wek_tj, wek_sz;
    vector<string> wek_klucze1, wek_klucze2;
    ifstream tj("tj.txt");
    ifstream klucze1("klucze1.txt");
    ifstream klucze2("klucze2.txt");
    ifstream sz("sz.txt");
    ofstream wynik4a("wynik4a.txt");
    ofstream wynik4b("wynik4b.txt");
    string linia;

    while(!tj.eof())
    {
        getline(tj,linia);
        wek_tj.push_back(linia);
    }
    linia="";
    while(!klucze1.eof())
    {
        getline(klucze1,linia);
        wek_klucze1.push_back(linia);
    }
    linia="";
    while(!sz.eof())
    {
        getline(sz,linia);
        wek_sz.push_back(linia);
    }
    linia="";
    while(!klucze2.eof())
    {
        getline(klucze2,linia);
        wek_klucze2.push_back(linia);
    }


    for(int i=0; i<wek_tj.size();i++)
    {
        wynik4a << koduj(wek_tj[i],wek_klucze1[i]) << endl;
        wynik4b << dekoduj(wek_sz[i],wek_klucze2[i]) << endl;
    }

    return 0;
}

string koduj(string wyraz, string haslo)
{
    int obiegi = 0;
    int znak_wyraz,znak_haslo,znak_nowy;
    string zakodowany = "";
    if (wyraz.length()>haslo.length())
    {
        obiegi = wyraz.length()-haslo.length();
        obiegi = ceil(obiegi/haslo.length());
        for (int i = 0; i<=obiegi;i++)
            haslo +=haslo;
    }
    for(int i=0;i<wyraz.length();i++)
    {
        znak_wyraz=static_cast<int>(wyraz[i]);
        znak_haslo=static_cast<int>(haslo[i])-64;
        znak_nowy = znak_haslo+znak_wyraz;
        if (znak_nowy>90 )
            znak_nowy = znak_nowy-26;
        zakodowany+=static_cast<char>(znak_nowy);
    }
    return zakodowany;
}

string dekoduj(string wyraz, string haslo)
{
    int obiegi = 0;
    int znak_wyraz,znak_haslo,znak_nowy;
    string zakodowany = "";
    if (wyraz.length()>haslo.length())
    {
        obiegi = wyraz.length()-haslo.length();
        obiegi = ceil(obiegi/haslo.length());
        for (int i = 0; i<=obiegi;i++)
            haslo +=haslo;
    }
    for(int i=0;i<wyraz.length();i++)
    {
        znak_wyraz=static_cast<int>(wyraz[i]);
        znak_haslo=static_cast<int>(haslo[i])-64;
        znak_nowy = znak_wyraz-znak_haslo;
        if (znak_nowy<65 )
            znak_nowy = znak_nowy+26;
        zakodowany+=static_cast<char>(znak_nowy);
    }
    return zakodowany;
}
