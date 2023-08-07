#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

int main()
{
    _
    string entry;
    cin >> entry;

    long long int x, y;
    long long int soma = 0;
    for (int i = 0; i < entry.size(); i++)
        soma += (int)entry[i] - 48;

    x = (soma - 1) % 3;
    y = (soma - 2) % 3;

    if (!x)
        cout << 1 << endl;
    else if (!y)
        cout << 2 << endl;
    else
        cout << 0 << endl;
    return 0;
}