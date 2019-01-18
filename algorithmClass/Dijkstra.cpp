//2017029416_김상효_12525
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define NEINF -999
#define INF 999999
using namespace std;
vector<pair<int, int> > arr[7777];
priority_queue<pair<int, int> > Q;
int v[100000];
int main() {

	int   E = 0, n, vertex_num, edge_num, num, weight;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vertex_num >> edge_num;
		for (int j = 0; j < edge_num; j++) {
			cin >> num >> weight;
			arr[vertex_num].push_back(make_pair(num, weight));
			E++;


		}
	}
	for (int i = 0; i <= n; i++)
		v[i] = 999999;
	v[1] = 0;
	Q.push(make_pair(-0, 1));
	while (!Q.empty()) {
		int f = -Q.top().first;
		int s = Q.top().second;
		Q.pop();
		for (int i = 0; i < arr[s].size(); i++) {
			int ni = arr[s][i].first;      
			int nv = f + arr[s][i].second;
			if (v[ni] > nv) {
				v[ni] = nv;
				Q.push(make_pair(-nv, ni)); 
			}
		}
	}
	int max = NEINF;
	for (int i = 1; i <= n; i++) {

		if (v[i] != INF) {
			if (max < v[i]) {
				max = v[i];
			}
		}
	}
	cout << max << endl;


}
