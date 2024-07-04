// by SkyRainWind
#include <cstdio>
#include <vector>
#include <queue>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5 + 5;

int n,m;
char s[100005];
LL dis[205][205];

struct AC{
	int lst[maxn*26];
	int tr[maxn][27], dep[maxn*26];
	vector<int>str2id[maxn];
	int cnt;
	int val[maxn*26];	// 多少个以 i 结点结尾的单词 
	int fail[maxn*26];
	int lstt[maxn];
	
	AC(){cnt=0;memset(val,0,sizeof val);}
	
	void insert(char *s, int id){
		int p=0;
		int ns = strlen(s + 1);
		for(int i=1;i<=ns;i++){
			int k = s[i] - 'a';
			if(!tr[p][k])tr[p][k] = ++ cnt, dep[cnt] = i;
			str2id[tr[p][k]].push_back(id);
			p = tr[p][k];
		}
		val[p]++;
		lstt[id] = p;
	}
	
	void build(){
		queue<int>Q;
		Q.push(0);
		while(!Q.empty()){
			int u = Q.front();Q.pop();
			for(int i=0;i<26;i++)
				if(tr[u][i]){
					fail[tr[u][i]] = u ? tr[fail[u]][i] : 0;
					if(val[fail[tr[u][i]]])lst[tr[u][i]] = fail[tr[u][i]];
					else lst[tr[u][i]] = lst[fail[tr[u][i]]];
					
					Q.push(tr[u][i]);
				}else tr[u][i] = tr[fail[u]][i];
		}
	}
}ac;

struct mat{
	LL a[205][205];
	mat(){memset(a,63,sizeof a);}
};
mat operator * (mat a, mat b){
	mat c;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				c.a[i][k] = min(c.a[i][k], a.a[i][j] + b.a[j][k]);
	return c;
}

mat a;
void pw(int b){
	mat base = a;
	while(b){
		if(b&1)a = a * base;
		base = base * base;
		b >>= 1;
	}
}

signed main(){
//	freopen("cho3.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s", s+ 1);
		ac.insert(s, i);
		dis[0][i] = strlen(s + 1);
	}
	ac.build(); 
	for(int i=1;i<=n;i++){
		// lstt[i] -> lst[lstt[i]]
		int p = ac.fail[ac.lstt[i]];
		while(p){
			for(int curv : ac.str2id[p]){
				dis[i][curv] = max(dis[i][curv], (LL)ac.dep[p]);
			}
			p = ac.fail[p];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[i][j] = dis[0][j] - dis[i][j];
		dis[i][0] = 1e18;
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)a.a[i][j] = dis[i][j];
	a.a[0][0] = 1e18;
	pw(m-1);
	LL ans = 1e18;
	for(int i=1;i<=n;i++)ans = min(ans, a.a[0][i]);
	printf("%lld\n",ans);

	return 0;
}

