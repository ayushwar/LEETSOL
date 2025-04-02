// Implement Queue using Stack
// 02/04/2025
class MyQueue {
public:
    stack<int>first;
    stack<int>sec;

    
    void push(int x) {
      
      while(!first.empty()){
       sec.push(first.top());
       first.pop();
      }
        first.push(x);
        while(!sec.empty()){
            first.push(sec.top());
            sec.pop();
        }

        
    }
    
    int pop() {
        int res=first.top();
        first.pop();
        return res;
        
    }
    
    int peek() {
       return first.top();
        
    }
    
    bool empty() {
       return first.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
