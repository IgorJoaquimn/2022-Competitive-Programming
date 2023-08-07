#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define INF 0x3f3f3f
#define MAX 1000000000
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
typedef unsigned long long ll;
 
ll mod = 1000000;
 
 
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
 
int main()
{
    _
    ll n,k,l;
    while(cin >> n >> k >> l)
    {
        ll p = n/10;
        ll r = n%10;
 
        ll initialN = (2*p -1)%mod;
        ll initialQ = 1 %mod;
 
        ll ans = initialN;
 
        for(int i = 1; i<=p; i++)
        {
            cout << (2*(p+i) - 1)<<endl;
            // ans += comb(2*p, 2*i);
        }
 
        // printf("%6ll\n", ans%1000000);
        // cout << p << " " << r << endl;
    }
}