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
map<string,int>mp;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		int te;cin>>te;
		int fg = 0;
		vector<string>vb;
		while(te--){
			string str;
			cin >> str;
			int gg=0;
			for(int i=0;i+2<str.size();i++){
				if(str[i] == 'b' && str[i+1] == 'i' && str[i+2] == 'e'){gg=1;break;}
			}
			if(gg){
				if(mp.count(str))continue;
				mp[str] = 1;
				fg = 1;
				vb.pb(str);
			}
		}
		if(vb.size() == 0)cout << "Time to play Genshin Impact, Teacher Rice!" << '\n';
		else
			for(auto it : vb)cout << it << '\n';
	}

	return 0;
}

