#include<bits/stdc++.h>
#include <climits>
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

// Convert the graph into a new a graph of strongly connected components then use max path sum or dp to find the answer

void dfs1(int current, vector<vector<int>>& g, vector<bool>& visited, vector<int>& endTime) {
    if(visited[current]) return;
    
    visited[current] = true;
    for(auto &itr : g[current]) {
        dfs1(itr, g, visited, endTime);
    }

    endTime.push_back(current);
}

void dfs2(int current, int color_code, vector<vector<int>>& rev_g, vector<int>& color) {
    if(color[current] != 0) return;

    color[current] = color_code;
    for(auto &itr: rev_g[current]) {
        dfs2(itr, color_code, rev_g, color);
    }

    return;
}

ll dfs3(int current, vector<set<int>>& g, vector<bool>& visited, vector<ll>& coins) {
    if(visited[current]) return coins[current];

    visited[current] = true;
    ll maxi = LLONG_MIN;

    for(auto &next: g[current]) {
        if(next == current) continue;
        maxi = max(maxi, dfs3(next, g, visited, coins));
    }

    if(maxi != LLONG_MIN)
        coins[current] += maxi;

    return coins[current];
}

int solve(void) {
    int n, m;
    cin >> n >> m;

    vector<ll> coins(n + 1);
    iterate(i,n) {
        cin >> coins[i + 1];
    }

    vector<vector<int>> g(n + 1), rev_g(n + 1);
    vector<pair<int, int>> edges(m);
    iterate(i,m) {
        int a, b;
        cin >> a >> b;

        edges[i] = {a, b};

        g[a].push_back(b);
        rev_g[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> endTime;

    iterate(i,n) {
        if(visited[i + 1]) continue;
        dfs1(i + 1, g, visited, endTime);
    }

    vector<int> color(n + 1, 0);
    int color_code = 0;

    while(!endTime.empty()) {
        int current = endTime.back();
        endTime.pop_back();

        if(color[current] != 0) continue;
        color_code++;

        dfs2(current, color_code, rev_g, color);
    }

    vector<set<int>> new_g(color_code + 1);
    iterate(i,m) {
        int a = edges[i].first;
        int b = edges[i].second;

        new_g[color[a]].insert(color[b]);
    }

    vector<ll> tot_coins(color_code + 1, 0);
    iterate(i,n) {
        tot_coins[color[i + 1]] += coins[i + 1];
    }

    vector<bool> visited_new(color_code + 1, false);
    iterate(i,color_code) {
        if(visited_new[i + 1]) continue;
        dfs3(i + 1, new_g, visited_new, tot_coins);
    }

    ll ans = LLONG_MIN;
    iterate(i,color_code) {
        ans = max(ans, tot_coins[i + 1]);
    }

    cout << ans;
    return 0;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;

    while(t-- > 0) {
        solve();
        cout << endl;
    }

    return 0;
}
