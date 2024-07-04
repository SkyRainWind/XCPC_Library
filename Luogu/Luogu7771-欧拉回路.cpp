// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;
// O(n+m)

int n,m;
vector<int>g[maxn];

struct edges{
	int to,next;
}ed[maxn<<1];
int head[maxn],ecnt=0;
void add(int x,int y){
	ed[++ecnt].to=y;
	ed[ecnt].next=head[x];
	head[x]=ecnt;
}

namespace di_euler_path{	// 有向图欧拉路径
	int in[maxn],hd[maxn];
	int st[maxn], tp;
	void dfs(int id){
		for(int &i = hd[id];i<g[id].size();)dfs(g[id][i++]);
		st[++ tp] = id;
	}
	
	void main(){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int x,y;scanf("%d%d",&x,&y);
			g[x].push_back(y);++ in[y];
		}
		
		int lst = 0;
		for(int i=1;i<=n;i++){
			sort(g[i].begin(), g[i].end());	// 字典序最小的路径
			// !!!!!!!!! g[i].size() 是 unsigned 类型，如果出现负数的话会变成大数 
			if(abs((int)g[i].size() - in[i]) > 1){puts("No");return ;}
			if(g[i].size() > in[i]){
				if(lst){puts("No");return ;}
				else lst = i;
			}
		}
		
		dfs(lst ? lst : 1);
		if(tp != m+1)puts("No");
		else{
			reverse(st+1,st+tp+1);
			for(int i=1;i<=tp;i++)printf("%d ",st[i]);
			puts("");
		}
	}
}

namespace undirected_euler{
	int de[maxn];
	int ans[maxn<<1],acnt=0;
	int vis[maxn<<1];	// 注意 vis 记录的是边，双向边需开2倍 
	
	void euler_un(int x){	// 当前搜到 x 号点 
		for(;head[x]!=-1;){
			int curedge=head[x];		// 一条边解决了之后就相当于删掉 
			head[x]=ed[curedge].next; 
			
			if(!vis[curedge]){
				vis[curedge]=vis[curedge^1]=1;	// 两条无向边拆成的边都不能走 
				euler_un(ed[curedge].to);
				if(curedge&1)ans[++acnt]=-(curedge>>1);	// 对应的是同一条无向边（因为无向，所以有2倍边） 
				else ans[++acnt]=((curedge>>1));
			}
		}
	}
	
	void undirect(){
		memset(head,-1,sizeof head);
		scanf("%d%d",&n,&m);
		ecnt=1;			// 确保无向边的标号都是 2&3  4&5 .. 这样 
		int x=0,y=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			add(y,x);add(x,y);	// 注意加边顺序！否则会引起正负方向相反 
			++de[x];++de[y];
		} 
		for(int i=1;i<=n;i++)	// 度数一定是偶数 
			if(de[i]%2!=0)return (void)puts("NO");
		euler_un(x);
		
		if(acnt!=m){	// 加的边数没到m，显然不行 
			return (void)puts("NO");
		}
		puts("YES");
		for(int i=1;i<=acnt;i++)printf("%d ",ans[i]);
		puts("");
	}
}

namespace directed_euler{
	int ans[maxn<<1],acnt=0;
	int vis[maxn<<1];	// 注意 vis 记录的是边，双向边需开2倍 
	int in[maxn],out[maxn];
	
	void euler_di(int x){
		for(;head[x]!=-1;){
			int curedge=head[x];
			head[x]=ed[curedge].next;
			
			if(!vis[curedge]){
				vis[curedge]=1;
				euler_di(ed[curedge].to);
				ans[++acnt]=curedge;
			}
		}
	}
	
	void direct(){	// 有向图同理 
		memset(head,-1,sizeof head);
		scanf("%d%d",&n,&m);
		
		int x=0,y=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			add(y,x);++out[x];++in[y];
		}
		for(int i=1;i<=n;i++)	// 只需要判断出度入度是否相等 
			if(in[i]!=out[i])return (void)puts("NO");
		euler_di(x);
		
		if(acnt!=m)return (void)puts("NO");
		puts("YES");
		for(int i=1;i<=acnt;i++)printf("%d ",ans[i]); 
		puts("");
	}
}

int main(){
	int kas;
	scanf("%d",&kas);
	if(kas==1)undirected_euler::undirect();
	else directed_euler::direct();

	return 0;
}

