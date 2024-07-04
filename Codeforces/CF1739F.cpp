// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 200005;

struct AC{
	int lst[maxn];
	int tr[maxn][27],cnt;
	int val[maxn];	// 多少个以 i 结点结尾的单词 
	int fail[maxn];
	
	AC(){cnt=0;memset(val,0,sizeof val);}
	
	void insert(string s,int vv){
		int p=0;
		int ns = s.size();
		for(int i=0;i<ns;i++){
			int k = s[i] - 'a';
			if(!tr[p][k])tr[p][k] = ++ cnt;
			p = tr[p][k];
		}
		val[p] += vv;
	}
	
	void build(){
		queue<int>Q;
		Q.push(0);
		while(!Q.empty()){
			int u = Q.front();Q.pop();
			for(int i=0;i<12;i++)
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
char ts[maxn];
vector<int>g[14];
string re;
int n;
int dp[(1<<12) + 5][(1<<12) + 5];
pii pt[(1<<12) + 5][(1<<12) + 5];

void dfs(int x,int lst=0){
	re += x + 'a' - 1;
	for(int u : g[x])if(u != lst){
		dfs(u, x);
	}
}

void print(int S,int arg){
//	printf("? %d %d\n",S,arg);
	if(S == 0)return ;
	pii now = pt[S][arg];
	print(S ^ (1 << now.first), now.second);
	printf("%c",now.first + 'a');
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int val;
		scanf("%d",&val);
		scanf("%s",ts + 1);
		int nt = strlen(ts + 1);
		int de[17];memset(de,0,sizeof de);
		int mt[14][14];memset(mt,0,sizeof mt);
		for(int i=1;i<=12;i++)g[i].clear();
		re = "";
		
		for(int i=2;i<=nt;i++){
			int f1 = ts[i-1] - 'a' + 1;
			int f2 = ts[i] - 'a' + 1;
			if(mt[f1][f2])continue;
			mt[f1][f2] = mt[f2][f1] = 1;
			++ de[f1], ++ de[f2];
			g[f1].pb(f2), g[f2].pb(f1);
		}
		int gg = 0;
		for(int i=1;i<=12;i++)
			if(de[i] >= 3){
				gg = 1;
				break;
			}
		if(gg)continue;

		for(int i=1;i<=12;i++){
			if(de[i] == 1){
				dfs(i);
				break;
			}
		}
		if(!re.size())continue;
		
		ac.insert(re, val);
		reverse(re.begin(), re.end());
		ac.insert(re, val);
	}
	ac.build();
	
	memset(dp,-0x3f,sizeof dp);
	dp[0][0] = 0;
	
	for(int S=0;S<(1<<12);S++){
		for(int i=0;i<12;i++)if((S&(1<<i)) == 0){
			for(int j=0;j<=ac.cnt;j++){
				int p = ac.tr[j][i], v = 0;
				while(p){
					v += ac.val[p];
					p = ac.lst[p];
				}
				if(dp[S | (1<<i)][ac.tr[j][i]] < dp[S][j] + v){
					dp[S | (1<<i)][ac.tr[j][i]] = dp[S][j] + v;
					pt[S | (1<<i)][ac.tr[j][i]] = mpr(i, j);
				}
			}
		}
	}
	
	int mx = -1e9, arg;
	for(int i=0;i<=ac.cnt;i++)
		if(dp[(1<<12)-1][i] > mx){
			mx = dp[(1 << 12)-1][i];
			arg = i;
		}

	print((1<<12)-1, arg);
	puts("");

	return 0;
}

