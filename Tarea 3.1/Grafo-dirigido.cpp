#include "Libreria.h"
#include <vector>

using namespace std;

struct limite {
    int from;
    int to;
};

void mostrar(const vector<limite>& limites,int numNodes){
    vector<vector<int>> listaAdj(numNodes);
    for (const auto& limite : limites) {
        listaAdj[limite.from].push_back(limite.to);
    }
    for (int i=0;i<numNodes;++i) {
        cout <<"Nodo"<<i<<" tiene aristas dirigidas a: ";
        for (const auto& vecino : listaAdj[i]) {
            cout << vecino << " ";
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
    cout<<"Grafo dirigido:\n";
    mostrar(limites, numNodes);
    return 0;
}
