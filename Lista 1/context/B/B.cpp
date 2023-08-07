#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))

int main()
{
    _ int M, x, y, z, TT;
    cin >> TT;
    while (TT--)
    {
        int N;
        cin >> N;
        vector<int> v;
        v.push_back(0);

        int maxi = -INF;
        for (int i = 0; i < N; i++)
        {
            int aux;
            cin >> aux;
            v.push_back(aux);
        }

        vector<int> M(N + 1,0);
        maxi = -INF;
        for (int j = N; j > 0; j--)
        {
            int sum = j + v[j];
            if (sum > N)
                M[j] = v[j];
            else if (M[sum] != 0)
                M[j] = v[j] + M[sum];
            
            maxi = max(maxi, M[j]);
        }
        cout << maxi << endl;
    }
}