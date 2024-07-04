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
	int te;scanf("%d",&te);
	while(te--){
		int n,k;scanf("%d%d",&n,&k);
		int r=n;
		while(k --){
			r=(r+1)/2;
			if(r==1||r==0)break;
		}
		printf("%d\n",r);
	}

	return 0;
}

