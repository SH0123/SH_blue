#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <functional>

using namespace std;

typedef struct edge {
	public:
		edge(int v1, int v2, int weight) {
			w = weight;
			from = v1;
			to = v2;
		}
		int w;
		int from;
		int to;
}edge;
typedef struct vertex {
	int value;
	int rank;
	vertex* p;
}vertex;

struct tmp_ {
	bool operator()(edge e1, edge e2) {

		if (e1.w != e2.w) return e1.w > e2.w;
		if (e1.from != e2.from) return e1.from > e2.from;
		return e1.to > e2.to;
	}

};

priority_queue <edge, vector<edge>, tmp_ > qu_;
vector<edge> final_;
void Make_set(vertex * x, int value);
void change();
vertex* Find(vertex * x);
void Union(vertex * x, vertex * y);

vertex* v;

int main() {

	int num;
	int cnt = 0;
	scanf("%d", &num);
	v = (vertex*)malloc(sizeof(vertex)*(num + 1));
	for (int i = 1; i < num + 1; i++) {
		Make_set(&v[i], i);
	}

	int v1_,v2_,weigh;
	while (scanf("%d %d %d", &v1_, &v2_, &weigh) != EOF) {
		qu_.push(edge(v1_, v2_, weigh));
	}
	while (!qu_.empty()) {

		if (Find(&v[qu_.top().from]) != Find(&v[qu_.top().to])) {
			edge t_e = qu_.top();
			Union(&v[qu_.top().from], &v[qu_.top().to]);
			cnt++;
			final_.push_back(t_e);
		}
		qu_.pop();
	}
	printf("%d\n", cnt);
	change();


	for (int i = 0; i < cnt; i++) {
		printf("%d %d %d\n", final_[i].from, final_[i].to, final_[i].w);
	}
}

void change() {
	for (int i = 0; i < final_.size() - 1; i++) {
		if (final_[i].from > final_[i].to) {
			int tmp = final_[i].to;
			final_[i].to = final_[i].from;
			final_[i].from = tmp;
		}
	}
}

void Make_set(vertex* x, int value) {
	x->value = value;
	x->p = x;
	x->rank = 0;
}


vertex* Find(vertex* x) {
	if (x == x->p) {
		return x;
	}
	return Find(x->p);
}

void Union(vertex * x, vertex * y) {
	vertex* root1 = Find(x);
	vertex* root2 = Find(y);
	if (root1->rank > root2->rank) {
		root2->p = root1;
	}
	else {
		root1->p = root2;
		if (root1->rank == root2->rank) {
			root2->rank = root1->rank + 1;
		}
	}
}
