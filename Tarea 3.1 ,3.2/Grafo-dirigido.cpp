#include "Libreria.h"
#include <vector>

using namespace std;

struct limite {
    int from;
    int to;
};

void printGraph(const vector<limite>& limites, int numNodes) {
    vector<vector<int>> adjList(numNodes);

    for (const auto& limite : limites) {
        adjList[limite.from].push_back(limite.to);
    }
    
    for (int i = 0; i < numNodes; ++i) {
        cout << "Nodo " << i << " tiene aristas dirigidas a: ";
        for (const auto& neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}

int main() {
    int numNodes = 5;

    vector<limite> limites = {
        {0, 1},
        {0, 4},
        {1, 3},
        {2, 0},
        {2, 1},
        {3, 2},
        {3, 4},
        {4, 0}
    };

    // Imprimir el grafo dirigido
    cout << "Grafo dirigido:\n";
    printGraph(limites, numNodes);

    return 0;
}
