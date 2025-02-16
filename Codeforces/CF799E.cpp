// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <queue>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

struct node{int val, id;}nd[maxn];
bool operator < (node a,node b){return a.val > b.val;}
node pq[maxn],pq2[maxn],pq3[maxn],pq4[maxn];
// pq 都不喜欢 pq2 A pq3 B pq4 AB 
int s2[maxn], s3[maxn], s4[maxn], s5[maxn];
// 前缀和 
int n,m,k,vis[maxn],pc1,pc2,pc3,pc4,pc5;
priority_queue<int>r1;
priority_queue<int,vector<int>,greater<int> >r2;	// 对顶堆 

void upd(int s,LL &res){	// 注意 res 是只包含单 A 单B AB都不喜欢 三种情况 
	// 去掉（不选）单 A 和单 B 的第(k-s)项，加入对顶堆中，因为实际上选的个数少了1，因此答案的堆（大根堆）中size需要+1 
	LL mx=-1;
	if(!r1.empty())mx = r1.top();
	node cur1 = pq2[k-s], cur2 = pq3[k-s];
	if(cur1.val > cur2.val)swap(cur1, cur2);
	if(r1.empty()){	// 特判一开始：如果AB都喜欢的s项和单A单B分别的(k-s)项加起来恰好是m的情况（此时答案堆size为0但是要更新了） 
		res -= cur1.val; res -= cur2.val;
		vector<int>tmp;
		tmp.push_back(cur1.val);
		tmp.push_back(cur2.val);
		if(!r2.empty())tmp.push_back(r2.top()), r2.pop();
		if(!r2.empty())tmp.push_back(r2.top()), r2.pop();
		sort(tmp.begin(), tmp.end());
		// 利用辅助堆（小根堆）中的2个元素（因为最坏情况是单A 单B 的第(k-s)项都比小根堆顶2个元素小 
		
		res += tmp[0];	// 因为 答案堆size 要加1，选最小的 
		r1.push(tmp[0]);r2.push(tmp[1]);r2.push(tmp[2]);r2.push(tmp[3]); 
		return ;
	}
	
	// 剩下的三种情况相对好考虑，注意答案堆和辅助堆每次都要size+1 
	// res 减是因为本来加上了的前缀和中含有当前第 (k-s) 项，但是现在要删去 
	if(cur2.val <= mx){	// delete mx
		r1.pop();r1.push(cur1.val);r1.push(cur2.val);r2.push(mx);
		res = res - mx;
	}else if(cur1.val <= mx){
		r1.push(cur1.val);r2.push(cur2.val);
		res = res - cur2.val;
	}else{
		int tp = r2.top();r2.pop();
		r2.push(cur1.val), r2.push(cur2.val);
		r1.push(tp);
		res = res + tp - cur1.val - cur2.val;
	}
}

signed main(){
//	freopen("CF799E.in","r",stdin);
//	freopen("CF799E-my.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&nd[i].val), nd[i].id = i;
	sort(nd+1,nd+n+1);
	reverse(nd+1,nd+n+1);
	
	int tt;scanf("%lld",&tt);
	while(tt--){int v;scanf("%lld",&v);vis[v] ++;}
	scanf("%lld",&tt);
	while(tt--){int v;scanf("%lld",&v);vis[v] += 2;}
	for(int i=1;i<=n;i++){
		if(vis[nd[i].id] == 1){pq2[++pc2] = nd[i];s2[pc2] = s2[pc2-1] + nd[i].val;} 
		else if(vis[nd[i].id] == 2){pq3[++pc3] = nd[i];s3[pc3] = s3[pc3-1] + nd[i].val;}
		else if(vis[nd[i].id] == 3){pq4[++pc4] = nd[i];s4[pc4] = s4[pc4-1] + nd[i].val;}
		else pq[++pc1]=nd[i];
	}
		
	LL ans = 1e18, ff=0, res;
	for(int s=0;s<=min(pc4, k);s++){	// 枚举都喜欢的有几个 
		if(s + 2 * (k-s) > m)continue;	// 光满足喜欢>=k就已经超 m 了 
		if(n-(pc4-s) < m)continue;		// 因为钦定了剩下都喜欢的不选了（否则可以在那时候更新答案），而能选的不到 m个，也不行 
		if(k-s > pc2 || k-s > pc3)continue;
		
		int rest = m - s - 2*(k-s);
		if(++ ff == 1){	// 第一个暴力处理，之后每次更新答案 
			vector<int>tmp;
			for(int i=1;i<=pc1;i++)tmp.push_back(pq[i].val);
			for(int i=k-s+1;i<=pc2;i++)tmp.push_back(pq2[i].val);
			for(int i=k-s+1;i<=pc3;i++)tmp.push_back(pq3[i].val);
			sort(tmp.begin(),tmp.end());
			int rr = 0;
			LL sum = 0;
			for(int u : tmp){
				if(++rr <= rest)r1.push(u), sum += u;
				else r2.push(u);
			}
			res = s2[k-s] + s3[k-s] + sum;
			ans = min(ans, s4[s] + res);	// 因为都喜欢的是钦定的不改的，所以每次更新只需要维护 单A 单B 和AB 都不喜欢的答案 
			upd(s, res);
			continue;
		}
		
		ans = min(ans, res + s4[s]);
		upd(s, res);
	}
	
	// 特殊情况：AB都喜欢的数量 >= k，此时剩下的三种里面随便选，肯定取最小的 
	for(int i=1;i<=n;i++)
		if(vis[nd[i].id] <= 2){
			++pc5;
			s5[pc5] = s5[pc5-1] + nd[i].val;
		}
	for(int s=k;s<=min(pc4,m);s++){
		// s 个2个喜欢 剩下随便选
		if(m-s <= pc5){
			int tmp = s4[s];
			ans = min(ans, tmp + s5[m-s]); 
		}
	}
	printf("%lld\n",ans==(LL)1e18 ? -1 : ans);
//	cerr<<ans<<'\n';

	return 0;
}

