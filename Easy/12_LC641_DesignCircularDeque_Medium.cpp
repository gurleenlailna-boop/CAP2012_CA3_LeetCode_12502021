class MyCircularDeque {
private:
    vector<int> deque;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        front = 0;
        rear = -1;
        size = 0;
        deque.resize(k);
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;

        if (size == 0)
            rear = front;

        deque[front] = value;
        size++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        rear = (rear + 1) % capacity;

        if (size == 0)
            front = rear;

        deque[rear] = value;
        size++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return deque[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return deque[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
