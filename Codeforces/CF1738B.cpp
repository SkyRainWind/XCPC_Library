// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

void solve(){
	vector<int>vc;vc.clear();
	int n;scanf("%d",&n);
	int gg=0;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if(i == 1)vc.push_back(x);
		else{
			int lst = vc[vc.size() - 1];
			if(x > 0 && lst - x >= 0){
				gg=1;
			}else vc.push_back(x + lst);
		}
	}
	if(gg){puts("-1");return ;}
	for(int i : vc)printf("%d ",i);puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

