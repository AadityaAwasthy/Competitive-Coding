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

int solve(void)
{
    int n , m;
    cin >> n >> m ;

    vector<vector<pair<int , int>>> graph(n + 1);
    vector<bool> visited(n+1 , false);

    for(int i = 0 ; i < m ; i++)
    {
        int a , b , c;
	cin >> a >> b >> c;

	graph[a].push_back({b , c});
    }

    vector<ll> distance(n+1 , LONG_MAX);
    distance[1] = 0;

    priority_queue<pair<ll , ll> , vector<pair<ll ,ll>> , greater<pair<ll , ll>> > pq;

    pq.push({0 , 1});

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

	    if(newDis < distance[itr.first])
	    {
		distance[itr.first] = newDis;
		pq.push({newDis , itr.first});
	    }
	}
    }

    for(int i = 1 ; i <= n ; i++)
    {
        cout << distance[i] << " ";
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
