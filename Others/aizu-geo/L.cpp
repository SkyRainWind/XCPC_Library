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
	if(n<=2*m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j == m-(i+1)/2+1)printf("%.10f ",1.0);
				else printf("%.10f ",0.0);
			}
			puts("");
		}
	}else{
		for(int i=1;i<=2*m;i++){
			for(int j=1;j<=m;j++){
				if(j == m-(i+1)/2+1)printf("%.10f ",1.0);
				else printf("%.10f ",0.0);
			}
			puts("");
		}
		for(int i=1+2*m;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j == m)printf("%.10f ",1.0);
				else printf("%.10f ",0.0);
			}
			puts("");
		}
	}

	return 0;
}

