#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(long(x), long(y))

bool e_primo(long long n) {
    for (int d : {2, 3, 5}) 
        if (n % d == 0) 
            return false;
            
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) 
    {
        if (n % d == 0)
            return false;

        if (i == 8)
            i = 0;
    }
    return true;
}

void ndp(long long  n)
{
    int k = 2;
    set<int> S;

    while ((n > 1) && (k <= 1000000))
    {
        if (n % k == 0)
        {
            S.insert(k);
            while(n%k == 0) n /= k;
        }
        k++;
    }
    if(n>1){S.insert(k);} 
    // int count = S.size();

    // long aux = (pow(2,count)) - count -1;

    cout << (1 << S.size()) -S.size() - 1 << endl;
    // return aux;
}

int main()
{
    _ long long x = 1;
    cin >> x;

    ndp(x);
}