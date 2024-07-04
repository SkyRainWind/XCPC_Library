// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2005;

int n;
int s[maxn], t[maxn];
vector<int>ans;

void ml(int x,int del){
	ans.pb(del);
	for(int i=del+1-del;i+del<=n;i++){
		s[i] ^= s[i+del];
	}
}

void mr(int x,int del){
	ans.pb(-del);
	for(int i=n;i>=1+del;i--){
		s[i] ^= s[i-del];
	}
}

void solve(){
	ans.clear();
	vector<int>v1,v2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		if(s[i])v1.pb(i);
	}
	for(int i=1;i<=n;i++){
		scanf("%1d",&t[i]);
		if(t[i])v2.pb(i);
	}
	if(v1.size()==0||v2.size()==0){
		if(v1.size()+v2.size()==0)puts("0");
		else puts("-1");
		return ;
	}
	
	if(v1[0] != v2[0]){
		if(v1[0] > v2[0])ml(v1[0], v1[0] - v2[0]);
		else{
			for(int i=v1[0]+1;i<=v2[0];i++){
				if(!s[i])mr(v1[0], i-v1[0]);
			}
			int ff = -1,gg;
			for(int i=n;;i--)if(s[i]==1){gg=i;break;}
			for(int i=v1[0]-1;i>=1;i--){
				if(!s[i])ml(gg,gg-i);
			}
			for(int i=v2[0]+1;i<=n;i++)if(s[i]==0){ff=i;break;}
			if(ff==-1){
				ml(n-(v2[0]-1)+1,n-(v2[0]-1));
			}else{
				int dist = ff - v2[0];
				ml(dist + 1, dist);
			}
		}
	}
	for(int i=v2[0]+1;i<=n;i++){
		if(s[i]==t[i])continue;
		mr(v2[0],i-v2[0]);
	}
	
	printf("%d\n",ans.size());
	for(int it : ans)printf("%d ",it);
	if(ans.size())puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

