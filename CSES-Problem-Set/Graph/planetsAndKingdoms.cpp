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

// Implementation for finding strongly connected components in a DAG, this is inspired from kosaraju's algorithm , refer to Introduction to algorithms page 615 for further details

void dfs(bool flag, int current, int color_code, int& time, priority_queue<pair<int, int>>& pq, vector<int>& color, vector<vector<int>>& g, vector<bool>& visited)
{
    if(visited[current]) return;

    visited[current] = true;
    color[current] = color_code;
    
    for(auto &itr: g[current])
    {
        dfs(flag, itr, color_code,  time, pq, color, g, visited);
    }

    time++;
    if(flag)
        pq.push({time, current});

    return;
}

int solve(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1), rev_g(n + 1);
    iterate(i,m)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        rev_g[b].push_back(a);
    }

    priority_queue<pair<int, int>> pq;
    vector<bool> visited(n + 1, false);
    vector<int> color(n + 1 , 0);
    int color_code = 0;
    int time = 0;

    iterate(i,n)
    {
        if(visited[i + 1]) continue;
        dfs(true, i + 1, color_code, time, pq, color, g, visited);
    }

    visited = vector<bool>(n + 1, false);
    while(!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        if(color[current] != 0) continue;
        color_code++;
        dfs(false, current, color_code, time, pq, color, rev_g, visited);
    }

    cout << color_code << endl;
    iterate(i,n) cout << color[i + 1] << " ";

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
