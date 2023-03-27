#include<bits/stdc++.h>
using namespace std;
#define iterate(i,n) for(int i = 0 ; i < n ; i++)
#define INF LONG_MAX
#define MOD 1000000007
#define MAXN 1000001
#define endl "\n"
#define deb(x) cout << #x << " = " << x << "\n";
#define arrout(a) for(auto itr : a) cout << itr << " "
#define arrin(a) for(auto& itr : a) cin >> itr;
typedef long long ll;

vector<vector<ll>> dist(501 , vector<ll>(501 , INF));
vector<vector<ll>> inp(501 , vector<ll>(501 , INF));
vector<vector<pair<int,int>>> graph(501);

void dijkstra(int source)
{
    vector<bool> visited (501 , false);

    dist[source][source] = 0;

    priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll , ll>>> pq;

    pq.push({0 , source});

    while(!pq.empty())
    {
	auto current = pq.top();
	pq.pop();

	ll dis = current.first;
	int v = current.second;

	if(visited[v]) continue;

	visited[v] = true;

	for(auto itr : graph[v])
	{
	    ll newDis = dis + itr.second;

	    if(newDis < dist[source][itr.first])
	    {
		dist[source][itr.first] = newDis;

		pq.push({newDis , itr.first});
	    }
	}
    }

    return ;
}

int solve(void)
{
    int n , m , q;
    cin >> n >> m >> q;

    while(m-- > 0)
    {
	ll a , b , c;
	cin >> a >> b >> c;

	inp[a][a] = 0;
	inp[b][b] = 0;
	inp[a][b] = min(inp[a][b] , c);
	inp[b][a] = min(inp[b][a] , c);
    }

    for(int i = 1 ; i <= n ; i++)
    {
	for(int j = i+1 ; j <= n ; j++)
	{	
	    if(inp[i][j] != INF)
	    {
		graph[i].push_back({j , inp[i][j]});
		graph[j].push_back({i , inp[i][j]});
	    }
	}
    }

    for(int i = 1 ; i <= n ; i++)
    {
	dijkstra(i);
    }

    while(q-- > 0)
    {
	int a , b;
	cin >> a >> b;

	if(dist[a][b] == INF)
	    cout << -1 << endl;
	else
	    cout << dist[a][b] << endl;
    }

    return 0;
}



int main()
{
    int t;

    t = 1;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
