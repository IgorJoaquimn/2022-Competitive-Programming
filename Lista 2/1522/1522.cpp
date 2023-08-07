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

int N, R, C, K;
int pilha[3][100] = {0};
int dp[101][101][101] = {-1};

int resolve(int i, int j, int k)
{
    if(dp[i][j][k] != -1) 
    return dp[i][j][k];
    int achou = 0;
    int pos[3] = {i, j, k};
    for (int a = 0; a < 3; a++)
    {
        if(pos[a] < N)
        if (!(pilha[a][pos[a]] % 3))
        {
            int pos_aux[3] = {i, j, k};
            pos_aux[a]++;
            achou |= resolve(pos_aux[0], pos_aux[1], pos_aux[2]);
            if(achou) return 1;
        }
    }

    for (int a = 0; a < 3; a++)
    {
        for (int b = a + 1; b < 3; b++)
        {
            if(pos[a] < N && pos[b] < N)
            if (!((pilha[a][pos[a]] + pilha[b][pos[b]]) % 3))
            {
                int pos_aux[3] = {i, j, k};
                pos_aux[a]++;
                pos_aux[b]++;
                achou |=resolve(pos_aux[0], pos_aux[1], pos_aux[2]);
                if(achou) return 1;

            }
        }
    }

    if(pos[0] < N && pos[1] < N && pos[2] < N)
    if (!((pilha[0][pos[0]] + pilha[1][pos[1]] + pilha[2][pos[2]]) % 3))
    {
        int pos_aux[3] = {i, j, k};
        pos_aux[0]++;
        pos_aux[1]++;
        pos_aux[2]++;
        achou |=resolve(pos_aux[0], pos_aux[1], pos_aux[2]);
        if(achou) return 1;

    }

    dp[i][j][k] = 0;
    return 0; 
}

int main()
{
     int x, y, z;
    while (cin >> N)
    {
        if (N == 0) break;
        for(int a = 0; a <= N; a++)
        for(int b = 0; b <= N; b++)
        for(int c = 0; c <= N; c++)
        dp[a][b][c] = -1;
        dp[N][N][N] = 1;
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y >> z;
            pilha[0][i] = (x);
            pilha[1][i] = (y);
            pilha[2][i] = (z);
        }
        int a = resolve(0, 0, 0);
        cout << a << endl;
    }
}