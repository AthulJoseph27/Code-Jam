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
    // int tempN = n;
    // vector<vector<unsigned long long>> pascal;

    // pascal.push({1});
    // pascal.push({1, 1});

    // for (int i = 3; i <= 500; i++)
    // {
    //     vector<unsigned long long> tmp(i);
    //     tmp[0] = 1;
    //     tmp[i - 1] = 1;
    //     for (int j = 1; j < i - 1; j++)
    //     {
    //         tmp[j] = pascal[i - 2][j] + pascal[i - 2][j - 1];
    //     }
    //     pascal.push(tmp);
    // }

    // every number can be represented as powers of 2
    // each row sum of pascal triangle is 2^(r-1)
    // represent the number in binary, if the bit at ith position is 1, then traverse through that row
    // we cant skip a row since the path should be continous
    // we can try to build n - 32 using this method, because sum of all extra ones cant be more than 32
    // and then add extra 1s as required ; coz upper limit is 10^9 which is less than 2^32
    // numbers below 32 should be handled seperately, here i am solving all numberse less than or equal
    // to 500 by travesing along the edges

    cout << "Case #" << cc << ":" << endl;

    // int checkSum = 0;

    if (n <= 500)
    {
        for (int i = 1; i <= 500; i++)
        {
            if (n == 0)
                break;
            n--;
            cout << i << " " << i << endl;
            // checkSum += pascal[i - 1][i - 1];
        }
        // assert(checkSum == tempN);
        return;
    }

    // checkSum = 1;
    cout << "1 1" << endl;
    n--;
    string N = std::bitset<32>(n - 32).to_string();
    reverse(all(N));

    int tn = n - 32;
    int i = 2;
    bool atLeft = true;

    while (tn > 0)
    {
        if (N[i - 1] == '1')
        {
            int rowSum = pow(2, i - 1);
            tn -= rowSum;
            n -= rowSum;
            for (int j = 1; j <= i; j++)
            {
                if (atLeft)
                {
                    // checkSum += pascal[i - 1][j - 1];
                    cout << i << " " << j << endl;
                }
                else
                {
                    // checkSum += pascal[i - 1][i - j];
                    cout << i << " " << (i - j + 1) << endl;
                }
            }
            atLeft = !atLeft;
        }
        else
        {
            n--;
            tn--;
            if (atLeft)
            {
                // checkSum += pascal[i - 1][0];
                cout << i << " " << 1 << endl;
            }
            else
            {
                // checkSum += pascal[i - 1][i - 1];
                cout << i << " " << i << endl;
            }
        }
        i++;
    }

    while (n > 0)
    {
        n--;
        if (atLeft)
        {
            // checkSum += pascal[i - 1][0];
            cout << i << " " << 1 << endl;
        }
        else
        {
            // checkSum += pascal[i - 1][i - 1];
            cout << i << " " << i << endl;
        }
        i++;
    }
    // assert(checkSum == tempN);
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
