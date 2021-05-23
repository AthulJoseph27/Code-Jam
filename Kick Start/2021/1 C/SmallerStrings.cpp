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

const long long modulo = (long long)(1e9 + 7);

long long mul(long long a, long long b)
{
    return ((a % modulo) * (b % modulo)) % modulo;
}
void solve(int cc)
{
    int n, k;

    cin >> n >> k;

    string s;
    cin >> s;

    if (n == 1)
    {
        cout << "Case #" << cc << ": " << (s[0] - 'a') << '\n';
        return;
    }

    vector<long long> mp = {1};

    for (int i = 1; i <= n; i++)
    {
        mp.push_back((mp.back() * k) % modulo);
    }

    long long ans = 0;

    int mid;

    if (n % 2 == 0)
    {
        mid = n / 2 - 1;
    }
    else
    {
        mid = n / 2;
    }

    for (int i = 0; i <= mid; i++)
    {
        ans += mul(mp[(mid - i)], (s[i] - 'a'));
    }

    // last mid position, check if we can place the mid char and the result is smaller than input

    string sp = "";

    for (int i = 0; i <= mid; i++)
        sp += s[i];

    if (n % 2 != 0)
        mid--;

    for (int i = mid; i >= 0; i--)
        sp += s[i];

    if (sp < s)
        ans++;

    ans %= modulo;

    cout << "Case #" << cc << ": " << ans << '\n';
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
