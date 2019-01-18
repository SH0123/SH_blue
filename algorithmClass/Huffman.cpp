//2017029416_김상효_12525

#include <stdio.h>
#include <stdlib.h>

typedef struct _minHeap minheap;
typedef struct _node node;

struct _minHeap {
	int capacity;
	int size;
	node** arr; //array of type node* -> node*[i]
};

struct _node {
	node* left;
	node* right;
	int freq;
	char data[4];
};

minheap* CreateHeap(int);
node* DeleteMin(minheap*);
void insert(minheap*, node*);
void order(node*, int);
void huff(minheap*);
int sum_ = 0;

int main() {
	int num, t_num;
	minheap* heap;
	scanf("%d", &num);
	node* f_arr = (node*)malloc(sizeof(node)*num);
	heap = CreateHeap(num);
	for (int i = 0; i < num; ++i) {
		scanf("%s", f_arr[i].data);
		scanf("%d", &f_arr[i].freq);
		f_arr[i].left = NULL;
		f_arr[i].right = NULL;
		insert(heap, &f_arr[i]);
	}
	scanf("%d", &t_num);

	//for (int i = 1; i < num + 1; ++i) printf("%d\n", heap->arr[i]->freq);

	huff(heap);
	int sum = 0;
	order(heap->arr[1], 0);

	int bi = 1;
	int i;
	for ( i = 0; i < num; ++i) {
		bi *= 2;
		if (bi > num) break;
	}
	sum = (i + 1)*t_num;
	printf("%d\n", sum);//first output
	printf("%d\n", sum_);
	return 0;
}


minheap* CreateHeap(int size_) {
	minheap* tmp;
	tmp = (minheap*)malloc(sizeof(minheap));
	tmp->capacity = size_;
	tmp->size = 0;
	tmp->arr = (node**)malloc(sizeof(node*)*(size_ + 1));


	return tmp;
}
node* DeleteMin(minheap* h) {
	int i, child;
	node* min; // = (node*)malloc(sizeof(node));
	node* end; // = (node*)malloc(sizeof(node));
	min = h->arr[1];
	end = h->arr[h->size--];

	for (i = 1; i * 2 <= h->size; i = child) {
		child = i * 2;
		if (child != h->size&&h->arr[child]->freq > h->arr[child + 1]->freq) child++;
		if (end->freq > h->arr[child]->freq) h->arr[i] = h->arr[child];
		else break;
	}
	h->arr[i] = end;
	/*for (int i = 1; i < h->size+1; ++i) printf("%d ", h->arr[i]->freq);
	printf("\n");
	printf("min %d\n", min->freq);*/
	return min;
}
void huff(minheap* h) {
	// node* left1 = (node*)malloc(sizeof(node));
	// node* right1 = (node*)malloc(sizeof(node));
	node *left1, *right1;
	node* temp = (node*)malloc(sizeof(node));
	for(int i=0;i<h->capacity-1;++i) {
		//temp = (node*)malloc(sizeof(node));
		left1 = DeleteMin(h);
		//printf("left %d\n", left1->freq);
		right1 = DeleteMin(h);
		//printf("right %d\n", right1->freq);
		if (right1 == NULL) break;

		temp->left = left1;
		temp->right = right1;
		temp->freq = left1->freq + right1->freq;
		temp->data[0] = '\0';
		//printf("tmp%d\n", temp->freq);
		insert(h, temp);
	}
}
void insert(minheap* h, node* n) {
	int i;
	for (i = ++h->size; i / 2 > 0 && h->arr[i / 2]->freq > n->freq; i /= 2) {
		//printf("%d번에%d\n", h->size, h->arr[h->size]->freq);
		h->arr[i] = h->arr[i / 2];
	}
	node* temp = (node*)malloc(sizeof(node));
	*temp = *n;

	h->arr[i] = temp;
	//printf("%d번에%d\n", i,h->arr[i]->freq);
	// for (int i = 1; i < h->size; ++i);// printf("%d\n", h->arr[i]->freq);

}
void order(node* n, int height) {
	if (n) {
		if (n->data[0] != '\0') {
			sum_ += n->freq*height;
		}
		order(n->left, height + 1);
		order(n->right, height + 1);
	}
}

