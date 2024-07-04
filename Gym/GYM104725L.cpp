// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=233;

int n,m,k;
int b[maxn];

struct node{
	int i,j,op,a,b,d,v;
}a[maxn];
ll ans=0;

void ck(){
	ll res=0;
	for(int i=1;i<=m;i++)
		if(a[i].op==0){if(a[i].a*b[a[i].i]+a[i].b*b[a[i].j]<=a[i].d)res+=a[i].v;}
		else{if(a[i].a*b[a[i].i]+a[i].b*b[a[i].j]>=a[i].d)res+=a[i].v;}
	ans=max(ans,res);
}

void dfs(int x){
	if(x == n+1){
		ck();
		return ;
	}
	for(int i=0;i<=k;i++)b[x]=i,dfs(x+1);
}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)cin>>a[i].i>>a[i].j>>a[i].op>>a[i].a>>a[i].b>>a[i].d>>a[i].v;
	dfs(1);
	cout<<ans<<'\n';

	return 0;
}

