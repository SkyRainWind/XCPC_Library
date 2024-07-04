// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 55, mod = 10000;

int n,m,st,ed,K;

struct mat{
	int a[maxn][maxn];
	mat(){memset(a,0,sizeof a);}
};
mat each[15], g;
mat operator * (mat a,mat b){
	mat c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				(c.a[i][j] += 1ll * a.a[i][k] * b.a[k][j] % mod) %= mod;
			}
		}
	}
	return c;
}

struct _fish{
	int t;
	int p[5];
}fi[maxn];
int nfish;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int lcm(int a,int b){return a * b / gcd(a,b);}

mat e;
void pw(int b){
	mat ans;
	for(int i=1;i<=n;i++)ans.a[i][i] = 1;
	mat base = e;
	while(b){
		if(b & 1)ans = ans * base;
		base = base * base;
		b >>= 1;
	}
	e = ans; 
}

signed main(){
	scanf("%d%d%d%d%d",&n,&m,&st,&ed,&K);
	++ st, ++ ed;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		++ x,++ y;g.a[x][y] ++, g.a[y][x] ++;
	}
	scanf("%d",&nfish);
	int lc = 1;
	for(int i=1;i<=nfish;i++){
		scanf("%d",&fi[i].t);
		lc = lcm(lc, fi[i].t);
		for(int j=1;j<=fi[i].t;j++){
			scanf("%d",&fi[i].p[j]);
			++ fi[i].p[j];
		}
	}
	
	for(int i=1;i<=n;i++)e.a[i][i] = 1;
	for(int k=1;k<=12;k++){
		each[k] = g;
		for(int i=1;i<=nfish;i++){
			int tmp = k % fi[i].t  + 1;
			int banned = fi[i].p[tmp];
			for(int j=1;j<=n;j++)
				if(each[k].a[j][banned])
					each[k].a[j][banned] = 0;
		}
		e = e * each[k];
	}
//	for(int i=1;i<=n;i++,puts(""))
//		for(int j=1;j<=n;j++)printf("%d ",each[1].a[i][j]);
//	e = e * each[1];
	pw(K / 12);
	for(int i=1;i<=K%12;i++){
		e = e * each[i];
	}
	printf("%d\n",e.a[st][ed]);

	return 0;
}

