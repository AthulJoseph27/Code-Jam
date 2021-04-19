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
    // Test Set 1

    // D is either 2 or 3

    int n, d;
    cin >> n >> d;

    vector<long long> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    cout << "Case #" << cc << ": ";

    if (d == 2)
    {
        if (n < 2)
        {
            cout << 1 << '\n';
            return;
        }
        unordered_set<long long> st;
        for (long long i : s)
            st.insert(i);

        if (st.size() != s.size())
        {
            cout << 0 << '\n';
            return;
        }

        cout << 1 << '\n';
        return;
    }

    // d = 3
    // max is 2, cut any at 1/3 2/3 then cut the 2/3 again to 1/3 1/3 ..... so 2 cuts

    sort(all(s));

    if (n < 3)
    {
        if (n == 1)
        {
            cout << 2 << '\n';
            return;
        }
        else if (n == 2)
        {
            long long temp = 2 * s[0];
            if (temp == s[1])
            {
                cout << 1 << '\n';
                return;
            }
            cout << 2 << '\n';
            return;
        }
    }

    unordered_map<long long, int> mp;
    for (long long i : s)
        mp[i]++;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 3)
        {
            cout << 0 << '\n';
            return;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 2)
        {
            for (long long i : s)
            {
                if (i == it->first)
                    continue;
                if (i > it->first)
                {
                    cout << 1 << '\n';
                    return;
                }
            }
        }
    }

    // debug(s);

    for (int i = 0; i < n; i++)
    {
        long long req = 2 * s[i];
        for (int j = i + 1; j < n; j++)
        {
            if (req == s[j])
            {
                cout << 1 << '\n';
                return;
            }
        }
    }

    cout << 2 << '\n';
    return;
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
