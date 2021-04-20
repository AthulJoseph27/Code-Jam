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
    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n < 4)
    {
        cout << "Case #" << cc << ": ";
        cout << n << '\n';
        return;
    }

    // 1 2 3 4 5 6 0 8 9 10 11 12 13 14 ....
    // 0 1 1 1 1 1 6 8 1 01 01 01 01 01 .....

    cout
        << "Case #" << cc << ": ";

    vector<pair<long long, pair<long long, long long>>> v;

    int st = 0;
    long long d = a[1] - a[0];

    for (int i = 1; i < n; i++)
    {
        if ((a[i] - a[i - 1]) != d)
        {
            v.push_back(make_pair(d, make_pair(st, i - 1)));
            st = i - 1;
            d = a[i] - a[i - 1];
        }
    }

    if (v.empty())
    {
        cout << n << '\n';
        return;
    }

    if (v.back().first != d)
    {
        v.push_back(make_pair(d, make_pair(st, n - 1)));
    }

    // no matter where, i can increase the length of the final grp by atleast one
    // unless tht one change has already been used

    bool canInc = true;

    // debug(v);

    long long mxL = v[0].second.second - v[0].second.first + 1;

    mxL = max(mxL, v.back().second.second - v.back().second.first + 1);

    for (int i = 0; i < (int)v.size() - 3; i++)
    {
        // mid grp is of length 1
        if (v[i + 1].second.second - v[i + 1].second.first == 1)
        {
            // (a,b) (b,c) , (c,d) , (d,e)
            // a.....b c d......e
            // 1 1 3 1 5
            // (1,(0,1)) (2,(1,2)) (-2,(2,3)) (4,(3,4))

            if ((v[i].first == v[i + 3].first) && (a[v[i].second.second] + v[i].first + v[i].first == a[v[i + 3].second.first]))
            {
                long long tmp = mxL;
                mxL = max(mxL, (v[i + 3].second.second - v[i].second.first + 1));
                if (tmp != mxL)
                    canInc = false;
            }
            else
            {
                long long tmp = mxL;
                mxL = max(mxL, v[i].second.second - v[i].second.first + 1);
                if (tmp != mxL)
                    canInc = true;
            }
        }
    }

    for (int i = 0; i < v.size() - 2; i++)
    {
        // 1 1 3 1 5
        // (0,1) (1,3) (3,1)
        // (a,b) (b,c) (c,d)
        // a......b c c ... d
        // b is an element of series c....d
        // d is element of series a....b
        if (v[i + 1].second.second - v[i + 1].second.first == 1)
        {
            // long long atb = a[v[i + 2].second.first] - (v[i + 2].first + v[i + 2].first);
            // long long atd = (a[v[i].second.second - 1]);
            // debug(atb, atd);
            if (a[v[i + 2].second.first + 1] == (v[i].first + v[i].first + a[v[i].second.second]))
            {
                long long tmp = mxL;
                mxL = max(mxL, v[i].second.second - v[i].second.first + 3);
                if (tmp != mxL)
                    canInc = false;
            }
            else if (a[v[i + 2].second.first] - (v[i + 2].first + v[i + 2].first) == (a[v[i].second.second - 1]))
            {

                long long tmp = mxL;
                mxL = max(mxL, v[i + 2].second.second - v[i + 2].second.first + 3);
                if (tmp != mxL)
                    canInc = false;
            }
        }

        // 0 5 2 3 4 5
    }

    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i].second.second - v[i].second.first + 1) >= mxL)
        {
            mxL = v[i].second.second - v[i].second.first + 1;
            canInc = true;
        }
    }

    if (canInc)
    {
        mxL = max(mxL, v.back().second.second - v.back().second.first + 1);
        mxL = min(mxL + 1, (long long)n);
    }

    cout << mxL << '\n';
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

long long max(long long a, long long b)
{
    if (a > b)
        return a;

    return b;
}
