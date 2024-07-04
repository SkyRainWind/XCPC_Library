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
	string s;cin>>s;
	int fg=1;
	for(int i=1;i<s.size();i++)
		fg &= s[i] == s[i-1];
	if(fg)printf("%d\n",s.size()-1);
	else puts("0");

	return 0;
}

