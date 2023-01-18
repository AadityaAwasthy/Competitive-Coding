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
#define endl printf("\n");
#define deb(x) cout << #x << " = " << x << "\n";
#define inArr(v) iterate(i,v.size()){si(v[i]);}
#define printArr(v) iterate(i,v.size()) {pi(v[i]);}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int solve(void)
{
   string s ;
   cin >> s ;

   int n = s.length();

   ll ans , max0 , max1 ;
   ans = max0 = max1 = 0 ;

   iterate(i , n)
   {
       if(s[i] == '1')
       {
	   max1++;
	   max0 = 0;
	   ans += max1;
       }
       else if(s[i] == '0')
       {
	   max0++;
	   max1 = 0;
	   ans += max0;
       }
       else
       {
	   max0++;
	   max1++;
	   ans += max(max0 , max1);
       }

       swap(max0 , max1);
   }

   cout << ans;

   return 0;
}



int main()
{
    int t;
    si(t);

    while(t-- > 0)
    {
        solve();
        endl;
    }

    return 0;
}
