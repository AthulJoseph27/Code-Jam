// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1155

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

void solve(int c)
{
    char resp[105][10005];

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 10000; j++)
            cin >> resp[i][j];

    double q_rating[10005];
    double ratios[105];
    vector<double> temp;

    for (int i = 0; i < 10000; i++)
    {
        double cnt = 1;
        for (int j = 0; j < 100; j++)
        {
            if (resp[j][i] == '1')
                cnt++;
        }

        q_rating[i] = ((double)101) / cnt;
        temp.push_back(q_rating[i]);
    }

    sort(temp.begin(), temp.end());

    double threshold = temp[temp.size() - 3000];

    for (int i = 0; i < 100; i++)
    {
        double score = 1;
        double weightedScore = 0;
        for (int j = 0; j < 10000; j++)
        {
            if (resp[i][j] == '1' && threshold < q_rating[j])
            {
                score++;
                weightedScore += q_rating[j];
            }
        }
        ratios[i] = weightedScore / score;

        // cout << i + 1 << " " << score << " " << ratios[i] << endl;
    }

    int index = 0;
    double value = -1;

    for (int i = 0; i < 100; i++)
    {
        if (value < ratios[i])
        {
            index = i;
            value = ratios[i];
        }
    }

    cout << "Case #" << c << ": "
         << index + 1
         << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, P;

    cin >> T >> P;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}
