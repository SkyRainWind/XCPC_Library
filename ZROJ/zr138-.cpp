// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f;
int n,m;
char s[222];
int in[223], out[233];
signed main(){
	freopen("zr138.in","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s",s + 1);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(s[i] == '1')swap(x, y);
		++ out[x];++ in[y]; 
	}
	for(int i=1;i<=n;i++)printf("%d %d %d\n",i,in[i],out[i]);

	return 0;
}

