#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

ofstream zadanie4("zadanie4.txt");

void zad_a(vector<int> &wektor);
void zad_b(vector<int> &wektor);
void zad_c(vector<int> &wektor);

int main()
{
    vector<int> liczby;
    ifstream cyfry("cyfry.txt");

    string linia;
    long long int liczbaint;

    while(getline(cyfry, linia))
    {
        stringstream ss(linia);
        ss >> liczbaint;
        liczby.push_back(liczbaint);
    }
    zad_a(liczby);
    zad_b(liczby);
    zad_c(liczby);
    return 0;
}

void zad_a(vector<int> &wektor)
{
    vector<int>::iterator it;
    int parzyste = 0;
    for(it=wektor.begin();it!=wektor.end();it++)
    {
        if(*it%2==0)
            parzyste+=1;
    }
    zadanie4 << "a) " << parzyste << endl;
}

void zad_b(vector<int> &wektor)
{
    vector<int>::iterator it;
    int najwieksza = 0;
    int suma_najw = 0;
    int najmniejsza = *wektor.begin();
    int suma_najm=0;
    int liczba = *wektor.begin();
    while(liczba!=0)
    {
        suma_najm+=liczba%10;
        liczba=floor(liczba/10);
    }
    for(it=wektor.begin();it!=wektor.end()-1;it++)
    {
        int liczba = *it;
        int suma = 0;

        while(liczba!=0)
        {
            suma+=liczba%10;
            liczba=floor(liczba/10);
        }
        if (suma > suma_najw)
            najwieksza = *it;
        else if (suma < suma_najm)
            najmniejsza = *it;
    }
    zadanie4 << "b) " << najwieksza << " " << najmniejsza << endl;
}

void zad_c(vector<int> &wektor)
{
    vector<int>::iterator it;
    bool rosnacy = false;
    zadanie4 << "c) " << endl;
    for(it=wektor.begin();it!=wektor.end();it++)
    {
        int liczba= *it;
        int a=liczba%10;
        liczba=floor(liczba/10);
        while(liczba!=0)
        {
            if(liczba%10 < a)
            {
                rosnacy = true;
                a=liczba%10;
            }

            else
            {
                rosnacy = false;
                liczba =0;
            }

            liczba=floor(liczba/10);
        }
        if (rosnacy)
            zadanie4 << *it << endl;
    }
}
