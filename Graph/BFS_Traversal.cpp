#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // N = Number of Vertices      E = Number of edges
    int N, E;

    cout << "Enter the number of vertices: ";
    cin >> N;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> AdjList(N);

    // Entering Adjacency List
    for(int i = 1; i <= E; i++) {
        cout << "Enter the end points of the Edge " << i << ": ";

        int a, b;
        cin >> a >> b;

        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }

    // Printing Adjacency List
    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << AdjList[i][j] << ", ";
        }
        cout << endl;
    }

    // Breadth First Search (BFS)
    queue<int>Q;
    vector<int>status(N,0);

    Q.push(0);
    status[0]=1;

    cout << "BFS order is: ";

    while (!Q.empty()){

        int x = Q.front();
        Q.pop();
        cout << x << " ,";

        for(int k = 0; k < AdjList[x].size(); k++) {

            int e = AdjList[x][k];

            if (status[e] == 0) {
                status[e] = 1;
                Q.push(e);
            }
        }
    }
}

