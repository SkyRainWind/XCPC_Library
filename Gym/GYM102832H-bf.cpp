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

int n,m;
string s;
map<string,int>sg,vis;

signed main(){
	scanf("%d%d",&n,&m);
	queue<string>Q; 
	cin >> s;Q.push(s);
	sg[s] = vis[s] = 1;
	for(int i=1;i<=m;i++)cin >> s, sg[s] = vis[s] = 1, Q.push(s);
	while(!Q.empty()){
		string u = Q.front(); Q.pop();
		for(int i=1;)
	}

	return 0;
}

