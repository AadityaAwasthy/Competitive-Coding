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

int numOperations[1001];

void bfs(void)
{
    numOperations[1] = 0;

    vector<bool> visited(1001 , false);
    visited[1] = true;

    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
	int current = q.front();
	q.pop();
	
	for(int i = current ; i >= 1 ; i--)
	{
	    int next = current + (current/i);

	    if(next > 1000) continue;
	    if(visited[next]) continue;

	    numOperations[next] = numOperations[current] + 1;
	    visited[next] = true;
	    q.push(next);
	}
    }

    return ;
}


int solve(void)
{
   int n , k;
   cin >> n >> k;

   k = min(k , 12*n);

   bfs();

   vector<int> price(n) , reward(n);

   iterate(i,n)
   {
       int temp;
       cin >> temp;

       price[i] = numOperations[temp];
   }

   iterate(i,n) cin >> reward[i];

   vector<vector<int>> dp(n+1 , vector<int>(k + 1, 0));

   for(int i = 1 ; i <= n ; i++)
   {
       for(int j = 0 ; j <= k ; j++)
       {
           dp[i][j] = dp[i-1][j];

	   int left = j - price[i-1];

	   if(left < 0) continue;

	   dp[i][j] = max(dp[i][j] , dp[i-1][left] + reward[i-1]);
       }
   }
   
   cout << dp[n][k] ;

   return 0;
}



int main()
{
    int t;
    cin >> t;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}

