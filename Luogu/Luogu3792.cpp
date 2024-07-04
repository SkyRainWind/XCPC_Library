// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5 + 5, maxm = 1e6+5;

int n,qu;
int ls[maxn], cnt = 0;
int pre[maxn], prei[maxn], a[maxn], b[maxn];
// a[] 存离散化后的数，b[] 存未离散化时的数（每次修改都更新） 
set<int>id[700005];	// id[j] 代表离散化之后的 j 这个数对应的数组中的位置，为了方便每个用到的 j 前面都加了个 0 
map<int,int>ifocc;	// ifocc[i] 离散化过后为 i 的下标是否回收，如果否，这个下标对应的原数是什么 
int stk[maxn], tp=0;	// 记录哪些下标回收了 

struct segm{
	int mn, mx, pr;
}se[maxn << 2];

void pushup(int num){
	se[num].mn = min(se[num << 1].mn, se[num << 1|1].mn);
	se[num].mx = max(se[num << 1].mx, se[num << 1|1].mx);
	se[num].pr = max(se[num << 1].pr, se[num << 1|1].pr);
}

void build(int x,int y,int num){
	if(x == y){
		se[num].mn = se[num].mx = b[x];
		se[num].pr = prei[x];
		return ;
	}
	
	int mid = x+y>>1;
	build(x,mid,num << 1);build(mid+1,y,num << 1|1);
	pushup(num);
}

void update(int suf,int pre,int to,int l,int r,int num){
	if(l == r){
		se[num].pr = pre;
		se[num].mx = se[num].mn = to;
		return ; 
	}
	int mid = l+r>>1;
	if(suf <= mid)update(suf,pre,to,l,mid,num << 1);
	else update(suf,pre,to,mid+1,r,num << 1|1);
	pushup(num);
}

segm query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y)
		return se[num];
	int mid = l+r>>1;
	if(y <= mid)return query(x,y,l,mid,num << 1);
	else if(x > mid)return query(x,y,mid+1,r,num << 1|1);
	else{
		segm s1 = query(x,y,l,mid,num << 1);
		segm s2 = query(x,y,mid+1,r,num << 1|1);
		return segm{min(s1.mn,s2.mn), max(s1.mx,s2.mx), max(s1.pr,s2.pr)};
	}
}

signed main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), ls[++ cnt] = b[i] = a[i];

	sort(ls+1,ls+cnt+1);
	cnt = unique(ls+1,ls+cnt+1) - (ls + 1);
	for(int i=1;i<=n;i++)
		a[i] = lower_bound(ls+1,ls+cnt+1,a[i]) - ls,
		id[a[i]].insert(i),
		ifocc[b[i]] = a[i];
		
	for(int i=1;i<=cnt;i++)
		id[i].insert(0);
	
	for(int i=1;i<=n;i++){
		prei[i] = pre[a[i]];
		pre[a[i]] = i;
	}
	build(1,n,1);
	
	for(int i=1;i<=qu;i++){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		// y -> ny
		
		if(op == 1){
			int ny;
			if(ifocc.count(y))
				ny = ifocc[y];
			else{
				if(tp){
					ny = stk[tp --];
				}else ny = ++ cnt, id[cnt].insert(0);
				ifocc[y] = ny;
			}

			int nowc = a[x];
			int j = x;
			set<int>::iterator it = id[nowc].find(j);
			
			int prev = 0, suff;
			
			prev = *(--it);
			++ it;
			++ it;
			if(it != id[nowc].end()){
				suff = *it;
				update(suff,prev,b[suff],1,n,1);
					// 原来 i 对应的数的后面一个结点的 pr 需要修改 
			}
			-- it;
			id[nowc].erase(it);
			if(id[nowc].size() == 1)
				stk[++ tp] = nowc,
				ifocc.erase(ls[a[x]]);
			
			int toc = ny;
			id[toc].insert(j);
			it = id[toc].find(j);
			
			prev = *(-- it);
			++ it;
			update(j,prev,y,1,n,1);
			++ it;
			// i 修改过后 i 的 pr 以及 i 的后继的 pr 都需要修改 
			if(it != id[toc].end()){
				suff = *it;
				update(suff,j,y,1,n,1);
			}
			-- it;
			a[j] = toc;
			b[j] = y;
		}else{
			int l = x, r = y;
			segm res = query(l,r,1,n,1);
			if(res.mx - res.mn == r-l && res.pr < l)
				puts("damushen");
			else
				puts("yuanxing");
		}
	}

	return 0;
}

