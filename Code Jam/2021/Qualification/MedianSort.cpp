// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284

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

int query(int a, int b, int c)
{
    cout << (a + 1) << " " << (b + 1) << " " << (c + 1) << endl;
    int resp;
    cin >> resp;
    return resp - 1;
}

int binarySearch(vi &v, int element, int st, int end)
{
    int mid;
    int s = st, e = end;

    int med = query(v[st], element, v[end]);
    if (med == v[end])
    {
        return end + 1;
    }
    while (st < end)
    {
        mid = (st + end) / 2;
        if (mid == 0)
        {
            med = query(v[0], element, v[1]);
            if (med == element)
                return 1;

            assert(med != v[1]);

            return 0;
        }
        int a = v[mid - 1];
        int b = v[mid];
        int median = query(a, b, element);

        // if median is mid - 1
        //     surely element is smaller than mid - 1
        // if median is mid
        //     surely element is greater than mid

        if (median == element)
        {
            return mid;
        }

        if (median == a)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return st;
}

void printResult(vi &v)
{
    for (int i : v)
        cout << (i + 1) << " ";
    cout << endl;
    int resp;
    cin >> resp;
    assert(resp == 1);
}

void solve(int cc, int N)
{
    vi v(N);
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }

    int a = v[0];
    int b = v[1];
    int c = v[2];
    int median = query(a, b, c);

    if (median == a)
    {
        swap(v[0], v[1]);
    }
    else if (median == c)
    {
        swap(v[1], v[2]);
    }

    for (int i = 3; i < v.size(); i++)
    {
        int j = i - 1;
        int selected = v[i];
        int location = binarySearch(v, selected, 0, j);

        if (location > j)
            continue;

        while (j >= location)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = selected;
    }
    printResult(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, Q, N;

    cin >> T >> N >> Q;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1, N);
    }

    return 0;
}
