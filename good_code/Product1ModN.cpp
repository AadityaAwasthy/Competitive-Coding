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

/* Facts used :
 * gcd (n , n +1) = 1
 * all multiples of n will satisfy the above for a single n + 1
 * mod of product of numbers that are coprime with n will give back a coprime
 */

vector<bool> isCoPrime(1e5 + 1 , false);

template <typename T>
T gcd(T a, T b)
{
    return (b == 0) ? a : gcd(b , a % b);
}

int solve(void)
{
    int n;
    cin >> n;

    ll prod = 1;

    for(int i = 1 ; i < n ; i++)
    {
	if(gcd<ll> (i , n) == 1)
	{
	    isCoPrime[i] = true;

	    prod = (prod*i) % n ; 
	}
    }

    if(prod != 1)
    {
	isCoPrime[prod] = false;
    }

    vector<int> ans;

    for(int i = 1 ; i < n ; i++)
    {
        if(isCoPrime[i])
	    ans.pb(i);
    }

    cout << ans.size() << endl;

    arrout(ans);

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
