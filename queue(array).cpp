#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T * arr;
    int head;
    int tail;
    size_t cap;
    size_t sz;

public:
    Queue(const size_t& value = 10){
        arr = new T[value];
        head = -1;
        tail = -1;
        cap = value;
        sz = 0;
    }
    ~Queue(){
        delete[] arr;
    }
    const T front() const {
        if(is_empty()){
            throw std::runtime_error("Queue is empty!");
        }
        return arr[head];
    }
    const T back() const{
        if(is_empty()){
            throw std::runtime_error("Queue is empty!");
        }
        return arr[tail];
    }
    bool is_empty() const { 
        return sz == 0;
    }
    bool is_full() const { 
        return sz == cap;
    }

    size_t size() const { 
        return sz;
    }
    void enqueue( const T& value ) {
        if(is_full()){
            //resize
            size_t new_cap = cap * 2;
            T* new_arr = new T[new_cap];
            for(size_t i = 0; i<cap; i++){
                new_arr[i] = arr[(i + head) % cap];
            }
            delete[] arr;
            head = 0;
            tail = sz-1;
            arr = new_arr;
            cap = new_cap;
        }
        if(is_empty()){
            head = 0;
            tail = 0;
            arr[0] = value;
        }
        else{
            tail = (tail + 1) % cap;
            arr[tail] = value;
        }
        sz++;
    }

    void dequeue() {
        if(is_empty()){
            throw std::runtime_error("Queue is Empty");
        }
        head = (head + 1) % cap;
        sz--;
    }
    void display(){
        cout << sz << "\n";
        for(size_t i=0; i<sz; i++){
            cout << arr[(i + head) % cap] << " ";
        }
        cout << "\n";
    }
};
int main() {    

    Queue<int> q(5);
    for(int i=1; i<=5; i++){
        q.enqueue(i);
    }
    for(int i=1; i<=3; i++){
        q.dequeue();
    }
    for(int i=1; i<=3; i++){
        q.enqueue(i);
    }
    for(int i=1; i<=3; i++){
        q.enqueue(i + 69);
    }
    q.display();  
    return 0;
}