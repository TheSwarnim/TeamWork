class Solution {
public:
    int maximum69Number (int num) {
        int x = 1000;
        while(x > 0){
            if((num/x)%10 == 6){
                num += 3*x;
                break;
            } 
            x /= 10;
        }
        return num;
    }
};