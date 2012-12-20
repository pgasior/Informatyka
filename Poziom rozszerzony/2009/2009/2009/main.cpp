#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ifstream dane("dane.txt");
ofstream zad_5("zad5.txt");
ofstream slowa("slowa.txt");
void zad_a(vector< vector < string > > &wektor);
void zad_b(vector< vector < string > > &wektor);
void zad_c(vector< vector < string > > &wektor);
void zad_d(vector< vector < string > > &wektor);
string utworz_c(string a, string b);

int main()
{
    vector< vector < string > > slowa;

    string linia;


    while(getline(dane,linia))
    {
        //cout << linia << endl;
        string linia2;
        vector<string> tymczasowy;

        stringstream ss(linia);
        while(ss >> linia2)
        {

            tymczasowy.push_back(linia2);
        }
        slowa.push_back(tymczasowy);
    }
   // cout << slowa[0][0] << endl << slowa[0][1] << endl<<slowa[1][0] << endl << slowa[1][1] << endl;


    zad_a(slowa);
    zad_b(slowa);
    zad_c(slowa);
    zad_d(slowa);
    return 0;
}

void zad_a(vector< vector < string > > &wektor)
{
    int parandolimy=0;
    vector< vector < string > >::const_iterator x;
    vector<string>::const_iterator y;
    for(x=wektor.begin();x!=wektor.end();x++)
    {
        for(y=x->begin();y!=x->end();y++)
        {
            if(*y==string(y->rbegin(),y->rend()))
                parandolimy++;
        }
    }
    zad_5 << "a) " << parandolimy << endl;
}

void zad_b(vector< vector < string > > &wektor)
{
    vector< vector < string > >::const_iterator x;
    vector<string>::const_iterator y;
    int zawierajace =0;
    for(x=wektor.begin();x!=wektor.end();x++)
    {
        y=x->begin();
        //cout << *y << endl;
        size_t znaleziony;
        znaleziony=(*y).find(*(y+1));
        if(znaleziony!=string::npos)
            zawierajace++;
    }
    zad_5 << "b) " << zawierajace << endl;
}

void zad_c(vector< vector < string > > &wektor)
{
    vector< vector < string > >::const_iterator x;
    vector<string>::const_iterator y;
    string a,b;
    size_t znaleziony;
    int pary = 0;
    for(x=wektor.begin();x!=wektor.end();x++)
    {
        y=x->begin();
        a=*y;
        b=*(y+1);
        znaleziony = a.find(b);
        if(znaleziony == string::npos)
            pary++;
    }
    zad_5 << "c) " << pary << endl;

}

void zad_d(vector< vector < string > > &wektor)
{
    vector< vector < string > >::const_iterator x;
    vector<string>::const_iterator y;
    string a,b;
    for(x=wektor.begin();x!=wektor.end();x++)
    {
        y=x->begin();
        a=*y;
        b=*(y+1);
        cout << a << " " << b << endl;
        slowa << utworz_c(a,b) << endl;
    }
}
string utworz_c(string a, string b)
{
    size_t znaleziony;
    znaleziony = a.find(b);
    if(znaleziony == string::npos)
        return a+b;
    if(znaleziony != string::npos)
        return a;
    //doklejam z pocz¹tku
    string b2 = b;
    int i=0;
    while(b2.length()!=1)
    {
        b2=string(b2.begin()+1,b2.end());
        i++;
        znaleziony = a.find(b2);
        if (static_cast<int>(znaleziony) ==0)
        {
            return b.erase(i,b2.length()-1)+a;
        }
    }
    //doklejam do konca
    b2 = b;
    i=0;
    while(b2.length()!=1)
    {
        b2=string(b2.begin(),b2.end()-1);
        i++;
        znaleziony = a.find(b2);
        if (static_cast<int>(znaleziony) ==a.length()-1-b2.length()-1)
        {
            return a+b.erase(0,b2.length()-1);
        }
    }

}
