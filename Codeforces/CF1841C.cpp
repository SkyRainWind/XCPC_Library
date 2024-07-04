// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

char s[maxn];
int suf[maxn];

int re(int i){int r=1;for(int j=0;j<i;j++)r*=10;return r;}

int getans(){
	vector<int>vis(7, 0); 
	int res = 0;
	int n = strlen(s + 1);
	for(int i=n;i>=1;i--){
		int op = s[i] - 'A', fg=0, sgn=1;
		for(int j=op+1;j<=4;j++)
			fg |= vis[j];
		if(fg)sgn = -1;
		
		res += sgn * re(s[i] - 'A');
		vis[s[i] - 'A'] = 1;
	}
	return res;
}

void solve(){
	vector<int>vis(7, 0);
	vector<int>pos(7, -1), rpos(7, -1);
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	suf[n+1] = 0;
	for(int i=n;i>=1;i--){
		int op = s[i] - 'A', fg=0, sgn = 1;
//		for(int j=op+1;j<=4;j++)fg |= vis[j];
//		if(fg)sgn = -1;
//		suf[i] = suf[i+1] + sgn * re(op);
		
		vis[op] = 1;
		if(pos[op] == -1)rpos[op] = i;
		pos[op] = i;
	}
	
	int ans = -2e9;
	
	for(int i=0;i<=4;i++)if(~pos[i]){
		int now = pos[i];
		for(int j=0;j<=4;j++){
			s[now] = j+'A';
			ans = max(ans, getans()); 
		}
		s[now] = i + 'A';
	}
	
	for(int i=0;i<=4;i++)if(~rpos[i]){
		int now = rpos[i];
		for(int j=0;j<=4;j++){
			s[now] = j+'A';
			ans = max(ans, getans()); 
		}
		s[now] = i + 'A';
	}
	
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

