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

template<typename T>
struct segmentTree
{
    vector<T> seg;
    int n;

    segmentTree (int n)
    {
	this -> n = n;
	seg.assign (2*n , 0);
    }


    segmentTree (vector <int> const &a) : segmentTree (a.size())
    {
	for(int i = 0 ; i < n ; i++)
	    seg[n + i] = a[i];

	for(int i = n-1 ; i >= 1 ; i--) 
	    seg[i] = max (seg[2*i] , seg[2*i + 1]);
    }


    void update(int index , T value)
    {
	index += n;

	seg[index] = value;

	while(index > 1)
	{
	    index >>= 1;

	    seg[index] = max (seg[2*index] , seg[2*index + 1]);
	}
    }

    T maximum (int left , int right)
    {
	left += n;
	right += n;

	T ret = INT_MIN ;

	while(left <= right)
	{
	    if(left & 1)
		ret = max (ret , seg[left++]);

	    if(!(right & 1))
		ret = max (ret , seg[right--]);

	    left /= 2;
	    right /= 2;
	}

	return ret;
    }

    void print(void)
    {
	for(int i = 0 ; i < n ; i++)
	{
	    cout << seg[i + n] << " ";
	}
    }
};

int solve(void)
{
    int n , q;
    cin >> n >> q;

    vector<int> arr(n);
    iterate(i,n) cin >> arr[i];

    segmentTree<int> s(arr);

    while(q-- > 0)
    {
	int num;
	cin >> num;

	if(s.maximum(0 , n-1) < num)
	{
	    cout << 0 << " ";
	    continue;
	}

	int l = 0 , r = n - 1;

	while(l < r)
	{
	    int mid = (l + r)/2;

	    if(s.maximum(l , mid) >= num)
		r = mid;
	    else
		l = mid + 1;
	}

	s.update(l , s.seg[l + n] - num);

	cout << l + 1 << " ";
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
