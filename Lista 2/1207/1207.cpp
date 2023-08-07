#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

int n;
vector<vector<int>> adj_list;
vector<vector<int>> capacity_graph;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj_list[cur])
        {
            if (parent[next] == -1 && capacity_graph[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity_graph[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity_graph[prev][cur] -= new_flow;
            capacity_graph[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    _ int N, M, x;
    while (cin >> N >> M)
    {
        int sum = 0;
        n = N + M + 2;
        vector<vector<int>> adj(n);
        vector<vector<int>> cap(n, vector<int>(n));

        vector<int> qtd_cerveja, beneficio;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            cap[1 + M + i][n - 1] = x;
            adj[1 + M + i].push_back(n - 1);
            adj[n - 1].push_back(1 + M + i);
        }
        for (int i = 0; i < M; i++)
        {
            cin >> x;
            qtd_cerveja.push_back(x);
            adj[0].push_back(1 + i);
            adj[1 + i].push_back(0);
        }

        for (int i = 0; i < M; i++)
        {
            cin >> x;
            sum+=x;
            cap[0][i + 1] = x;
            beneficio.push_back(x);
            for (int j = 0; j < qtd_cerveja[i]; j++)
            {
                cin >> x;
                adj[i + 1].push_back(M + x);
                adj[M + x].push_back(i + 1);

                cap[i + 1][M+x] = INF;
            }
        }
        adj_list = adj;
        capacity_graph = cap;
        int mf = maxflow(0, n - 1);
        cout << sum - mf << endl;
    }
    return 0;
}