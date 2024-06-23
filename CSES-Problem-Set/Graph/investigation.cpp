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

vector<vector<pair<ll, ll>>> buildGraph(ll n, ll m)
{
   vector<vector<pair<ll, ll>>> g(n + 1);

   iterate(i,m)
   {
       ll a, b, c;
       cin >> a >> b >> c;

       g[a].push_back({b, c});
   }

   return g;
}

// This code is just an update to the regular djikstra , earlier i tried to explore a vertex even if the dist of that vertex was equal to the new dist , although the logic was right we got TLE due to unnesary repetion of work, instead keeping a information logged in vectors and using them to generate further information when the condition of dist being equal to new arise without any loss.

void djikstra(ll n, ll m,vector<vector<pair<ll, ll>>>& g)
{
    priority_queue<pair<ll ,ll> , vector<pair<ll , ll>>, greater<pair<ll , ll>>>pq;
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    pq.push({0, 1});

    vector<ll> minFlights(n + 1), maxFlights(n + 1), numFlights(n + 1, 0);
    numFlights[1] = 1;

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        ll curDist = cur.first;
        ll curNode = cur.second;

        if(dist[curNode] < curDist) continue;

        for(auto &itr: g[curNode])
        {
            ll nextNode = itr.first;
            ll w = itr.second;

            if(curDist + w == dist[nextNode])
            {
                numFlights[nextNode] = (numFlights[nextNode] + numFlights[curNode]) % MOD;
                minFlights[nextNode] = min(minFlights[nextNode], minFlights[curNode] + 1);
                maxFlights[nextNode ] = max(maxFlights[nextNode] , maxFlights[curNode] + 1);
            } else if(curDist + w < dist[nextNode])
            {
                numFlights[nextNode] = numFlights[curNode];
                minFlights[nextNode] = minFlights[curNode] + 1;
                maxFlights[nextNode] = maxFlights[curNode ] + 1;
                pq.push({dist[nextNode] = curDist + w, nextNode });
            }
        }
    }

    cout << dist[n] << " " << numFlights[n] << " " << minFlights[n] << " " << maxFlights[n];
    return;
}

int solve(void)
{
    ll n , m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> g = buildGraph(n, m);
    djikstra(n, m, g);

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
