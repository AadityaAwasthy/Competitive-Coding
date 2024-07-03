#include<bits/stdc++.h>
#include <vector>
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

//The theorem used here is that if one vertex can both reach and be reached by all others, then every vertex in this graph can reach all others.
// Reverse graph and traverse from the same root, the root should be reachable by both means

void dfs(int current, vector<vector<int>>& g, vector<bool>& visited)
{
    if(visited[current]) return;

    visited[current] = true;

    for(auto &itr: g[current])
    {
        if(visited[itr]) continue;
        dfs(itr, g, visited);
    }

    return;
}

int solve(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<vector<int>> gr(n + 1);

    iterate(i,m)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<bool> visited(n + 1, false), visitedr(n + 1, false);

    dfs(1, g, visited);
    dfs(1, gr, visitedr);

    for(int i = 2; i <= n; i++)
    {
        if(visited[i] && visitedr[i]) continue;

        cout << "NO" << endl;
        if(visited[i])
            cout << i << " " << 1;
        else
            cout << 1 << " " << i;

        return 0;
    }

    cout << "YES";

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
