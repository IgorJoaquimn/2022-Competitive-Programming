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

struct ponto2D
{
    int x, y;
    ponto2D() { x = y = 0; }
    ponto2D(int _x, int _y) : x(_x), y(_y) {}

    double dist(ponto2D p1)
    {
        return hypot(p1.x - x, p1.y - y);
    }
};

struct circulo
{
    ponto2D c;
    int r;
    int pos_final;
    circulo()
    {
        c = ponto2D();
        r = 0;
        pos_final = 0;
    }
    circulo(ponto2D _c, int _r, int _pos_final) : c(_c), r(_r), pos_final(_pos_final) {}
    bool intersect(circulo c1)
    {
        return c.dist(c1.c) <= c1.r + r;
    }
};

int main(int argc, char const *argv[])
{
    int n, m, k;
    int x, y, r;
    cin >> n >> m >> k;
    vector<circulo> c;
    vector<vector<circulo>> intersecoes;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y >> r;
        c.push_back(circulo(ponto2D(x, y), r, -1));
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == j) continue;
            if (c[i].intersect(c[j]))
            {
                // c[i] ou c[j] NAO foram selecionados
                if (c[i].pos_final == -1 && c[j].pos_final == -1)
                {
                    int pos_final = intersecoes.size();
                    c[i].pos_final = pos_final;
                    c[j].pos_final = pos_final;
                    intersecoes.push_back(vector<circulo>({c[i], c[j]}));
                }

                // c[i] ou c[j] ja foram selecionados
                else
                {
                    // c[i] e c[j] ja estao juntos
                    if (c[i].pos_final == c[j].pos_final) continue;

                    // c[i] ou c[j] nao foi selecionado
                    else if (c[i].pos_final == -1 || c[j].pos_final == -1)
                    {
                        int selecionado     = c[i].pos_final == -1 ? j : i;
                        int nao_selecionado = c[i].pos_final == -1 ? i : j;
                        int pos_final       = c[selecionado].pos_final;
                        intersecoes[pos_final].push_back(c[nao_selecionado]);
                        c[nao_selecionado].pos_final = pos_final;
                    }
                    // c[i] e c[j] selecionados mas separados : JOIN 
                    else
                    {
                        int pos_I = c[i].pos_final;
                        int pos_J = c[j].pos_final;
                        for (int i = 0; i < intersecoes[pos_J].size(); i++)
                        {
                            intersecoes[pos_I].push_back(intersecoes[pos_J][i]);
                            intersecoes[pos_J][i].pos_final = pos_I;
                        }
                        intersecoes[pos_J] = vector<circulo>();
                    }
                }
            }
        }
        if (c[i].pos_final == -1) intersecoes.push_back(vector<circulo>({c[i]}));
    }
    
    for (int i = 0; i < intersecoes.size(); i++)
    {
        int minX = n + 1, maxX = 0, minY = m + 1, maxY = 0;
        for (int j = 0; j < intersecoes[i].size(); j++)
        {
            circulo caux = intersecoes[i][j];
            minX = min(minX, caux.c.x - caux.r);
            maxX = max(maxX, caux.c.x + caux.r);
            minY = min(minY, caux.c.y - caux.r);
            maxY = max(maxY, caux.c.y + caux.r);
        }
        if ((minX <= 0 && (maxX >= n || minY <= 0)) || (maxY >= m && (minY <= 0 || maxX >= n)))
        {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}