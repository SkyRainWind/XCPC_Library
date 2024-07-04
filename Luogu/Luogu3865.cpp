// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,m,a[maxn],st[maxn][25];

int query(int x,int y){
	int len = (int)(log(1.0*(y-x+1)) / log(2.0));
	return max(st[x][len], st[y-(1<<len)+1][len]);
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),st[i][0] = a[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]); 
	while(m --){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}

	return 0;
}


