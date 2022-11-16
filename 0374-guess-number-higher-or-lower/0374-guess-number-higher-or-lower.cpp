/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    int guessNumber(int n) {
        long low = 1, high = n;
        long mid = (high - low)/2 + low;
        int g = guess(mid);
        // cout << low << " " << mid <<" " << high << " " << g << endl;
        while(g != 0){
            if(g < 0){
                high = mid - 1;
            } else if(g > 0) {
                low = mid + 1;
            }
            mid = (high - low)/2 + low;
            g = guess(mid);
            // cout << low << " " << mid <<" " << high << " " << g << endl;
        }
        
        return mid;
    }
};