#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 100000
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

#define mp(x, y) std::make_pair(int(x), int(y))
int LOG = ceil(log2(MAX));

ll seg[4 * MAX], lazy[4 * MAX];
int n, *v;

ll build(int p = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        seg[p] = ((ll)(1))<<(v[l]-1);
        return seg[p];
    }
    int m = (l + r) / 2;
    return seg[p] = build(2 * p, l, m) | build(2 * p + 1, m + 1, r);
}

void build(int n2, int *v2)
{
    n = n2, v = v2;
    build();
}

ll query(int a, int b, int p = 1, int l = 0, int r = n - 1)
{
    if (a <= l and r <= b)
        return seg[p];
    if (b < l or r < a)
        return 0;
    int m = (l + r) / 2;
    return query(a, b, 2 * p, l, m) | query(a, b, 2 * p + 1, m + 1, r);
}

ll update(int a, int b, int x, int p = 1, int l = 0, int r = n - 1)
{
    if (a <= l and r <= b)
    {
        return seg[p] = ((ll)(1))<<(x-1);
    }
    if (b < l or r < a)
        return seg[p];
    int m = (l + r) / 2;
    return seg[p] = update(a, b, x, 2 * p, l, m) |
                    update(a, b, x, 2 * p + 1, m + 1, r);
}


int main()
{
    int v[MAX];
    _ int N, Q, M, x, y,z;
    cin >> N >> Q >> M;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    build(N, v);
    for(int i = 0; i < Q; i++)
    {
        cin >> x >> y >> z;
        y--;
        if(x == 2)
            update(y,y,z);
        else 
        {
            z--;
            int c = 0;
            ll a = query(y,z), aux = 1;
            for (int i = 0; i < M; i++)
            {
                ll b = a & aux;
                if(b != 0) 
                c++;
                aux <<= 1;	
            }
            cout << c << endl;
        }
    }
}
