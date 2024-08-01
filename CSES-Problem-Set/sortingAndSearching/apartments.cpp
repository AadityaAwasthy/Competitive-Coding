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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> customer(n), apartments(m);
    iterate(i,n) cin >> customer[i];
    iterate(i,m) cin >> apartments[i];

    sort (customer.begin() , customer.end());
    sort (apartments.begin() , apartments.end());

    ll ptr_c = 0, ptr_a = 0;
    ll ans = 0;

    while(ptr_c < n && ptr_a < m) {

        ll l = max(1ll*0, customer[ptr_c] - k);
        ll r = (customer[ptr_c] + k);

        if(apartments[ptr_a] >= l && apartments[ptr_a] <= r) {
            ans++;
            ptr_a++;
            ptr_c++;
        } else if (apartments[ptr_a] < l) {
            ptr_a++;
        } else if(apartments[ptr_a] > r){
            ptr_c++;
        }
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
