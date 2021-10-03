#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

const int N = 1000; // number of nodes in graph

int n, e;
vector<vector<int>> adj;

int startTime[N] = { -1 };
int endTime[N] = { -1 };

int timer = 0;
int cycles = 0;		// number of cyclic edges
int forward = 0;	// number of forward edges
int cross = 0;		// number of cross edges
void dfsTime(int node) { // for Edge Classification --> cycle or forward or cross
	if (startTime[node] == -1)
		startTime[node] = time++;

	for (int child : adj[node]) {
		if (startTime[child] == -1) // has no start time
			dfsTime(child);

		// has start time
		else {
			if (endTime[child] == -1) // no end time, waits for current child to finish --> back
				cycles++;
			else { // has start time and end end time --> forward, or cross
				if (startTime[child] > startTime[node])
					forward++;
				else if (startTime[child] < startTime[node])
					cross++;
			}
		}
	}
	endTime[node] = time++;
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
	dfsTime(1);
}
