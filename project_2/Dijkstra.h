#pragma once
#ifndef _Dijkstra
#define _Dijkstra
#include <stdlib.h>
#include <time.h>
#include <queue>
#include "priorityQueue.h"
#include "BruteForceQueue.h"
#include "heapQueue.h"
#define max_size 2000

class vertex {
public:
    vertex(int i, int d, vertex* n) {
        index = i;
        weight = d;
        next = n;
    }
    int index;
    int weight;
    vertex* next;
};

class Dijkstra {
public:
    Dijkstra(int v, int e) {
        _v = v;     // initial the number of vertex in graph
        _e = e;     // initial the number of edges in graph
        init();     // initial the directed graph randomly for both matrix and adjacency
    }

    void printGraph();

    void init();
    void Dijkstra_a_brute(int terminal);
    void Dijkstra_a_heap(int terminal);
    void Dijkstra_m_brute(int terminal);
    void Dijkstra_m_heap(int terminal);

private:
    int _v, _e;
    int _graph_m[max_size][max_size];   // matrix graph
    int parent[max_size];               // record parent for each node
    int dis[max_size];                  // recode distance for each node
    vertex** _graph_a;                  // adjacency graph

    bool visit[max_size] = { false };   // auxiliary array

    void dfs(int s);
    bool checkConnect();
    void randGen();
    void printPath(int terminal);
};


#endif

inline void Dijkstra::printGraph()
{
    std::cout << "Following is the graph of matrix: " << std::endl;
    for (int i = 0; i < _v; ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < _v; ++j)
            std::cout << _graph_m[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Following is the graph of adjacency: " << std::endl;
    for (int i = 0; i < _v; ++i) {
        std::cout << i << ": ";
        vertex* cur = _graph_a[i];
        while (cur) {
            std::cout << cur->index << "(" << cur->weight << ")" << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
}

void Dijkstra::init()
{
    if (_v - 1 > _e) {  // check connect
        std::cout << "The graph cannot be connected";
        abort();    // stop the program
    }
    else if (_e > _v * (_v - 1)) {  // check duplicate edge or self loop
        std::cout << "The graph must have double edge or self loop";
        abort();    // stop the program
    }

    _graph_a = new vertex*[_v];

    memset(_graph_m, 0, _v * max_size);         // initialize matrix to 0
    memset(parent, 0, _v);                      // initialize parents to 0
    memset(dis, INT_MAX, _v);                   // initialize distance to 0
    for (int i = 0; i < _v; ++i)
        _graph_a[i] = NULL;

    randGen();  //randomly generalize the matrix
}

inline void Dijkstra::Dijkstra_a_brute(int terminal)
{
    // initialize parents to 0
    // initialize distance to max
    for (int i = 0; i < _v; ++i) {
        parent[i] = -1;
        dis[i] = INT_MAX;
    }

    BruteForceQueue q(dis);
    for (int i = 0; i < _v; ++i)
        q.add(i);

    dis[0] = 0;
    while (!q.empty()) {
        int u = q.pop();
        for (vertex* cur = _graph_a[u]; cur; cur = cur->next) {
            if (dis[cur->index] > dis[u] + cur->weight) {
                parent[cur->index] = u;
                dis[cur->index] = cur->weight + dis[u];
            }
        }
    }

    //printPath(terminal);
    //std::cout << " The shortest distance is: " << dis[terminal] << std::endl;
}

inline void Dijkstra::Dijkstra_a_heap(int terminal)
{
    // initialize parents to 0
    // initialize distance to max
    for (int i = 0; i < _v; ++i) {
        parent[i] = -1;
        dis[i] = INT_MAX;
    }

    heapQueue q(dis);
    for (int i = 0; i < _v; ++i)
        q.add(i);

    dis[0] = 0;
    while (!q.empty()) {
        int u = q.pop();
        for (vertex* cur = _graph_a[u]; cur; cur = cur->next) {
            if (dis[cur->index] > dis[u] + cur->weight) {
                parent[cur->index] = u;
                dis[cur->index] = cur->weight + dis[u];
                q.maintain(cur->index);
            }
        }
    }

    //printPath(terminal);
    //std::cout << " The shortest distance is: " << dis[terminal] << std::endl;
}

inline void Dijkstra::Dijkstra_m_brute(int terminal)
{
    // initialize parents to 0
    // initialize distance to max
    for (int i = 0; i < _v; ++i) {
        parent[i] = -1;
        dis[i] = INT_MAX;
    }

    BruteForceQueue q(dis);
    for (int i = 0; i < _v; ++i)
        q.add(i);

    dis[0] = 0;
    while (!q.empty()) {
        int u = q.pop();
        for (int i = 0; i < _v; ++i) {
            if (_graph_m[u][i] && dis[i] > dis[u] + _graph_m[u][i]) {
                parent[i] = u;
                dis[i] = _graph_m[u][i] + dis[u];
            }
        }
    }

    //printPath(terminal);
    //std::cout << " The shortest distance is: " << dis[terminal] << std::endl;
}

inline void Dijkstra::Dijkstra_m_heap(int terminal)
{
    // initialize parents to 0
    // initialize distance to max
    for (int i = 0; i < _v; ++i) {
        parent[i] = -1;
        dis[i] = INT_MAX;
    }

    heapQueue q(dis);
    for (int i = 0; i < _v; ++i)
        q.add(i);

    dis[0] = 0;
    while (!q.empty()) {
        int u = q.pop();
        for (int i = 0; i < _v; ++i) {
            if (_graph_m[u][i] && dis[i] > dis[u] + _graph_m[u][i]) {
                parent[i] = u;
                dis[i] = _graph_m[u][i] + dis[u];
                q.maintain(i);
            }
        }
    }

    //printPath(terminal);
    //std::cout << " The shortest distance is: " << dis[terminal] << std::endl;
}

inline void Dijkstra::dfs(int s)
{
    visit[s] = true;
    for (int i = 0; i < _v; ++i)
        if (!visit[i] && _graph_m[s][i])
            dfs(i);
}

inline bool Dijkstra::checkConnect()
{
    dfs(0);
    for (int i = 0; i < _v; ++i)
        if (!visit[i])
            return true;
    return false;
}

inline void Dijkstra::randGen()
{
    srand((unsigned)time(NULL));
    int a, b;

    do {
        memset(_graph_m, 0, _v * max_size);
        for (int i = 0; i < _e; ++i) {
            do {
                a = rand() % _v;
                b = rand() % _v;
            } while (a == b || _graph_m[a][b]);
            _graph_m[a][b] = rand() % 20 + 1;   // weight range from 1 to 20
        }
    } while (checkConnect());

    for (int i = 0; i < _v; ++i) {
        for (int j = 0; j < _v; ++j) {
            if (_graph_m[i][j]) {
                if (!_graph_a[i])
                    _graph_a[i] = new vertex(j, _graph_m[i][j], NULL);
                else {
                    vertex* cur = _graph_a[i];
                    while (cur->next)
                        cur = cur->next;
                    cur->next = new vertex(j, _graph_m[i][j], NULL);
                }
            }
        }
    }
}

inline void Dijkstra::printPath(int terminal)
{
    if (parent[terminal] == -1) {
        std::cout << "The shortest path is: ";
        return;
    }
    printPath(parent[terminal]);
    std::cout << terminal << " ";
}
