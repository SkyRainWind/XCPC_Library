// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f;

int query(int x,int y){
	cout << "? " << x << ' ' << y << '\n';
	fflush(stdout);
	int r;
	cin >> r;
	return r;
}

void solve(){
	int n;
	cin>>n;
	int i=1,j=2;
	for(int x=3;x<=n;x++){
		int r1 = query(i,x), r2 = query(j, x);
		if(r1 > r2)j = x;
		else if(r1 < r2)i = x;
	}
	cout << "! " << i << ' ' << j << '\n';fflush(stdout);
	int r;cin >> r;
}

signed main(){
	int te;cin>>te;
	while(te--)solve();

	return 0;
}

