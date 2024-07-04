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
#define NO return puts("No"), void()

int m;
struct prob{
	int ty,x,y,tocs,tofz;
}p[23];

void solve(){
	for(int i=0;i<=20;i++)p[i]=prob{0,0,0,0,0};
	int np,tp;scanf("%d%d",&np,&tp);
	
	vector<int>vc;
	for(int i=1;i<=m;i++){
		char op[4];scanf("%s",op+1);
		if(op[1]=='+'){
			int ty,ti;
			scanf("%d/%d",&ty,&ti);
			p[i]=prob{1,ty,ti,0,0};
			np --, tp -= (ty-1)*20+ti;
		}else if(op[1]=='.')p[i]=prob{2,0,0,0,0};
		else if(op[1]=='-'){
			int ti;scanf("%d",&ti);
			p[i]=prob{3,ti,0,0,0};
		}else if(op[1]=='?'){
			int x,y;scanf("%d%d",&x,&y);
			p[i]=prob{4,x,y,0,0};
			vc.pb(i);
		}
	}
//	printf("bef %d\n",vc.size());
	if(np<0)NO;
	for(int S=0;S<(1<<(vc.size()));S++){
//		printf("!! %d\n",S);
		if(__builtin_popcount(S) != np)continue;
		vector<int>vd;
		for(int i=0;i<vc.size();i++)if(S&(1<<i))vd.pb(i);
		int mn = 0, mx=0;
		for(auto it : vd){
			int x=p[vc[it]].x, y=p[vc[it]].y;
			mn += (y-x)*20 + 240;
			mx += (y-1)*20 + 299;
		}
//		printf("QW %d %d %d\n",mn,mx,tp);
		if(mn <= tp && tp <= mx);
		else continue;
		
		puts("Yes");
		int qw = tp - mn;qw /= 20;
		int go = 0;
		for(auto it : vd){
			int x=p[vc[it]].x, y=p[vc[it]].y;
			if(x-1<qw)qw -= x-1, p[vc[it]].tocs = y, go += x-1;
			else{
				p[vc[it]].tocs = y-x+qw + 1;
				go += qw;
				qw = 0;
			}
		}
//		printf("%d %d %d\n",tp,mn,go);
		int del = tp - mn - go*20;
		for(auto it : vd){
			if(del > 59)del -= 59, p[vc[it]].tofz=299;
			else{
				p[vc[it]].tofz = 240 + del;
				del=0;
//				break;
			}
		}
		
		for(int i=1;i<=m;i++){
			if(p[i].ty==1)printf("+ %d/%d\n",p[i].x,p[i].y);
			else if(p[i].ty==2)printf(".\n");
			else if(p[i].ty==3)printf("- %d\n",p[i].x);
			else{
				if(p[i].tofz >= 240)printf("+ %d/%d\n",p[i].tocs,p[i].tofz);
				else printf("- %d\n",p[i].y);
			}
		}
		return ;
	}
	NO;
}

signed main(){
	int te;
	scanf("%d%d",&te,&m);
	while(te--)solve();

	return 0;
}

