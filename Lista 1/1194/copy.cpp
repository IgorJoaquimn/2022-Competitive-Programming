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
    size_t root = s2.find(s1[0]);
    size_t left_leaf = s1.find(s2[0]);

    string aux1 = s1.substr(1, left_leaf);
    string aux2 = s2.substr(0, root);

    string aux3 = s1.substr(left_leaf + 1, s1.length() - 1);
    string aux4 = s2.substr(root + 1, s2.length() - 1);

       if (aux1.length())
    {
        reverse(aux1.begin(), aux1.end());
        if (strcmp(aux2.c_str(), aux1.c_str()) == 0)
            saida += aux2.substr(0, aux1.length());
        else
        {
            reverse(aux1.begin(), aux1.end());
            post_order(aux1, aux2, saida);
        }
    }

    if (aux3.length())
    {
        reverse(aux3.begin(), aux3.end());
        if (strcmp(aux3.c_str(), aux4.c_str()) == 0)
            saida += aux4.substr(0, aux3.length());
        else
        {
            reverse(aux3.begin(), aux3.end());
            post_order(aux3, aux4, saida);
        }
    }
    saida += s1[0];
}

int main()
{_
    string s1  = "DBHEIAFCG", s2 = "ABDEHICFG", s3;
    post_order(s2, s1, s3);
    cout << s3 << endl;

    // int ttt;
    // cin >> ttt;
    // while (ttt--)
    // {
    //     int LLLL;
    //     cin >> LLLL;

    //     string s1, s2, s3;
    //     cin >> s1 >> s2;
    //     post_order(s1, s2, s3);
    //     cout << s3 << endl;
    // }
}