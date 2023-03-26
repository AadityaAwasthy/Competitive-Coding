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
#define pb push_back
typedef long long ll;

int solve(void)
{
    int n;
    cin >> n;

    vector<ll> a(n) , b(n);
    arrin(a);
    arrin(b);

    vector<ll> prefix(n+1 , 0);

    for(int i = 1 ; i <= n ; i++)
    {
        prefix[i] += prefix[i-1] + a[i-1]*b[i-1];
    }

    ll ans = prefix[n];

    for(int c = 0 ; c < n ; c++)
    {
        ll curr = a[c] * b[c];

	for(int l = c-1 , r = c+1 ; l >= 0 && r < n; l-- , r++)
	{
	    curr += a[l] * b[r];
	    curr += a[r] * b[l];

	    ans = max(ans , curr + prefix[l] + (prefix[n] - prefix[r+1]));
	}

	curr = 0;

	for(int l = c , r = c + 1 ; l >= 0 && r < n ; l-- , r++)
	{
	    curr += a[l] * b[r];
	    curr += a[r] * b[l];

	    ans = max(ans , curr + prefix[l] + (prefix[n] - prefix[r+1]));
	}
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
