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

int SearchIndex(vector<int> &a, int l)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == l)
        {
            return i;
        }
    }
    return -1;
}

int SearchMultiIndex(vector<int> &a, int l, int u)
{
    int index = -1;
    for (int i = l; i >= 0; i--)
    {
        index = SearchIndex(a, i);
        if (index != -1)
            return index;
    }

    for (int i = l; i < u; i++)
    {
        index = SearchIndex(a, i);
        if (index != -1)
            return index;
    }

    return index;
}

void solve(int cc, int n, int b)
{
    // there will be 20 * 15 = 300 numbers
    // and numbers can be 0 to 9 , inclusive
    // so expected number of 9s is 30
    // goal is to place all 9s on top
    // and all 8s below it, as much as possible
    // so we have a buffer of 10 + 10 = 20 possible 9s and 8s (10 each)
    // + small tweakings
    // currently filling up to n-3 positions with everything except 7,8,9 and then placing
    // them on the highest tower

    vector<int> a(n, 0);
    int l = n * b;
    int col = 0;
    for (int i = 0; i < l; i++)
    {
        int d;
        cin >> d;
        if (col < n && d < 7)
        {
            if (a[col] >= b - 3)
            {
                col++;
            }
            if (col < n)
            {
                a[col]++;
                cout << col + 1 << endl;
            }
            else
            {
                int index = SearchMultiIndex(a, b - 10 + d, b);
                assert(index != -1);
                a[index]++;
                cout << index + 1 << endl;
            }
        }
        else
        {
            int index = SearchMultiIndex(a, b - 10 + d, b);
            assert(index != -1);
            a[index]++;
            cout << index + 1 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, b;
    long long p;

    cin >> T >> n >> b >> p;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1, n, b);
    }

    return 0;
}
