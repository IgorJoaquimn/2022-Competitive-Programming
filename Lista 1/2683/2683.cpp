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

unsigned int len[1000000];
unsigned int pai[1000000];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        len[i] = 1;
        pai[i] = i;
    }
}

int find(int i)
{
    int q, t = i;
    while (pai[i] != i)
    {
        i = pai[i];
    }
    while (pai[t] != t)
    {
        q = pai[t];
        pai[t] = i;
        t = q;
    }
    return i;
}

void unionn(int i, int j)
{
    i = find(i);
    j = find(j);
    if (len[i] > len[j])
    {
        pai[j] = i;
        len[i] += len[j];
    }
    else
    {
        pai[i] = j;
        len[j] += len[i];
    }
}

int main()
{
    _ int ttt, dist, x, y;
    cin >> ttt;
    set<pair<int, pair<int, int>>> ARESTAS, ARESTAS_neg;
    init(ttt);

    int MST = 0, MST_neg = 0;

    for (int i = 0; i < ttt; i++)
    {
        cin >> x >> y >> dist;
        ARESTAS.insert(make_pair(dist, mp(x - 1, y - 1)));
        ARESTAS_neg.insert(make_pair(-dist, mp(x - 1, y - 1)));
    }

    int peso;
    for (auto &c : ARESTAS_neg)
    {
        peso = c.first;
        x = c.second.first;
        y = c.second.second;
        if (find(x) != find(y))
        {
            MST_neg -= peso;
            unionn(x, y);
        }
    }

    init(ttt);
    for (auto &c : ARESTAS)
    {
        peso = c.first;
        x = c.second.first;
        y = c.second.second;
        if (find(x) != find(y))
        {
            MST += peso;
            unionn(x, y);
        }
    }

    cout << MST_neg << endl;
    cout << MST << endl;
}