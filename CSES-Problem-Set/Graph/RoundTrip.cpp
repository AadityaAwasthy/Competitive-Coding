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

bool dfs(int current , int parent , vector<vector<int>> &graph ,vector<bool> &visited ,stack<int>& rec)
{
    visited[current] = true;

    for(auto itr : graph[current])
    {
	rec.push(itr);

	if(!visited[itr])
	{
	    if(dfs(itr , current , graph , visited , rec))
		return true;
	}
	else if(itr != parent)
	    return true;

	rec.pop();
    }

    return false;
}

int solve(void)
{
    int n , m;
    cin >> n >> m ;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1,false);
    
    iterate(i,m)
    {
	int a , b;
	cin >> a >> b;

	graph[a].push_back(b);
	graph[b].push_back(a);
    }

    int flag = 0;

    for(int i = 1 ; i <= n ; i++)
    {
        if(visited[i]) continue;

	stack<int> rec;
	rec.push(i);

	if(dfs(i , 0 , graph , visited , rec))
	{
	    flag = 1;

	    vector<int> ans;

	    int end = rec.top();
	    ans.push_back(rec.top());
	    rec.pop();

	    while(!rec.empty())
	    {
		ans.push_back(rec.top());
		
		if(rec.top() == end)
		    break;

		rec.pop();
	    }

	    cout << ans.size() << endl;

	    for(auto itr : ans)
		cout << itr << " ";

	    break;
	}
    }

    if(flag == 0)
	cout << "IMPOSSIBLE";
    return 0;
}



int main()
{
    int t = 1;

    while(t-- > 0)
    {
        solve();
    }

    return 0;
}
