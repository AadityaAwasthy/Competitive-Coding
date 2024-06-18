#include<bits/stdc++.h>
#include <climits>
#include <pthread.h>
#include <tuple>
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

vector<vector<ll>> build(ll n , ll m)
{
    vector<vector<ll>> edges(m , vector<ll>(3));
    
    iterate(i,m)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    return edges;
}

tuple<bool , vector<ll>> bellman_ford(ll source ,ll n, ll m, vector<vector<ll>>& edges)
{
    //Do not use LLONG_MAX and ignore case where dist is still LLONG_MAX , this would mean that the current vertex was not visited when we predermined the
    //source , this induces constraint on the solution , only vertices that could be visited from source would be evaluated , we want the algoirhtm to run 
    //for the general case.

    vector<ll> dist(n + 1 , 1LL<<62);
    vector<ll> par(n + 1 , -1);

    par[source] = 0;
    dist[source] = 0;

    ll f = 0;
    iterate(i,n)
    {
        f = 0;
        for(auto &edge : edges)
        {
            ll u = edge[0];
            ll v = edge[1];
            ll w = edge[2];

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                f = v;
            }
        }
    }

    if(!f)
    {
        return tuple<bool , vector<ll>>(false , vector<ll>());
    }

    iterate(i,n)
        f = par[f];

    vector<ll> path;
    for(ll v = f ; ; v = par[v])
    {
        path.push_back(v);
        if(v == f && path.size() > 1)
            break;
    }
    reverse(path.begin() , path.end());
    return tuple<bool , vector<ll>>(true , path);
}

int solve(void)
{
    ll n , m;
    cin >> n >> m;

    vector<vector<ll>> edges = build(n, m);
    if(edges.size() == 1 && edges[0][0] == -1)
    {
        cout << "YES" << endl;
        cout << edges[0][2] << " " << edges[0][2];
        return 0;
    }

    auto result = bellman_ford(1, n, m, edges);

    if(get<0>(result))
    {
        cout << "YES" << endl;
        arrout(get<1>(result));
    }
    else 
    {
        cout << "NO";
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
