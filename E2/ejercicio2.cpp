#include <iostream>
#include <string>

using namespace std;

int top= 0;

int* createHeap(int elements){
    int* heap = new int[elements];
    heap[0] = -1; //Seteo la posicion 0 con el -1
    return heap;
}

void insert (int*& heap, int value){
    top++;
    //inserta en la primera posicion vacía (al final)
    heap[top] = value;
    int actual = top;
    while (heap[actual/2] > value) { //la posicion actual/2 es el padre
        //flota si es menor
        heap[actual] = heap[actual/2]; 
        actual = actual / 2;
    }
    heap[actual] = value;
}

int heapify (int*& heap){
    int minElement, lastElement, son, actual;
    //el mas chico siempre en la raiz
    minElement = heap[1]; 
    //ultimo elemento está en la posicion tope -1
    lastElement = heap[top--]; 

    for (actual =1; actual *2 <= top; actual = son){  
        son = actual * 2;
        if (son != top && heap[son+1] < heap[son]){
            son++;
        }
        if (lastElement > heap[son]){
            heap[actual] = heap[son];
        }else {
            break;
        }
    }
    
    heap[actual] = lastElement;
    return minElement;
}

int main() {
    int amount;
    int element;
    
    cin >> amount; 

    int* heap = createHeap(amount); 

    for (int i=1; i<=amount; i++){
        cin >> element;
        insert(heap,element);
    }

    for (int i=0; i < amount; i++) {
        cout << heapify(heap) << endl;
    }
    
    delete[] heap;
    return 0;
    
}