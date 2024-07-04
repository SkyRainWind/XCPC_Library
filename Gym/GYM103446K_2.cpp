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
vector<int> dfs(int n){
	if(n==2){
		return vector<int>{1,0};
	}
	if(n==6){
		return vector<int>{0,1,1,0,0,1};
	}
	if(n==7){
		return vector<int>{0,1,1,0,0,0,1}; 
	}
	vector<int>r,ans;
	r = dfs(n/2);
	ans = r;
	if(n%2==0){
		for(int i=r.size()-1;i>=0;i--)
			ans.pb(r[i]);
	}else{
		ans.pb(0);
		for(int i=r.size()-1;i>=0;i--)
			ans.pb(r[i]);
	}
	return ans;
}

signed main(){
	scanf("%d",&n);
	if(n==3){
		puts("Unlucky");
		return 0;
	}
	vector<int>res = dfs(n);
	for(auto it : res)printf("%d",it);puts("");

	return 0;
}

