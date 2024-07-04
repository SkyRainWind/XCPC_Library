// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#define mpr make_pair
#define debug() cerr<<"Yoshino"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m;
int tmp[20005],a[105][105];
int tmp2[20005];
int gg = 0;
string curp;

void dfs2(int x,int p0=0,int p1=0){	// 0 D 1 R ×ÖµäÐò ++ 
	if(p1 > m-1)return ;
	if(p0 > n-1)return ;
	if(x == n+m-1){
		if(p0 == n-1 && p1 == m-1){
			string cur="";
			int fx = 1, fy = 1;
			cur += (a[1][1] + '0');
			for(int i=1;i<=n+m-2;i++)
				if(tmp2[i] == 1)cur += (a[fx][++fy]+'0');
				else cur += (a[++fx][fy]+'0');
//			cout << cur <<" "<<curp<<endl;
			if(cur > curp)gg = 1;
			else curp = cur;
		}
		return ;
	}
	tmp2[x] = 0;
	dfs2(x+1,p0+1,p1);
	tmp2[x] = 1;
	dfs2(x+1,p0,p1+1);
}

int r =0;
void ck(){
	curp="";
	for(int i=1;i<=n+m-1;i++)curp += '1';
	gg = 0;
	dfs2(1);
//	printf("g %d   ",gg);for(int i=1;i<=n*m;i++)printf("%d ",tmp[i]);puts("");
	if(!gg)++ r;
}

void dfs(int x){
	if(x == n*m+1){
		int pp=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)a[i][j]=tmp[++pp];
		ck();
//		exit(0);
		return ;
	}
	tmp[x] = 0;
	dfs(x+1);
	tmp[x] = 1;
	dfs(x+1);
}

signed main(){
	scanf("%d%d",&n,&m);
	dfs(1); 
	printf("%d\n",r);

	return 0;
}


