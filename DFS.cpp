#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

const int N = 1000; // number of nodes in graph

int n, e;
vector<vector<int>> adj;
vector<bool> dfsVisited;
void dfs(int node);

int connectedComponenets() { // O(e + v)
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!dfsVisited[i]) {
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}

void dfs(int node) { // O(e + v)
	if (dfsVisited[node])
		return;
	cout << "Node : " << node << '\n';
	for (int child : adj[node])
		dfs(child);

	dfsVisited[node] = true;
}

int main() {
	cin >> n >> e;
	adj = vector<vector<int>>(n + 1);
	dfsVisited = vector<bool>(n + 1);
	int from, to;
	for (int i = 0; i < e; ++i) {
		cin >> from >> to;
		adj[from].push_back(to);
	}
	dfs(1);
// cout << connectedComponenets();
}
