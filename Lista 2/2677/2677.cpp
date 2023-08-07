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

int n;
vector<int> lista;

int resolve()
{
    int dp[ (2 * n)+1][(2 * n)+1][2] = {0};
    for (int x = 0; x < 2 * n; x++)
    {
        dp[x][x][1] = !(lista[x] % 2);
    }
    
    for (int w = 1; w < 2 * n; w++)
    {
        for (int x = 0; x < 2 * n; x++)     
        {
            int y = x + w;
            if(y >= 2*n) continue;
            dp[x][y][1] = max(dp[x][y - 1][0] + !(lista[y] % 2), dp[x + 1][y][0] + !(lista[x] % 2));
            dp[x][y][0] = min(dp[x][y - 1][1],                   dp[x + 1][y][1]);
        }
    }

    return dp[0][2*n-1][1];
}

int main()
{
    _ int aux, x, y;
    while (cin >> n)
    {
        if (n == 0)
            return 0;

        for (int i = 0; i < n * 2; i++)
        {
            cin >> aux;
            lista.push_back(aux);
        }
        cout << resolve() << endl;
        lista.clear();
    }
}