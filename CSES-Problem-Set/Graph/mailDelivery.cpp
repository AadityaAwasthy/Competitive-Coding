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

// A path that goes through all edges and comes back to the starting point is called a Euler Tour, this what this problem is about, all nodes must have even number of edges on it so that we can always get out if we ever get in.

void dfs(int current, vector<int>& path, vector<vector<pair<int, int>>>& g, vector<bool>& visited) {
    while(!g[current].empty()) {
        auto node = g[current].back();
        g[current].pop_back();

        if(visited[node.second]) continue;
        visited[node.second] = true;
        dfs(node.first, path,  g, visited);
    }

    path.push_back(current);
}


int solve(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> inDegree(n + 1, 0);
    vector<bool> visited(m , false);

    iterate(i,m) {
        int a, b;
        cin >> a >> b;

        inDegree[a]++;
        inDegree[b]++;

        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }

    for(int i = 1; i <= n ; i++) {
        if(inDegree[i] % 2 != 0) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> path;
    dfs(1, path, g, visited);

    if(path.size() == m + 1) {
        arrout(path);
    } else {
        cout << "IMPOSSIBLE";
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
