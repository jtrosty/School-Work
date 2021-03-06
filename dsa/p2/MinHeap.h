
class MinHeap {
    private:

    // Resize functions
    char resizeSmaller();
    char resizeLarger();

    // Heapify
    char heapifyUp(int index);
    char heapifyDown(int index);

    public:
    int* heap;
    int size;
    int capacity;
    int resizeFactor = 2;


    MinHeap();
    ~MinHeap();

    char insert(int value);

    int extractMin();

    char deleteValue(int value);
    char deleteIndex(int index); 

    void traversal();

    void printHeap();
    void traversalOfMinHeap(std::ofstream& outfile); 
    int search(int itemToFind);

    char isEmpty();
};


////////////////////////////////////////////////////////////////////////
//                  Constructors and Destructor
MinHeap::MinHeap() {
    size = 0;
    int initialCapacity = 10;
    capacity = initialCapacity;
    heap = new int[initialCapacity];
}

MinHeap::~MinHeap() {
    if (heap == nullptr) {}
    else delete[] heap;
}

////////////////////////////////////////////////////////////////////////
//                  Insert
char MinHeap::insert(int value) {
    if (size == 0) {
        heap[size] = value;
        size++;
    }
    else {
        size++;
        heap[size - 1] = value;
        heapifyUp(size - 1);
    }

    // Check if a resize is requried
    if (size == capacity - 1)   resizeLarger();

    return 1;
}

////////////////////////////////////////////////////////////////////////
//                  Delete Value
char MinHeap::deleteIndex(int index) {
    if (size >= 0 && index < size) {
        heap[index] = heap[size - 1];
        size--;
        heapifyDown(index);
        if ((size <= (capacity / 4)) && (size != 0)) resizeSmaller();
        return 1;
    }
    else return 0;
}

char MinHeap::deleteValue(int value) {
    int index = search(value);
    if (index >= 0 && index < size) 
        return deleteIndex(index);
    return 0;
}

////////////////////////////////////////////////////////////////////////
//                  Extract Min
int MinHeap::extractMin() {
    int result;
    if (size >= 0) {
        result = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        if ((size <= (capacity / 4)) && (size != 0)) resizeSmaller();
        return result;
    }
    else return result;
}

////////////////////////////////////////////////////////////////////////
//                  Resize Functions
char MinHeap::resizeLarger() {
    capacity = capacity * 2;
    int* newHeap = new int[capacity];
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
    return 1;
}

char MinHeap::resizeSmaller() {
    capacity = capacity / 2;
    int* newHeap = new int[capacity];
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
    return 1;
}

////////////////////////////////////////////////////////////////////////
//                  Heapify Functions
char MinHeap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    int temp = -1;

    while (heap[index] < heap[parent]) {
        temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;

        // break out if we traded out the root
        if (parent == 0) break;
        
        // adjust index for going up
        index = parent;
        parent = (index - 1) /2;
    }

    return 1;
}

char MinHeap::heapifyDown(int index) {
    int child1 = (2 * index) + 1;
    int child2 = (2 * index) + 2;
    int temp = -1;

    while ((child1 < size) && (heap[index] > heap[child1] || heap[index] > heap[child2])) {
        // Case of the last item being a leaf with no sibling
        if (size - 1 == child1) {
            if (heap[index] > heap[child1]) {
                temp = heap[index];
                heap[index] = heap[child1];
                heap[child1] = temp;
                index = child1;
            }
        } 
        else if (heap[index] > heap[child1] || heap[index] > heap[child2]) {
            if (heap[child1] < heap[child2]) {
                temp = heap[index];
                heap[index] = heap[child1];
                heap[child1] = temp;
                index = child1;
            }
            else {
                temp = heap[index];
                heap[index] = heap[child2];
                heap[child2] = temp;
                index = child2;
            }
        }
        child1 = (index * 2) + 1;
        child2 = (index * 2) + 2;
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////
//                  Print Functions
void MinHeap::printHeap() {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            if (i == size-1) std::cout << heap[i] << std::endl;
            else std::cout << heap[i] << ", ";
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                  Traverse Heaps
void MinHeap::traversalOfMinHeap(std::ofstream& outFile) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            if (i == size-1) outFile << heap[i] << std::endl;
            else outFile << heap[i] << ", ";
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                  Traverse Heaps
int MinHeap::search(int itemToFind) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == itemToFind)  return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////////////////////////////
//                  Empty Functions
char MinHeap::isEmpty() {
    if (size <= 0) return 1;
    else return 0;
}