#include<iostream>
using namespace std;
#define size 20
#define maxSize 14

int number[size];
int head = 0;
int tail = 0;

void enqueue(int item){
    if((tail + 1) % size == head){
        printf("The queue is full.\n");
        return;
    }

    number[tail] = item;
    tail = (tail + 1) % size;
}


int dequeue(){

    if(head == tail){
        printf("The queue is empty.\n");
        return -1;
    }

    int item = number[head];
    head = (head + 1) % size;
    return item;
}

bool isEmpty(){
    return head == tail;
}


int BFS(int graph[maxSize][maxSize], int source, int target){
    
    int level[maxSize];

    for(int i = 0; i < maxSize; i++){
        level[i] = INT8_MAX;
    }

    enqueue(source);
    level[source] = 0;

    // cout << "the BFS start form " << source << ": \n" ;

    while(!isEmpty()){
        int u = dequeue();

        // printf("node %d (level - %d)\n", u, level[u]);
        for(int v = 0; v < maxSize; v++){

            if(level[v] == INT8_MAX && graph[u][v]){
                level[v] = level[u] + 1;
                enqueue(v);
            }
        }
    }
    return level[target];
}

int main(){

    int graph[maxSize][maxSize] = {0};
    
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[6][3] = graph[3][6] = 1;
    graph[3][5] = graph[5][3] = 1;
    graph[4][5] = graph[5][4] = 1;
    graph[5][7] = graph[7][5] = 1;
    graph[5][8] = graph[8][5] = 1;
    graph[4][9] = graph[9][4] = 1;
    graph[7][10] = graph[10][7] = 1;
    graph[9][11] = graph[11][9] = 1;
    graph[10][12] = graph[12][10] = 1;
    graph[12][13] = graph[13][12] = 1;
   
    
    
    

    int source = 1;
    int target = 10;
    int level = BFS(graph, source, target);

    if (level != INT8_MAX) {
        cout << "Level of node " << target << " from node " << source << " is " << level << endl;
    } else {
        cout << "Node " << target << " is not reachable from node " << source << endl;
    }

    return 0;
}
