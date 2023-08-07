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

int N, mana, x, y;
vector<int> monstro;
vector<int> dano;

double damage;
double tempo[100][1001] = {0};
int adano[100][1001] = {0};

void resolve()
{
    tempo[0][0] = monstro[0]/damage;
    adano[0][0] = damage;
    for(int i=1; i<N; i++)
    {
        tempo[i][0] = monstro[i]/damage + tempo[i-1][0];
        adano[i][0] = damage;
    }
    for(int j = 1; j <= mana; j++)
    {
        adano[0][j] = damage + dano[0];
    }

    for(int j = 1; j <= mana; j++)
    {
        for(int i=1; i<N; i++)
        {
            if((tempo[i-1][j] + (monstro[i]/adano[i-1][j])) < (tempo[i-1][j-1] + (monstro[i]/adano[i-1][j-1])))
            {
                adano[i][j] = adano[i-1][j];
                tempo[i][j] = tempo[i-1][j] + (monstro[i]/adano[i][j]);
            }
            else
            {
                adano[i][j] = adano[i-1][j-1]   + dano[i];
                tempo[i][j] = tempo[i-1][j-1] + (monstro[i]/adano[i][j]);
            }
        }
    }   

}

int main()
{
    cout << fixed;
    cout << setprecision(4);
    _ 
    while (cin >> N >> mana >> damage)
    {
        
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            monstro.push_back(x);
            dano.push_back(y);
        }

        resolve();

        cout << tempo[N-1][mana] << endl;

        monstro.clear();
        dano.clear();
    }
}