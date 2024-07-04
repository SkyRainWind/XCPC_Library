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

typedef struct node{
	int val;
	struct node *nxt;
};

void test_link(){
	node *head;
	head = (node *)malloc(sizeof(node));
	node *lst = head;
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		node *now = (node *)malloc(sizeof(node));
		now->val = x;
		now->nxt = NULL;
		lst->nxt = now;
		lst = now; 
	}
	
	while(m --){
		int id,x;scanf("%d%d",&id,&x);
		node *now = head;
		for(int i=1;i<=id;i++){
			now = now->nxt;
		}
		node *nn = (node *)malloc(sizeof(node));
		nn->val = x;
		nn->nxt = now->nxt;
		now->nxt = nn;
	}
	
	
	node *now = head;
	now = now->nxt;
	while(now){
		printf("%d ",now->val);
		now = now->nxt;
	}
}

signed main(){
	test_link();

	return 0;
}

