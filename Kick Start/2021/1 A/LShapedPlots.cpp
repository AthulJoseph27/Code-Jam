#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
#define all(v) v.begin(), v.end()

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void solve(int cc)
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    vector<pair<pair<pair<int, int>, pair<int, int>>, int>> v;
    vector<pair<pair<pair<int, int>, pair<int, int>>, int>> h;

    for (int i = 0; i < r; i++)
    {
        bool flag = false;
        pair<int, int> st;
        for (int j = 0; j < c; j++)
        {
            if (!flag && a[i][j] == 1)
            {
                flag = true;
                st = make_pair(i, j);
            }
            if (flag && a[i][j] == 0)
            {
                flag = false;
                h.push_back(make_pair(make_pair(st, make_pair(i, j - 1)), j - st.second));
            }
        }
        if (flag)
        {
            h.push_back(make_pair(make_pair(st, make_pair(i, c - 1)), c - st.second));
        }
    }

    for (int i = 0; i < c; i++)
    {
        bool flag = false;
        pair<int, int> st;
        for (int j = 0; j < r; j++)
        {
            if (!flag && a[j][i] == 1)
            {
                flag = true;
                st = make_pair(j, i);
            }
            if (flag && a[j][i] == 0)
            {
                flag = false;
                v.push_back(make_pair(make_pair(st, make_pair(j - 1, i)), j - st.first));
            }
        }
        if (flag)
        {
            v.push_back(make_pair(make_pair(st, make_pair(r - 1, i)), r - st.first));
        }
    }

    // sort(all(h), [&](const pair<pair<pair<int, int>, pair<int, int>>, int> a, const pair<pair<pair<int, int>, pair<int, int>>, int> b) {
    //     return a.second < b.second;
    // });

    // sort(all(v), [&](const pair<pair<pair<int, int>, pair<int, int>>, int> a, const pair<pair<pair<int, int>, pair<int, int>>, int> b) {
    //     return a.second < b.second;
    // });

    int count = 0;

    for (auto ph : h)
    {
        for (auto pv : v)
        {
            pair<int, int> vs = pv.first.first;
            pair<int, int> ve = pv.first.second;
            pair<int, int> hs = ph.first.first;
            pair<int, int> he = ph.first.second;

            if (vs.first == ve.first)
                continue;

            if (hs.second == he.second)
                continue;

            pair<int, int> intersection = make_pair(hs.first, vs.second);

            if (intersection.first >= vs.first && intersection.first <= ve.first && intersection.second >= hs.second && intersection.second <= he.second)
            {
                // debug(intersection, count);

                int vl = ve.first - intersection.first + 1;
                int hl = he.second - intersection.second + 1;
                // debug(hl, vl);
                if (min(vl, hl) > 1)
                {
                    int mn = min(vl, hl);
                    int mx = max(vl, hl);
                    for (int i = 2; i <= mn; i++)
                    {
                        if (i * 2 <= mx)
                            count++;
                    }
                    for (int i = 2; i <= mx; i++)
                    {
                        if (i * 2 <= mn)
                            count++;
                    }
                }

                vl = intersection.first - vs.first + 1;

                if (min(vl, hl) > 1)
                {
                    int mn = min(vl, hl);
                    int mx = max(vl, hl);
                    for (int i = 2; i <= mn; i++)
                    {
                        if (i * 2 <= mx)
                            count++;
                    }
                    for (int i = 2; i <= mx; i++)
                    {
                        if (i * 2 <= mn)
                            count++;
                    }
                }

                hl = intersection.second - hs.second + 1;

                if (min(vl, hl) > 1)
                {
                    int mn = min(vl, hl);
                    int mx = max(vl, hl);
                    for (int i = 2; i <= mn; i++)
                    {
                        if (i * 2 <= mx)
                            count++;
                    }
                    for (int i = 2; i <= mx; i++)
                    {
                        if (i * 2 <= mn)
                            count++;
                    }
                }

                vl = ve.first - intersection.first + 1;

                if (min(vl, hl) > 1)
                {
                    int mn = min(vl, hl);
                    int mx = max(vl, hl);
                    for (int i = 2; i <= mn; i++)
                    {
                        if (i * 2 <= mx)
                            count++;
                    }
                    for (int i = 2; i <= mx; i++)
                    {
                        if (i * 2 <= mn)
                            count++;
                    }
                }
                // debug(intersection, count);
            }
        }
    }

    cout << "Case #" << cc << ": ";
    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}