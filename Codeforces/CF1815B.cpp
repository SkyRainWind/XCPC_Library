// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;

void q1(int x){printf("+ %d\n",x);fflush(stdout);scanf("%*d");}
void q2(int i,int j){printf("? %d %d\n",i,j);fflush(stdout);}

int n;
pii res[maxn];

void solve(){
	scanf("%d",&n);
	q1(n+1), q1(n+2);
	vector<int>r1(n+1);
	if(n%2 == 0){
		for(int i=1;i<=n/2;i++){
			r1[2*i-1] = i;
			r1[2*i] = n+1-i;
		}
	}else{
		for(int i=1;i<=n/2;i++){
			r1[2*i-1] = i;
			r1[2*i] = n+1-i;
		}
		r1[n] = n/2+1;
	}
	
	int mx=0, st;
	for(int i=2;i<=n;i++){
		q2(1,i);
		int x;scanf("%d",&x);
		if(x > mx){
			mx = x;
			st = i;
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++)if(i != st){
		q2(st,i);
		int x;scanf("%d",&x);
		res[++ cnt] = mpr(i, x);
	}
	res[++ cnt] = mpr(st, 0);
	sort(res+1,res+n+1,[&](pii a,pii b){
		return a.second < b.second;
	});

	vector<int>ans1(n+1), ans2(n+1);
	for(int i=1;i<=n;i++){
		ans1[res[i].first] = r1[i];
	}
	for(int i=1;i<=n;i++){
		ans2[res[i].first] = r1[n+1-i];
	}
	
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d%c",ans1[i],"  "[i == n]);
	for(int i=1;i<=n;i++)printf("%d%c",ans2[i]," \n"[i == n]);
	fflush(stdout);
	scanf("%*d");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

