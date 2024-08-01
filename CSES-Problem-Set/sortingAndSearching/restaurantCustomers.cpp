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

// Priority queue holds all elements that i have seen and whose upper limit is greater than the current lower limit, this is the answer for current case

int solve(void)
{
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    iterate(i,n) {
        int a, b;
        cin >> a >> b;

        arr[i].first = a;
        arr[i].second = b;
    }

    sort (arr.begin() , arr.end());

    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        while(!pq.empty() && pq.top() < arr[i].first) {
            pq.pop();
        }

        pq.push(arr[i].second);

        ans = max(ans, (int)pq.size());
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
