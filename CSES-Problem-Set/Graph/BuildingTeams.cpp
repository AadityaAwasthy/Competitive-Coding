#include<bits/stdc++.h>
using namespace std;
#define range(a,b,c,i) for(int i = a ; i < b ; i += c)
#define iterate(i,n) for(int i = 0 ; i < n ; i++)
#define INF 1e9
#define MOD 1000000007
#define MAXN 1000001
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define pi(x) printf("%d ",x)
#define endl "\n"
#define deb(x) cout << #x << " = " << x << "\n";
#define arrout (a) for(auto itr : a) cout << itr << " "
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

bool bfs (vector<vector<int>> &graph , vector<int> &team)
{
    queue<int> q;

    for(int i = 1 ; i <= graph.size() - 1; i++)
    {
        if(team[i] != 0) continue;

	team[i] = 1;
	q.push(i);
	
	while(!q.empty())
        {
	    int current = q.front();
	    q.pop();

	    for(int i = 0 ; i < graph[current].size() ; i++)
	    {
		if(team[graph[current][i]] == team[current]) return false;

		if(team[graph[current][i]] != 0) continue;

		team[graph[current][i]] = (-1)*team[current];

		q.push(graph[current][i]);
	    }
	}
    }

    return true;
}

int main()
{
    int n , m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> team(n + 1 , 0);

    iterate(i,m)
    {
	int a , b;
	cin >> a >> b;

	graph[a].push_back(b);
	graph[b].push_back(a);
    }

    if(!bfs(graph , team))
    {
	cout << "IMPOSSIBLE";
	return 0;
    }

    for(int i = 1 ; i <= n ; i++)
    {
	if(team[i] == -1)
	    cout << 2 << " ";
	else
	    cout << 1 << " ";
    }

    cout << endl;

    return 0;
}
