// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e6+5;

char s[maxn];
namespace sam{
	struct node{
		int nxt[26];
		int link,len;	// link 上一个点（endpos是当前点的超集对应的点） len 当前等价类（endpos相同）的最长字符串长度 
	}t[maxn<<1];
	
	int sz=0,lst;
	void newnode(int len){
		t[++sz].len = len;
		t[sz].link = -1;
		memset(t[sz].nxt,0,sizeof t[sz].nxt);
	}
	
	void init(){
		sz=-1,lst=0;
		newnode(0);
	}
	
	void insert(int c){
		newnode(t[lst].len+1);
		int p=lst,cur=sz;
		while(~p && !t[p].nxt[c])t[p].nxt[c]=cur, p=t[p].link;
		if(p==-1)t[cur].link=0;
		else{
			int q=t[p].nxt[c];
			if(t[q].len==t[p].len+1)t[cur].link=q;
			else{
				newnode(t[p].len+1);
				int nq=sz;
				memcpy(t[nq].nxt,t[q].nxt,sizeof t[q].nxt);
				t[nq].link = t[q].link;
				t[cur].link = t[q].link = nq;
				while(p >=0 && t[p].nxt[c]==q)
					t[p].nxt[c]=nq,p=t[p].link;
			}
		}
		lst=cur;
	}
	int get(){
		return t[lst].len - t[t[lst].link].len;
	}
}

signed main(){
	ll ans=0;int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	sam::init();
	for(int i=1;i<=n;i++){
		sam::insert(s[i]-'a');
		ans += sam::get();
	}
	printf("%lld\n",ans);

	return 0;
}

