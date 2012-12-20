#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;
bool pierwsza(int a);
bool pierwiastek(int a);
int main()
{
    vector<int> liczby;
    ifstream dane("liczby.txt");
    ofstream zad_5("zad_5.txt");
    vector<int>::iterator it;
    string linia;
    int liczba;
    while(getline(dane,linia))
    {

        stringstream str(linia);
        str >> liczba;
        liczby.push_back(liczba);
        //cout << liczba << endl;
    }

    for(it=liczby.begin();it!=liczby.end();it++)
    {
        if (pierwiastek(*it))
            zad_5 << *it << endl;
    }

    return 0;
}
bool pierwiastek(int a)
{
    double b,c,d;
    b = sqrt(a);
    c = floor(sqrt(a)); //sqrt zamiast pow i floor zamiast ceil
    d = b-c;
    if(d==0 )
    {
        if (pierwsza(sqrt(a)))
        {
            return true;
        }

    }
    return false; //false w zlym miejscu
}
bool pierwsza(int a)
{
    if (a==2) //dla 2 nie zwracalo true
        return true;
    for (int i=2;i<=ceil(sqrt(a));i++) // blad w obliczaniu pierwiaska i ceil zamiast floor
    {
        if ((a % i) == 0)
            return false;
    }
    return true;
}
