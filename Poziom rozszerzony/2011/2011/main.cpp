#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
unsigned long long int bin2dec(unsigned long long int a);
unsigned long long int dec2bin(unsigned long long int a);
void zad_a(vector<unsigned long long int> &wek);
void zad_b(vector<unsigned long long int> &wek);
void zad_c(vector<unsigned long long int> &wek);
ofstream zadanie6("zadanie6.txt");
int main()
{
    vector<unsigned long long int> dane;
    ifstream liczby("liczby.txt");

    string linia;
    unsigned long long int x =0;
    while(getline(liczby,linia))
    {
        stringstream sslinia(linia);
        sslinia >> x;
        dane.push_back(x);
    }

    zad_a(dane);
    zad_b(dane);
    zad_c(dane);

    return 0;
}
unsigned long long int bin2dec(unsigned long long int a)
{
    int i=0;
    unsigned long long int wynik = 0;
    while(a>=1)
    {
        wynik+=a%10*pow(2,i);
        a=a/10;
        i++;
    }
    return wynik;
}
unsigned long long int dec2bin(unsigned long long int a)
{
    if(a==0)
        return 0;

    vector<unsigned long long int> tmp;
    vector<unsigned long long int>::reverse_iterator it;
    while(a>=1)
    {
        tmp.push_back(a%2);
        a=floor(a/2);
    }
    string koniec;
    for(it=tmp.rbegin(); it!=tmp.rend();it++)
    {
        koniec+=*it+48;
    }
    stringstream ss(koniec);
    unsigned long long int i;
    ss >> i;

    return i;
}
void zad_a(vector<unsigned long long int> &wek)
{
    int parzyste =0;
    vector<unsigned long long int>::iterator it;
    for(it=wek.begin();it!=wek.end();it++)
    {
        if(bin2dec(*it)%2==0)
            parzyste++;

    }
    zadanie6 << "a) " << parzyste << endl;
}

void zad_b(vector<unsigned long long int> &wek)
{

    unsigned long long int maksymalny;
    maksymalny = *max_element(wek.begin(),wek.end());
    zadanie6 << "b) " << bin2dec(maksymalny) << " " << maksymalny << endl;
}
void zad_c(vector<unsigned long long int> &wek)
{

    vector<unsigned long long int>::iterator it;
    int ile = 0;
    int suma =0;
    for(it=wek.begin(); it!=wek.end(); it++)
    {
        string testowa;
        stringstream sstestowa(testowa);
        sstestowa << *it;

        if(sstestowa.str().length()==9)
        {
            suma++;
            ile+=bin2dec(*it);
        }
    }

    zadanie6 << "c) " << suma << " " << ile << endl;
}

