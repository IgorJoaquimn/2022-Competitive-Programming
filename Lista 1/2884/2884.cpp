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

void acende(int n, vector<int> &lamp, vector<int> intr[])
{
    for (auto &c : intr[n])
        lamp[c] = !lamp[c];
}

int tudo_apagado(vector<int> &lamp)
{
    int t = 0;
    for (auto &c : lamp)
        t+=c;
    return !t;
}

int main()
{
    _ int N, M, L, x, y;
    cin >> N >> M;
    cin >> L;

    vector<int> lamp(M, 0);
    vector<int> intr[N];

    for (int i = 0; i < L; i++)
    {
        cin >> x;
        lamp[x - 1] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            intr[i].push_back(y - 1);
        }
    }
    vector<int> initial_state(lamp);

    int n=0;
    while(!tudo_apagado(lamp))
    {
        for(int i=0; i <N; i++)
        {
            acende(i, lamp, intr);
            n++;
            if(tudo_apagado(lamp)) break;
        }
        if(lamp == initial_state)
        {
            n=-1;
            break;
        }

    }
    cout << n << endl;
}