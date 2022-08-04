class Solution {
public:
    int mirrorReflection(int p, int q) {
        // m*p = n*q
        // m : number of room extensions + 1
        // n : number of reflections + 1
        int m = q, n = p;
        while(m%2 == 0 && n%2 == 0){
            m /= 2;
            n /= 2;
        }
        if(m%2 == 0 && n%2 == 1) return 0;
        if(m%2 == 1 && n%2 == 0) return 2;
        if(m%2 == 1 && n%2 == 1) return 1;
        return -1;
    }
};