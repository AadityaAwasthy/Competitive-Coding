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

int lift(int start, int length, vector<vector<int>>& bing)
{
    if(length <= 0) return start;
    for(int i = 0 ; i < 21 ; i++)
    {
        if(length & (1 << i)) start = bing[start][i];
    }

    return start;
}

void dfs(int current, vector<vector<int>>& bing, vector<bool>& visited, vector<int>& length)
{
    if(visited[current]) return;
    visited[current] = true;

    dfs(bing[current][0], bing, visited, length);

    length[current] = length[bing[current][0]] + 1;

    return;
}

int solve(void)
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> bing(n + 1, vector<int>(21));
    iterate(i,n) cin >> bing[i + 1][0];

    for(int i = 1 ; i < 21 ; i++)
    {
        for(int j = 1 ; j < n + 1 ; j++)
        {
            bing[j][i] = bing[bing[j][i - 1]][i - 1];
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> length(n + 1, 0);

    iterate(i,n) if(!visited[i + 1]) dfs(i + 1, bing, visited, length);

    while(q--)
    {
        int a, b;
        cin >> a >> b;

        int xx = lift(a, length[a], bing);

        if(lift(a, length[a] - length[b], bing) == b)
            cout << length[a] - length[b] << endl;
        else if(lift(xx, length[xx] - length[b], bing) == b)
            cout << length[a] + length[xx] - length[b] << endl;
        else 
            cout << -1 << endl;
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
