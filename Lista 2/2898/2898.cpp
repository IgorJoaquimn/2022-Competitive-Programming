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

int N, M, A, R, C, K;

struct dinic {
    struct edge {
        int to, cap, rev, flow;
        bool res;
        edge(int to_, int cap_, int rev_, bool res_)
            : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };
 
    vector<vector<edge>> g;
    vector<int> lev, beg;
    long long F;
    dinic(int n) : g(n), F(0) {}
 
    void add(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size(), false);
        g[b].emplace_back(a, 0, g[a].size()-1, true);
    }
    bool bfs(int s, int t) {
        lev = vector<int>(g.size(), -1); lev[s] = 0;
        beg = vector<int>(g.size(), 0);
        queue<int> q; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto& i : g[u]) {
                if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }
    int dfs(int v, int s, int f = 0x3f3f3f3f) {
        if (!f or v == s) return f;
        for (int& i = beg[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (lev[e.to] != lev[v] + 1) continue;
            int foi = dfs(e.to, s, min(f, e.cap - e.flow));
            if (!foi) continue;
            e.flow += foi, g[e.to][e.rev].flow -= foi;
            return foi;
        }
        return 0;
    }
    long long max_flow(int s, int t) {
        while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
        return F;
    }
};

int main()
{
    _ int x, y, z;
    char c;
    int N, M, A;
    while (cin >> N >> M >> A)
    {
        if (N == 0 && M == 0 && A == 0)
            break;

        vector<pair<int, int>> adj_list[N];
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y >> z;
            adj_list[x - 1].push_back(mp(y - 1, z));
        }

        int max_flow = 0;
        int acumul = 0;
        for (int d = 1; d < 101; d++)
        {
            dinic D(N);
            set<int> dia[d + 1];
            dia[0].insert(0);
            for (int i = 1; i <= d; i++)
                for (auto next : dia[i - 1])
                {
                    dia[i].insert(next);
                    for (auto e : adj_list[next])
                        dia[i].insert(e.first);
                }

            for (auto next : dia[d - 1])
            {
                for (auto e : adj_list[next])
                {
                    int peso = e.second;
                    int dest = e.first;
                    D.add(next, dest, peso);
                }
            }

            if(max_flow)
                D.add(0,N-1,max_flow);

            max_flow = D.max_flow(0, N - 1);
            if (max_flow >= A)
            {
                cout << d << endl;
                break;
            }
        }
    }
}