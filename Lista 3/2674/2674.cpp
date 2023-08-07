#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 100000
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))
typedef unsigned long long ull;



int primo[MAX];
int main()
{
    
    _ int tttt, aux,x;

    for(int i = 0; i < MAX; i++)
        primo[i] = 1;

    primo[0] = 0;
    primo[1] = 0;
    for(int i = 2; i <=MAX; i++)
    {
        if(!primo[i]) 
            continue;
        for(int j = 2*i; j<=MAX; j+=i)
            primo[j] = 0;
    }

    string n;
    while(cin >> n)
    {
        x = stoi(n);
        if(!primo[x])
        {
            cout << "Nada" << endl;
            continue;
        }

        bool a = 0;
        for(int j = 0; j < n.size(); j++)
        {
            x = (int)(n[j] - '0');
            if(!primo[x])
            {
                cout << "Primo" << endl;
                a = 1;
                break;
            }
        }
        if(!a)
                cout << "Super" << endl;

    }
}
