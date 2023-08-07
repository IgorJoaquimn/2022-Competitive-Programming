#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f
#define MAX 26
#define _                             \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);

void post_order(string &s1, string &s2, string &saida)
{
    if(s2.length() == 1)
    {
        s1 = s1.substr(1, s1.length() -1);
        saida+=s2;
        return;
    }

    if(s1.length())
    {
        size_t root = s2.find(s1[0]);
        size_t left_leaf    = s1.find(s2[0]);
        string left_tree    = s2.substr(0, root);
        string rigth_tree   = s2.substr(root + 1, s2.length() - 1);

        s1 = s1.substr(1, s1.length() -1);


        if(left_tree.length())
        post_order(s1,left_tree,saida);
        if(rigth_tree.length())
        post_order(s1,rigth_tree,saida);
        saida += s2[root];

        return;
    }
    
}

int main()
{_
    int ttt;
    cin >> ttt;
    while (ttt--)
    {
        int LLLL;
        cin >> LLLL;

        string s1, s2, s3;
        cin >> s1 >> s2;
        post_order(s1, s2, s3);
        cout << s3 << endl;
    }
}