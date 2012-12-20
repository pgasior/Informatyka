#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> hasla;
    vector<string>::iterator it;
    ifstream dane("hasla.txt");
    ofstream wynik4a("wynik4a.txt");
    ofstream wynik4b("wynik4b.txt");
    ofstream wynik4c("wynik4c.txt");
    string linia;
    string odwrocony;
    int parzyste = 0;
    int nieparzyste = 0;
    char a,b;

    while(!dane.eof())
    {
        getline(dane,linia);
        hasla.push_back(linia);
    }
    /************* 4a **************************************************/
    for(it=hasla.begin();it!=hasla.end();it++)
    {
        if( (( (*it).length()%2)==0) and ((*it).length()!=0) )
            parzyste++;
        else if ((*it).length()!=0)
            nieparzyste++;
    }
    wynik4a << "parzyste " << parzyste << "\nnieparzyste " << nieparzyste;
    /************* 4a **************************************************/

    /************* 4b **************************************************/
    for(it=hasla.begin();it!=hasla.end();it++)
    {
        odwrocony = string((*it).rbegin(),(*it).rend());
        if ((*it==odwrocony)and((*it).length() !=0))
            wynik4b << *it << endl;
    }
    /************* 4b **************************************************/

    /************* 4c **************************************************/
    int dobry=0;
    for(it=hasla.begin();it!=hasla.end();it++)
    {
        int dl = (*it).length();
        for (int i=0;i<dl-1;i++)
        {
            a=(*it)[i];
            b=(*it)[i+1];
            if (a+b==220)
                dobry++;
        }
        if (dobry>=1)
            wynik4c << *it << endl;
        dobry=0;
    }
    /************* 4c **************************************************/
    cout << "Hello world!" << endl;
    return 0;
}
