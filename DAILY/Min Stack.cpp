 // Min Stack
// 05/04/2025
class MinStack {
public:stack <pair<int,int>>s;
    MinStack() {
    } 
       
    
    void push(int x) {
      

            if(s.empty()){
                
                s.push({x,x});
            }   
            else{
               int mini=s.top().second;
                s.push({x,min(x,mini)});
            }
    }


    
    void pop() {
        
        s.pop();
       
        
    }
    
    int top() {
        return s.top().first;
        
    }
    
    int getMin() {
        return s.top().second;       
    }
};
