#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

char mat[310][310];
int r, c, k; // r -> rows, c -> columns
int m[310][310];

int achaArea(int i, int j, int co)
{
    int assentos = m[i][j] - m[i][co - 1];
    if (assentos < k)
        return INF;
    int ans = i * (j - co + 1);
    int e = 1, d = j;
    int mid = (e + d) / 2;
    while (e < d)
    {
        mid = (e + d) / 2;
        int aux = assentos - m[mid - 1][j] + m[mid - 1][co - 1];
        if (aux >= k)
        {
            d = mid;
        }
        else
            e = mid + 1;
    }
    for (int a = 0; a < e; a++)
    {
        int aux = assentos - m[a - 1][j] + m[a - 1][co - 1];
        if (aux >= k)
            ans = min(ans, (i - a + 1) * (j - co + 1));
    }
    return ans;
}

int main()
{
    _
            cin >>
        r >> c >> k;
    while (r && c && k)
    {
        int assentos = 0;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == '.')
                    assentos++;
            }
        }
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j <= c; j++)
            {
                bool flag = (mat[i][j] == '.');
                if (i == 1 && j == 1) m[i][j] = 0 + flag;
                else if (i == 1) m[i][j] = m[i][j - 1] + flag;
                else if (j == 1) m[i][j] = m[i - 1][j] + flag;
                else m[i][j] = m[i][j - 1] + m[i - 1][j] - m[i - 1][j - 1] + flag;
            }
        }

        vector<int> rows;
        for (int i = 0; i <= r; i++)
        {
            rows.push_back(m[i][c]);
        }
        vector<int> cols;
        for (int i = 0; i <= c; i++)
        {
            cols.push_back(m[r][i]);
        }
        
        int minRows = lower_bound(rows.begin(), rows.end(), k) - rows.begin();
        int minCols = lower_bound(cols.begin(), cols.end(), k) - cols.begin();

        int area = INF;
        for (int i = minRows; i <= r; i++)
        {
            for (int j = minCols; j <= c; j++)
            {
                if (m[i][j] >= k)
                {
                    for (int l = 1; l <= j; l++)
                    {
                        area = min(area, achaArea(i, j, l));
                    }
                }
            }
        }
        cout << area << endl;
        cin >> r >> c >> k;
    }
    return 0;
}