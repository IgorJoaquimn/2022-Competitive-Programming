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

void desce(int *sx, int *sy, vector<int> &v)
{
    int x = *sx;
    int y = *sy;

    while (v[x + 1] > y - 1)
    {
        x++;
        y--;
        if (y == 0)
            break;
        if (x == v.size())
            break;
    }
    *sx = x;
    *sy = y;
}

int main()
{
    _ int N, aux, x, y, max_altura = -INF;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }

    for (int i = 0; i < N - 1; i++)
    {
        x = i;
        y = 0;
        int altura = 1;
        while (v[x + 1] > y + 1)
        {
            if (x == N)
                break;
            if (altura * 2 == N)
                break;
            x++;
            y++;
            altura++;
        }

        int initial_x = x;
        altura++;

        while ((altura > max_altura))
        {
            desce(&x, &y, v);
            altura--;
            if (x == v.size())
                break;
            if (y == 0)
                break;
            x = initial_x - 1;
            y = altura - 1;
        }
        max_altura = max(max_altura, altura);
    }
    cout << max_altura << endl;
}