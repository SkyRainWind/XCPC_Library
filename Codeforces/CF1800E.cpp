// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,k;
char s[maxn], t[maxn];

void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	scanf("%s",t+1);
	vector<int>buc(27, 0);
	
	for(int i=1;i<=n;i++){
		if(i-k < 1 && i+k > n){
			if(s[i] != t[i]){
				puts("NO");
				return ;
			}
		}
	}
	for(int i=1;i<=n;i++){
		++ buc[s[i] - 'a'];
		-- buc[t[i] - 'a'];
	}
	for(int i=0;i<=25;i++)
		if(buc[i]){
			puts("NO");
			return ;
		}
	puts("YES");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

