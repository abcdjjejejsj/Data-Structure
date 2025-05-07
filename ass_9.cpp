#include <iostream>
#include <vector>
using namespace std;

// MaxHeap Class
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int removeMax() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    void print() {
        cout << "MaxHeap: ";
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

// MinHeap Class
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int removeMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    void print() {
        cout << "MinHeap: ";
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

// Main Function
int main() {
    MaxHeap maxHeap;
    MinHeap minHeap;

    // Sample operations for MaxHeap
    maxHeap.insert(50);
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(40);
    maxHeap.insert(10);
    maxHeap.print();
    cout << "Max Removed: " << maxHeap.removeMax() << endl;
    maxHeap.print();

    cout << endl;

    // Sample operations for MinHeap
    minHeap.insert(50);
    minHeap.insert(30);
    minHeap.insert(20);
    minHeap.insert(40);
    minHeap.insert(10);
    minHeap.print();
    cout << "Min Removed: " << minHeap.removeMin() << endl;
    minHeap.print();

    return 0;
}
