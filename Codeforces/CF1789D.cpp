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

void solve(){
	int ss=0,fir,ts=0;
	vector<int>ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		if(s[i]){
			++ss;
			fir = i;
		}
	}
	for(int i=1;i<=n;i++)scanf("%1d",&t[i]), ts += t[i];
	if(ts==0){
		if(ss==0)puts("0");
		else puts("-1");
		return ;
	}
	if(ss==1){
		if(s[fir] != t[fir]){
			for(int i=1;i<=n;i++)if(i!=fir&&t[i]==1){
				s[i] = 1;
				ans.pb(fir-i);
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(s[i] == t[i])continue;
		int now = s[i];
		
		int lst = 0;
		for(int j=1;j<=i-1;j++){
			if(s[j] == 1){lst = j;break;}
		}
		if(lst){
			int dist = i - lst;
			for(int j=n;j>=i;j--){
				int to = j-dist;
				s[j] ^= s[to];
			}
			ans.pb(-dist);
			continue;
		}
		
		int fs = -1;
		for(int j=i+1;j<=n;j++)
			if(s[j] == 1){fs = j;break;}
		int dist = fs - i;
		if(fs ==-1 || (i - dist >= 1 && s[i]==1)){
			puts("-1");
			return ;
		}
		ans.pb(dist);
		for(int j=fs;j<=n;j++){
			int to = j-dist;
			s[to] ^= s[j]; 
		}
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

