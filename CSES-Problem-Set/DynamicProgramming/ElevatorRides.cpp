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
   ll n , x;
   cin >> n >> x;

   vector<ll> arr(n);
   iterate(i,n) cin >> arr[i];

   pair<ll,ll> dp[(1<<(n))];
   dp[0] = {1 , 0};

   for(int i = 1 ; i < (1<<n) ; i++)
   {
       dp[i] = {n + 1 , INT_MAX};

       for(int j = 0 ; j < n ; j++)
       {
	   if(i & (1<<j))
	   {
	       auto withoutCurrent = dp[i ^ (1<<j)];

	       if(withoutCurrent.second + arr[j] <= x)
	       {
		   withoutCurrent.second += arr[j];
	       }
	       else
	       {
		   withoutCurrent.first++;
		   withoutCurrent.second = min(withoutCurrent.second , arr[j]);
	       }

	       dp[i] = min(dp[i] , withoutCurrent);
	   }
       }
   }

   cout << dp[(1<<n) - 1].first;

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
