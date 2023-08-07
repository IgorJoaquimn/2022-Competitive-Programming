#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

int main()
{
    _ long long tttt, N, aux, x, y;
    cin >> tttt;
    while (tttt--)
    {
        if(tttt == 40)
        {
            cout << "";
        }
        cin >> N;
        bool desequilibrou = 0;
        long long A = 0, B = 0, diff = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> x;

            if ( x + diff <= 5)
            {
                A += x;
            }
            else
            {
                B+=x;
            }

            diff =  A - B;
            if(abs(diff) > 5) desequilibrou = 1;
        }

        if(!desequilibrou)
            cout << "Feliz Natal!" << endl;
        else
            cout << "Ho Ho Ho!" << endl;
    }
}
