#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))

void dijkstra(int source, vector<pair<int, int>> adj_list[], int N, vector<int> &dist, vector<int> &prev)
{
    priority_queue<pair<int, int>> queue;

    dist[source] = 0;

    for (int i = 0; i < N; i++)
        queue.push(mp(-dist[i], i));

    while (queue.size())
    {
        auto u = queue.top();
        queue.pop();
        for (auto &v : adj_list[u.second])
        {
            int new_dist = dist[u.second] + v.first;
            if (new_dist < dist[v.second])
            {
                dist[v.second] = new_dist;
                prev[v.second] = u.second;
                queue.push(mp(-new_dist, v.second));
            }
        }
    }
}

int main()
{
    _ int N, M, x, y, z;
    cin >> N >> M;

    vector<pair<int, int>> adj_list[N];
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        adj_list[x - 1].push_back(mp(z, y - 1));
        adj_list[y - 1].push_back(mp(z, x - 1));
    }
    cin >> x;

    vector<int> dist(N, INF);
    vector<int> prev(N, -1);
    dijkstra(x-1,adj_list,N,dist,prev);
    sort(dist.begin(),dist.end());
    cout << dist[N-1] - dist[1] << endl;
}