// this is the test file
#ifndef TEST
#include <iostream>
#include <algorithm>
#include "Dijkstra.h"
#include "priorityQueue.h"
#include "BruteForceQueue.h"
#include "heapQueue.h"
#include <time.h>
#endif // !TEST
using namespace std;

int main() {
    // v is the number of vertex and should be smaller than 100000
    // e is the number of edges
    int v, e, terminal;    
    cout << "Please enter number of vertex and edges" << endl;
    cin >> v >> e;
    clock_t start, end;
    //cout << "Please enter the terminal (initially the source is 0): ";
    //cin >> terminal;

    //if (terminal < 0 || terminal >= v)
    //    cerr << "Invalid terminal";

    Dijkstra* G = new Dijkstra(v, e);  // create a new class to test algorithm

    // If we want to check the graph
    //G->printGraph();


    cout << endl;
    //G->Dijkstra_a(terminal);
    cout << "Following is the Dijkstra algorithm using adjacency graph and brute force queue" << endl;
    start = clock();
    for (int i = 1; i < v; ++i) {
       // cout << "The path to vertex " << i << " is: " << endl;
        G->Dijkstra_a_brute(i);
    }
    end = clock();
    cout << "The time used is " << end - start << " ms. " << endl << endl;


    cout << "Following is the Dijkstra algorithm using adjacency graph and heap queue" << endl;
    start = clock();
    for (int i = 1; i < v; ++i) {
        //cout << "The path to vertex " << i << " is: " << endl;
        G->Dijkstra_a_heap(i);
    }
    end = clock();
    cout << "The time used is " << end - start << " ms. " << endl << endl;

    cout << endl;
    cout << "Following is the Dijkstra algorithm using matrix graph and brute force queue" << endl;
    start = clock();
    for (int i = 1; i < v; ++i) {
        //cout << "The path to vertex " << i << " is: " << endl;
        G->Dijkstra_m_brute(i);
    }
    end = clock();
    cout << "The time used is " << end - start << " ms. " << endl << endl;

    cout << endl;
    cout << "Following is the Dijkstra algorithm using matrix graph and heap queue" << endl;
    start = clock();
    for (int i = 1; i < v; ++i) {
        //cout << "The path to vertex " << i << " is: " << endl;
        G->Dijkstra_m_heap(i);
    }
    end = clock();
    cout << "The time used is " << end - start << " ms. " << endl << endl;

    return 0;
}
