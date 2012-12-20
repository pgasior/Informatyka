#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream dane("dane.txt");
    ofstream zadanie4("zadanie4.txt");
    string linia;
    while (getline(dane,linia))
    {
        string paran = string(linia.rbegin(),linia.rend());
        if(linia==paran)
            zadanie4 << linia << endl;
    }

    return 0;
}
