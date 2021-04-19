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

    // Test Set 1 , 2 & 3

    // The idea is, we can split the string into prefs * mid * suffs
    // a string which begin and end with * , all such strings can be concatinated together (without *)
    // we just need to check if the prefs and suffs of all string can be matched.

    string prefs = "";
    string suffs = "";
    string mid = "";

    vector<string> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << "Case #" << cc << ":"
         << " ";

    for (string s : p)
    {
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
                break;

            tmp += s[i];
        }

        int l = min((int)prefs.size(), (int)tmp.size());

        for (int i = 0; i < l; i++)
        {
            if (prefs[i] != tmp[i])
            {
                cout << "*" << endl;
                return;
            }
        }

        if (prefs.size() < tmp.size())
            prefs = tmp;

        tmp = "";

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
                break;

            tmp = s[i] + tmp;
        }

        l = min((int)suffs.size(), (int)tmp.size());

        for (int i = 0; i < l; i++)
        {
            if (suffs[suffs.size() - i - 1] != tmp[tmp.size() - i - 1])
            {
                cout << "*" << '\n';
                return;
            }
        }

        if (suffs.size() < tmp.size())
            suffs = tmp;

        for (char c : s)
            if (c != '*')
                mid += c;
    }

    // debug(prefs, mid, suffs);
    cout << prefs + mid + suffs << '\n';
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
