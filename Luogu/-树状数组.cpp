struct fen{
	int a[maxn];
	int N = -1;
	void init(int up){
		N = up;
//		for(int i=0;i<=N;i++)a[i]=0;	// check if multiple cases
	}
	
	int lb(int x){return x & (-x);}
	void add(int x,int del){	// init N!!!
		assert(N != -1);
		for(int i=x;i<=N;i+=lb(i)){
			a[i] += del;
		}
	}
	
	int query(int x){
		int res = 0;
		for(int i=x;i;i-=lb(i))res += a[i];
		return res;
	}
	int query(int l,int r){
		return query(r) - query(l-1);
	}
};
