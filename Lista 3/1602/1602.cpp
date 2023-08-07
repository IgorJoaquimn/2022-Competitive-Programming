#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 2*1000000 + 1
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))
typedef unsigned long long ull;



int dp[MAX];
    int primo[MAX];
    int rfp[MAX];
    int expo[MAX];
int divisores(int n)
{
    if(n == 0) return 0;
    int resp = 1;
    while(n > 1)
    {
        resp *= (expo[n]+1);
        n = rfp[n];
    }
    return resp;
}

int main()
{
    
    _ int tttt, aux,x;

    primo[0] = 0;
    primo[1] = 1; 
    for(int i = 0; i <=MAX; i++)
    {
        primo[i]    = i;
        expo[i]     = 1;
        rfp[i]      = 1;
    }

    for(int i = 2; i <=MAX; i++)
    {
        if(primo[i] != i) continue;
        for(int j = 2*i; j <= MAX; j+=i)
        {
            primo[j] = i;
            if(primo[j/i] == i)
            {
                expo[j] = expo[j/i] + 1;
                rfp[j] = rfp[j/i];
            } 
            else
            {
                expo[j] = 1;
                rfp[j]  = j/i;
            }
        }
    }


    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3; i<=MAX; i++)
    {
        dp[i] = dp[i-1];
        if(primo[divisores(i)] == divisores(i))    
            dp[i]+= 1;
    }
    int n;
    while(cin >> n)
    {
        cout << dp[n] << endl;
    }
}
