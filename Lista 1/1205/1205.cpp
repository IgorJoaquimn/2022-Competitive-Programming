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

int dijkstra(int source, int destiny, vector<int> Arestas[], vector<int> &Pesos)
{
    priority_queue<pair<int, int>> queue;
    int N = Pesos.size();

    vector<int> dist(N, INF);
    dist[source] = 0;

    for (int i = 0; i < N; i++)
        queue.push(mp(-dist[i], i));

    while (queue.size())
    {
        auto u = queue.top();
        queue.pop();
        for (auto &v : Arestas[u.second])
        {
            int new_dist = dist[u.second] + Pesos[u.second];
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                queue.push(mp(-new_dist, v));
            }
        }
    }
    return dist[destiny] + Pesos[destiny];
}

int main()
{
    _ int N, M, K, x, y, A, source, destiny;
    long double P;
    cout << fixed;
    cout << setprecision(3);
    while (cin >> N)
    {
        vector<int> v[N];
        vector<int> qtd_soldados(N, 0);
        cin >> M >> K >> P;
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y;
            v[x - 1].push_back(y - 1);
            v[y - 1].push_back(x - 1);
        }
        cin >> A;
        for (int i = 0; i < A; i++)
        {
            cin >> x;
            qtd_soldados[x - 1]++;
        }
        cin >> source >> destiny;
        int min_snippers = dijkstra(source - 1, destiny - 1, v, qtd_soldados);
        cout << powl(P, min_snippers) << endl;
    }
}