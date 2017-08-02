#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

ll init(vector<ll>& a, vector<ll>& tree, int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(){
	return 0;
}
