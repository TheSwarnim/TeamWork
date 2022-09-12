class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score= 0, n = tokens.size();
        priority_queue<int> pq;
        sort(begin(tokens), end(tokens));
        int i = 0, j = n-1;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
            } else {
                if(i == j or score == 0) break;
                score--;
                power += tokens[j--];
            }
        }
        return score;
    }
};