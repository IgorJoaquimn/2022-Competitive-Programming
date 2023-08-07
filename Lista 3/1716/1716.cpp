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
typedef long long ll;


int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}

void fatora(ll N, ll *P, ll*Q)
{
    for (ll i = 3; i <= sqrt(N); i = i + 2)
    {
        if (!(N % i))
        {
            *P = i;
            *Q = N/i;
        }
    }
}

ll power(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
int main()
{
    _
    ll N,C,P,Q,M;
    int E,T,D,x;
    cin >> N >> E >> C;
    fatora(N,&P,&Q);
    T = (P-1)*(Q-1);
    D = modInverse(E,T);
    M = power(C,D,N);

    // cout << N << " " << P << " " << Q << " " << D << " " << M << endl;
    cout <<  M << endl;
}