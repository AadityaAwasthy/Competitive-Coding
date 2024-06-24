#include<bits/stdc++.h>
using namespace std;
#define iterate(i,n) for(int i = 0 ; i < n ; i++)
#define INF 1e9
#define MOD 1000000007
#define MAXN 1000001
#define endl "\n"
#define deb(x) cout << #x << " = " << x << "\n";
#define arrout(a) for(auto itr : a) cout << itr << " "
#define arrin(a) for(auto& itr : a) cin >> itr;
typedef long long ll;

// Binary lifting question, remember it is like dynamic programming so the sequence in which you compute subproblems in the helper function need to be taken care of.

vector<vector<int>> helper(vector<int>& g, int n)
{
    vector<vector<int>> bing(n + 1, vector<int>(31));
    iterate(i,n) bing[i + 1][0] = g[i + 1];

    for(int i = 1; i < 31; i++)
    {
        for(int j = 1 ; j < n + 1 ; j++)
        {
            bing[j][i] = bing[bing[j][i - 1]][i - 1];
        }
    }

    return bing;
}

int resolves(int start, int steps, vector<vector<int>>& bing)
{
    for(int i = 0; i < 31; i++)
    {
        if(steps & (1 << i)) start = bing[start][i];
    }

    return start;
}

int solve(void)
{
    int n, q;
    cin >> n >> q;

    vector<int> g(n + 1);
    iterate(i,n) cin >> g[i + 1];

    vector<vector<int>> bing = helper(g, n);

    while(q-- > 0)
    {
        int start , steps;
        cin >> start >> steps;

        int ans = resolves(start, steps, bing);
        cout << ans << endl;
    }

    return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;

    while(t-- > 0)
    {
        solve();
        cout << endl;
    }

    return 0;
}
