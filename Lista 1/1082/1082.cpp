#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26



void DFS(int v, int adj_m[MAX][MAX], vector<int> &visited, vector<int> &order)
{
    order.push_back(v);
    visited[v] = 1;
    for(int i = 0; i <MAX; i++)
    {
        if (adj_m[i][v] == INF) break;
        if(adj_m[i][v] == 1)
            if(!visited[i])
                DFS(i,adj_m,visited,order);
    }
}

void printa_m(int adj_m[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        if (adj_m[i][i] != INF)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (adj_m[i][j] == INF)
                    break;
                cout << adj_m[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ttt;
    cin >> ttt;
    int caso =1;
    while (ttt--)
    {

        int rows;
        cin >> rows;

        int adj_m[MAX][MAX];
        vector<int> visited(MAX, 0);


        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                adj_m[i][j] = INF;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rows; j++)
                adj_m[i][j] = 0;

        
        int vertices;
        cin >> vertices;

        string v;
        string w;

        for (int i = 0; i < vertices; i++)
        {
            cin >> v;
            cin >> w;
            adj_m[v[0] - 97][w[0] - 97] = 1;
            adj_m[w[0] - 97][v[0] - 97] = 1;
        }
        cout << "Case #" << caso<< ":"<<endl;


        int n = 0;
        for (int i = 0; i <rows ; i++)
        {
            if(!visited[i])
            {
                vector<int>order;
                DFS(i,adj_m,visited,order);

                sort(order.begin(), order.end());
                for(auto c: order)
                    cout << (char) (c + 97) << ",";
                cout << endl;

                n++;
            }
        }
        cout << n << " connected components" << endl;
        cout << endl;

        caso++;
    }
}