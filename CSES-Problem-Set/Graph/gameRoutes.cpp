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

vector<vector<ll>> build(ll n, ll m)
{
    vector<vector<ll>> g(n + 1);
    iterate(i,m)
    {
        ll a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }
    
    return g;
}

ll dfs(int current, int n,  vector<vector<ll>>& g, vector<ll>& numWays)
{
    if(current == n)
    {
        numWays[n] = 1;
        return numWays[n];
    }

    if(numWays[current] != -1) return numWays[current];

    ll currWays = 0;

    for(auto &itr : g[current])
    {
        currWays += dfs(itr, n, g, numWays);
        currWays %= MOD;
    }

    return numWays[current] = currWays;
}

int solve(void)
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g = build(n, m);
    vector<ll> numWays(n + 1, -1);
    ll ans = dfs(1, n, g, numWays);

    cout << ans;

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
