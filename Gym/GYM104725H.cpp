// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5, mod=1e9+7;

vector<int>res[maxn];
struct segm{
	int lazy;
	int sum;
}se[maxn << 2];

void build(int l,int r,int num){
	se[num].lazy = se[num].sum = 0;
	if(l==r)return ;
	int mid=l+r>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
}

void pushdown(int num,int l,int r){
	if(!se[num].lazy)return ;
	int mid=l+r>>1;
	
	int t=se[num].lazy;
	se[num << 1].lazy = t;se[num << 1].sum += (mid-l+1);
	se[num << 1|1].lazy = t;se[num << 1|1].sum += (r-mid);
	
	se[num].lazy = 0;
}

void update(int x,int y,int l,int r,int num){
	if(x<=l&&r<=y){
		se[num].lazy ++;
		se[num].sum += r-l+1;
		return ;
	}
	int mid = l+r>>1;
	if(y<=mid)update(x,y,l,mid,num<<1);
	else if(x>mid)update(x,y,mid+1,r,num<<1|1);
	else update(x,y,l,mid,num<<1), update(x,y,mid+1,r,num<<1|1);
	se[num].sum = se[num << 1].sum + se[num<<1|1].sum;
}

int query(int x,int y,int l,int r,int num){
	if(x<=l&&r<=y)return se[num].sum;
	int mid=l+r>>1;
	pushdown(num,l,r);
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return query(x,y,l,mid,num<<1) + query(x,y,mid+1,r,num<<1|1);
}

struct AC{
	int lst[maxn];
	int tr[maxn][27],cnt;
	vector<int> val[maxn];	// 多少个以 i 结点结尾的单词 
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
		val[p].pb(ns);
	}
	
	void build(){
		queue<int>Q;
		Q.push(0);
		while(!Q.empty()){
			int u = Q.front();Q.pop();
			for(int i=0;i<26;i++)
				if(tr[u][i]){
					fail[tr[u][i]] = u ? tr[fail[u]][i] : 0;
					if(val[fail[tr[u][i]]].size())lst[tr[u][i]] = fail[tr[u][i]];
					else lst[tr[u][i]] = lst[fail[tr[u][i]]];
					
					Q.push(tr[u][i]);
				}else tr[u][i] = tr[fail[u]][i];
		}
	}
	
	void query(char *t){	// not forget to build
		int p=0;
		int nt = strlen(t + 1);
		for(int i=1;i<=nt;i++){
			p = tr[p][t[i] - 'a'];
			for(auto it : val[p]){
				res[i-it+1].pb(i);
			}
			int v = lst[p];
			while(v){	// 沿失配边跳，加上abc bc c这种的匹配 
				for(auto it : val[v]){
					res[i-it+1].pb(i);
				}
				v = lst[v];
			}
		}
	}
}ac;
char s[maxn],t[maxn];

signed main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		ac.insert(s);
	}
	ac.build();
	for(int i=1;i<=m;i++){
		scanf("%s",t+1);
		int nt = strlen(t+1);
//		build(1,nt,1);
		ac.query(t);
		ll ans=0,sum=0;
		for(int i=nt;i>=1;i--){
			for(auto it : res[i]){
//				update(i,it,1,nt,1);
//				printf("qw %d %d\n",i,it);
				sum += nt-it+1;
				sum %= mod;
			}
			ans += sum, ans %= mod;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=nt;i++)res[i].clear();
	}

	return 0;
}

