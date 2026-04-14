#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph / Social Network structure
struct SocialNetwork {
    int numUsers;
    struct Node** adjLists;
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create social network
struct SocialNetwork* createNetwork(int users) {
    struct SocialNetwork* sn = (struct SocialNetwork*)malloc(sizeof(struct SocialNetwork));
    sn->numUsers = users;

    sn->adjLists = (struct Node**)malloc(users * sizeof(struct Node*));

    for (int i = 0; i < users; i++)
        sn->adjLists[i] = NULL;

    return sn;
}

// Add friendship (undirected edge)
void add_friendship(struct SocialNetwork* sn, int user1, int user2) {
    struct Node* newNode = createNode(user2);
    newNode->next = sn->adjLists[user1];
    sn->adjLists[user1] = newNode;

    newNode = createNode(user1);
    newNode->next = sn->adjLists[user2];
    sn->adjLists[user2] = newNode;
}

// BFS to find degrees of separation
int degrees_of_separation(struct SocialNetwork* sn, int start, int end) {
    int* visited = (int*)calloc(sn->numUsers, sizeof(int));
    int* distance = (int*)malloc(sn->numUsers * sizeof(int));

    int queue[100];
    int front = 0, rear = 0;

    // Initialize
    visited[start] = 1;
    distance[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        // If reached target
        if (current == end)
            return distance[current];

        struct Node* temp = sn->adjLists[current];

        while (temp) {
            int adj = temp->vertex;

            if (!visited[adj]) {
                visited[adj] = 1;
                distance[adj] = distance[current] + 1;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
    }

    return -1; // No connection
}

// Main function
int main() {
    struct SocialNetwork* sn = createNetwork(6);

    add_friendship(sn, 0, 1);
    add_friendship(sn, 0, 2);
    add_friendship(sn, 1, 3);
    add_friendship(sn, 2, 4);
    add_friendship(sn, 3, 5);

    int user1 = 0, user2 = 5;

    int result = degrees_of_separation(sn, user1, user2);

    if (result != -1)
        printf("Degrees of separation between %d and %d: %d\n", user1, user2, result);
    else
        printf("No connection found\n");

    return 0;
}