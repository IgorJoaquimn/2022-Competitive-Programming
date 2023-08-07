#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 10000000
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))
typedef unsigned long long ll;

#define mod 2

int primo[MAX + 1];

int paridade(int n)
{
    int paridade_n = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!(i % 2))
        {
            int count = 0, aux = i;
            while (!(aux % 2))
            {
                aux /= 2;
                count++;
            }
            paridade_n += count;
        }
    }
    return paridade_n;
}


int main()
{

    _ int tttt, x;

    for (int i = 0; i <= MAX; i++)
    {
        primo[i] = 1;
    }

    for (int i = 2; i <= MAX; i++)
    {
        // paridade[i] = paridade[i-1];

        if (!primo[i])
            continue;
        for (int j = 2 * i; j <= MAX; j += i)
            primo[j] = 0;
    }

    int a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << "?" << endl;
        return 0;
    }

    int ma = max(a, b);
    int mi = min(a, b);
    int k = abs(a - b);

    if (mi == 1)
        mi++;
    int num_primos = 0;
    for (int i = mi; i <= ma; i++)
        if (primo[i])
            num_primos++;

    if (!num_primos)
    {
        cout << "Bob" << endl;
        return 0;
    }
    int p = 1;
    int n = num_primos + k - 1;

    int paridade_n  = paridade (n);
    int paridade_k  = paridade(k);
    int paridade_nk = paridade(n-k);
    

    if (paridade_n > (paridade_k + paridade_nk))
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;

    return 0;
}
