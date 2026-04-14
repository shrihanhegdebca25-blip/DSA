#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void add_edge(struct Graph* graph, int v, int w) {
    struct Node* newNode = createNode(w);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;

    newNode = createNode(v);
    newNode->next = graph->adjLists[w];
    graph->adjLists[w] = newNode;
}

// DFS helper for cycle detection
int dfsCycle(struct Graph* graph, int vertex, int visited[], int parent) {
    visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adj = temp->vertex;

        // If not visited → recurse
        if (!visited[adj]) {
            if (dfsCycle(graph, adj, visited, vertex))
                return 1;
        }
        // If visited and not parent → cycle found
        else if (adj != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

// Function to detect cycle
int detect_cycle(struct Graph* graph) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, -1)) {
                return 1; // True → cycle exists
            }
        }
    }

    return 0; // False → no cycle
}

// Main function
int main() {
    struct Graph* graph = createGraph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 1); // creates a cycle

    if (detect_cycle(graph))
        printf("Cycle detected (True)\n");
    else
        printf("No cycle (False)\n");

    return 0;
}