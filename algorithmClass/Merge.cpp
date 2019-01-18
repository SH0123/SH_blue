//2017029416_김상효_12525

#include<stdio.h>
#include<stdlib.h>

void Merge_sort(int*,int,int);
void Merge(int*,int,int,int);
int f_arr[100000];
int main(){
    int p,q,r,num;
    scanf("%d",&num);
    int* arr_=(int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;++i){
	scanf("%d",&arr_[i]);
    }
    p=0,r=num-1,q=(p+r)/2;
    Merge_sort(arr_,p,q);
    Merge_sort(arr_,q+1,r);
    Merge(arr_,p,q,r);

   for(int i=num-1;i>=0;--i){
	printf("%d\n",arr_[i]);
    }
    return 0;
}
void Merge_sort(int* arr,int p,int q){
    if(p<q){
    int m;
    m=(p+q)/2;
    Merge_sort(arr,p,m);
    Merge_sort(arr,m+1,q);
    Merge(arr,p,m,q);
    }
}
void Merge(int* arr,int p,int q,int r){
    int k=0;
    int lpt=p,rpt=q+1;
    while(lpt<=q&&rpt<=r){
	if(arr[lpt]<=arr[rpt]){
	    f_arr[k++]=arr[lpt++];
	}
	else if(arr[lpt]>arr[rpt]){
	    f_arr[k++]=arr[rpt++];
	}
    }
    while(lpt<=q)
	f_arr[k++]=arr[lpt++];
    while(rpt<=r)
	f_arr[k++]=arr[rpt++];
    k=0;
    for(int i=p;i<=r;++i)
	arr[i]=f_arr[k++];
}
