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

vector<string> v[10];

void init()
{
    v[0].push_back(".*");
    v[0].push_back("**");

    v[1].push_back("*.");
    v[1].push_back("..");

    v[2].push_back("*.");
    v[2].push_back("*.");

    v[3].push_back("**");
    v[3].push_back("..");

    v[4].push_back("**");
    v[4].push_back(".*");

    v[5].push_back("*.");
    v[5].push_back(".*");

    v[6].push_back("**");
    v[6].push_back("*.");

    v[7].push_back("**");
    v[7].push_back("**");

    v[8].push_back("*.");
    v[8].push_back("**");

    v[9].push_back(".*");
    v[9].push_back("*.");
}

void itb(int n, int fase)
{
    cout << v[n][fase - 1];
}

void crop(string &a, string &b, vector<string> &saida)
{
    saida.push_back(a.substr(0, 2));
    saida.push_back(b.substr(0, 2));

    if (a.size() > 3)
    {
        a = a.substr(3);
        b = b.substr(3);
    }
    else
    {
        a = a.substr(2);
        b = b.substr(2);
    }
}

int cmp(vector<string> &a)
{
    for (int i = 0; i < 10; i++)
    {
        if (!(v[i][0].compare(a[0])))
            if (!(v[i][1].compare(a[1])))
                return i;
    }
    return -1;
}

int main()
{
    init();
    _ int tttt;
    while (cin >> tttt)
    {
        if(tttt == 0) break;
        string entrada;
        cin >> entrada;
        if (entrada[0] == 'S')
        {
            cin >> entrada;
            for (int i = 0; i < entrada.size(); i++)
            {
                itb((int)entrada[i] - 48, 1);
                if (i != entrada.size() - 1)
                    cout << " ";
            }
            cout << endl;

            for (int i = 0; i < entrada.size(); i++)
            {
                itb((int)entrada[i] - 48, 2);
                if (i != entrada.size() - 1)
                    cout << " ";
            }
            cout << endl;

            for (int i = 0; i < entrada.size(); i++)
                if (i != entrada.size() - 1)
                    cout << ".. ";
                else
                    cout << "..";

            cout << endl;
        }
        else if (entrada[0] == 'B')
        {
            string entradaA, entradaB;
            vector<string> saida;
            getline(cin, entradaA);
            getline(cin, entradaA);
            getline(cin, entradaB);

            for (int i = 0; i < tttt; i++)
            {
                crop(entradaA, entradaB, saida);
                cout << cmp(saida);
                saida.clear();
            }
            cout << endl;
            getline(cin, entradaB);
        }
    }
}