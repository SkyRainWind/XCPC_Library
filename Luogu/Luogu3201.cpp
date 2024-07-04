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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e6+5;

int n,m,ans=1;
int a[100005];
int f[maxn];	// f[] 表示某个颜色当前的颜色 
int st[maxn],sz[maxn];	// st[i] 表示 i 颜色的开端在哪  sz[i] i 颜色的个数（启发式合并要用） 
int head[maxn],nxt[100005];

void merge(int x,int y){
	for(int i=head[x];i;i=nxt[i])ans -= (a[i+1] == y) + (a[i-1] == y);
	for(int i=head[x];i;i=nxt[i])a[i] = y;
	nxt[st[x]] = head[y];head[y] = head[x];
	sz[y] += sz[x];
	head[x] = st[x] = sz[x] = 0;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f[a[i]] = a[i];
	for(int i=1;i<=n;i++){
		if(!head[a[i]])st[a[i]]=i;
		nxt[i] = head[a[i]], head[a[i]] = i, ++ sz[a[i]];
		printf("%d %d %d\n",i,nxt[i],head[a[i]]);
	}
	for(int i=2;i<=n;i++)if(a[i] != a[i-1])++ ans;
	while(m --){
		int op;scanf("%d",&op);
		if(op == 2)printf("%d\n",ans);
		else{
			int x,y;scanf("%d%d",&x,&y);
			if(x == y)continue;
			if(sz[f[x]] > sz[f[y]])swap(f[x],f[y]);
			if(!sz[f[x]])continue;
			merge(f[x],f[y]);
		}
	}

	return 0;
}


