// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){int n;
	scanf("%d",&n);
	multiset<int>t;
	int res = n;
	for(int i=1;;){
		res -= i;
		t.insert(i);
		i <<= 1;
		if(res < i)break;
	}
	if(res){
		if(res == 1)t.insert(1);
//		else t.insert(1),t.insert(res-1);
		else if(t.find(res) != t.end()){
			t.erase(t.find(res));
			t.insert(res-1);t.insert(res+1);
		}else t.insert(res);
	}
	printf("%d\n",t.size());
	for(int u : t)printf("%d ",u);

	return 0;
}

