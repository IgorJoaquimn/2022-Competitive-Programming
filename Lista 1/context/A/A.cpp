#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))
int main()
{
    _ int N, M, x, y, z, TT;
    cin >> TT;
    while(TT--) 
    {
        cin >> N;
        vector<int> v;
        for(int i=0; i<N; i++)
        {
            int aux;
            cin >> aux;
            v.push_back(aux);
        }

        sort(v.begin(),v.end());
        int menor = 0;

        int mini = INF;
        for(int maior = 0; maior <  N - 1; maior++)
        {
            menor = maior +1;
            mini = min(mini, abs(v[menor]  - v[maior]));
        }

        cout << mini << endl;
    }

}