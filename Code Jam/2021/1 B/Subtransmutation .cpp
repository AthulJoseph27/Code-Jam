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

map<int, unordered_map<int, int>> lookup;
bool check(int n, int a, int b, unordered_map<int, int> &u, int mx)
{
    unordered_map<int, int> mp;

    // if u reach a, then there is no more possible way to make a
    // so dont break a if a has only the required number of counts

    vector<int> useless;
    useless.push_back(n);
    while (true)
    {
        vector<int> temp;
        // bool flag = true;
        for (int i : useless)
        {
            if (lookup.find(i) != lookup.end())
            {
                for (int j = 1; j <= mx; j++)
                {
                    int dt = lookup[i][j];
                    int sub = min(u[j] - mp[j], dt);
                    dt -= sub;
                    mp[j] += sub;
                    while (dt > 0)
                    {
                        temp.push_back(j);
                        dt--;
                    }
                }
            }
            else
            {
                int t1 = i - a;
                int t2 = i - b;

                // debug(t1, t2, mp);
                // debug(t1, mp[t1], u[t1]);
                if (t1 > 0 && mp[t1] < u[t1])
                {
                    mp[t1] = mp[t1] + 1;
                    // flag = false;
                }
                else
                {
                    temp.push_back(t1);
                }

                if (t2 > 0 && mp[t2] < u[t2])
                {
                    mp[t2] = mp[t2] + 1;
                    // flag = false;
                }
                else
                {
                    temp.push_back(t2);
                }
            }

            // debug(t1, t2, mp);
        }
        if (temp.size() == 0)
        {
            break;
        }

        bool flag = true;
        for (int i : temp)
        {
            if (i > 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            break;

        useless.clear();
        for (int i : temp)
        {
            if (i > 0)
                useless.push_back(i);
        }
        if (useless.size() == 0)
            break;
    }

    for (int i = 1; i <= mx; i++)
    {
        lookup[n][i] = mp[i];
    }

    for (int i = 1; i <= mx; i++)
    {
        if (mp[i] < u[i])
            return false;
    }
    return true;
}
void solve(int cc)
{
    lookup.clear();
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> u(n);

    for (int i = 0; i < n; i++)
    {
        cin >> u[i];
    }

    unordered_map<int, int> count;

    for (int i = 0; i < u.size(); i++)
    {
        count[i + 1] = u[i];
    }

    // 20 of everythng would require atmost 20 * 20

    for (int i = max(a, b); i <= 500; i++)
    {
        if (check(i, a, b, count, n))
        {
            cout << "Case #" << cc << ": " << i << '\n';
            return;
        }
    }
    cout << "Case #" << cc << ": "
         << "IMPOSSIBLE\n";
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
