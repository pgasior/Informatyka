#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
bool sortuj(char a, char b)
{
    return a>b;
}
bool anagram_check(string wyraz1, string wyraz2)
{
    if (wyraz1.length()!=wyraz2.length())
        return 0;

    /*for (int i=0; i<wyraz1.length()-1;i++)
    {
        for(int j=0; j<wyraz2.length()-1; j++)
        {
            if(wyraz1[j] >wyraz1[j+1])
                swap(wyraz1[j],wyraz1[j+1]);
            if(wyraz2[j] > wyraz2[j+1])
                swap(wyraz2[j],wyraz2[j+1]);
        }
    }
    if (wyraz1 == wyraz2)
        return 1;
    else
        return 0;*/

    vector<char> w1(wyraz1.c_str(), wyraz1.c_str()+wyraz1.length());
    vector<char> w2(wyraz2.c_str(), wyraz2.c_str()+wyraz2.length());

    sort(w1.begin(),w1.end(),sortuj);
    sort(w2.begin(),w2.end(),sortuj);
    string sw1(w1.begin(),w1.end());
    string sw2(w2.begin(),w2.end());
    if (sw1==sw2)
        return 1;
    else
        return 0;

}
int main()
{
    vector <vector <string> > anagram;
    vector <vector <string> >::const_iterator wiersz;
    vector <string>::const_iterator kolumna;
    ifstream plik("anagram.txt");
    ofstream z1("odp_4a.txt");
    ofstream z2("odp_4b.txt");
    string linia;
    while (getline(plik,linia))
    {
        vector < string > dane;
        string wyraz;
        istringstream iss(linia);
        while (iss >> wyraz)
        {
            dane.push_back(wyraz);
        }
        anagram.push_back(dane);
    }
    int i =0;

    for (wiersz = anagram.begin(); wiersz != anagram.end(); ++ wiersz)
    {
        int dobre = 0;
        int ana = 0;
        int j=0;

        for (kolumna = wiersz->begin()+1; kolumna != wiersz->end(); ++kolumna)
        {
            if (kolumna->length() == wiersz->begin()->length())
            {
                dobre = dobre+1;
            }


            if (anagram_check(*wiersz->begin(),*kolumna))
                ana = ana+1;
            j++;
        }

        if (dobre ==4)
        {
            for (kolumna = wiersz->begin(); kolumna != wiersz->end(); ++kolumna)
            {
                z1 << *kolumna << " ";
            }
            z1 << "\n";
        }

        if (ana ==4)
        {
            for (kolumna = wiersz->begin(); kolumna != wiersz->end(); ++kolumna)
            {
                z2 << *kolumna << " ";
            }
            z2 << "\n";
        }

        i++;

    }

    return 0;
}
