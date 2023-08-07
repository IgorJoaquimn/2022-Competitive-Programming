#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
 
int main() {
    cout  << setprecision(2) << fixed ;
    double A;
    cin >> A;
    int notas[6];
    int moedas[6];


    notas[0] = 100;
    notas[1] = 50;
    notas[2] = 20;
    notas[3] = 10;
    notas[4] = 5;
    notas[5] = 2;

    moedas[0] = 100;
    moedas[1] = 50;
    moedas[2] = 25;
    moedas[3] = 10;
    moedas[4] = 5;
    moedas[5] = 1;

    int auxINT = A;

    int i = 0;
    cout << "NOTAS:" << endl;
    while(auxINT>=2)
    {   
        cout << auxINT/notas[i] << " nota(s) de R$ " << notas[i]<<".00" << endl;
        auxINT = auxINT%notas[i];
        i++;
    }
    for(i; i<6; i++)
        cout << 0 << " nota(s) de R$ " << notas[i]<<".00" << endl;


    int auxINT2 = (A - floor(A) + auxINT) *100;

    cout << "MOEDAS:" << endl;
    i = 0;
    while(auxINT2>=1)
    {   
        double out = moedas[i]/100.0;
        cout << auxINT2/moedas[i] << " moeda(s) de R$ " << out << endl;
        auxINT2 = auxINT2%moedas[i];
        i++;
    }
    for(i; i<6; i++)
        cout << 0 << " moeda(s) de R$ " << moedas[i]/100 << endl;
    return 0;
}