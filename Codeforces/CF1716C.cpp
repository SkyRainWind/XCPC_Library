// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int a[3][200005],m,dist[200005],mn[200005];
int f[3][200005];
int changeindist(int x,int y){
	if(y&1)return (y-1)*2+x;
	return (y-1)*2+(3-x);
}

void solve(){
	int n;scanf("%d",&n);
	for(int i=1;i<=2;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	a[1][1] = -1;
	f[1][n] = a[1][n];f[2][n] = a[2][n];
	for(int j=n-1;j>=1;j--)for(int i=1;i<=2;i++)
		{
			f[i][j] = max(f[i][j+1]-1,a[i][j]);
		}
	f[1][n] = max(a[2][n]-1,a[1][n]);
	f[2][n] = max(a[1][n]-1,a[2][n]);
	for(int i=1;i<=2;i++){
		for(int j=n-1;j>=1;j--)f[i][j] = max(f[i][j+1]-1,max(a[3-i][j] - 2*(n-j)-1,a[i][j]));
	}
	int ans = f[1][1]+2*n, cur=a[2][1]+1;
	for(int j=2;j<=n;j++){
		ans = min(ans, (f[j%2 == 1?1:2][j] - cur <=0?0:f[j%2==1?1:2][j]-cur) + cur + 2*(n-j)+2);
		cur = max(cur+1,a[j%2==1?1:2][j]+1);
		cur = max(cur+1,a[j%2==1?2:1][j]+1);
	}
	ans = min(ans,cur); 
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}


