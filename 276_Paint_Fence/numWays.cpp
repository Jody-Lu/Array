class Solution {
public:
    int numWays(int n, int k) {
        // corner case
        // ways[1] = k, ways[2] = k * k, ways[i > 2] = (k - 1) * (ways[i - 1] + ways[i - 2])
        // Looks like we just think of it a bit differently.
        // You can use any of the k colors for the third, but if it's the same color as the second post,
        // then this color must be one of the k-1 not used for the first post. And if it's not the same
        // color as the second post, then it must be one of the k-1 not used for the second post.
        if(n < 2 || k <= 0) { return n * k; }
        if(n == 2) { return k * k; }
        int d1 = k, d2 = k * k, tmp;

        for(int i = 3; i < n; i++) {
            tmp = d2;
            d2 = (k - 1) * (d1 + d2);
            d1 = tmp;
        }

        return (k - 1) * (d1 + d2);

    }
};