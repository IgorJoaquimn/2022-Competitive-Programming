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

int R, C, K;
int matriz[300][300] = {0};
int pontos[300][300] = {0};
int dp[300][300][301] = {0};

int qtd_pontos(int x0, int y0, int x1, int y1)
{
    if (x0 == 0 && y0 == 0)
        return pontos[x1][y1];
    return pontos[x1][y1] - pontos[x1][y0 - 1] - pontos[x0 - 1][y1];
}

void calcula_pontos()
{
    int i = 0, j = 0;
    pontos[0][0] = matriz[0][0];
    for (int i = 1; i < R; i++)
        pontos[i][0] = pontos[i - 1][0] + matriz[i][0];
    for (int j = 1; j < C; j++)
        pontos[0][j] = pontos[0][j - 1] + matriz[0][j];

    for (int i = 1; i < R; i++)
        for (int j = 1; j < C; j++)
            pontos[i][j] = pontos[i][j - 1] + pontos[i - 1][j] - pontos[i - 1][j - 1] + matriz[i][j];
}

int existe_ret(int x0, int y0)
{
    int  lower = 0,  higher = x0, i = 0;
    int Blower = 0, Bhigher = y0, j = 0;
    while (lower < higher)
    {
        j = 0;
        i = lower + (higher - lower) / 2;
        bool existe = 0;
        int assentos = qtd_pontos(i, j, x0, y0);
        if (assentos < K)
            lower = i + 1;
        else
        {

            higher = i;
        }
    }


    return i*j;
}

int main()
{
    _ int x, y;
    char c;
    while (cin >> R >> C >> K)
    {
        if (R == 0 && C == 0 && K == 0)
            break;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> c;
                matriz[i][j] = (c == 'X') ? 0 : 1;
            }
        }
        calcula_pontos();
        int menor_altura = R * C;
        int m, last;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (pontos[i][j] >= K)
                {
                    menor_altura = min(existe_ret(i, j), menor_altura);
                }
            }
        }
        cout << menor_altura << endl;
    }
}