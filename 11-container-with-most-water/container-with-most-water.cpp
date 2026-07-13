class Solution {
public:
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
    int maxArea(vector<int>& height) {
         
        int maxArea = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            int currArea = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, currArea);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};