#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
void zad1(string a);
void zad2(string a);
void zad3(string a);
ifstream dane("hasla.txt");
ofstream wynik4a("wynik4a.txt");
ofstream wynik4b("wynik4b.txt");
ofstream wynik4c("wynik4c.txt");

int parzyste = 0;
int nieparzyste = 0;

int main()
{
    vector<string> hasla;
    vector<string>::iterator it;
    string linia;
    while(!dane.eof())
    {
        getline(dane,linia);
        hasla.push_back(linia);
    }

    for(it=hasla.begin();it!=hasla.end();it++)
    {
        zad1(*it);
        zad2(*it);
        zad3(*it);
    }
    wynik4a << "parzyste " << parzyste << "\nnieparzyste " << nieparzyste;
    cout << "Hello world!" << endl;
    return 0;
}

void zad1(string a)
{
    if( ((a.length()%2)==0) and (a.length()!=0) )
            parzyste++;
        else if (a.length()!=0)
            nieparzyste++;
}

void zad2(string a)
{
    string odwrocony = string(a.rbegin(), a.rend());
    if ((a==odwrocony)and(a.length() !=0))
        wynik4b << a << endl;
}

void zad3(string a)
{
    char z1,z2;
    int dobry=0;
    int dl = a.length();
    for (int i=0;i<dl-1;i++)
    {
        z1=a[i];
        z2=a[i+1];
        if (z1+z2==220)
            dobry++;
    }
    if (dobry>=1)
        wynik4c << a << endl;
}
