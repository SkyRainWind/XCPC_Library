#include <stdio.h>
#include <string.h>
#include <malloc.h>

int f(int a,int b){
	return a+ b;}
	
int g(int a,int b){return a - b;}

struct data{
	int x,y;
};

void change1(struct data t){	// !!!!
	t.x = 0;
}
void change2(struct data *t){
	t->x=10;
	t->y=10;
}

void testpp(){
	char a[3][3]={"123","456","789"};
	char (*test)[3]=a;
//	printf("%p\n%p\n",test,test+1);
//	printf("%p\n%p\n",a,a+1);
	char (*p)[3]=a;
	int i;
//	a	// ->a[0] -> a[0][0]
	char qq = **a;
//	printf("test %s\n",*p);
//	printf("%c\n",(*p)[1]);
	for(i=0;i<=1;i++){
//		printf("%s\n",*p);
		printf("%c\n",*(*p+1));
		p++; 
	}
	
	struct data t;t.x=1, t.y=2;
	change1(t);
	printf("\nsizeof %d\n",sizeof(struct data));
	printf("\n%d %d\n",t.x,t.y);
	change2(&t);
	printf("%d %d\n",t.x,t.y);
}

int swap(int *p,int *q){
	int t = *p;
	*p = *q;
	*q = t;
}

void mystrlen(char *s){
	int len = 0;
	while(s[len] != '\0') ++ len;
	printf("%d\n",len);
}

void Swap(int *p,int *q){
	int *t = p;
	p = q;
	q = t;
}

int ff(int a,int b){return a+b;}
int gg(int a,int b){return a-b;}

void testfp(){
	int (*p)(int,int);
	int a=2,b=3;
	if(0)p=ff;
	else p=gg;
	printf("%d\n",p(a,b));
}

int main(){
	testfp();return 0;
//	testpp();return 0;
//	int ii=2;
	// 1 0
//	while(i<=3)
//	while(0)
//	for(ii=0;23123;ii++){
//		puts("ok");
//	}return 0;
//	if(ii=1)//..
//	int ii=0;
//	for(ii=0;ii=0;ii)
//	int aa =2, b=3;
//	swap(&aa,&b);
//	printf("%d %d\n",aa,b);return 0;
//	char s[102];
//	scanf("%s",s);
//	mystrlen(s);return 0;
//	char s[9]={"China"};
//	s[5] = 'Q';
//	s[6] = 'Q';
//	s[7] = 'W';
//	printf("%s\n",s);
//	return 0;
//	int ar[]={1,2,3};
//	int a[3][3];
	// *(*(a+i)+j)
//	printf("111 %d\n",*(ar+1));	//ar[1]
//	double ar[] ={1,2,3,4,5};
//	printf("%p\n%p\n%p\n",ar,ar+1,ar+2);return 0;
//	int aa = 2, bb = 3;
//	swap(&aa ,&bb);
//	printf("%d %d\n",aa,bb);return 0;
//	char *str
//	str = "CHina";
// char str[] = "China";
//	printf("%s\n",str);

// ע�������Ǵ���ģ�char *a; scanf("%s",a); ���ڴ治��������ģ�char a[10]; ... 

// �ַ����鲻Ҫ���� '\0' 
//char str[10] = "China";
//str[5] = 'q';str[6] = 'w';
//str[7] = '\0';
//printf("%d", strlen(str));

/*	����ָ��
 
	int t;
	scanf("%d",&t);
	int (*pp)(int ,int);
	if(t == 0)pp= f;
	else pp = g;
	printf("%d\n",pp(2, 3)); 
	*/
	
	// ָ��ӷ���ÿ�ε�ַ + sizeof (type) ����type������������ͣ���int��4��int[3]��3*4
	// ���� int *p=&a; p+1 -> �ڴ�+4
	// �ڶ�ά������int[row][col]����Ϊÿ��ָ���������int[col]��������ֱ�Ӷ� a +1, -1,��ʵ���޸ĵ�ֻ��a[i][0] 
	// ������ int*p = a������ʽ��ÿ�� p+1 �ӵ��������е�һ��Ԫ�أ���˿��Ա��������е�����Ԫ�� 
	// ע�� int *p = a �� = *a ��һ������(*a = a[0]) �����Ǻ��߸��ţ���Ϊǰ���ǰ��е�ַ������int*����������ʵ����Ҫ�е�ַ�������)
	// int p[], p[3] == *(p+3)
	// int (*p)[3] p ��һ��ָ�룬ָ��һ������3��Ԫ�ص����飬ע��Ͷ�ά�����еĵ�һά���� 
	int a[3][3],i,j;
//	int *p = *(a+1);	// ��仰����˼��a+1����ָ�룬ָ��a[1] �����a[1]Ҳ�Ǹ����飡�� ��*��֮��ȡ����ָ��Ķ�������a[1]��ע��a[1]Ҳ�Ǹ�ָ�룡���������ָ�룩������p 
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
//			scanf("%d", p + (i*3 + j));
			a[i][j] = i *3 + j;
//	int p[3];
//	p &p[0]
//	a[0] &a[0][0]
	int (*q)[3] = a + 1;	// q ��һ��ָ�룬ָ��һ������ 3 ��Ԫ�ص�����
	// ����һ�£�a ��ʾָ���0�е�ָ�룬����ָ��
	// a[0] == *a�� ��ʾָ���0�е�һ��Ԫ�ص�ָ�룬����ָ��
	// a + 1 -> ָ���˵�1�е�0��Ԫ�� a[0] + 1 -> ָ���˵�0�е�1��Ԫ��
	// ע��qָ��������飬����Ӧ������ָ�룬�����a��ֵ��Ҳ����a+1 
	printf("%d\n",*(*a +1));	// *(a[0]+1) a[0][1]
//	printf("%p\n%p\n%p\n",a+1,a[0]+1,*a+1); 
//	printf("* %d\n",*(*q + 1));
	printf("* %d\n",(*q)[1]);
//	i = 1, j =2 ;
//	printf("%d\n", p[1]);
	
	char *pst[3] = {"hello"};
	pst[0] = "hello";
	pst[1] = "ysn";
	printf("%s\n",*(pst + 1));	// �� * ����Ϊpst��һ�����飬Ҳ����ָ���һ��Ԫ�ص�ָ�룬��ÿ��Ԫ����һ��char* ���ַ����� 
 
//	char *base = "testit";
//	char (*pstr)[10] = NULL;
//	*pstr = base;
//	printf("%s\n", *pstr);
	
// ָ�� +1 ���ӵ��ֽ���ȡ���ڻ����� 
//	int *p = a;
//	printf("%p\n%p\n", p + 3, &a[1][0]);
//double ap = 1, aq = 2;
//double *p = &ap;
//printf("%p\n",p);
//++ p;
//printf("%p\n",p);

// ָ��ָ���ָ��
	testpp(); 
	
	return 0;
}
