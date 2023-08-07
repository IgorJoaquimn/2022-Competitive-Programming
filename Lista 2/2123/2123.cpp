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
    int count = 1;
    _ int N, M, K, x, y;
    while (cin >> N >> M >> K)
    {
        n = N + M + 2;
        vector<vector<int>> adj(n);
        vector<vector<int>> cap(n, vector<int>(n));

        for (int i = 0; i < N; i++)
        {
            cin >> x;
            cap[1 + M + i][n - 1] = x;
            adj[1 + M + i].push_back(n - 1);
            adj[n - 1].push_back(1 + M + i);
        }

        for (int i = 0; i < K; i++)
        {
            cin >> x >> y;

            adj[M + x].push_back(y);
            adj[y].push_back(M + x);

            cap[y][M+x] = 1;
        }

        for(int i = 0; i < M; i++)
        {
            adj[0].push_back(i+1);
            adj[i+1].push_back(0);
            cap[0][i+1] = 1;
        }

        adj_list = adj;
        capacity_graph = cap;
        int mf = maxflow(0, n - 1);
        cout << "Instancia " << count << endl;
        cout << mf << endl;
        cout<< endl;

        count++;
    }
    return 0;
}