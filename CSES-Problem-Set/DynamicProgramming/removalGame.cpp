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

vector<vector<ll>> dp(5000 , vector<ll>(5000 , LONG_MIN));


ll range(int l , int r , vector<ll>& prefix)
{
    if(l > 0) return prefix[r] - prefix[l - 1];
    
    return prefix[r];
}

vector<ll> create(vector<ll>& arr)
{
    int n = arr.size();

    vector<ll> prefix(n);
    prefix[0] = arr[0];

    for(int i = 1 ; i < n ; i++)
    {
	prefix[i] += arr[i] + prefix[i - 1];
    }

    return prefix;
}

ll helper(int l , int r , vector<ll>& arr , vector<ll>& prefix)
{
    if(l == r) return dp[l][r] = arr[l];

    if(dp[l][r] != LONG_MIN) return dp[l][r];

    ll total = range(l , r , prefix);
    ll other = min(helper(l + 1 , r , arr , prefix) , helper(l , r - 1 , arr , prefix));

    return dp[l][r] = total - other;
}

int solve(void)
{
    int n;
    cin >> n;

    vector<ll> arr(n);
    iterate(i,n) cin >> arr[i];

    vector<ll> prefix = create(arr);

    cout << helper(0 , n - 1 , arr , prefix);

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
