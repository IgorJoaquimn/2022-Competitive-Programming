#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _ ios_base::sync_with_stdio(false);std::cin.tie(0);

int main() {_
    string buffer;
    map<int, set<unsigned long long>> mapa;

    while(cin >> buffer)
    {
        int index = 0;
        unsigned long long result = 0;
        for(int i = buffer.length()-1; i >= 0; i--)
        {
            if(buffer[i] == '(') 
                result += 1<<index;
            index++;
        }
        mapa[buffer.length()].insert(result);
    }

    int count=0;
    for(auto &c: mapa)
    {
        for(auto &v: c.second) 
        {
            count++;
        }
    }
        
    cout << count << endl;
}