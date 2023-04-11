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


struct edge
{
    int src;
    int dest;
    int score;
};

int n , m;
edge edges[5000];
vector<bool> visited (2501 , false);

void dfs(int src)
{
    visited[src] = true;

    for(int i = 0 ; i < m ; i++)
    {
        int sr = edges[i].src;
	int des = edges[i].dest;

	if(des == src && !visited[sr])
	    dfs(sr);
    }

    return;
}

int solve(void)
{
   cin >> n >> m;

   iterate(i,m)
   {
       cin >> edges[i].src >> edges[i].dest >> edges[i].score;
   }

   vector<ll> distance (n + 1 , LONG_MIN);

   distance[1] = 0;

   for(int i = 0 ; i < n-1 ; i++)
   {
       for(int j = 0 ; j < m ; j++)
       {
           int src = edges[j].src;
	   int dest = edges[j].dest;
	   int score = edges[j].score;

	   if(distance[src] == LONG_MIN) continue;

	   if(distance[dest] < distance[src] + score)
	   {
	       distance[dest] = distance[src] + score;
	   }
       }
   }

   int loop;
   bool check = false;
   dfs(n);

   for(int j = 0 ; j < m ; j++)
   {
       int src = edges[j].src;
       int dest = edges[j].dest;
       int score = edges[j].score;

       if(distance[src] == LONG_MIN) continue;

       if(distance[dest] < distance[src] + score)
       {
	   if(visited[dest])
	   {
	       cout << -1;
	       return 0;
	   }
       }
   }

   cout << distance[n];

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
