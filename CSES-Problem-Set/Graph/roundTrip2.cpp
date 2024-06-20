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

bool dfs(int current , vector<vector<int>>& g, vector<bool>& visited, vector<int>& par, int& cycle , vector<bool>& visitedPath)
{
    if(visitedPath[current])
    {
        cycle = current;
        return true;
    }

    visited[current] = true;
    visitedPath[current] = true;

    for(auto &itr : g[current])
    {
        par[itr] = current;
        if(visited[itr] && !visitedPath[itr]) continue;
        if(dfs(itr, g, visited, par, cycle, visitedPath))
        {
            return true;
        }
    }

    visitedPath[current] = false;
    return false;
}

vector<int> buildCycle(int start, vector<int>& par)
{
    vector<int> ans;
    int current = start;

    while(par[current] != start)
    {
        ans.push_back(current);
        current = par[current];
    }

    ans.push_back(current);
    ans.push_back(start);

    reverse(ans.begin() , ans.end());

    return ans;
}

int solve(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    iterate(i,m)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> visitedPath(n +1 , false);
    vector<int> par(n + 1);
    int cycle = -1;

    for(int i = 1 ; i <= n; i++)
    {
        if(visited[i]) continue;
        if(!dfs(i, g, visited, par, cycle , visitedPath)) continue;

        vector<int> ans = buildCycle(cycle , par);
        cout << ans.size() << endl;
        arrout(ans);
        return 0;
    }

    cout << "IMPOSSIBLE";

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
