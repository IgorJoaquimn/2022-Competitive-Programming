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

bool possivel_subir(int x, int y, int A, int B, vector<int> &v)
{
    if (x == A && y == B)
        return true;
    while (v[x + 1] > y + 1)
    {
        x++;
        y++;
        if (x == A && y == B)
            return true;
    }
    return false;
}

bool possivel_descer(int x, int y, int A, int B, vector<int> &v)
{
    if (x == A && y == B)
        return true;
    while (v[x + 1] > y - 1)
    {
        x++;
        y--;
        if (x == A && y == B)
            return true;
    }
    return false;
}

bool existe_triangulo(int x, int j, vector<int> &v)
{
    int y = 0;
    int A = x + j - 1;
    int B = y + j - 1;
    if (possivel_subir(x, y, A, B, v))
    {
        x = A;
        y = B;
        A = A + j - 1;
        B = B - j + 1;
        if (possivel_descer(x, y, A, B, v))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    _ int N, aux, x, y;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        if (i != 0)
            v.push_back(min(aux, v[i - 1] + 1));
        else
            v.push_back(aux);
    }
    int maior_altura = 1;
    int altura_maxima = (N + 1) / 2;

    for (int i = 0; i < N - 1; i++)
    {
        x = i;
        int higher = altura_maxima;
        int lower  = maior_altura + 1;
        //Condicao de optimizacao
        if ((x + maior_altura) > N)
            break;

        //Busca binaria
        if (existe_triangulo(x, maior_altura, v))
        {
            while (lower < higher)
            {
                int m = lower + (higher - lower) / 2;
                if (existe_triangulo(x, m, v))
                {
                    lower = m + 1;
                    maior_altura = max(m, maior_altura);
                }
                else
                {
                    higher = m;
                }
            }
        }
        //Busca binaria ultimo caso
        if (lower == higher  && existe_triangulo(x, higher, v))
            maior_altura = max(higher, maior_altura);
    }
    cout << maior_altura << endl;
}