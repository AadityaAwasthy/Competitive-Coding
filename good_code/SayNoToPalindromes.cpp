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

vector<bool> isTaken(3 , false);
vector<string> permutations;
string current(3 , 'n');
int taken = 0;

vector<vector<int>> prefix(6 , vector<int>(200010));

void generatePermutations(int index)
{
    if(taken == 3)
    {
	permutations.push_back(current);

	return ;
    }

    for(int i = 0 ; i < 3 ; i++)
    {
	if(isTaken[i]) continue;

	current[index] = i + 'a';

	isTaken[i] = true;
	taken++;

	generatePermutations(index + 1);

	isTaken[i] = false;
	taken--;
    }

    return ;
}

void calculatePrefix(string const &inp)
{
    int sum = 0;

    for(int itr = 0 ; itr < 6 ; itr ++)
    {
	sum = 0;

	int i = 0;

	while(i < inp.length())
	{
	    for(int j = 0 ; j < 3 && i < inp.length() ; j++,i++)
	    {
		sum += (permutations[itr][j] != inp[i]);

		prefix[itr][i] = sum;
	    }
	}
    }

    return ;
}

int solve(void)
{
   generatePermutations(0); 

   int n , m ;
   cin >> n >> m ;

   string inp;
   cin >> inp;

   calculatePrefix(inp);

   while(m-- > 0)
   {
       int l , r;
       cin >> l >> r;
       l--;
       r--;

       int ans = INT_MAX;

       for(int i = 0 ; i < 6 ; i++)
       {
	   if(l == 0)
	       ans = min(ans , prefix[i][r]);
	   else
	       ans = min(ans , prefix[i][r] - prefix[i][l - 1]);
       }

       cout << ans << endl;
   }

   return 0;
}



int main()
{
    int t;

    t = 1;

    while(t-- > 0)
    {
        solve();
    }

    return 0;
}
