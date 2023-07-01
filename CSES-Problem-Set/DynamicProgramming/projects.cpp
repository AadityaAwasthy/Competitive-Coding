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

bool cmp(const tuple<ll ,ll , ll>& a , const tuple<ll , ll , ll>& b)
{
    return get<1>(a) <= get<1>(b);
}

int solve(void)
{
   int n;
   cin >> n;

   vector<tuple<ll , ll , ll>> arr(n);

   iterate(i,n)
   {
       cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
   }

   sort(arr.begin() , arr.end() , cmp);

   map<ll , ll> dp;

   for(auto itr : arr)
   {
       ll l = get<0>(itr);
       ll r = get<1>(itr);
       ll p = get<2>(itr);

       if(dp.size() == 0)
       {
	   dp[r] = p;
	   continue;
       }

       auto upper = dp.find(r);

       if(upper == dp.end())
       {
	   auto prev = dp.end();
	   prev--;

	   dp[r] = prev -> second;
       }

       auto lower = dp.lower_bound(l);

       ll current = dp.find(r) -> second;

       if(lower == dp.begin()) dp[r] = max(current, p);
       else
       {
	   lower--;
	   dp[r] = max(current , lower -> second + p);
       }
   }

   ll ans = LONG_MIN;

   for(auto itr : dp)
   {
       ans = max(ans , itr.second);
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
