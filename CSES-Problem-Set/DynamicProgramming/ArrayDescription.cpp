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

bool isOk(int a)
{
    if(a >= 1 && a <= 100)
	return true;
    
    return false;
}

int solve(void)
{
   int n , m ;
   cin >> n >> m ;

   vector<int> arr(n);
   arrin(arr);

   vector<vector<int>> dp(n , vector<int>(m+1 , 0));

   if(arr[0] == 0)
   {
       for(int i = 1 ; i <= m ; i++)
       {
           dp[0][i] = 1;
       }
   }
   else
       dp[0][arr[0]] = 1;

   for(int i = 1 ; i < n ; i++)
   {
       if(arr[i] != 0)
       {
	   for(int k = -1 ; k <= 1 ; k++)
	   {
	       if(isOk(arr[i] + k))
	       {
		   dp[i][arr[i]] += dp[i-1][arr[i] + k];

		   dp[i][arr[i]] %= MOD;
	       }
	   }
       }
       else
       {
	   for(int j = 1 ; j <= m ; j++)
	   {
	       for(int k = -1 ; k <= 1 ; k++)
	       {
	           if(isOk(j + k))
		   {
		       dp[i][j] += dp[i-1][j + k];

		       dp[i][j] %= MOD;
		   }
	       }
	   }
       }
   }

   ll ans = 0;

   for(int i = 1 ; i <= m ; i++)
   {
       ans += dp[n-1][i];
       ans %= MOD;
   }

   cout << ans;

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
