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
#define UPR 1
#define UPL 2
#define DR 3
#define DL 4

int N = INF, M = INF, len, par;
vector<int> state;
vector<vector<int>> origin(100,vector<int>(4,-INF));
vector<vector<int>> maximum(origin);

int adjust(int n)
{
    if (M % 2)
        return 0;
    return !(((int)ceil(2.0 * n / M)) % 2);
    // return
}

int up_right(int pos)
{
    int mid  = pos + ceil(M / 2.0)      + adjust(pos);
    int dest = pos + 2 * ceil(M / 2.0)  + par; 

    if (par)
    {
        if ((pos % M) == 0) return 0;
        if ((mid % M) == 0)  return 0;
    }
    else
    {
        if (((pos - (int)ceil(M / 2.0)) % M) == 0) return 0;
        if (((mid - (int)ceil(M / 2.0)) % M) == 0) return 0;
    }
    if(dest > ceil((N * M) / 2.0)) return 0;
    if (state[mid-1]  != 2)  return 0;
    if (state[dest-1] != 0) return 0;
    return dest;
}

int up_left(int pos)
{
    int mid  = pos + ceil(M / 2.0)    + adjust(pos) - 1;
    int dest = pos + ceil(M / 2.0)*2  + par         - 2;
    
    if (((pos - 1) % M) == 0) return 0;
    if (((mid - 1) % M) == 0) return 0;

    if(dest > ceil((N * M) / 2.0)) return 0;
    if (state[mid-1] != 2)  return 0;
    if (state[dest-1] != 0) return 0;
    return dest;
}

int down_right(int pos)
{
    int mid  = pos - ceil(M / 2.0) + adjust(pos) + 1 - par;
    int dest = pos - 2 * ceil(M / 2.0) + 1 + !par;

    if (par)
    {
        if ((pos % M) == 0) return 0;
        if ((mid % M) == 0)  return 0;
    }
    else
    {
        if (((pos - (int)ceil(M / 2.0)) % M) == 0) return 0;
        if (((mid - (int)ceil(M / 2.0)) % M) == 0) return 0;
    }
    if(dest <= 0) return 0;
    if (state[mid-1] != 2) return 0;
    if (state[dest-1] != 0) return 0;
    return dest;
}

int down_left(int pos)
{
    int mid  = pos - ceil(M / 2.0)   - par + adjust(pos);
    int dest = pos - ceil(M / 2.0)*2 - par;
    if (((pos - 1) % M) == 0)  return 0;
    if (((mid - 1) % M) == 0) return 0;


    if(dest <= 0) return 0;
    if (state[mid-1] != 2)  return 0;
    if (state[dest-1] != 0) return 0;
    return dest;
}

int solv(int source, int come_by, vector<vector<vector<int>>> visitados, vector<int> path)
{
    int a,b,c,d;
    if(find(path.begin(), path.end(),source) != path.end())
    {

        vector<int> ops2;
        a = up_right(source);
        b = up_left(source);
        c = down_right(source);
        d = down_left(source);
        ops2.push_back(a);
        ops2.push_back(b);
        ops2.push_back(c);
        ops2.push_back(d);
        for(int i=0; i<4; i++)
        {
            int max = -INF;
            if(ops2[i])
            {
                // path.push_back(source);
                auto it = find(path.begin(), path.end(),ops2[i]);
                if(it == path.end())
                {
                    // path.push_back(ops2[i]);
                    if(visitados[source-1][i].size()) 
                    {
                        it = find(visitados[source-1][i].begin(), visitados[source-1][i].end(),ops2[i]);
                        int index = it - visitados[source-1][i].begin();
                        int aux = visitados[source-1][i].size() - index;
                        max = aux > max ? aux : max;
                    }
                }
            }
            if(max != -INF) return max;
        }
    }
    
    path.push_back(source);

    vector<int> ops;
    a = up_right(source);
    b = up_left(source);
    c = down_right(source);
    d = down_left(source);
    ops.push_back(a);
    ops.push_back(b);
    ops.push_back(c);
    ops.push_back(d);

    if (come_by)
        ops[4-come_by] = 0;

    for(int i=0; i<4; i++)
        if(visitados[source-1][i].size())
            ops[i] = 0;

    bool zeros = all_of(ops.begin(), ops.end(), [](int i) { return i==0; });
    if(zeros) return 0;

    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        int next = ops[i];
        if (next)
        {
            visitados[source-1][i] = path; 
            visitados[source-1][i].push_back(next); 
            int aux = 1;
            if(maximum[source-1][i] == -INF)
            {
                aux+= solv(next, i + 1, visitados,path);
                maximum[source-1][i] = aux;
            }
            else
                aux+=maximum[source-1][i];
                max = aux > max ? aux : max;
        }
    }
    return max;
}

int main()
{
    _ int x;

    while (1)
    {
        cin >> N >> M;
        if ((N == 0) && (M == 0))
            break;

        len = ceil((N * M) / 2.0);
        par = !(M % 2);
        for (int i = 0; i < len; i++)
        {
            cin >> x;
            state.push_back(x);
        }
        

        
        int max = 0;
        for (int i = 0; i < state.size(); i++)
            if (state[i] == 1)
            {
                vector<vector<vector<int>>> visitados(len,vector<vector<int>>(4));
                vector<int> path;
                int aux = solv(i+1, 0, visitados,path);
                max = aux > max ? aux : max;
            }
        cout << max << endl;
        state.clear();
        maximum.clear();
        maximum = origin;
    }
}