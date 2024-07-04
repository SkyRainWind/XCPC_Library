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
set<string>S;
string s[12];
int vis[12];

void dfs(int x,int rem,string now=""){
	if(x == n+1){
		if(now.size()<3||now.size()>16)return ;
		if(S.count(now))return ;
		cout << now << '\n';
		exit(0);
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i] = 1;
		string nn = now+s[i];
		if(x==n)dfs(x+1,rem,nn);
		else{
			for(int un=1;un<=rem;un++)if(un+n-x-1<=rem){
				nn = nn + '_';
				dfs(x+1,rem-un,nn);
			}
		}
		vis[i] = 0;
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	int sz = 0;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		sz += s[i].size();
	}
	for(int i=0;i<m;i++){
		string t;
		cin >>t;
		S.insert(t);
	}
	dfs(1,16-sz,"");
	puts("-1");

	return 0;
}

