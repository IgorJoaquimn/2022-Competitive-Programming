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

vector<int> marcados(11,0);
vector<string> v(10,"");



int main()
{
    _ int TT;
    cin >> TT;
    while (TT--)
    {
        v.clear();
        int N, len;
        cin >> N >> len;
        for (int i = 0; i < N; i++)
        {
            string aux;
            cin >> aux;
            v.push_back(aux);
        }
        
        f(N,0,0);
    }
}