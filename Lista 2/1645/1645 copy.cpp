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

#define mp(x, y) std::make_pair(int(x), int(y))

int n, k;
vector<long long> ms;
vector<long long> rg;
vector<int> s;

void regular_lis(vector<int> const& a) {
    int n = a.size();
    vector<long long> d(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }
    rg=d;
}


unsigned long long lis()
{
    vector<long long> maior_subs = ms;
    vector<int> sequence = s;

    unsigned long long sum = 0;
    maior_subs[0] = (k == 1) ? 1 : -1;

    vector<int> antecessor(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (sequence[j] < sequence[i])
            {
                if (maior_subs[j] < 0)
                {
                    if (abs(maior_subs[j] - 1) == k)
                    {
                        maior_subs[i] = 1;
                        break;
                    }
                    else
                        maior_subs[i] = min(maior_subs[j] - 1,maior_subs[i]);
                }

                else if (maior_subs[j] > 0)
                {
                    antecessor[i] = j;
                    unsigned long long count = 0, avg = 0, aux = i;
                    while (antecessor[aux] != -1)
                    {
                        aux = antecessor[aux];
                        avg += k * maior_subs[aux];
                        count++;
                    }
                    maior_subs[i] = avg / count;
                    break;
                }
            }
        }

        if (maior_subs[i] == 0)
            maior_subs[i] = -1;
        if (maior_subs[i] > 0)
        {
            sum += maior_subs[i];
        }
    }
    return sum;
}

int main()
{
    _ unsigned long long tttt, aux, x, y;
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
            break;
        vector<int> v(n, 0);
        vector<long long> vm(n, 0);
        ms = vm;
        rg = vm;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v[i] = x;
        }

        s = v;

        regular_lis(v);
        cout << lis() << endl;
    }
}
