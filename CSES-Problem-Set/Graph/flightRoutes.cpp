#include<bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
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

vector<vector<pair<ll , ll>>> build(ll n ,ll m)
{
    vector<vector<pair<ll ,ll>>> g(n + 1);
    iterate(i,m)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
    }

    return g;
}

// This function is similar to djikstra's algorithm, there is just a subtle difference in the way that these algorithms choose whether to queue a node or not, djikstra queues nodes based on whether it the distance from the source to the node has been updated while this algorithm queues the node based on how many times the node has been visited.
vector<ll> helper(ll n, ll m, vector<vector<pair<ll, ll>>>& g , ll k)
{
    vector<ll> vis(n + 1 ,0);
    priority_queue<pair<ll, ll> , vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    priority_queue<ll , vector<ll> , greater<ll>> ans;
    
    pq.push({0, 1});
    vector<ll> ret;

    while(!pq.empty() && vis[n] < k)
    {
        auto current = pq.top();
        pq.pop();

        ll curDist = current.first;
        ll curNode = current.second;
        vis[curNode]++;

        if(curNode == n) ret.push_back(curDist);

        //This is the point of difference for the two algorithms.
        if(vis[curNode] <= k)
        {
            for(auto &itr : g[curNode])
            {
                pq.push({ curDist + itr.second , itr.first });
            }
        }
    }
    
    return ret;
}

int solve(void)
{
    ll n , m, k;
    cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> g = build(n, m);
    vector<ll> ans = helper(n, m, g, k);

    arrout(ans);

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
