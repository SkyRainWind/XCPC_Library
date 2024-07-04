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
char s[200005];
int st[200005],tp;
int rr[200005];

void dfs(int l,int r){
	if(l > r)return ;
	if(s[l] == '('){
		int to = rr[l];
		dfs(l+1, to-1);
		printf("%d %d ",to,l);
		dfs(to+1,r);
	}
	if(s[l] == '-'){
		printf("%d ",l);
		dfs(l+1, r);
	}
}

signed main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	
	for(int i=1;i<=n;i++){
		if(s[i] == '(')st[++ tp] = i;
		if(s[i] == ')'){
			rr[st[tp --]] = i;
		}
	}
	
	dfs(1, n);

	return 0;
}

