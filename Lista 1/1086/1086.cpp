#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 100000
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

int minimum_planks(int n, int m, map<int, int> planks, int width)
{
    int min = 0;

    map<int, int> candidates;
    for (auto &c : planks)
    {
        if (c.first * -1 <= m)
            candidates[c.first] = c.second;
    }

    for (auto &c : candidates)
    {
        if (c.first * -1 == m)
        {
            min += c.second;
            n -= c.second * width;
            c.second = 0;
        }

        else
        {
            int resto = -(m + (c.first));
            if(resto == c.first && c.second >=2)

            if (candidates[resto] <= c.second)
            {
                if (n - (candidates[resto] * width) > 0)
                {
                    min += candidates[resto] * 2;
                    n   -= candidates[resto] * width;
                    c.second -= candidates[resto];
                    candidates[resto] = 0;
                }
                else
                {
                    candidates[resto] -= n;
                    c.second -= n;
                    min += n * 2;
                    n = 0;
                    break;
                }
            }
        }
    }

    if (n == 0)
        return min;
    else
        return INF;
}

int main()
{
    _ int N, M;
    while (cin >> N >> M)
    {
        int width;
        cin >> width;
        width /= 100;

        int nPlanks;
        cin >> nPlanks;

        map<int, int> planks;
        for (int i = 0; i < nPlanks; i++)
        {
            int aux;
            cin >> aux;
            planks[-1 * aux]++;
        }

        int x = minimum_planks(N, M, planks, width);
        int y = minimum_planks(M, N, planks, width);

        if (x == INF && y == INF)
            cout << "impossivel" << endl;

        else
        {
            int z = (x < y) ? x : y;
            cout << z << endl;
        }
    }
}