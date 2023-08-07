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

typedef pair<int, int> point;
typedef long long ll;
typedef unsigned long long ull;

int ccw(point p, point q, point r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val > 0)
        return 1; // collinear
    else
        return 0;
}

vector<point> envelope(vector<point> pts)
{
    vector<point> q;
    q.push_back(pts[0]);
    q.push_back(pts[1]);

    for (int i = 2; i < pts.size(); i++)
    {
        while (q.size() >= 2 && ccw(q[q.size() - 2], q.back(), pts[i]))
        {
            q.pop_back();
        }
        q.push_back(pts[i]);
    }
    return q;
}

vector<point> ch(vector<point> pts)
{
    vector<point> v1 = envelope(pts);
    reverse(pts.begin(), pts.end());
    vector<point> v2 = envelope(pts);
    v1.pop_back();
    v2.pop_back();
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

ll extern_product(point p, point q, point r)
{
    return (q.second - p.second) * (r.first - q.first) -
           (q.first - p.first) * (r.second - q.second);
}

double area(vector<point> pts)
{
    double res = 0;
    for (unsigned i = 0; i < pts.size(); i++) {
        point p = i ? pts[i - 1] : pts.back();
        point q = pts[i];
        res += (p.first - q.first) * (p.second + q.second);
    }
    return fabs(res) / 2;
}

int main()
{
    _ int n, x, y, z;
    while (1)
    {
        vector<point> pts;
        for (int i = 0; i < 5; i++)
        {
            cin >> x >> y;
            pts.push_back({x, y});
        }
        sort(pts.begin(), pts.end());
        if (pts[0].first == pts[1].first && pts[0].second == pts[1].second)
            break;
        vector<point> convex = ch(pts);

        if (convex.size() == 5)
        {
            double m = -INF;
            point aux;
            for (int i = 0; i < 5; i++)
            {
                if (i != 0)
                    pts.push_back(aux);

                sort(pts.begin(), pts.end());
                aux = pts[i];
                pts.erase(pts.begin() + i);
                convex = ch(pts);
                m = max(m, area(convex));
            }
            cout << m << endl;
            continue;
        }

        if (convex.size() == 3)
        {
            vector<point> difference;
            sort(convex.begin(), convex.end());
            set_difference(
                pts.begin(), pts.end(),
                convex.begin(), convex.end(),
                back_inserter(difference));
            sort(difference.begin(), difference.end());

            bool a = ccw(difference[0], difference[1], convex[0]);
            bool b = ccw(difference[0], difference[1], convex[1]);
            bool c = ccw(difference[0], difference[1], convex[2]);
            if (a == b)
            {
                auto it = find(pts.begin(), pts.end(), convex[2]);
                pts.erase(it);
            }
            else if (a == c)
            {
                auto it = find(pts.begin(), pts.end(), convex[1]);
                pts.erase(it);
            }
            else if (b == c)
            {
                auto it = find(pts.begin(), pts.end(), convex[0]);
                pts.erase(it);
            }

            convex = ch(pts);
        }

        cout << area(convex) << endl;
    }
    return 0;
}