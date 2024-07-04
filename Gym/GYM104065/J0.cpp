#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, a, b, c;
int na, nb, nc;
int sum;

void upd(int i, int j, int k){
//	if (i<0 || j<0 || k<0) return;
int p=i,pp=j,ppp=k;
	if (j<0) k+=j, j=0;
	if (k<0) j+=k, k=0;
	if (i+j+k!=n) return;
	if (abs(3*(i*a+j*b+k*c) - sum) < abs(3*(na*a+nb*b+nc*c) - sum)){
		printf("%d %d %d\n",p,pp,ppp);
		na=i, nb=j, nc=k;
	}
}

signed main() {
	//	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> n >> a >> b >> c;
		int ta=a, tb=b, tc=c;
		a*=3, b*=3, c*=3;
		sum = (a+b+c)*n;
		if (a==b && a==c){
			na=n, nb=0, nc=0;
		}else{
			na=n, nb=0, nc=0;
			if (b==c) swap(a, b);
			for (int i=0; i<=n; ++i){
				int D = sum/3 - i*a - (n-i)*c;
				int j = D / (b-c);
				int k = n - i - j;
//				printf("i=%d j=%d k=%d\n", i, j, k);
				upd(i, j, k);
				upd(i, j+1, k-1);
				upd(i, j-1, k+1);
			}
		}
		
		printf("na=%d nb=%d nc=%d\n", na, nb, nc);
//		exit(0);
//		printf("n=%d a=%d b=%d c=%d %lld\n", n, ta, tb, tc, na*a+nb*b+nc*c);
			for (int i=1; i<=na; ++i){
				int x, y;
				cout << a/3 << endl;
				cin >> x >> y;
			}
			for (int i=1; i<=nb; ++i){
				int x, y;
				cout << b/3 << endl;
				cin >> x >> y;
			}
			for (int i=1; i<=nc; ++i){
				int x, y;
				cout << c/3 << endl;
				cin >> x >> y;
			}
	}
	return 0;
}
