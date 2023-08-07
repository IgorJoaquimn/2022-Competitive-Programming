#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define mp(x, y) std::make_pair(int(x), int(y))

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 10000000
#define mod 2
typedef unsigned long long ll;

struct estado
{
    int next[26] = {-1};
    bool leaf = false;
    estado()
    {
        fill(begin(next), end(next), -1);
    }
    ~estado()
    {
    }
};

vector<estado> trie;
vector<int> passagens;

int eruim(string const &s)
{
    int v = 0;
    for (char ch : s)
    {
        int c = ch - 'a';
        passagens[v]++;
        if (trie[v].leaf && passagens[v] >= 2)
            return 1;
        if (trie[v].next[c] == -1)
        {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
            passagens.emplace_back(0);
        }
        v = trie[v].next[c];
    }
    passagens[v]++;
    trie[v].leaf = true;
    return (passagens[v] >= 2);
}

int main()
{

    _ int n, x;
    while (cin >> n)
    {
        trie.clear();
        passagens.clear();
        trie.emplace_back();
        passagens.emplace_back(0);

        if (n == 0)
            break;
    
        string s;
        bool e, achou = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (achou) continue;
            e = eruim(s);
            if (e)
            {
                cout << "Conjunto Ruim" << endl;
                achou = 1;
            }
        }
        if (!e)
            cout << "Conjunto Bom" << endl;
    }
}
