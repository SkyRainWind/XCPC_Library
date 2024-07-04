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

map<string,int>mp;
map<int,string>to; 

void solve(){
	int y1,m1,d1;
	int y2,m2,d2;
	string s;
	cin>>y1>>m1>>d1>>s;
	int now = mp[s];
	cin>>y2>>m2>>d2;
	ll t1 = y1*360ll + (m1-1)*30ll + d1;
	ll t2 = y2*360ll + (m2-1)*30ll + d2;
	ll dt = t2 -t1;dt %= 5;
	if(dt > 0){
		now += dt;
		if(now > 5)now -= 5;
		cout << to[now] << '\n';
	}else{
		now += dt;
		if(now <= 0)now += 5;
		cout << to[now] << '\n';
	}
}

signed main(){
	mp["Monday"] = 1;
	mp["Tuesday"] = 2;
	mp["Wednesday"] = 3;
	mp["Thursday"] = 4;
	mp["Friday"] = 5;
	to[1]="Monday";
	to[2]="Tuesday";
	to[3]="Wednesday";
	to[4]="Thursday";
	to[5]="Friday";
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

