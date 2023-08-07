#include <iostream>
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
    _
        string cifra,
        crib;
    cin >> cifra;
    cin >> crib;

    int total = cifra.size() - crib.size() + 1;
    int resp = total;
    for(int i = 0; i < total; i++)
    {
        for(int j = 0; j<crib.size(); j++)
        {
            if(crib[j] == cifra[j+i])
            {
                	resp--;
                    break;
            }
        }
    }

    cout<< resp<<endl;
}