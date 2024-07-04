// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n,m;
char s[maxn],t[maxn];
struct trie{
	int tr[maxn][26];
	int vis[maxn * 5];
	int cnt=0;
	void insert(char *t){
		int len = strlen(t+1);
		int now = 0;
		for(int i=1;i<=len;i++){
			if(!tr[now][t[i] - 'a']){
				tr[now][t[i] - 'a'] = ++cnt;
			}
			now = tr[now][t[i] - 'a'];
		}
		vis[now] = len;
	}
}tr[2];

vector<int> query(char *t,int id,int bs){
	int nt=strlen(t+1);
	int now = 0;
	vector<int>vc;
	for(int i=id;i<=nt;i++){
		if(!tr[bs].tr[now][t[i] - 'a'])return vc;
		now = tr[bs].tr[now][t[i] - 'a'];
		if(tr[bs].vis[now]){
			vc.pb(tr[bs].vis[now]);
		}
	}
	return vc;
}

int dp[maxn][2];
signed main(){
	memset(dp,0x3f,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s + 1);
		tr[0].insert(s);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s + 1);
		tr[1].insert(s);
	}
	
	scanf("%s",t+1);
	int nt=strlen(t+1);
	dp[0][0] = dp[0][1] = 0;
	for(int i=1;i<=nt;i++){
		vector<int>v = query(t,i,1);
//		printf("! %d %d\n",i,v.size());
//		if(v.size())printf("?? %d\n",v[0]);
		for(int u : v)
			dp[i+u-1][1] = min(dp[i+u-1][1], dp[i-1][0] + 1);
		v = query(t,i,0);
		for(int u : v)
			dp[i+u-1][0] = min(dp[i+u-1][0], dp[i-1][1] + 1);
	}
//	printf("? %d\n",dp[4][0]);
	if(dp[nt][0] == INF && dp[nt][1] == INF)puts("-1");
	else printf("%d\n",min(dp[nt][0], dp[nt][1])); 

	return 0;
}

