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
    int n , q;
    cin >> n >> q;

    vector<int> arr(n + 1 , 0);
    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] ^= arr[i-1];
    }

    while(q-- > 0)
    {
	int a , b;
	cin >> a >> b;

	int ans = arr[a-1] ^ arr[b];

	cout << ans << endl;
    }

    return 0;
}



int main()
{
    int t = 1;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
