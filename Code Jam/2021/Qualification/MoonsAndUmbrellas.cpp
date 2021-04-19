//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
#define ALL(v) v.begin(), v.end()
#define fo(a, b) for (int(a) = (0); (a) < (b); (a)++)
#define fos(a, b, c) for (int(a) = (c); (a) < (b); (a)++)

void solve(int cc)
{
    string s;
    int x, y;

    cin >> x >> y >> s;

    vector<vi> dp = vector<vi>(s.size() + 1, vi(2, 0));

    const int INF = 1e9 + 5;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
        {
            dp[i + 1][0] = min(dp[i][0], dp[i][1] + y);
            dp[i + 1][1] = min(dp[i][1], dp[i][0] + x);
        }
        else
        {
            if (s[i] == 'C')
            {
                dp[i + 1][0] = min(dp[i][0], dp[i][1] + y);
                dp[i + 1][1] = INF;
            }
            else
            {
                dp[i + 1][1] = min(dp[i][1], dp[i][0] + x);
                dp[i + 1][0] = INF;
            }
        }
    }

    cout << "Case #" << cc << ": "
         << min(dp.back()[0], dp.back()[1])
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
