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

int main()
{
    int n, c, t;
    int achou_resposta = 0;
    cin >> n >> c >> t;
    int qtd_pipo[n];

    int maior = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> qtd_pipo[i];
        maior = max(maior, qtd_pipo[i]);
    }


    // necessario no minimo maior/t segundos para comer
    int x = pow(2,(int) ceil(log2(maior/t)));
    int coeficiente_de_ajuste = (x / 2) , aux = 1;

    int possivel_resposta;
    while (aux != 0)
    {
        int qtd_comidas = 0;
        int qtd_competidores = 0;

        for (int i = 0; i < n; i++)
        {
            // Se comer esse saco de pipoca demorar mais que X segundos, aumente o X, se todo competidor ja tiver comido nesses X segundos, termine
            if (ceil(qtd_pipo[i] * 1.0 / t) > x || qtd_competidores == c)
            {
                qtd_competidores = c + 1;
                break;
            }

            // Se eu consigo comer todas as anteriores + a atual, coma
            if (ceil((qtd_comidas + qtd_pipo[i])*1.0 / (t * 1.0)) <= x) qtd_comidas += qtd_pipo[i];

            // Se não for possivel comer essa pipoca + nenhuma anterior,aloque um competidor para comer esse novo saco
            else
            {
                qtd_competidores++;
                qtd_comidas = qtd_pipo[i];
            }
        }
        
        qtd_competidores++;
        aux = (x - coeficiente_de_ajuste) / 2;
        if (qtd_competidores <= c)
        {
            possivel_resposta = x;
            achou_resposta = true;
            x -= aux;
        }
        else if (!achou_resposta)
        {
            aux = 1;
            coeficiente_de_ajuste = x;
            x = x * 2;
        }
        else
        {
            coeficiente_de_ajuste = x;
            x += aux;
        }
    }
    cout << possivel_resposta << endl;
}