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
   int n , k;
   cin >> n >> k;

   vector<int> arr(n + 1);
   
   for(int i = 1 ; i < n+1 ; i++)
   {
       cin >> arr[i];
   }

   vector<int> dp(n+1 , INT_MAX);
   dp[1] = 0;

   for(int i = 1 ; i <= n ; i++)
   {
       for(int j = 1 ; j < k+1 ; j++)
       {
           if(i+j > n) continue;

	   dp[i+j] = min(dp[i+j] , dp[i] + abs(arr[i+j] - arr[i]));
       }
   }

   cout << dp[n] ;

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
