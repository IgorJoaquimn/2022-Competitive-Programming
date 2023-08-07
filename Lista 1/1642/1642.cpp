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

string frase;


int LIS2(int n,int m)
{

    if(m <= 0) return 0;

    vector<vector<int>> maximum(frase.size(), vector<int>(frase.size(), -INF));
    vector<vector<string>> letras_usadas(frase.size(), vector<string>(frase.size(), ""));
    for(int i = 0; i < frase.size(); i++)
    {
        maximum[i][i] = 1;
        letras_usadas[i][i] = frase[i];
    }

    for(int i = 0; i < frase.size(); i++)
    {
        for(int j = i; j <frase.size(); j++)
        {
            // achou
            if(letras_usadas[i][j-1].find(frase[j]) != std::string::npos)
            {
                if(letras_usadas[i][j-1].length())

            }
        }
    }
    // if(m <= 0) return 0;
    // if(i == 0) return 0;
    // if(i == 1) return 1;


    // if(i <= m-1)
    // if(maximum[i] != -INF) 
    // return maximum[i];
    
    // int max = -INF;
    // for(int j = i-1; j >= 1; j--)
    // {
    //     int aux = 1;
    //     // if(um[frase[j-1]] <= um[frase[i-1]])
    //     {
    //         // if(um[frase[j-1]] != um[frase[i-1]])
    //             m--;
            
            
    //         aux += LIS(j,m);
    //     }
    //     max = aux > max ? aux : max;
    // }
    // maximum[i] = max;
    // return max;
    return 1;
}


int LIS(int i, int m)
{
    string aux = frase.substr(0, i+1);
    set<char> um;
    um.insert(aux[i]);

    int n = 0,size=1;
    for(int j = i - 1 ; j>=(m-i); j--)
    {
        auto ret = um.insert(aux[j]);
        if(ret.second == true)
            size++;
        if(size > m)
            return n + 1;
        n++;
    }
    return 1;
}

int main()
{
    _ int x = 1;
    while ((cin >> x) && (x != 0))
    {
        getline(cin,frase);
        getline(cin,frase);

        int max = -INF, aux;
        for(int i = 0; i <frase.length(); i++)
        {
            aux = LIS2(i,x);
            max = aux > max ? aux : max;
        }

        cout << max << endl;
    }
}