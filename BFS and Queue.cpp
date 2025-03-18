#include<iostream>
using namespace std;
#define size 10
#define maxNode 11

int number[size];
int head = 0, tail = 0;

void enqueue(int item){

    if((tail + 1) % size == head){
        cout << "The queue is full" << endl;
        return;
    }

    number[tail] = item;
    tail = (tail + 1) % size;
}

int dequeue(){
    if(head == tail){
        cout << "the queue is empty." << endl;
        return -1;
    }

    int item = number[head];
    head = (head + 1) % size;
    return item;
}

bool isempty(){
    return head == tail;
}

void BFS(int graph[maxNode][maxNode], int source){

    int level[maxNode];
    for(int i = 0; i < maxNode; i++)
    level[i] = INT16_MAX;

    enqueue(source);
    level[source] = 0;

    cout << "BFS traversal from Node " << source << ": " << endl;

    while(!isempty()){
        
        int u = dequeue();
        printf("Node %d (level %d)", u, level[u]);
        cout << endl;

        for(int j = 0; j < maxNode; j++){
            if(graph[u][j] && level[j] == INT16_MAX){
                level[j] = level[u] + 1;
                enqueue(j);
            }
        }
    }
}

int main(){
    
    int graph[maxNode][maxNode] = {0};

    // Adding edges from the BFS tree in the image
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[4][6] = graph[6][4] = 1;
    graph[4][7] = graph[7][4] = 1;
    graph[4][8] = graph[8][4] = 1;
    graph[7][9] = graph[9][7] = 1;
    graph[9][10] = graph[10][9] = 1;
    graph[8][5] = graph[5][8] = 1;

    BFS(graph, 1); // Start BFS from node 1

    return 0;
}
