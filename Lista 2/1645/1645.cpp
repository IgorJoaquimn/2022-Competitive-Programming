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

#define mp(x, y) std::make_pair(int(x), int(y))
typedef unsigned long long ull;

int n, k;
vector<int> s;


ull lis()
{
    vector<int> sequence = s;
    vector<vector<ull>> dp(n, vector<ull>(n,0));

    ull sum = 0;

    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    
    for (int l = 1; l < k; l++) {
        for (int i = l; i < n; i++) {
            dp[l][i] = 0;
            for (int j = l - 1; j < i; j++) {
                if (sequence[j] < sequence[i])
                    dp[l][i] += dp[l - 1][j];
            }
        }
    }
    for (int i = k - 1; i < n; i++)
        sum += dp[k - 1][i];
 
    return sum;

}

int main()
{
    _ ull tttt, aux, x, y;
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
            break;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v[i] = x;
        }

        s = v;
        cout << lis() << endl;
    }
}
