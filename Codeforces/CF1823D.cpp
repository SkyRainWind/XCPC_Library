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

int n,k;

void solve(){
	cin >> n >> k;
	vector<pii>con(k+2);
	for(int i=1;i<=k;i++)cin >> con[i].first;
	for(int i=1;i<=k;i++)cin >> con[i].second;
	
	con[0] = mpr(0,0);
	if(con[k].first != n){
		con[k+1] = mpr(n, con[k].second);++ k;
	}
	
	for(int i=1;i<=k;i++){
		int dx = con[i].first - con[i-1].first, dy = con[i].second - con[i-1].second;
		if(dy > dx){
			cout << "NO\n";
			return ;
		}
	}
	
	char ch = 'd';
	int tt=0;
	string s = "abc";
	for(int i=0;i<k;i++){
		int t1 = (con[i+1].first - con[i].first);
		if(i == 0)t1 -= 3;
		int t2 = (con[i+1].second - con[i].second);
		if(i == 0)t2 -= 3;
		t1 -= t2;
		while(t2 --){
			s += ch;
		}
//		cout << "QQ " << s << '\n';
		
		while(t1 --){
			s += s[tt++];
			if(tt >= 3)tt -= 3;
		}
		ch ++;
	}
	cout << "YES" << '\n';
	cout << s << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	int te;cin >> te;
	while(te --)solve();

	return 0;
}

