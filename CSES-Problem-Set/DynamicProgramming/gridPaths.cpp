#include<bits/stdc++.h>
using namespace std;
#define range(a,b,c,i) for(int i = a ; i < b ; i += c)
#define iterate(n) for(int i = 0 ; i < n ; i++)
typedef long long ll;
#define INF 1e9
#define MOD 1000000007
#define MAXN 1000001

int gridPath [1001][1001];
char grid[1001][1001];
int n;

int numPath (int i , int j)
{
    if(i < 1 || j < 1)
        return 0;

    if( gridPath[i][j] != -1)
        return gridPath[i][j] ;

    gridPath[i][j] = ( numPath(i-1,j) + numPath(i,j-1))%MOD;

    return gridPath[i][j];
}

int main()
{
    cin>>n;

    range(1,n+1,1,i)
    {
        range(1,n+1,1,j)
        {
            gridPath[i][j] = -1;
        }
    }

    gridPath[1][1] = 1;


    range(1,n+1,1,i)
    {
        range(1,n+1,1,j)
        {
            cin >> grid[i][j];

            if(grid[i][j] == '*')
                gridPath[i][j] = 0;
        }
    }

    cout<<numPath(n,n);

    return 0;
}


