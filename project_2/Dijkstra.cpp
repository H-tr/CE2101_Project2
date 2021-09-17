#include <limits.h>
#include <stdio.h>
#include <stdbool.h>


void dijkstra(int n, int graph[n][n], int src);
int extractCheapest(int n, int Q[], int d[]);
void insertInOrder(int n, int Q[], int v);


void printSolution(int dist[], int n)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


int main()
{
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    dijkstra(9, graph, 0);

    return 0;
}

void dijkstra(int n, int graph[n][n], int src)
{
    int d[n];
    int pi[n];
    int s[n];

    for (int i = 0; i < n; i++)
    {

        d[i] = 999;
        s[i] = 0;
        pi[i] = NULL;
    }

    d[src] = 0;
    int Q[n];
    int count;

    Q[0] = src;

    int temp;
    for (count = 0; count < n - 1; count++) {

        int i=0;
        for(i=0;i<n;i++)
        {
            if(Q[i]==NULL) break;
        }
        int size = i;
        temp = extractCheapest(n,Q,d);
        s[temp] = 1;

        for (int v = 0; v < n; v++){
            if (s[v]!=1 && d[temp] + graph[temp][v] < d[v] && graph[temp][v]!=0)
            {
                d[v] = d[temp] + graph[temp][v];
                pi[v] = temp;
                insertInOrder(n, Q, v);
            }
        }
    }
    printSolution(d, n);
    return;
}

void insertInOrder(int n, int Q[],int v)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(Q[i]==NULL) break;
    }
    int size = i;
    Q[size] = v;
    Q[size+1] = NULL;
    return;
}


int extractCheapest(int n, int Q[], int d[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(Q[i]==NULL) break;
    }
    int size = i;
    int smallest = Q[0];
    if (size <= 1)
    {
        Q[0] = NULL;
        return smallest;
    }
    int loc = 0;
    for (int j = 1; j<size-1; j++)
    {
        if (d[smallest]>d[Q[j]])
        {
            smallest = Q[j];
            loc = j;
        }
    }

    if (loc == size-1)
    {
        Q[loc] = NULL;
    }
    else
    {
        for(int j=loc; j<size-1; j++)
        {
            Q[j] = Q[j+1];
        }
        Q[size-1] = NULL;
    }

    for (int c = 0; c < size - 1; c++)
    {
        printf("%d\n", Q[c]);
    }



    return smallest;

}
