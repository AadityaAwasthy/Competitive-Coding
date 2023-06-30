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
   int n; cin >> n;
   vector<int> arr(n);
   iterate(i,n) cin >> arr[i];

   vector<int> ans;
   ans.push_back(arr[0]);

   for(int i = 1 ; i < n ; i++)
   {
       if(arr[i] > ans.back())
       {
	   ans.push_back(arr[i]);
	   continue;
       }

       auto itr = lower_bound(ans.begin() , ans.end() , arr[i]);
       *itr = arr[i];
   }

   cout << ans.size();

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
