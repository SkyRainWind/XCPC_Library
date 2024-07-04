// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int n;
char t[maxn], s[maxn];

struct AC{
	int lst[maxn];
	int tr[maxn][27],cnt;
	int val[maxn];	// 多少个以 i 结点结尾的单词 
	int fail[maxn];
	
	AC(){cnt=0;memset(val,0,sizeof val);}
	
	void insert(char *s){
		int p=0;
		int ns = strlen(s + 1);
		for(int i=1;i<=ns;i++){
			int k = s[i] - 'a';
			if(!tr[p][k])tr[p][k] = ++ cnt;
			p = tr[p][k];
		}
		++ val[p];
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
	
	void query(char *t){	// not forget to build
		int p=0, res=0;
		int nt = strlen(t + 1);
		for(int i=1;i<=nt;i++){
			p = tr[p][t[i] - 'a'];
			if(val[p])res += val[p], val[p] = 0;
			int v = lst[p];
			while(v){	// 沿失配边跳，加上abc bc c这种的匹配 
				if(val[v])res += val[v], val[v] = 0;
				v = lst[v];
			}
		}
		printf("%d\n",res);
	}
}ac;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s +1);
		ac.insert(s);
	}
	
	ac.build();
	scanf("%s", t+ 1);
	ac.query(t);

	return 0;
}
