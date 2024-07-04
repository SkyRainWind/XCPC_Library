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
map<pii,int>mp;

namespace un_euler_path{
	int de[maxn];
	int ans[maxn<<1],acnt=0;
	int vis[maxn<<1];	// ע�� vis ��¼���Ǳߣ�˫����迪2�� 
	int hd[maxn];
	
	void euler_un(int x){	// ��ǰ�ѵ� x �ŵ� 
		while(1){
			for(;hd[x]<g[x].size() && !mp[mpr(x,g[x][hd[x]])];)++ hd[x];
			if(hd[x] >= g[x].size())break;
			int v = g[x][hd[x]];
			-- mp[mpr(x, v)];
			-- mp[mpr(v, x)];
			++ hd[x];
			euler_un(v);
		}
		ans[++ acnt] = x;
	}
	
	void undirect(){	// ���δ��֤ŷ��·��һ�����ڣ�����Ҫ�ж��Ƿ�ֻ��2��/0�� ��㣬���յ�·��top �Ƿ�Ϊm 
		memset(hd,0,sizeof hd);
		scanf("%d",&m);
		int n = 500, st = 500;
		for(int i=1;i<=m;i++){
			int x,y;scanf("%d%d",&x,&y);
			g[x].push_back(y), g[y].push_back(x);
			++de[x];++de[y];
			++ mp[mpr(x, y)]; ++ mp[mpr(y, x)];
			st = min(st, min(x, y));
		} 
		for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
		for(int i=1;i<=n;i++){
			if(de[i]&1){
				st = i;
				break;
			}
		}
		
		euler_un(st);
		
//		if(acnt!=m)	// �ӵı���û��m����Ȼ���� 
//			return (void)puts("NO");
		for(int i=acnt;i>=1;i--)printf("%d\n",ans[i]);
	}
}

int main(){
	un_euler_path::undirect();

	return 0;
}

