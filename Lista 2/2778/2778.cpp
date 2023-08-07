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

int N,M,X,Y;
vector<vector<int>> matriz(100,vector<int>(100,INF));
int dp[100][100][20][20][3];


void resolve()
{

    for(int i = 0 ; i<3 ; i++)
    dp[0][0][0][0][i] = matriz[0][0];

    
    for(int i=0;i<N ; i++)
    {
        for(int j = 0 ; j<X ; j++)
        for(int k = 0 ; k<Y ; k++)
        dp[i][0][j][k][0] = INF;
    }
    for(int i=0;i<M; i++)
    {
        for(int j = 0 ; j<X ; j++)
        for(int k = 0 ; k<Y ; k++)
        dp[0][i][j][k][1] = INF;
    }
    for(int i=0;i<N ; i++)
    {
        for(int j = 0 ; j<X ; j++)
        for(int k = 0 ; k<Y ; k++)
        dp[i][M-1][j][k][2] = INF;
    }

    for(int i=0;i<N ; i++)
    {
        for(int j=1;j<M; j++)
        {
            dp[i][j][][][0] = dp[i][j-1][][][0]
        }
    }
}

int main()
{
    _ int x, y;
    while(cin >> N >> M >> X >> Y)
    {
        for(int i = 0 ; i < N ; i++)
        {
            for (int j = 0 ; j < M ; j++)
            {
                cin >> x;
                matriz[i][j] = x;
            }
        }
    }
}