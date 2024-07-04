// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n;
string s[maxn];
int sum[maxn],sum2[maxn],id[maxn];

signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		id[i] = i;
		cin>>s[i];
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]=='X')++sum[i];
			else sum2[i]+=s[i][j]-'0';
		}
	}
	sort(id+1,id+n+1,[&](int x,int y){
		return 1ll*sum[x]*sum2[y]>1ll*sum[y]*sum2[x];
	});
	int cx = 0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		string nt = s[id[i]];
		for(int j=0;j<nt.size();j++){
			if(nt[j] == 'X')++cx;
			else{
				ans += 1ll*cx*(nt[j]-'0');
			}
		}
	}
	cout << ans << '\n';

	return 0;
}

