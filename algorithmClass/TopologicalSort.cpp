//2017029416_김상효_12525

#include<stdio.h>
#include<stdlib.h>
#define BLACK 0
#define GRAY 1
#define WHITE 2
#define YES 0
#define NO 1

void dfs();
void d_visit(int);
void Edge(int,int);
void sort(int*,int);

typedef struct node_ node;

struct node_{
	int finish;
	int indegree;
	int outdegree;
	int* vertex;
};

node* n;
int* arr;
int num;
int DAG;
int dfs_num;

int main(){
	
	scanf("%d",&num);
	arr=(int*)malloc(sizeof(int)*num);
	n=(node*)malloc(sizeof(struct node_)*(num+1));
	
	for(int i=1;i<num+1;++i){
		n[i].outdegree=0;
		n[i].vertex=(int*)malloc(sizeof(int)*num);
		for(int j=0;j<num;++j){
			n[i].vertex[j]=0;
		}
	}
	DAG=NO;
	dfs_num=0;
	
	
	int from,to;
	while(scanf("%d %d",&from,&to)!=EOF){
		Edge(from,to);	
	}
	dfs();
	printf("%d\n",DAG);
	if(DAG){
		for(int i=0;i<num;++i){
			printf("%d ",arr[i]);
		}
	}

	return 0;
}

void dfs(){

	for(int i=1;i<num+1;++i){
		n[i].finish=WHITE;
		sort(n[i].vertex,n[i].outdegree);
	}
	for(int i=1;i<num+1;++i){
		if(n[i].finish==WHITE){
			d_visit(i);
		}
	}
}

void d_visit(int from_){

	int go;

	n[from_].finish=GRAY;
	for(int i=0;i<n[from_].outdegree;++i){
		go=n[from_].vertex[i];
		switch(n[go].finish)
		{	case WHITE:
				d_visit(go);
				break;
			case GRAY:
				DAG=YES;
				break;
			case BLACK:
				break;
			default:
				break;
		}
	}
	n[from_].finish=BLACK;
	arr[num-++dfs_num]=from_;
}

void Edge(int from_, int to_){
	
	int cnt=0;
	for(int i=0;i<num;++i){
		if(n[from_].vertex[i]==0){
			break;
		}
		cnt++;
	}
	n[from_].vertex[cnt]=to_;
	n[from_].outdegree++;
}

void sort(int* arr_,int num_){
	int tmp;

	for(int i=0;i<num_;++i){
		for(int j=i+1;j<num_;++j){
			if(arr_[i]>arr_[j]){
				tmp=arr_[i];
				arr_[i]=arr_[j];
				arr_[j]=tmp;
			}
		}
	}
}
