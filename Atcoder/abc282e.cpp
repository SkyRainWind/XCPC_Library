// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,m,fa[maxn],a[maxn];

int find(int x){return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
struct node{int i,j,v;}e[maxn];
int tot=0; 
int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%m*x%m;
	return 1ll*mid*mid%m;
}
int cmp(node a,node b){return a.v>b.v;}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			e[++tot] = node{i,j,((pw(a[i],a[j])+pw(a[j],a[i]))%m)};
	sort(e+1,e+tot+1,cmp);
	LL ans = 0;
	for(int i=1;i<=tot;i++){
		int x=e[i].i,y=e[i].j;
		x = find(x), y = find(y);
		if(x != y){
			fa[x] = y;
			ans += e[i].v;
		}
	}
	printf("%lld\n",ans);

	return 0;
}

