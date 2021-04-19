//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7

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

int Reversort(vi L)
{
    int cost = 0;
    for (int i = 0; i < L.size() - 1; i++)
    {
        int index = -1, element = INT_MAX;
        for (int j = i; j < L.size(); j++)
        {
            if (L[j] < element)
            {
                element = L[j];
                index = j;
            }
        }
        if (index == -1)
            return cost;
        cost = cost + index - i + 1;
        reverse(L.begin() + i, L.begin() + index + 1);
        // for (int i : L)
        //     cout << i << " ";
        // cout << endl;
    }
    // for (int i : L)
    //     cout << i << " ";
    // cout << endl;
    return cost;
}

void printVector(vi V)
{
    for (int i : V)
        cout << i << " ";
    cout << endl;
}
void solve(int c, vi &L, int C)
{
    int cost;
    bool flag = false;
    do
    {
        cost = Reversort(L);
        if (cost == C)
        {
            flag = true;
            break;
        }
        // printVector(L);
    } while (next_permutation(L.begin(), L.end()));

    if (!flag)
    {
        cout << "Case #" << c << ": "
             << "IMPOSSIBLE"
             << "\n";
    }
    else
    {
        cout << "Case #" << c << ": ";
        for (int i : L)
            cout << i << " ";
        cout << "\n";
    }
}

int main()
{

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N, C;
        cin >> N >> C;
        vi L(N);
        for (int j = 1; j <= N; j++)
        {
            L[j - 1] = j;
        }
        solve(i + 1, L, C);
    }

    return 0;
}
