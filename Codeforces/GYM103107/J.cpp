// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int>a(n+2,0),b(n+2,0);
	int cc=0;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		++a[x],++b[y];
		if(a[x]==n)++cc;
		if(b[y]==n)++cc;
	}
	if(cc)printf("%d\n",n-1);
	else printf("%d\n",n);
	
	return 0;
}

