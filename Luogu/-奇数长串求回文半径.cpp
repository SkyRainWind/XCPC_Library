	scanf("%s",s + 1);
	n = strlen(s + 1);
	s[n+1] = '#';
	vector<int>R(n+1);
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		if(i <= r)R[i] = min(r-i, R[l+r-i]);
		else R[i] = 0;

		while(s[i+R[i]+1] == s[i-R[i]-1])
			++ R[i];
		if(i + R[i] >= r)
			r = i+R[i],l=i-R[i];
	}

	for(int i=1;i<=n;i++)++ R[i];
