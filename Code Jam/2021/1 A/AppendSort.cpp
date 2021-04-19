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
    int n;
    cin >> n;
    vector<uint64_t> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = 0;

    for (int i = 1; i < n; i++)
    {
        // debug(a);

        if (a[i - 1] < a[i])
            continue;

        uint64_t last = a[i - 1];

        int dl = 0, dc = 0, temp;

        while (last > 0)
        {
            dl++;
            last /= 10;
        }

        last = a[i - 1];

        uint64_t cur = a[i];
        uint64_t mx = a[i];
        // debug(mx);
        while (cur > 0)
        {
            dc++;
            cur /= 10;
        }

        cur = a[i];

        temp = dc;
        while (dc < dl)
        {
            cur *= 10;
            mx *= 10;
            mx += 9;
            dc++;
            count++;
        }
        // debug(mx);

        dc = temp;

        if (cur > a[i - 1])
        {
            a[i] = cur;
            continue;
        }

        if (mx <= a[i - 1])
        {
            a[i] = cur * 10;
            count++;
            continue;
        }

        a[i] = a[i - 1] + 1;
    }

    // debug(a);

    cout << "Case #" << cc << ": "
         << count
         << "\n";
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
