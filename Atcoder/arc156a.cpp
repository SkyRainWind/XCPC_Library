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

int n;
int solve(){
	string s;
	cin>>n>>s;
	int r=0;
	for(int i=0;i<n;i++)
		r += s[i]-'0';
	if(r&1)return -1;
	
	if(r>=4)return r/2;
	if(r==0)return 0;
	
	int gg=0;
	for(int i=0;i<n-1;i++)
		if(s[i] == s[i+1] && s[i] == '1')gg=1;
	if(!gg)return 1;
	if(n==3)return -1;
	if(n==4 && s=="0110")return 3;
	return 2;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int te;cin>>te;
	while(te--)cout << solve() << '\n';

	return 0;
}

