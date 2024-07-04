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

struct node{
	int id,x,y;
	ll hp;
};
vector<node>v;
int hh[2005];

ll dist(int x1,int y1,int x2,int y2){
	return 1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2); 
}

int qu;
signed main(){
	scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			int h;scanf("%d",&h);
			v.pb(node{i,x,y,h});
		}else{
			int atk,r;scanf("%d%d",&atk,&r);
			node to;
			ll md = 2e18;
			for(auto it : v){
				if(it.hp <= 0)continue;
				if(dist(it.x,it.y,x,y) < md){
					md = dist(it.x,it.y,x,y);
					to = it;
				}
			}
			int gg = 1;
			for(auto &it : v){
				if(dist(it.x,it.y,to.x,to.y) <= 1ll*r*r){
					it.hp -= atk*3ll;
					if(it.hp > 0)gg=0;
				}
			}
			hh[i]=gg;
		}
	}
	for(auto it : v)if(it.hp<=0)hh[it.id]=0;else hh[it.id]=1;
	for(int i=1;i<=qu;i++)puts(hh[i] ? "Yes" : "No");

	return 0;
}

