#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int maxn = 100;
vector<int> adjList[maxn];
int adjMatrix[maxn][maxn];
int color[maxn];

void DFS(int u) {
    color[u] = 1;
    for ( int i = 0; i < adjList[u].size(); i++ ) {
        int v = adjList[u][i];
        if ( color[v] == 0 ) {
            DFS(v);
        }
    }
    color[u] = 2;
}


int main() {
    const auto lang = "C++";

    ifstream f("bemenet.txt");
    if (!f.is_open()) {
        cerr << "Error " << endl;
        return 1;
    }

    int n , m;
    if (!(f >> n >> m)) return 0;

    int u,v,w;
    for (int i = 0; i<m; i++) {
        f >> u >> v >> w;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    f.close();
    DFS(1);


    return 0;
}