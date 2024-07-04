// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n, m;
char t[maxn], s[maxn];

struct AC{
	int lst[maxn];
	int tr[maxn][27],cnt;
	int val[maxn];	
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
		val[p] = ns;
	}
	
	void build(){
		queue<int>Q;
		Q.push(0);
		while(!Q.empty()){
			int u = Q.front();Q.pop();
			for(int i=0;i<26;i++)
				if(tr[u][i]){	// 如果 tr[u][i] 这个模式串前缀确实存在 
					// 这里相当于是路径压缩，因为 tr[fail[u]][i] 相当于已经是构建好的 trie图了，因此直接连就行了 
					fail[tr[u][i]] = u ? tr[fail[u]][i] : 0;
		/*
		lst[] 代表这个点为后缀的能匹配的下一个字符串位置
		如 当前点代表的是 abcd,而模式串是 abcd bcd cd那么 lst[abcd] -> bcd, lst[bcd] -> cd，这两个是为了能够计数才没有路径压缩
		lst[cd] -> lst[d]，这里是路径压缩因为 d 这个后缀没有用处 
		*/
					if(val[fail[tr[u][i]]])lst[tr[u][i]] = fail[tr[u][i]];
					else lst[tr[u][i]] = lst[fail[tr[u][i]]];
					
					Q.push(tr[u][i]);
				}else tr[u][i] = tr[fail[u]][i];
				// 构建 trie图，tr[u][i] 不存在 就将其链接到 fail[u] 看看 fail[u] 有没有 i 这个儿子 
		}
	}
	
	int stk[maxn], tp = 0;
	char stkk[maxn];
	void query(char *t){
		int p=0, res=0;
		int nt = strlen(t + 1);
		for(int i=1;i<=nt;i++){
			p = tr[p][t[i] - 'a'];
			stk[++ tp] = p;
			stkk[tp] = t[i];
			if(val[p]){
				tp -= val[p];
				p = stk[tp];
				continue;
			}
		}
		for(int i=1;i<=tp;i++)putchar(stkk[i]);puts("");
	}
}ac;

signed main(){
	scanf("%s",t + 1);
	n = strlen(t+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s + 1);
		ac.insert(s);
	}
	ac.build();
	
	ac.query(t);

	return 0;
}

