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

    // int m, N = 0;
    // cin >> m;
    // vi a;
    // for (int i = 0; i < m; i++)
    // {
    //     int p, n;
    //     cin >> p >> n;
    //     // debug(p, n);
    //     for (int j = 0; j < n; j++)
    //         a.push_back(p);
    //     // mp[p] = m;
    //     N += n;
    // }
    // assert(N == a.size());
    // debug(a, N);
    // long long maxScore = 0;

    // debug(a);

    // for (int i = 1; i < a.size(); i++)
    // {
    //     // group 1 has i cards and group 2 has N - i cards
    //     do
    //     {
    //         // vi g1;
    //         // vi g2;
    //         long long sm = 0;
    //         long long pd = 1;
    //         // debug(i, a.size());
    //         for (int j = 0; j < i; j++)
    //         {
    //             sm += a[j];
    //             // pd2 *= a[j];
    //         }

    //         for (int j = i; j < a.size(); j++)
    //         {
    //             pd *= a[j];
    //             // sm2 += a[j];
    //         }

    //         // exit(0);

    //         if (pd == sm)
    //         {
    //             maxScore = max(maxScore, sm);
    //         }

    //         // if (pd2 == sm2)
    //         // {
    //         //     maxScore = max(maxScore, sm2);
    //         // }

    //     } while (next_permutation(all(a)));
    // }

    // cout << "Case #" << cc << ": "
    //      << maxScore
    //      << "\n";

    // _______________________________________________________________________________________________

    // n1 * n2 * n3 = total_sum - n1 - n2 - n3

    // max sum = 100 * 500 * 10^15 = 5 * 10^19 ~ 10^20

    // max no of numbers needed to make 10^20 ~ 2^66 ~ 499^7.41 ; there for max number of elements needed is 66

    // sum of 66 numbers ....

    // max = 66 * 500 = 33000

    // n1 + n2 + n3 ... = sum

    // _______________________

    // 499 * 8 = 3992 ; 2 * 66 = 132

    // min element required to make 10^20 is 8 and max elements is 66

    // 7.412622199140116 * 499 = 3698.89 ~ 3698

    int m;
    cin >> m;
    unordered_map<int, long long> mp;

    const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};

    long long total_sum = 0;

    for (int i = 0; i < m; i++)
    {
        int n;
        long long p;
        cin >> n >> p;
        mp[n] = p;
        total_sum += (p * n);
    }

    for (int sum = 2; sum <= 3698; sum++)
    {
        long long rp = total_sum - sum; // required_product
        unordered_map<int, long long> tf = mp;
        int crSum = sum;
        for (int prime : primes)
        {
            if (rp == 1)
                break;

            while ((rp % prime == 0) && (tf[prime] > 0) && (crSum > 0))
            {
                tf[prime]--;
                rp /= prime;
                crSum -= prime;
            }
        }
        if (rp == 1 && crSum == 0)
        {
            cout << "Case #" << cc << ": "
                 << (total_sum - sum)
                 << "\n";
            return;
        }
    }

    cout << "Case #" << cc << ": "
         << 0
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
