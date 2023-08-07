#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 100000
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))

void DFS(int source, vector<pair<int, int>> *adj_list, vector<int> visited, vector<int> &cycle_nodes)
{
    if (visited[source])
        cycle_nodes.push_back(source);
    else
    {
        visited[source] = 1;
        for (auto &c : adj_list[source])
        {
            auto d   = begin(adj_list[c.first]);
            while(d != end(adj_list[c.first]))
            {
                if (d->first == source)
                {
                    d = adj_list[c.first].erase(d);
                    break;
                }
                d++;
            }
            DFS(c.first, adj_list, visited, cycle_nodes);
        }
    }
}


// void find_cycle_len(int source, int )

int main()
{
    _ int nVertices, nEdges;
    while (cin >> nVertices >> nEdges)
    {
        vector<pair<int, int>> adj_list[nVertices];
        for (int i = 0; i < nEdges; i++)
        {
            int in, out, len;
            cin >> in >> out >> len;
            adj_list[in - 1].push_back(mp(out - 1, len));
            adj_list[out - 1].push_back(mp(in - 1, len));
        }

        vector<int> cycle_nodes;
        vector<int> visited(nEdges, 0);

        int n = 0;
        for(auto &c: adj_list)
        {
            cout << n << ": ";
            for(auto &d: c)
            {
                cout<< "(" << d.first << ", " << d.second << ") ";
            }
            cout << endl;
            n++;
        }

        DFS(0, adj_list, visited, cycle_nodes);
        for (auto &c : cycle_nodes)
            cout << c << endl;

        // int querys; cin >> querys;
        // while(querys--)
        // {
        //     int start, len;
        //     cin >> start >> len;

        // }

        n = 0;
        for(auto &c: adj_list)
        {
            cout << n << ": ";
            for(auto &d: c)
            {
                cout<< "(" << d.first << ", " << d.second << ") ";
            }
            cout << endl;
            n++;
        }
    }
}