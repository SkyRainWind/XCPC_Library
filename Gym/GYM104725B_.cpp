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

int f(int x,int y){return (x-566)*(x-566)+(y-398)*(y-398);}

signed main(){
	while(1){
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",f(x,y));
	}

	return 0;
}

