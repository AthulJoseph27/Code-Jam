#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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

vector<pair<int, int>> getNeighbours(vector<vector<int>> &a, int i, int j)
{
    vector<pair<int, int>> rs(4);

    if (i - 1 >= 0)
        rs[0] = make_pair(i - 1, j);
    else
        rs[0] = make_pair(-1, -1);

    if (j - 1 >= 0)
        rs[1] = make_pair(i, j - 1);
    else
        rs[1] = make_pair(-1, -1);

    if (i + 1 < a.size())
        rs[2] = make_pair(i + 1, j);
    else
        rs[2] = make_pair(-1, -1);

    if (j + 1 < a[0].size())
        rs[3] = make_pair(i, j + 1);
    else
        rs[3] = make_pair(-1, -1);

    return rs;
}
void solve(int cc)
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> a(r, vector<int>(c));

    vector<pair<int, int>> pos;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            pos.push_back(make_pair(i, j));
        }
    }

    sort(all(pos), [&](const pair<int, int> ta, const pair<int, int> tb) {
        return a[ta.first][ta.second] > a[tb.first][tb.second];
    });

    unsigned long long count = 0;

    queue<pair<int, int>> toCheck;

    for (auto p : pos)
    {
        vector<pair<int, int>> n = getNeighbours(a, p.first, p.second);
        for (pair<int, int> v : n)
        {
            if (v.first != -1)
            {
                if (a[v.first][v.second] < a[p.first][p.second] - 1)
                {
                    count += (a[p.first][p.second] - 1 - a[v.first][v.second]);
                    a[v.first][v.second] = a[p.first][p.second] - 1;
                    toCheck.push(make_pair(v.first, v.second));
                }
            }
        }
    }

    while (!toCheck.empty())
    {
        pair<int, int> p = toCheck.front();
        toCheck.pop();
        vector<pair<int, int>> n = getNeighbours(a, p.first, p.second);
        for (pair<int, int> v : n)
        {
            if (v.first != -1)
            {
                if (a[v.first][v.second] < a[p.first][p.second] - 1)
                {
                    count += (a[p.first][p.second] - 1 - a[v.first][v.second]);
                    a[v.first][v.second] = a[p.first][p.second] - 1;
                    toCheck.push(make_pair(v.first, v.second));
                }
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