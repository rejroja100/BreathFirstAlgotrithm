#include<iostream>
using namespace std;
#define size 20
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
