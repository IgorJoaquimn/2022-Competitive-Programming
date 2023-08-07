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
vector<long long> ms;
vector<long long> rg;
vector<int> s;

ull nCr(ull x, ull r)
{
    long long p = 1, k = 1;
    if (x - r < r)
        r = x - r;
    if (r != 0)
    {
        while (r)
        {
            p *= x;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            x--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

void regular_lis(vector<int> const &a)
{
    int n = a.size();
    vector<long long> d(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }
    rg = d;
}

ull lis()
{
    vector<long long> maior_subs = ms;
    vector<int> sequence = s;

    ull sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (rg[i] == k)
            maior_subs[i] = 1;

        if (rg[i] > k)
        {
            int det = (rg[i] - 1);
            int coef = k - 1;
            maior_subs[i] = nCr(det, coef);
        }
        if (maior_subs[i] > 0)
            sum += maior_subs[i];
    }

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
        vector<long long> vm(n, 0);
        ms = vm;
        rg = vm;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v[i] = x;
        }

        s = v;

        regular_lis(v);
        cout << lis() << endl;
    }
}
