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
    _ int N, P, x, y, capacity, life;
    while (cin >> N >> P)
    {
        
        vector<int> mana;
        vector<int> damage;
        mana.push_back(0);
        damage.push_back(0);
        for (int i = 1; i <= N; i++)
        {
            cin >> x >> y;
            damage.push_back(x);
            mana.push_back(y);
        }
        vector<int> dp[N + 1];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= P; j++)
                dp[i].push_back(INF);

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= P; j++)
            {
                if (damage[i] >= j)
                    dp[i][j] = min(dp[i - 1][j], mana[i]);
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - damage[i]] + mana[i]);
            }
        }

        int min = dp[N][P];
        if (min != INF)
            cout << min << endl;
        else
            cout << -1 << endl;
    }
    return 0;

}