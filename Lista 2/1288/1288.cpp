#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

int main()
{
    _
    int tttt;
    cin>>tttt;
    while(tttt--) 
    {
        int N, x, y, capacity, life;
        cin >> N;
        vector<int> weight;
        vector<int> value;
        weight.push_back(0);
        value.push_back(0);
        for(int i = 1; i <= N; i++)
        {
            cin >> x >> y;
            value.push_back(x);
            weight.push_back(y);
        }
        cin >> capacity >> life;
        vector<int> dp[N+1];
        for(int i = 0; i <= N; i++) for(int j = 0; j <= capacity; j++)
                dp[i].push_back(0);

        for(int i = 1; i <= N; i++)
        {
            for(int j = 0; j <= capacity; j++)
            {
                if(weight[i] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j -weight[i]] + value[i]);
            }
        }

        int max =  dp[N][capacity];
        if(max >= life)
            cout << "Missao completada com sucesso" << endl;
        else
            cout << "Falha na missao" << endl;
    }
    return 0;
}