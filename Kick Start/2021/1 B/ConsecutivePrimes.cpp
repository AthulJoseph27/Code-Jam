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

long long binpower(long long base, long long e, long long mod)
{
    long long result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (long long)result * base % mod;
        base = (long long)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(long long n, long long a, long long d, int s)
{
    long long x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = (long long)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(long long n)
{
    if (n < 2)
        return false;

    int r = 0;
    long long d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

void solve(int cc)
{
    long long z;
    cin >> z;

    cout << "Case #" << cc << ": ";

    /*
        p1 * p2 <= z
        these primes will be in the range of sqrt(z) - k to sqrt(z) + k
        387096133 ^ 2 > 10^18
        max prime gap between 2 consecutive primes is 282 ... wikipedia
        we need to find only 2 primes below sqrt(z) and one prime above sqrt(z)
        Miller Rabin , a very fast way to check if a number is prime
        This is the deterministic verision, way faster than naive method
    */

    long long n = sqrt(z);

    int max_prime_gap = 282;

    vector<long long> primes;

    long long l = n - 2 * max_prime_gap;
    long long h = n + max_prime_gap;

    if (l < 2)
        l = 2;

    for (long long i = n; i >= l; i--)
    {
        if (primes.size() == 2)
            break;

        if (MillerRabin(i))
        {
            primes.push_back(i);
        }
    }

    for (long long i = n + 1; i <= h; i++)
    {
        if (primes.size() == 3)
            break;

        if (MillerRabin(i))
        {
            primes.push_back(i);
        }
    }

    sort(all(primes));

    long long ans = primes[2] * primes[1];

    if (ans > z)
    {
        ans = primes[1] * primes[0];
    }

    cout << ans << '\n';
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
