namespace ls {
	const int maxnum = 5e5 + 5;
	int C[maxnum], L[maxnum], A[maxnum];
	//�� ����Ϊn��a�����������ɢ���� f ��
	void ls(int *f, int *a, int n) {
		for (int i = 0; i < n; i++)A[i] = a[i + 1];
		memcpy(C, A, sizeof(A));
		sort(C, C + n);
		int l = unique(C, C + n) - C;
		for (int i = 0; i < n; ++i)
			L[i] = lower_bound(C, C + l, A[i]) - C + 1;
		for (int i = 0; i < n; i++)f[i + 1] = L[i];
	}
}
