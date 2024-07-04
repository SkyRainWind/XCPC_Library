// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
char s[200005];
void solve(){
	scanf("%s",s + 1);
	int n=strlen(s + 1);
	int gg = 0;
	for(int i=2;i<=n-1;i++)
		if(s[i] == 'a'){gg = i;break;}
	if(gg){
		for(int i=1;i<=gg-1;i++)
			printf("%c",s[i]);
		printf(" %c ",s[gg]);
		for(int i=gg+1;i<=n;i++)
			printf("%c",s[i]);
		puts("");return ;
	}
	printf("%c ",s[1]);
	for(int i=2;i<=n-1;i++)printf("%c",s[i]);
	printf(" %c",s[n]);puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

