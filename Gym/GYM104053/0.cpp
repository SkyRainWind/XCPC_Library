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
int n,m;
int a[10005];
int cnt,ans=0;
void ck(){
	int ff=1;
	for(int i=1;i<=m;i++){
		int f=1;
		for(int j=1;j<=a[i];j++)f*=j;
		ff *= f;
	}
	ans += ff;
}
void dfs(int x){
	if(x==n+1){
		ck();
		return ;
	}
	for(int i=1;i<=m;i++){a[i]++;dfs(x+1);a[i]--;}
}
signed main(){
	scanf("%d%d",&n,&m);
	dfs(1);
	printf("%d\n",ans);

	return 0;
}

