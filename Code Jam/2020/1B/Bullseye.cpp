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

int t, cc = 0;

char getResponse(long long x, long long y)
{
    string resp;
    cout << x << " " << y << endl;
    cin >> resp;

    assert(resp != "WRONG");

    return resp[0];
}

void solve(long long a, long long b)
{
    // a is minimum dart board radius
    // b is maximum dart board radius
    // both inclusive

    // first get a point inside the circle
    // bottom left is (0,0)

    long long x = 1e9 / 4, y = 1e9 / 4;
    long long jmp = 1e9 / 2;
    long long pa = -1, pb = -1;
    for (int i = 0; i < 4; i++)
    {
        bool flag = false;
        x = 1e9 / 4;
        for (int j = 0; j < 4; j++)
        {
            char r = getResponse(x - 1'000'000'000, y - 1'000'000'000);
            if (r == 'C')
            {
                cc++;

                return;
            }
            else if (r == 'H')
            {
                flag = true;
                pa = x;
                pb = y;
                break;
            }
            x += jmp;
        }
        if (flag)
            break;
        y += jmp;
    }

    assert(pa != -1);

    // Finding Xc
    // find a left most point on the circle

    long long st = max(pa - b - b, (long long)0), en = pa, mid;

    while (st < en)
    {
        mid = (st + en) / 2;

        char r = getResponse(mid - 1000'000'000, pb - 1000'000'000);
        if (r == 'H')
        {
            if (en == mid)
            {
                st = mid;
                break;
            }
            en = mid;
        }
        else if (r == 'M')
        {
            st = mid + 1;
        }
        else if (r == 'C')
        {
            cc++;
            return;
        }
    }

    // left most point is found

    long long lx = st;

    if (getResponse(lx - 1 - 1000'000'000, pb - 1000'000'000) == 'H')
        lx--;

    st = pa, en = min(pa + b + b, ((long long)2) * 1000'000'000);

    while (st < en)
    {
        mid = (st + en) / 2;

        char r = getResponse(mid - 1000'000'000, pb - 1000'000'000);

        if (r == 'H')
        {
            if (st == mid)
            {
                break;
            }
            st = mid;
        }
        else if (r == 'M')
        {
            en = mid - 1;
        }
        else if (r == 'C')
        {
            cc++;
            return;
        }
    }

    long long rx = st;

    if (getResponse(rx + 1 - 1000'000'000, pb - 1000'000'000) == 'H')
        rx++;

    // Finding Yc

    st = max(pb - b - b, (long long)0), en = pb;

    while (st < en)
    {
        mid = (st + en) / 2;

        char r = getResponse(pa - 1000'000'000, mid - 1000'000'000);
        if (r == 'H')
        {
            if (en == mid)
            {
                st = en;
                break;
            }
            en = mid;
        }
        else if (r == 'M')
        {
            st = mid + 1;
        }
        else if (r == 'C')
        {
            cc++;
            return;
        }
    }

    // bottom most point is found

    long long ly = st;

    if (getResponse(pa - 1000'000'000, ly - 1 - 1000'000'000) == 'H')
        ly--;

    st = pb, en = min(pb + b + b, ((long long)2) * 1000'000'000);

    while (st < en)
    {
        mid = (st + en) / 2;

        char r = getResponse(pa - 1000'000'000, mid - 1000'000'000);
        if (r == 'H')
        {
            if (st == mid)
                break;
            st = mid;
        }
        else if (r == 'M')
        {
            en = mid - 1;
        }
        else if (r == 'C')
        {
            cc++;
            return;
        }
    }

    long long ry = st;

    if (getResponse(pa - 1000'000'000, ry + 1 - 1000'000'000) == 'H')
        ry++;

    char c = getResponse((lx + rx) / 2 - 1'000'000'000, (ly + ry) / 2 - 1'000'000'000);

    assert(c == 'C');

    cc++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;

    cin >> t >> a >> b;

    while (cc < t)
    {
        solve(a, b);
    }

    return 0;
}

long long min(long long a, long long b)
{
    if (a < b)
        return a;

    return b;
}

long long max(long long a, long long b)
{
    if (a > b)
        return a;

    return b;
}
