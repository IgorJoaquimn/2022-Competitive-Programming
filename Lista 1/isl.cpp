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
    string entrada;
    while ( cin >> entrada)
    {
        unsigned long decimal   = std::bitset<5>(entrada).to_ulong();
        string binary           = std::bitset<5>(decimal).to_string();
        cout << decimal << " " << binary << endl;
    }
    // for(int i = 0; i <= 7; i++)
    // {
        // string binary = std::bitset<3>(i).to_string() + "00";
        // unsigned long decimal = std::bitset<5>(binary).to_ulong();
        // cout << decimal << " " << binary << endl;

        // for(int j = 1; j<=3; j++)
        // {
        //     cout<<i<<" % " << j<< "= " << std::bitset<2>(i%j).to_string() << endl;
        // }
        // cout<< endl;
    // }
}
