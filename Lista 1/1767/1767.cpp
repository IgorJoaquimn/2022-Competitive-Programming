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

vector<int> WORI(101, INF);
vector<int> VORI(101, -INF);
vector<vector<int>> ORIGINAL(101, vector<int>(51, -INF));
vector<int> WEIGHT;
vector<int> VALUE;
vector<vector<int>> m;

void saco(int n, int w)
{
    for (int j = 0; j <= w; j++)
        m[0][j] = 0;

    for (int i = 1; i <= n; i++)
        m[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (WEIGHT[i] > j)
                m[i][j] = m[i - 1][j];
            else
                m[i][j] = max(m[i - 1][j], m[i - 1][j - WEIGHT[i]] + VALUE[i]);
        }
    }

    
}

set<int> decide_optimal(int i, int j)
{
    if (i == 0)
        return set<int>();
    if (m[i][j] > m[i - 1][j])
    {
        set<int> value = {i};
        set<int> other = decide_optimal(i - 1, j - WEIGHT[i]);
        set<int> dest;
        set_union(value.begin(), value.end(), other.begin(), other.end(), inserter(dest, dest.begin()));
        return dest;
    }
    else
    {
        return decide_optimal(i - 1, j);
    }
}

int main()
{
    _ int tttt;
    cin >> tttt;
    while (tttt--)
    {
        int n;
        cin >> n;

        WEIGHT = WORI;
        VALUE  = VORI;
        m = ORIGINAL;

        WEIGHT[0] = INF;
        VALUE[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int qtd, pesos;
            cin >> qtd >> pesos;
            WEIGHT[i] = pesos;
            VALUE[i]  = qtd;
        }
        saco(n, 50); 
        auto www = decide_optimal(n, 50);
        int peso = 0, quantidade = 0;
        for(auto &c:www) 
        {
            peso+= WEIGHT[c];
            quantidade+= VALUE[c];
        }
        
        int sobra = n - www.size() ;


       
        cout << quantidade << " brinquedos" <<  endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "sobra(m) " << sobra << " pacote(s)" << endl;
        cout << endl;

        WEIGHT.clear();
        VALUE.clear();
        m.clear();
    }
}