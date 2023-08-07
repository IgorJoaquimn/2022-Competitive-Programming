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
typedef unsigned long long ull;

int letters[]   = {0,2,3,5,7,8,10};
int tom[12][12] = {0};

void pi(string str, int *p)
{
	p[0] = 0;
	for(int i =1, j=0; i <str.size(); i++)
	{
		while(j > 0 and str[j] != str[i]) j= p[j-1];
		if(str[j] == str[i]) j++;
		p[i] = j;
	}
}

int m,t;

int main()
{
    _ ull tttt, aux;

    for(int i = 0; i <12; i++) 
    {
        for(int j = 0; j <12-i; j++)
        {
            tom[i][j+i] = j;
        }
    }

    for(int i = 1; i <12; i++) 
    {
        for(int j = 1; j <=i; j++)
        {
            tom[i][i-j] = 12-j;
        }
    }

    for(int i = 0; i <12; i++) 
        tom[i][i] = 12;

        

    string x;
    int count = 1;
    while (cin >> m >> t)
    {
        if (m == 0 && t == 0) return 0;
        string str[m];
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            str[i] = x;
        }
        
        string p[t];
        for (int i = 0; i < t; i++)
        {
            cin >> x;
            p[i] = x;
        }

        string text;
        for (int i = 0; i < m - 1; i++)
        {
            int f = letters[(int)(str[i][0] - 'A')];
            if(str[i].size() == 2)
                f += (str[i][1] == '#') ? 1 : -1;
            
            int l = letters[(int)(str[i+1][0] - 'A')];
            if(str[i+1].size() == 2)
                l += (str[i+1][1] == '#') ? 1 : -1;
            
            if(f == -1) f = 11;
            if(l == -1) l = 11;
            
            
            text.append(to_string(tom[f][l]));
            if(i!= m -2) text.push_back('-');
        }

        string pattern;
        for (int i = 0; i < t - 1; i++)
        {
            if(count == 47)
                cout << "";
            int f = letters[(int)(p[i][0] - 'A')];
            if(p[i].size() == 2)
                f += (p[i][1] == '#') ? 1 : -1;
            
            int l = letters[(int)(p[i+1][0] - 'A')];
            if(p[i+1].size() == 2)
                l += (p[i+1][1] == '#') ? 1 : -1;

            if(f == -1) f = 11;
            if(l == -1) l = 11;
            
            pattern.append(to_string(tom[f][l]));
            if(i!= t -2) pattern.push_back('-');
            
        }
        int psize = pattern.size();
        pattern += "$" + text;
        // cout << pattern << endl;


        int d[pattern.size()];
        pi(pattern,d);

        int i;
        for(i = 0 ; i < pattern.size(); i++)
            if(d[i] == psize)
            {
                cout << "S" << endl;
                break;
            }
        if(i == pattern.size())
        cout << "N" << endl;

        count++;
    }
}
