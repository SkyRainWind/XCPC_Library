// by SkyRainWind
#include <cstdio>
#include <vector>
#include <map> 
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
char t[maxn], s[152][maxn];

struct AC{
	int lst[maxn];
	int tr[maxn][27],cnt;
	int val[maxn];	// 多少个以 i 结点结尾的单词 
	int fail[maxn];
	map<int,int>end;	// 无重复的串，end[p]=id trie上p号点到根代表第 id 个字符串 
	map<int,int>cou;
	
	void clear(){
		cnt=0;memset(lst,0,sizeof lst);memset(fail,0,sizeof fail);
		end.clear();cou.clear();memset(tr,0,sizeof val);memset(val,0,sizeof val);
	}
	
	void insert(char *s,int id){
		int p=0;
		int ns = strlen(s + 1);
		for(int i=1;i<=ns;i++){
			int k = s[i] - 'a';
			if(!tr[p][k])tr[p][k] = ++ cnt;
			p = tr[p][k];
		}
		++ val[p];
//		printf("map : %d -> %d\n",p,id); 
		end[p] = id;
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
			if(val[p]){
				res += val[p];
				++ cou[p];
			}
			int v = lst[p];
			while(v){	// 沿失配边跳，加上abc bc c这种的匹配 
				if(val[v]){
					res += val[v];
					++ cou[v];
				}
				v = lst[v];
			}
		}
		int mx = -1e9;
		vector<int> ansid;
		for(auto it : cou){
			if(mx < it.second){
				ansid.clear();
				mx = it.second, ansid.push_back(it.first);
			}else if(mx == it.second)ansid.push_back(it.first);
//			printf("%d %d\n",it.first,it.second);
		}
		printf("%d\n",mx);
		for(int u : ansid)
			printf("%s\n",s[end[u]] + 1);
//		printf("%d\n",res);
	}
}ac;

signed main(){
	while(scanf("%d",&n), n){
		ac.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i] +1);
			ac.insert(s[i], i);
		}
		
		ac.build();
		scanf("%s", t+ 1);
		ac.query(t);
	}

	return 0;
}

