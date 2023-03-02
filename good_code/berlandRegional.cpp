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

bool comparator(const vector<ll>& v1 , const vector<ll>& v2)
{
    return v1[0] > v2[0];
}

int solve(void)
{
   int n ;
   si(n);

   vector<vector<ll>> v(n+1 ,vector<ll> (1,0));

   vector<int> u(n) , s(n);

   iterate(i , n) si(u[i]);
   iterate(i , n) si(s[i]);

   iterate(i , n)
   {
       v[u[i]][0]++;
       v[u[i]].push_back(s[i]);
   }

   sort(v.begin(),v.end() , comparator);

   for(int i = 0 ; i < v.size() ; i++)
   {
       sort(&v[i][1] , &v[i][0] + v[i].size());
   }


   for(int i = 0 ; i < v.size(); i++)
   {
       for(int j = 2 ; j < v[i].size() ; j++)
       {
	   v[i][j] += v[i][j-1];
       }
   }

   vector<ll> ans(n) ;

   for(int k = 1 ; k <= n ; k++)
   {
       ll sum = 0;

       for(int j = 0 ; j < n ; j++)
       {
	   if(v[j][0] >= k)
	   {
	       int mod = v[j][0] % k ;

	       if(mod == 0)
		   sum += v[j][v[j][0]];
	       else
	           sum += v[j][v[j][0]] - v[j][mod];
	   }
	   else
	   {
	       break;
	   }
       }

       ans[k-1] = sum ;
   }

   for(auto itr : ans)
       cout << itr << " ";

 

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
