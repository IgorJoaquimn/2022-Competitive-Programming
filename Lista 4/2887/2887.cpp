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

namespace seg
{
    ll seg[2 * MAX], lazy[2 * MAX];
    int n;

    ll junta(ll a, ll b)
    {
        return a + b;
    }

    // soma x na posicao p de tamanho tam
    void poe(int p, ll x, int tam, bool prop = 1)
    {
        seg[p] += x * tam;
        if (prop and p < n)
            lazy[p] += x;
    }

    // atualiza todos os pais da folha p
    void sobe(int p)
    {
        for (int tam = 2; p /= 2; tam *= 2)
        {
            seg[p] = junta(seg[2 * p], seg[2 * p + 1]);
            poe(p, lazy[p], tam, 0);
        }
    }

    // propaga o caminho da raiz ate a folha p
    void prop(int p)
    {
        int tam = 1 << (LOG - 1);
        for (int s = LOG; s; s--, tam /= 2)
        {
            int i = p >> s;
            if (lazy[i])
            {
                poe(2 * i, lazy[i], tam);
                poe(2 * i + 1, lazy[i], tam);
                lazy[i] = 0;
            }
        }
    }

    void build(int n2, int *v)
    {
        n = n2;
        for (int i = 0; i < n; i++)
            seg[n + i] = v[i];
        for (int i = n - 1; i; i--)
            seg[i] = junta(seg[2 * i], seg[2 * i + 1]);
        for (int i = 0; i < 2 * n; i++)
            lazy[i] = 0;
    }

    ll query(int a, int b)
    {
        ll ret = 0;
        for (prop(a += n), prop(b += n); a <= b; ++a /= 2, --b /= 2)
        {
            if (a % 2 == 1)
                ret = junta(ret, seg[a]);
            if (b % 2 == 0)
                ret = junta(ret, seg[b]);
        }
        return ret;
    }

    void update(int a, int b, int x)
    {
        int a2 = a += n, b2 = b += n, tam = 1;
        for (; a <= b; ++a /= 2, --b /= 2, tam *= 2)
        {
            if (a % 2 == 1)
                poe(a, x, tam);
            if (b % 2 == 0)
                poe(b, x, tam);
        }
        sobe(a2), sobe(b2);
    }
};
namespace hld
{
    vector<int> g[MAX];
    int pos[MAX], sz[MAX];
    int peso[MAX], pai[MAX];
    int h[MAX], v[MAX], t;

    void build_hld(int k, int p = -1, int f = 1)
    {
        v[pos[k] = t++] = peso[k];
        sz[k] = 1;
        for (auto &i : g[k])
            if (i != p)
            {
                pai[i] = k;
                h[i] = (i == g[k][0] ? h[k] : i);
                build_hld(i, k, f);
                sz[k] += sz[i];

                if (sz[i] > sz[g[k][0]] or g[k][0] == p)
                    swap(i, g[k][0]);
            }
        if (p * f == -1)
            build_hld(h[k] = k, -1, t = 0);
    }

    void build(int root = 0)
    {
        t = 0;
        build_hld(root);
        seg::build(t, v);
    }

    ll query_path(int a, int b)
    {
        if (pos[a] < pos[b])
            swap(a, b);

        if (h[a] == h[b])
            return seg::query(pos[b], pos[a]);
        return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
    }
    void update_path(int a, int b, int x)
    {
        if (pos[a] < pos[b])
            swap(a, b);

        if (h[a] == h[b])
            return (void)seg::update(pos[b], pos[a], x);
        seg::update(pos[h[a]], pos[a], x);
        update_path(pai[h[a]], b, x);
    }
    ll query_subtree(int a)
    {
        return seg::query(pos[a], pos[a] + sz[a] - 1);
    }
    void update_subtree(int a, int x)
    {
        seg::update(pos[a], pos[a] + sz[a] - 1, x);
    }
    int lca(int a, int b)
    {
        if (pos[a] < pos[b])
            swap(a, b);
        return h[a] == h[b] ? b : lca(pai[h[a]], b);
    }
};
int main()
{
    _ int N, Q, x, y;
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        hld::g[i].clear();
    for (int i = 0; i < N - 1; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        hld::g[x].push_back(y);
        hld::g[y].push_back(x);
    }
    hld::build();

    int a, b, c, d;
    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        hld::update_path(a, b, 1);
        cout << hld::query_path(c, d) << endl;
        hld::update_path(a, b, -1);
    }
}
