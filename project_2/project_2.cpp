// this is the test file
#include <iostream>
#include <algorithm>
#include "Dijkstra.h"
using namespace std;

int main() {
    // v is the number of vertex and should be smaller than 100000
    // e is the number of edges
    int v, e;    
    cout << "Please enter number of vertex and edges" << endl;
    cin >> v >> e;

    Dijkstra* G = new Dijkstra(v, e);  // create a new class to test algorithm
    G->printGraph();

    return 0;
}
