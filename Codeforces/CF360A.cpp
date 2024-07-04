// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=5005;
int n,m,delt[maxn],a[maxn];
int up[maxn];
struct node{int op,x,y,z;};
vector<node>vc; 
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)up[i] = 1e9;
	for(int i=1;i<=m;i++){
		int op,x,y,z;scanf("%d%d%d%d",&op,&x,&y,&z);
		if(op == 1){
			for(int j=x;j<=y;j++)delt[j] += z;
		}else{
			for(int j=x;j<=y;j++)
				up[j] = min(up[j], z - delt[j]);
		}
		vc.push_back(node{op,x,y,z});
	}
	memcpy(a,up,sizeof up);
	for(node t : vc){
		int op,x,y,z;op=t.op,x=t.x,y=t.y,z=t.z;
		if(op == 1){
			for(int j=x;j<=y;j++)a[j] += z;
		}else{
			int r=-1e9;
			for(int j=x;j<=y;j++)
				r = max(r, a[j]);
			if(r != z)return puts("NO"), 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",up[i]);puts("");

	return 0;
}

