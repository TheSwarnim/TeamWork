class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    map<int, int> bmap;
    int book(int start, int end) {
        bmap[start]++;
        bmap[end]--;
        
        int res = 0, sum = 0;
        for(auto &p : bmap){
            sum += p.second;
            res = max(res, sum);
        }
        
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */