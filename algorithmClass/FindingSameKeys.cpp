//2017029416_김상효_12525

#include<stdio.h>
#include<stdlib.h>

int main(){

	int n,m;
	int *n_arr, *m_arr;
	int c[1000000]={0,};
	int cnt=0;

	scanf("%d %d",&n,&m);
	n_arr=(int*)malloc(sizeof(int)*n);
	m_arr=(int*)malloc(sizeof(int)*m);

	for(int i=0;i<n;++i){
		scanf("%d",&n_arr[i]);
		c[n_arr[i]]++;
	}
	for(int i=0;i<m;++i){
		scanf("%d",&m_arr[i]);
		if(c[m_arr[i]]!=0){
			cnt++;
		}
	}
	printf("%d\n",cnt);

	return 0;
}
