#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

void fold(vector<int> v, int pos, vector<int> &saida)
{

    if (pos > 0)
    {
        vector<int> left = {v.begin(), v.end() - pos};
        vector<int> right = {v.end() - pos, v.end()};
        reverse(left.begin(), left.end());

        vector<int> menor = (right.size() <= left.size()) ? right : left;
        saida = (right.size() <= left.size()) ? left : right;

        for (int i = 0; i < menor.size(); i++)
            saida[i] += menor[i];

        reverse(saida.begin(), saida.end());
    }
    else
    {
        saida = v;
    }
}

int main()
{
    _

        int Nsource,
        Nresult, aux;
    while (cin >> Nsource)
    {
        vector<int> source;
        for (int i = 0; i < Nsource; i++)
        {
            cin >> aux;
            source.push_back(aux);
        }

        cin >> Nresult;

        vector<int> result;
        for (int i = 0; i < Nresult; i++)
        {
            cin >> aux;
            result.push_back(aux);
        }

        vector<int> dobra1, dobra2;

        fold(source, (Nsource - Nresult), dobra1);
        fold(source, (Nresult), dobra2);

        if ((dobra1 == result) || (dobra2 == result))
            cout << "S" << endl;

        else
        {
            vector<int> dobra3;
            if(Nresult == 1)
            {
                fold(source, (Nresult), dobra3);
                for(int i = 1; i <Nsource; i++)
                    fold(dobra3, (Nresult), dobra3);
            }
            if (dobra3 == result)
                cout << "S" << endl;
            else
                cout << "N" << endl;
        }
    }
}