//2017029416_김상효_12525

#include<stdio.h>
#include<stdlib.h>
#define WHITE 0
#define BLACK 1

void dfs();
void d_visit(int);
void Edge(int,int);

typedef struct node_ node;
struct node_{

	int color;
	int outdegree;
	int* arr;
	int address;

};

node* n;
int cnt;
int num;

int main(){
	
	scanf("%d",&num);
	n=(node*)malloc(sizeof(struct node_)*(num+1));
	
	//initializing
	for(int i=1;i<num+1;++i){
		n[i].outdegree=0;
		n[i].arr=(int*)malloc(sizeof(int)*num);
		for(int j=0;j<num;++j){
			n[i].arr[j]=0;
		}
	}
	cnt=0;

	

	int v1,v2;
	while(scanf("%d %d",&v1,&v2)!=EOF){
		Edge(v1,v2);
	}
	dfs();

	printf("%d\n",cnt);
	for(int i=1;i<num+1;++i){
		printf("%d\n",n[i].address);
	}
	return 0;
}

void dfs(){
	
	for(int i=1;i<num+1;++i){
		n[i].color=WHITE;
	}
	for(int i=1;i<num+1;++i){
		if(n[i].color==WHITE){
			++cnt;
			n[i].address=cnt;
			d_visit(i);	
		}
	}
}

void d_visit(int from){
	
	int go;

	n[from].color=BLACK;
	n[from].address=cnt;
	for(int i=0;i<n[from].outdegree;++i){
		go=n[from].arr[i];
		switch(n[go].color)
		{
			case WHITE:
				d_visit(go);
				break;
			case BLACK:
				break;
			default:
				break;
		}
	}
}

void Edge(int v1_,int v2_){
	
	int br=0;
	
	for(int i=0;i<num;++i){
		if(n[v1_].arr[i]==0){
			break;
		}
		br++;
	}
	n[v1_].arr[br]=v2_;
	n[v1_].outdegree++;

	br=0;
	for(int i=0;i<num;++i){
		if(n[v2_].arr[i]==0){
			break;
		}
		br++;
	}
	n[v2_].arr[br]=v1_;
	n[v2_].outdegree++;

}
