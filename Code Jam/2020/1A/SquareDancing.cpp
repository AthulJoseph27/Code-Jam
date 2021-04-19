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

vector<pair<int, int>> getNeighbours(const vector<vector<int>> &f, int r, int c)
{
    vector<pair<int, int>> results;

    int i, j;

    i = r - 1;

    if (i >= 0)
        results.emplace_back(i, c);
    else
        results.emplace_back(-1, -1);

    i = r + 1;

    if (i < f.size())
    {
        results.emplace_back(i, c);
    }
    else
    {
        results.emplace_back(-1, -1);
    }

    j = c - 1;

    if (j >= 0)
    {
        results.emplace_back(r, j);
    }
    else
    {
        results.emplace_back(-1, -1);
    }

    j = c + 1;

    if (j < f[0].size())
    {
        results.emplace_back(r, j);
    }
    else
        results.emplace_back(-1, -1);

    return results;
}

void solve(int cc)
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> f(r, vector<int>(c, 0));
    set<pair<int, int>> toCheck;

    vector<vector<vector<pair<int, int>>>> neighbourMap(r, vector<vector<pair<int, int>>>(c, vector<pair<int, int>>(4)));

    long long skill = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> f[i][j];
            skill += f[i][j];
            toCheck.insert(make_pair(i, j));
        }

    long long initialSkill = skill;
    long long elSkill = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            neighbourMap[i][j] = getNeighbours(f, i, j);
        }

    while (true)
    {
        vector<pair<int, int>> eliminated;

        for (pair<int, int> p : toCheck) // O(toCheck.len)
        {
            if (p.first == -1 || f[p.first][p.second] == 0)
                continue;

            double avg = 0;

            int l = 0;

            for (pair<int, int> v : neighbourMap[p.first][p.second])
            {
                if (v.first == -1)
                    continue;

                if (f[v.first][v.second] == 0)
                    continue;
                l++;
                avg += f[v.first][v.second];
            }

            if (l == 0)
                continue;

            avg = avg / ((double)l);

            double d = f[p.first][p.second];
            if (d < avg)
            {
                eliminated.emplace_back(p.first, p.second);
            }
        }

        // debug(eliminated);

        if (eliminated.size() == 0)
            break;

        toCheck.clear();

        for (pair<int, int> p : eliminated) // O(eleminated.len)
        {
            elSkill += f[p.first][p.second];
            f[p.first][p.second] = 0;
        }

        for (pair<int, int> p : eliminated) // O(eleminated.len)
        {
            pair<int, int> top_neighbour = neighbourMap[p.first][p.second][0];
            pair<int, int> bottom_neighbour = neighbourMap[p.first][p.second][1];
            pair<int, int> left_neighbour = neighbourMap[p.first][p.second][2];
            pair<int, int> right_neighbour = neighbourMap[p.first][p.second][3];

            toCheck.insert(top_neighbour);
            toCheck.insert(bottom_neighbour);
            toCheck.insert(left_neighbour);
            toCheck.insert(right_neighbour);

            if (top_neighbour.first != -1)
            {
                neighbourMap[top_neighbour.first][top_neighbour.second][1] = bottom_neighbour;
            }
            if (bottom_neighbour.first != -1)
            {
                neighbourMap[bottom_neighbour.first][bottom_neighbour.second][0] = top_neighbour;
            }
            if (left_neighbour.first != -1)
            {
                neighbourMap[left_neighbour.first][left_neighbour.second][3] = right_neighbour;
            }
            if (right_neighbour.first != -1)
            {
                neighbourMap[right_neighbour.first][right_neighbour.second][2] = left_neighbour;
            }
        }

        // debug(toCheck);

        skill = skill + initialSkill - elSkill;
    }

    cout << "Case #" << cc << ":"
         << " " << skill << '\n';
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
