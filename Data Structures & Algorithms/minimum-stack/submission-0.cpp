class MinStack {
public:
    vector <int> arr;
    vector <int> minArr;
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);

        if (minArr.empty()) minArr.push_back(val);

        else {
            if (val < minArr.back()) minArr.push_back(val);
            else minArr.push_back(minArr.back());
        }
    }
    
    void pop() {
        arr.pop_back();
        minArr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return minArr.back();
    }
};
