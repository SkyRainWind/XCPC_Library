// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=1e6+5;

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
	
	void query(char *t){
		int p=0, res=0;
		int nt = strlen(t + 1);
		for(int i=1;i<=nt;i++){
			p = tr[p][t[i] - 'a'];
			int fg = 0;
			if(val[p]){
				fg = 1;
			}
			
			int v = lst[p];
			while(v){	// 沿失配边跳，加上abc bc c这种的匹配 
				if(val[v]){
					fg = 1;
				}
				v = lst[v];
			}
			if(fg){
				++ res;
				p = 0;
			}
		}
		printf("%d\n",res);
	}
}ac;
char s[maxn],t[maxn];
int n;

signed main(){
	scanf("%s",t+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s +1);
		ac.insert(s);
	}
	ac.build();
	ac.query(t);

	return 0;
}

