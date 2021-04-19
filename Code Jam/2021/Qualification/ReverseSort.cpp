//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

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

int ReverseSort(vi &V)
{

    int cost = 0;

    for (int i = 0; i < V.size() - 1; i++)
    {
        int index = i;
        int value = INT_MAX;
        for (int j = i; j < V.size(); j++)
        {
            if (V[j] < value)
            {
                value = V[j];
                index = j;
            }
        }
        reverse(V.begin() + i, V.begin() + index + 1);

        cost = cost + index - i + 1;
    }

    return cost;
}

void solve(int c)
{
    int N;
    cin >> N;

    vi L = vi(N);
    for (int i = 0; i < N; i++)
        cin >> L[i];

    int cost = ReverseSort(L);

    cout << "Case #" << c << ": "
         << cost
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
