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
#define arrout(a) for(auto itr : a) cout << itr << " "
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void diffArray(vector<ll> &arr)
{
    int n = arr.size();

    ll sum = arr[0];

    for(int i = 1 ; i < n ; i++)
    {
        arr[i] -= sum;

	sum += arr[i];
    }

    return ;
}

template<typename T>
struct fenwickTree
{
    vector<T> bit;
    int n;

    fenwickTree (int n)
    {
	this -> n = n;
	bit.assign (n , 0);
    }

    fenwickTree (vector<T> const &a) : fenwickTree(a.size())
    {
	for(int i = 0 ; i < n ; i++)
	{
	    bit[i] += a[i];

	    int nextIndex = i | (i + 1);

	    if(nextIndex < n) bit[nextIndex] += bit[i];
	}
    }

    T sum (int r)
    {
	T ret = 0;

	for(; r >= 0 ; r = (r & (r + 1)) - 1)
	{
	    ret += bit[r];
	}

	return ret;
    }

    T sum (int l , int r)
    {
	return sum(r) - sum(l-1);
    }

    void add (int index , int delta)
    {
	for(; index < n ; index = index | (index + 1))
	    bit[index] += delta;
    }
};

int solve(void)
{
   int n , q;
   cin >> n >> q;

   vector<ll> arr(n);
   iterate(i,n) cin >> arr[i];

   diffArray(arr);

   fenwickTree<ll> bit(arr);

   while(q-- > 0)
   {
       int t;
       cin >> t;

       if(t == 1)
       {
	   int a , b , u;

	   cin >> a >> b >> u;
	   
	   bit.add(a-1 , u);

	   if(b < n)
	       bit.add(b, (-1)*u);
       }
       else
       {
	   int index;
	   cin >> index;

	   cout << bit.sum(0 , index - 1) << endl;
       }
   }

 return 0;
}



int main()
{
    int t = 1;

    while(t-- > 0)
    {
        solve();
    }

    return 0;
}
