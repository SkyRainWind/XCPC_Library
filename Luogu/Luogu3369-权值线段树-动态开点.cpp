// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, maxp=1e7+5;

struct segm{
	int l,r,sum;
}se[maxn << 6];
int cnt=0,rt;

void ins(int &rt,int l,int r,int qu,int v){
	if(!rt)rt = ++cnt;
	se[rt].sum += v;
	if(l == r){
		return ;
	}
	int mid=l+r>>1;
	if(qu <= mid)ins(se[rt].l,l,mid,qu,v);
	else ins(se[rt].r,mid+1,r,qu,v);
}

int queryx(int rt,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return se[rt].sum;
	int mid=l+r>>1;
	if(qr<=mid)return queryx(se[rt].l,l,mid,ql,qr);
	else if(ql>mid)return queryx(se[rt].r,mid+1,r,ql,qr);
	else return queryx(se[rt].l,l,mid,ql,qr)+queryx(se[rt].r,mid+1,r,ql,qr);
}

int querykth(int rt,int l,int r,int rk){
	if(l==r)return l;
	int s = se[se[rt].l].sum;
	int mid=l+r>>1;
	if(rk<=s)return querykth(se[rt].l,l,mid,rk);
	else return querykth(se[rt].r,mid+1,r,rk-s);
}

map<int,int>mp;
void solve(){
	int opt,x;
	scanf("%d%d",&opt,&x);
	if(opt == 1)ins(rt,1,maxp*2,x+maxp,1),++mp[x];
	else if(opt==2){
		ins(rt,1,maxp*2,x+maxp,-1),--mp[x];
		if(mp[x]==0)mp.erase(x);
	}
	else if(opt==3)printf("%d\n",queryx(rt,1,maxp*2,1,x+maxp-1)+1);
	else if(opt==4)printf("%d\n",querykth(rt,1,maxp*2,x)-maxp);
	else if(opt==5){
		auto u = --mp.lower_bound(x);	//////
		printf("%d\n",u->first);
	}else{
		auto u = mp.upper_bound(x);
		printf("%d\n",u->first);
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

