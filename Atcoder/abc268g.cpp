// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5, mod = 998244353;
const int inv2 = (mod+1)/2;

int n;
char s[maxn];
struct trie{
	int tr[maxn][27], cnt = 0, pos[maxn*26], sz[maxn*26];
	int mp[maxn * 26];
	void insert(char *s,int id){
		int n=strlen(s+1);
		int p = 0;
		for(int i=1;i<=n;i++){
			int t = s[i] - 'a';
			if(!tr[p][t]){
				tr[p][t] = ++cnt;
			}
			p = tr[p][t];
		}
		++ pos[p];
		mp[p] = id;
	}
	
	int ans[maxn];
	void dfs(int x,int pref=0,int id=0){
//		printf("%d %d %d\n",x,pref,id);
		int p = x;
		sz[p] = pos[p];
		for(int i=0;i<26;i++)if(tr[p][i]){
			dfs(tr[p][i], pref+pos[p], mp[tr[p][i]]?mp[tr[p][i]]:0);
			sz[p] += sz[tr[p][i]];
		}
//		printf("? %d %d %d   %d %d\n",p,id,sz[p],(n-pref-sz[p]),pref);
		if(id)(ans[id] = 1ll*(n-pref-sz[p])*inv2%mod + (pref)%mod + 1) %= mod; 
	}
}tr;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s +1);
		tr.insert(s, i);
	}
	tr.dfs(0);
	for(int i=1;i<=n;i++)printf("%d\n",tr.ans[i]);

	return 0;
}

