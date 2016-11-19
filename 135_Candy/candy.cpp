class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 0);
        candies[0] = 1;

        // left -> right
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                candies[i] = 1 + candies[i - 1];
            }
            else {
                candies[i] = 1;
            }
        }

        // right -> left
        int res = candies[n - 1];

        // if ratings[i] > ratings[i - 1], then candies[i] shoud > candies[i - 1]
        // if ratings[i] > ratings[i + 1], then candies[i] shoud > candies[i - 1]
        // so increment candies[i] would not violate the rule.
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = 1 + candies[i + 1];
            }
            res += candies[i];
        }

        return res;
    }
};