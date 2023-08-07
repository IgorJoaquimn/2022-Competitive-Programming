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
vector<vector<vector<int>>> dp;

int resolve(int i, int j, bool vez)
{
    if(dp[i][j][vez] != -INF) 
        return dp[i][j][vez];
     
    if (i == j && vez)
    {
        dp[i][j][vez] = !(lista[i] % 2);
        return !(lista[i] % 2);
    }
    
    if (i == j && !vez)
    {
        dp[i][j][vez] = 0;
        return 0;
    }

    int direita  = resolve(i, j - 1, !vez);
    int esquerda = resolve(i + 1, j, !vez);
    if (vez)
    {
        direita  += !(lista[j] % 2);
        esquerda += !(lista[i] % 2);
    }
    dp[i][j][vez] = max(direita, esquerda);
    return max(direita, esquerda);
}

int main()
{
    _ int aux, x, y;
    while (cin >> n)
    {
        vector<int> v(n * 2);
        vector<vector<vector<int>>> dpg(n * 2, vector<vector<int>>(n * 2, vector<int>(2,-INF)));
        if (n == 0)
            break;
        for (int i = 0; i < n * 2; i++)
        {
            cin >> aux;
            v[i] = aux;
        }
        lista = v;
        dp    = dpg;

        
        cout << resolve(0, (n * 2) - 1, 1) << endl;
        lista.clear();
        dp.clear();
    }
}