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
	set<int>S;
	int a=9,b=12,m=15; 
	for(int x=1;x<=100;x++)
		for(int y=1;y<=100;y++)
			S.insert((a*x+b*y)%m);
	for(auto it:S)printf("%d\n",it);

	return 0;
}

