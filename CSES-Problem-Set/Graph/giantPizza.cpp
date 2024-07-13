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

// Great question using 2-SAT , ie 2 satifiability read at https://cp-algorithms.com/graph/2SAT.html.

void dfs1(int current, vector<vector<int>>& g, vector<bool>& visited, stack<int>& order)
{
    if(visited[current]) return;
    
    visited[current] = true;
    for(auto &itr: g[current])
    {
        dfs1(itr, g, visited, order);
    }

    order.push(current);

    return;
}

void dfs2(int current, int color_code, vector<vector<int>>& rev_g, vector<int>& color)
{
    if(color[current] != 0) return;

    color[current] = color_code;
    for(auto &itr: rev_g[current])
    {
        dfs2(itr, color_code, rev_g, color);
    }

    return;
}

int solve(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(2*m), rev_g(2*m);
    iterate(i,n)
    {
        char a, b;
        int x, y;
        cin >> a >> x >> b >> y;
        x--;
        y--;

        int x_index = 2*x + (int)(a != '+');
        int y_index = 2*y + (int)(b != '+');

        int x_index_neg = x_index ^ 1;
        int y_index_neg = y_index ^ 1;

        g[x_index_neg].push_back(y_index);
        g[y_index_neg].push_back(x_index);
        rev_g[y_index].push_back(x_index_neg);
        rev_g[x_index].push_back(y_index_neg);
    }

    stack<int> order;
    vector<bool> visited(2*m, false);
    iterate(i,2*m)
    {
        if(visited[i]) continue;
        dfs1(i, g, visited, order);
    }

    vector<int> color(2*m, 0);
    int color_code = 1;
    while(!order.empty())
    {
        int current = order.top();
        order.pop();

        if(color[current] != 0) continue;
        dfs2(current, color_code, rev_g, color);
        color_code++;
    }

    vector<bool> ans(m, false);
    for(int i = 0 ; i < 2*m ; i += 2)
    {
        if(color[i] == color[i + 1])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }

        // cout << color[i] << " " << color[i + 1] << endl;

        ans[i/2] = color[i] > color[i + 1];
    }

    iterate(i,m)
    {
        if(ans[i])
            cout << '+' << " ";
        else 
            cout << '-' << " ";
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
