// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n;
struct node{
	int op,v,k;
}a[maxn];
unordered_set<int>mp;

int dfs(int r,int k){
//	printf("qwq %d %d\n",r,k);
	if(k == n+1)return 1;
	if(mp.count(r*10001+k))return 0;
	mp.insert(r*10001+k);
	
	if(a[k].op==1)return dfs((r+a[k].v)%256,k+1);
	else if(a[k].op==2)return (r==a[k].v ? dfs(r,a[k].k) : dfs(r,k+1));
	else if(a[k].op==3)return (r!=a[k].v ? dfs(r,a[k].k) : dfs(r,k+1));
	else if(a[k].op==4)return (r<a[k].v ? dfs(r,a[k].k) : dfs(r,k+1));
	else return (r>a[k].v ? dfs(r,a[k].k) : dfs(r,k+1));
}

void solve(){
	mp.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int v;char op[7];scanf("%s",op+1);scanf("%d",&v);
		if(op[1]=='a'){
			a[i] = node{1,v,0};
		}else if(op[2]=='e'){
			int k;scanf("%d",&k);
			a[i] = node{2,v,k};
		}else if(op[2]=='n'){
			int k;scanf("%d",&k);
			a[i] = node{3,v,k};
		}else if(op[2]=='l'){
			int k;scanf("%d",&k);
			a[i] = node{4,v,k};
		}else{
			int k;scanf("%d",&k);
			a[i] = node{5,v,k};
		}
	}
	
	int t = dfs(0,1);
	puts(t ? "Yes" : "No");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

