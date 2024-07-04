// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

/*
0 0 0 0 1 0 1 0
1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 1 0 0 0 0 0
0 0 0 0 0 1 0 1
0 1 0 1 0 0 0 0
0 0 0 0 0 1 0 1
0 1 0 1 0 0 0 0

0 1 0 1 0 0 0 0
0 0 0 0 0 1 0 1
0 1 0 1 0 0 0 0
0 0 0 0 0 1 0 1
1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0
*/

int n,b[2005][2005],c[2005][2005],a[2005][2005],ok[2005][2005];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=4*n;i++)
		for(int j=1;j<=4*n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++){
			if(i<=n&&j<=n)b[i][j]=3;
			if(i<=n&&j>n)b[i][j]=1;
			if(i>n&&j<=n)b[i][j]=4;
			if(i>n&&j>n)b[i][j]=2;
		}
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++){
			if(i<=n&&j<=n)c[i][j]=2;
			if(i<=n&&j>n)c[i][j]=4;
			if(i>n&&j<=n)c[i][j]=1;
			if(i>n&&j>n)c[i][j]=3;
		}
	
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++){
			if(b[i][j]==1)ok[i*2-1][j*2-1]=1;
			if(b[i][j]==2)ok[i*2-1][j*2]=1;
			if(b[i][j]==3)ok[i*2][j*2-1]=1;
			if(b[i][j]==4)ok[i*2][j*2]=1;
		}
	vector<int>cnt(4*n+23,0);
	for(int i=1;i<=4*n;i++)
		for(int j=1;j<=4*n;j++)if(ok[i][j])cnt[a[i][j]]++;
	
	int f=1;
	for(int i=1;i<=4*n;i++)
		if(cnt[i]!=n)f=0;
	if(f){
		puts("YES");
		for(int i=1;i<=4*n;i++)
			for(int j=1;j<=4*n;j++)if(ok[i][j])printf("%d %d\n",i,j);
		return 0;
	}
	memset(ok,0,sizeof ok);
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++){
			if(c[i][j]==1)ok[i*2-1][j*2-1]=1;
			if(c[i][j]==2)ok[i*2-1][j*2]=1;
			if(c[i][j]==3)ok[i*2][j*2-1]=1;
			if(c[i][j]==4)ok[i*2][j*2]=1;
		}
	cnt.assign(4*n+23,0);
	for(int i=1;i<=4*n;i++)
		for(int j=1;j<=4*n;j++)if(ok[i][j])cnt[a[i][j]]++;
	
	f=1;
	for(int i=1;i<=4*n;i++)
		if(cnt[i]!=n)f=0;
	if(f){
		puts("YES");
		for(int i=1;i<=4*n;i++)
			for(int j=1;j<=4*n;j++)if(ok[i][j])printf("%d %d\n",i,j);
		return 0;
	}
	puts("NO");

	return 0;
}

