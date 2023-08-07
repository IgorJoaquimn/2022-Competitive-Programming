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

int N,M,G,R, C, K;




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
    _ int x,y;
    char c;
    int N,M,G;
    while(cin >> N >> M >> G)
    {
        if(N == 0 && M == 0 && G == 0)  break;
        int times[N] = {0};
        vector<int> partidas_jogadas[N];

        for(int i = 0; i < G; i++)
        {   
            cin >> x >> c >> y;
            if(c == '<') times[y] += 2;
            if(c == '=') {times[x]++; times[y]++;}
            partidas_jogadas[x].push_back(y);
            partidas_jogadas[y].push_back(x);
        }

        times[0] += 2 * ((N-1)*M - partidas_jogadas[0].size());
        
        for(int i=1; i<N; i++) 
            while(count(partidas_jogadas[i].begin(), partidas_jogadas[i].end(),0) != M) 
            {
                partidas_jogadas[0].push_back(i);
                partidas_jogadas[i].push_back(0);
            }

        int partidas_faltam = 0;
        for(int i=1; i<N; i++)  for(int j=i+1; j<N; j++)
        partidas_faltam += (M - count(partidas_jogadas[i].begin(), partidas_jogadas[i].end(),j));
        dinic D(1 + partidas_faltam + N);

        //Flow 2 entre s e partidas
        for(int i=1; i<=partidas_faltam; i++)
            D.add(0,i,2);

        //Flow 2 entre partidas e times
        int a= 1, b =2;
        for(int i=1; i<=partidas_faltam; i++)
        {
            if(count(partidas_jogadas[a].begin(), partidas_jogadas[a].end(),b) != M)
            {
                D.add(i,partidas_faltam + a,2);
                D.add(i,partidas_faltam + b,2);
                partidas_jogadas[a].push_back(b);
                partidas_jogadas[b].push_back(a);

                continue;
            }
            else
            {
                i--;
                if(b == N - 1)
                {
                    a++;
                    b = a + 1;
                    if(a == N - 1) 
                        break;
                }
                else b++;
            }

        }

        //Flow entre times e t
        for(int i=1; i<N; i++)
            D.add(partidas_faltam + i, partidas_faltam + N, times[0] - times[i] -1);


        int maxflow = D.max_flow(0,partidas_faltam + N);
        bool ganhou = (maxflow == partidas_faltam*2);
        if(ganhou)
        cout << "Y" << endl;
        else
        cout << "N" << endl;
    }
}