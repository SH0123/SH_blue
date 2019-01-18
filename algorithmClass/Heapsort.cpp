//2017029416_김상효_12525

#include <stdio.h>
#include <stdlib.h>

typedef struct Heapstruct heap;

struct Heapstruct{
	int size;
	int* arr;
};
heap* CreateHeap(int);
void heapify(heap*,int);
int DeleteMax(heap*);
int main(){
	int num,a,last,max;
	heap* maxheap;
	scanf("%d %d",&num,&a);
	maxheap=CreateHeap(num);
	for(int i=1; i<=num;++i){
		scanf("%d",&(maxheap->arr[i]));
	}
	for(int i=num/2;i>=1;--i){
		heapify(maxheap,i);

	}

	for(int i=0;i<a;++i){
		printf("%d ",DeleteMax(maxheap));
	}
	printf("\n");
	for(int i=1;i<=maxheap->size;++i)
		printf("%d ",maxheap->arr[i]);


	return 0;
}

heap* CreateHeap(int size_){
	heap* tmp;
	tmp=(heap*)malloc(sizeof(heap));
	tmp->size= size_;
	tmp->arr=(int*)malloc(sizeof(int)*(size_+1));

	return tmp;
}
void heapify(heap* Uheap, int k){ //return 형태 void여도 됨 heap* 아니어도 된다
	int child=k*2;
	int tmp_;
	if(Uheap->size >= child){ //내가 생각해보지 못한 예외 처리
		if(child!=Uheap->size&&Uheap->arr[child]<Uheap->arr[child+1]) child++;
		if(Uheap->arr[child]>Uheap->arr[k]){
			tmp_=Uheap->arr[k];
			Uheap->arr[k]=Uheap->arr[child];
			Uheap->arr[child]=tmp_;
			heapify(Uheap,child);
		}
	}

}
int DeleteMax(heap* h){ 
	int i,child,max,end;
	max=h->arr[1];
	end=h->arr[h->size--];

	for(i=1;i*2<=h->size;i=child){
		child=i*2;
		if(child!=h->size&&h->arr[child]<h->arr[child+1]) child++;
		if(end<h->arr[child]) h->arr[i]=h->arr[child];
		else break;
	}
	h->arr[i]=end;
	return max;
}
