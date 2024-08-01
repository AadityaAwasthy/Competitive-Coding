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
    int n, m;
    cin >> n >> m;

    multiset<int> s;
    iterate(i,n) {
        int temp;
        cin >> temp;

        s.insert(temp);
    }

    iterate(i,m) {
        int demand;
        cin >> demand;

        auto found = s.upper_bound(demand);
        if(found == s.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--found) << endl;
            s.erase(found);
        }
    }

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
