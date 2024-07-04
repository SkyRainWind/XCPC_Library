#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f;

void solve(){
	int n; 
	scanf("%d",&n);
	vector<int>b(n+2),a(n+2);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	if(b[1] != 1){
		puts("NO");
		return ;
	}
	b[0] = 1;
	int cc = 50,dd = 50;
	for(int i=1;i<=n;i++)
		if(b[i] >= b[i-1] && b[i] <= b[i-1]+1){
			if(b[i] == b[i-1])a[i] = -- cc;
			else a[i] = ++ dd;
		}
		else{
			puts("NO");
			return ;
		}
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

