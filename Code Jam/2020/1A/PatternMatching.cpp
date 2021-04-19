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

string solvePB(vector<string> p)
{
    int n = p.size();

    if (n == 0)
        return "";

    sort(all(p), [&](const string a, const string b) {
        return a.size() < b.size();
    });

    for (int i = 1; i < n; i++)
    {
        bool imp = false;
        for (int j = 0; j < p[i - 1].size() - 1; j++)
        {
            // debug(p[i][p[i].size() - j - 1], p[i - 1][p[i - 1].size() - j - 1]);
            if (p[i][p[i].size() - j - 1] != p[i - 1][p[i - 1].size() - j - 1])
            {
                imp = true;
            }
        }
        if (imp)
        {
            return "*";
        }
    }
    string res = "";
    for (int i = 1; i < p.back().size(); i++)
    {
        res += p.back()[i];
    }

    return res;
}

string solvePE(vector<string> p)
{
    int n = p.size();

    if (n == 0)
        return "";

    sort(all(p), [&](const string a, const string b) {
        return a.size() < b.size();
    });

    for (int i = 1; i < n; i++)
    {
        bool imp = false;
        for (int j = 0; j < p[i - 1].size() - 1; j++)
        {
            if (p[i][j] != p[i - 1][j])
            {
                imp = true;
            }
        }
        if (imp)
        {
            return "*";
        }
    }
    string res = "";
    for (int i = 0; i < p.back().size() - 1; i++)
    {
        res += p.back()[i];
    }

    return res;
}

void solve(int cc)
{
    int n;
    cin >> n;
    // vector<string> p(n);

    // Test Set 1

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> p[i];
    // }

    // sort(all(p), [&](const string a, const string b) {
    //     return a.size() < b.size();
    // });

    // cout << "Case #" << cc << ":"
    //      << " ";

    // for (int i = 1; i < n; i++)
    // {
    //     bool imp = false;
    //     for (int j = 0; j < p[i - 1].size() - 1; j++)
    //     {
    //         // debug(p[i][p[i].size() - j - 1], p[i - 1][p[i - 1].size() - j - 1]);
    //         if (p[i][p[i].size() - j - 1] != p[i - 1][p[i - 1].size() - j - 1])
    //         {
    //             imp = true;
    //         }
    //     }
    //     if (imp)
    //     {
    //         cout << "*" << endl;
    //         return;
    //     }
    // }
    // for (int i = 1; i < p.back().size(); i++)
    // {
    //     cout << p.back()[i];
    // }
    // cout << endl;

    //______________________________________________________________________________________________

    // Test Set 1 & 2

    vector<string> pb;
    vector<string> pm;
    vector<string> pe;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp[0] == '*')
            pb.push(tmp);
        else if (tmp.back() == '*')
            pe.push(tmp);
        else
            pm.push(tmp);
    }

    for (string s : pm)
    {
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                tmp += "*";
                pe.push(tmp);
                tmp = "*";
                for (int j = i + 1; j < s.size(); j++)
                {
                    tmp += s[j];
                }
                pb.push(tmp);
                break;
            }
            else
            {
                tmp += s[i];
            }
        }
    }

    string b = solvePB(pb);
    string e = solvePE(pe);

    cout << "Case #" << cc << ":"
         << " ";

    if (b == "*" || e == "*")
    {
        cout << "*" << endl;
    }
    else
    {
        cout << e << b << endl;
    }
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
