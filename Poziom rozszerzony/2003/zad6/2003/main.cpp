#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    const int ilosc_krolikow = 100;
    const int ile_dni = 32;
    vector <vector <double> > trawa;
    vector <double> wiersz(3);
    enum ilosc_trawy
    {
        RANO,
        POLODNIE,
        WIECZOR
    };
    wiersz[RANO] = 15000;
    wiersz[POLODNIE] = wiersz[RANO]-ilosc_krolikow*0.25;
    wiersz[WIECZOR] = wiersz[POLODNIE]-ilosc_krolikow*0.25;
    trawa.push_back(wiersz);
    for(int i=1; i<500;i++)
    {
        wiersz[RANO]=(30000-trawa[i-1][WIECZOR])*0.05+trawa[i-1][WIECZOR];
        wiersz[POLODNIE] = wiersz[RANO]-ilosc_krolikow*0.25;
        wiersz[WIECZOR] = wiersz[POLODNIE]-ilosc_krolikow*0.25;
        trawa.push_back(wiersz);
        cout.precision(30);
        cout << i+1 << "\t" << wiersz[RANO] << endl;
    }

    cout.precision(2);
    cout.setf( ios::fixed);
    cout << trawa[31][POLODNIE]/30000*100 << endl;
    ofstream tabelka("tableka.txt");
    tabelka << left;
    tabelka.precision(2);
    tabelka.setf( ios::fixed);
    tabelka << setw(15) << "Dzien" << setw(15) << "Rano" << setw(15) << "Polodnie" << setw(15) << "Wieczorem" << endl;

    for(int i=0; i<32;i++)
    {
        //tabelka << setw(6) << "| " << i << " maj | " << trawa[i][RANO] << "\t| " << trawa[i][POLODNIE] << "\t| " << trawa[i][WIECZOR] << "\t|\n";
        tabelka << setw(15) << i+1 << setw(15) << trawa[i][RANO] << setw(15) << trawa[i][POLODNIE] << setw(15) << trawa[i][WIECZOR] << endl;
    }

    return 0;
}
