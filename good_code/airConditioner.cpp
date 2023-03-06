#include<bits/stdc++.h>
using namespace std;
#define range(a,b,c,i) for(int i = a ; i < b ; i += c)
#define iterate(i,n) for(int i = 0 ; i < n ; i++)
#define INF 1e9
#define MOD 1000000007
#define MAXN 1000001
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define pi(x) printf("%d ",x)
#define endl "\n"
#define deb(x) cout << #x << " = " << x << "\n";
#define arrout (a) for(auto itr : a) cout << itr << " "
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int solve(void)
{
    int n , k ;
    cin >> n >> k;

    vector<int> pos(k);
    vector<int> temp(k);

    iterate(i,k) cin >> pos[i];
    iterate(i,k) cin >> temp[i];

    vector<ll> c(n , INT_MAX);

    iterate(i,k)
    {
	c [pos[i] - 1] = temp[i];
    }

    ll p = INT_MAX;

    vector<ll> L(n , INT_MAX);
    vector<ll> R(n , INT_MAX);

    iterate(i,n)
    {
	p = min(p + 1 , c[i]);
	L[i] = p;
    }

    p = INT_MAX;

    for(int i = n-1 ; i >= 0 ; i--)
    {
	p = min(p + 1 , c[i]);
	R[i] = p;
    }

    iterate(i,n)
    {
	cout << min(L[i] , R[i]) << " ";
    }

    return 0;
}



int main()
{
    int t;
    si(t);

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
