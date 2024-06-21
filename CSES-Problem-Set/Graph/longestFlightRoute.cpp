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

vector<vector<int>> build(int n, int m)
{
    vector<vector<int>> g(n + 1);
    iterate(i,m)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }
    
    return g;
}

void dfs(int current, int n, vector<vector<int>>& g, vector<int>& dist, vector<int>& next)
{
    if(current == n)
    {
        next[current] = 0;
        dist[current] = 1;
        return;
    }

    if(dist[current] == -2) return;
    if(dist[current] >= 0) return;

    int currDist = INT_MIN;

    for(auto &itr : g[current])
    {
        if(dist[itr] == -2) continue;
        if(dist[itr] == -1) dfs(itr, n, g, dist, next);

        if(dist[itr] >= 0 && dist[itr] > currDist)
        {
            currDist = dist[itr];
            next[current] = itr;
        }
    }

    if(currDist == INT_MIN)
    {
        dist[current] = -2;
        return;
    }

    dist[current] = currDist + 1;

    return;
}

vector<int> buildPath(vector<int>& next, int n)
{
    vector<int> path;
    int current = 1;
    
    while(next[current] != 0)
    {
        path.push_back(current);
        current = next[current];
    }

    path.push_back(n);
    
    return path;
}

int solve(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g = build(n, m);
    vector<int> dist(n + 1 , -1);
    vector<int> next(n + 1);

    dfs(1, n, g, dist, next);

    if(dist[1] == -2)
    {
        cout << "IMPOSSIBLE";
    }
    else 
    {
        vector<int> path = buildPath(next, n);
        cout << path.size() << endl;
        arrout(path);
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
