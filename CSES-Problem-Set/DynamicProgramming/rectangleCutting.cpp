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

int dp[501][501] = {-1};

int helper(int a , int b)
{
    if(a == b) return dp[a][b] = 0;

    if(dp[a][b] != -1) return dp[a][b];
    if(dp[b][a] != -1) return dp[b][a];

    int ans = INT_MAX;

    for(int i = 1 ; i <= a/2 ; i++)
    {
	ans = min(ans , helper(i , b) + helper(a - i , b) + 1);
    }

    for(int i = 1 ; i <= b/2 ; i++)
    {
	ans = min(ans , helper(a , i) + helper(a , b - i) + 1);
    }

    return dp[a][b] = dp[b][a] = ans;
}

int solve(void)
{
    int a , b;
    cin >> a >> b;

    cout << helper(a , b);

    return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp , -1 , sizeof(dp));

    int t = 1;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
