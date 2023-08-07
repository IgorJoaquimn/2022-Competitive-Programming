#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 5*1000000
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

#define mp(x, y) std::make_pair(int(x), int(y))
typedef unsigned long long ull;



int primo[MAX];
int main()
{
    
    _ int tttt, aux,x;

    for(int i = 0; i < MAX; i++)
        primo[i] = 1;

    for(int i = 2; i <=MAX; i++)
    {
        if(!primo[i]) 
            continue;
        for(int j = 2*i; j<=MAX; j+=i)
            primo[j] = 0;
    }

    cin >> tttt;
    while(tttt--)
    {
        int n;
        cin >> n;
        set<int> q;
        int m = -1;
        for(int i = 0; i < n; i++)
        {
            cin>>x;
            q.insert(x); 
            m = max(m,x);
        }

        for(int i = 1; i <= 2*m; i++)
        {
            // cout << i << " " << primo[i] << endl;
            if(primo[i] && !q.count(i))
            {
                cout << i -1 << endl;
                break;
            }
        }
    }
}
