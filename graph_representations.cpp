#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

const int N = 1000; // number of nodes in graph

// Adjacency Matrix -> N*N
bool adjMatrixBool[N][N]; // unweighted graph
int adjMatrix[N][N];	// weighted graph

vector<int> AdjMatrixMult[N][N]; // for multiple edges graph

// if edges are very small compared to the number of nodes
// --> E
map<pair<int, int>, bool> sparseAdjMatrixBool; // <<i, j>, exist>  unweighted
map<pair<int, int>, int> sparseAdjMatrix; // <<i, j>, cost> weighed

map<pair<int, int>, vector<int>> sparseAdjMatrixMlutBool; // unweighted and multiple edges graph
map<pair<int, int>, vector<pair<int, int>>> sparseAdjMatrixMlut; //weighted and multiple edges graph

/***************/

// Adjacency List --> E
vector<int> adjListBool[N]; // unweighted
vector<pair<int, int>> adjList[N]; // weighted

int main() {
  return 0;
}
