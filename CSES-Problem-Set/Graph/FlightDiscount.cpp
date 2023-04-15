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

int n , m ;

void djikstra(vector<vector<pair<int,int>>> &graph , vector<bool> &visited ,vector<ll> &distance ,int source)
{
    distance[source] = 0;

    priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<pair<ll , int>>> pq;

    pq.push({0 , source});

    while(!pq.empty())
    {
	auto current = pq.top();
	pq.pop();

	int node = current.second;
	ll dis = current.first;

	if(visited[node]) continue;

	visited[node] = true;

	for(auto itr : graph[node])
	{
	    int next = itr.first;
	    int weight = itr.second;

	    if(distance[next] > dis + weight)
	    {
		distance[next] = dis + weight;

		pq.push({distance[next] , next});
	    }
	}
    }

    return;
}


int solve(void)
{
    cin >> n >> m ;

    vector<vector<pair<int,int>>> graph(n + 1);
    vector<vector<pair<int,int>>> reverse(n + 1);
    
    vector<bool> visited (n+1);
    vector<bool> revVisited (n+1);

    vector<ll> distance(n+1 , LONG_MAX);
    vector<ll> revDistance(n+1 , LONG_MAX);
    
    iterate(i,m)
    {
	int a , b , c;
	cin >> a >> b >> c;

	graph[a].push_back({b , c});
	reverse[b].push_back({a , c});
    }

    djikstra(graph , visited , distance , 1);
    djikstra(reverse , revVisited , revDistance , n);

    ll ans = LONG_MAX;

    for(int i = 1 ; i < n+1 ; i++)
    {
	for(auto pi : graph[i])
	{
	    int b = pi.first;
	    ll c = pi.second;

	    if(visited[i] && revVisited[b])
	    {
		ans = min(ans , distance[i] + revDistance[b] + c/2);
	    }
	}
    }

    cout << ans;

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
