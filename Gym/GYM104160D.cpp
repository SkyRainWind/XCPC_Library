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
	string s;
	cin>>s;
	int d=0,t=0;
	for(int i=0;i<5;i++)
		if(s[i]=='D')++d;
		else if(s[i]=='T')++t;
	if(d==3)puts("DRX");
	else puts("T1");

	return 0;
}

