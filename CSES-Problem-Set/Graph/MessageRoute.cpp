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

void bfs (vector<vector<int>> &graph , vector<int> &path)
{
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
	int current = q.front();
	q.pop();

	for(int i = 0 ; i < graph[current].size() ; i++)
	{
	    if(path[graph[current][i]] != -1)
		continue;

	    path[graph[current][i]] = current;
	    
	    q.push(graph[current][i]);
	}
    }

    return;
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> path(n+1 , -1);
    path[1] = 1;

    vector<vector<int>> graph(n + 1);

    iterate(i,m)
    {
	int a , b;
	cin >> a >> b;

	graph[a].push_back(b);
	graph[b].push_back(a);
    }

    bfs(graph , path);


    if(path[n] == -1)
    {
	cout << "IMPOSSIBLE";
	return 0;
    }

    int itr = n;
    stack<int> stk;

    while(itr != 1)
    {
	stk.push(itr);

	itr = path[itr];
    }
    stk.push(1);

    cout << stk.size() << endl;

    while(!stk.empty())
    {
	cout << stk.top() << " ";
	stk.pop();
    }

    return 0;
}
