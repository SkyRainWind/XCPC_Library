// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5 + 5;

int n,qu,rt[maxn],a[maxn];
struct segm{
	ll lazy,sum;
	int ls,rs;
}se[maxn << 6];
int clk=0;

void build(int x,int y,int &num){
	num = ++clk;
	if(x == y){
		se[num].sum = a[x];
		return ;
	}
	int mid = x+y>>1;
	build(x,mid,se[num].ls);
	build(mid+1,y,se[num].rs);
	se[num].sum = se[se[num].ls].sum + se[se[num].rs].sum;
}

void update(int l,int r,int to,int x,int y,int &num,int pre){
	num = ++ clk;
	se[num].ls = se[pre].ls, se[num].rs = se[pre].rs, se[num].lazy = se[pre].lazy, se[num].sum = se[pre].sum;
	if(l <= x && y <= r){
		se[num].lazy += to;
//		se[num].sum += 1ll * (r-l+1) * to;
		return ;
	}
	
	int mid = x+y>>1;
	if(r <= mid){
		update(l,r,to,x,mid,se[num].ls,se[pre].ls);
	}else if(l > mid){
		update(l,r,to,mid+1,y,se[num].rs,se[pre].rs);
	}
	else{
		update(l,mid,to,x,mid,se[num].ls,se[pre].ls);
		update(mid+1,r,to,mid+1,y,se[num].rs,se[pre].rs);
	}
	se[num].sum = se[se[num].ls].sum + se[se[num].rs].sum + 1ll*(mid-x+1)*se[se[num].ls].lazy + 1ll*(y-mid)*se[se[num].rs].lazy;
}

ll query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y){
		return se[num].sum + se[num].lazy * 1ll * (r-l+1);
	}
	int mid = l+r>>1;
	if(y <= mid)return query(x,y,l,mid,se[num].ls) + se[num].lazy * 1ll * (y-x+1);
	else if(x > mid)return query(x,y,mid+1,r,se[num].rs) + se[num].lazy * 1ll * (y-x+1);
	else return query(x,mid,l,mid,se[num].ls) + query(mid+1,y,mid+1,r,se[num].rs) + se[num].lazy * 1ll * (y-x+1);
}

signed main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,rt[0]);
	int now = 0;
	while(qu --){
		char s[3];
		scanf("%s",s);
		if(s[0] == 'C'){
			int l,r,d;scanf("%d%d%d",&l,&r,&d);
			++ now;
			update(l,r,d,1,n,rt[now],rt[now-1]);
		}else if(s[0] == 'Q'){
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r,1,n,rt[now]));
		}else if(s[0] == 'B'){
			scanf("%d",&now);
		}else{
			int l,r,t;scanf("%d%d%d",&l,&r,&t);
			printf("%lld\n",query(l,r,1,n,rt[t]));
		}
	}

	return 0;
}

