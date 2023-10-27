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

void dfs(int current , int prev , vector<int>& dist , vector<vector<int>>& g)
{
    if(prev != -1) dist[current] = dist[prev] + 1;

    for(auto &itr : g[current])
    {
	if(itr == prev) continue;

	dfs(itr , current , dist , g);
    }

    return;
}

int solve(void)
{
   int n , k ;

   cin >> n >> k;

   vector<int> marked(k);

   iterate(i,k) cin >> marked[i];

   vector<vector<int>> g(n + 1);

   iterate(i,n - 1)
   {
       int a , b;
       cin >> a >> b;

       g[a].push_back(b);
       g[b].push_back(a);
   }

   if(k == 1)
   {
       cout << 0;

       return 0;
   }

   vector<int> d1(n + 1 , 0) , d2(n + 1 , 0);

   dfs(marked[0] , -1 , d1 , g);

   int maxi = marked[0];

   for(auto &itr : marked)
   {
       if(d1[itr] > d1[maxi]) maxi = itr;
   }

   dfs(maxi , -1 , d2 , g);

   int ans = 0;

   for(auto &itr : marked) ans = max(ans , d2[itr]);

   cout << (ans + 1) / 2;

   return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
