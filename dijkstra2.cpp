#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 10001;
const int MAX = 501;

int n, m, s, d;
int a[MAX][MAX], dist[MAX];

void dijkstra() {

	for (int i = 0; i < n; i++) dist[i] = INF;
	dist[s] = 0;

	priority_queue<pair<int, int>> q;
	q.push({ 0, s });

	while (!q.empty()) {
		pair<int, int> node = q.top();
		int next = node.second;
		int cost = -node.first;
		q.pop();
		if (dist[next] < cost) continue;
		for (int i = 0; i < n; i++) {
			if (a[next][i] == 0) continue;
			int k = cost + a[next][i];
			if (k < dist[i]) {
				dist[i] = k;
				q.push({ -k, i });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		
		cin >> s >> d;
		
		while(m--) {
			int from, next, cost;
			cin >> from >> next >> cost;
			a[from][next] = cost;
		}

		dijkstra();

		queue<int> q;
		q.push(d);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int i = 0; i < n; i++) {
				if (a[i][p] == 0) continue;
				if (dist[p] == dist[i] + a[i][p]) {
					a[i][p] = 0;
					q.push(i);
				}
			}
		}

		dijkstra();

		cout << (dist[d] != INF ? dist[d] : -1) << '\n';

	}

}
