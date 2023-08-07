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
    _ int ttt;
    while (cin >> ttt)
    {
        list<int> v;

        int op;
        int value;

        // FLAGS
        bool isPriority = true;
        bool isQueue    = true;
        bool isStack    = true;

        for(int i=0; i<ttt; i++)
        {
            cin >> op >> value;


            if (op == 1)
                v.push_back(value);

            int maxPriority = *max_element(v.begin(), v.end());
            int first   = v.front();
            int last    = v.back();
            if (op == 2)
            {
                if (value != maxPriority)
                    isPriority = false;
                if (value != last)
                    isStack = false;
                if (value != first)
                    isQueue = false;
                
                v.remove(value);
            }
        }

        if (isPriority && !isQueue && !isStack)
        {
            cout << "priority queue" << endl;
        }
        else if (!isPriority && isQueue && !isStack)
        {
            cout << "queue" << endl;
        }
        else if (!isPriority && !isQueue && isStack)
        {
            cout << "stack" << endl;
        }
        else if (isPriority || isQueue || isStack)
        {
            cout << "not sure" << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }
}