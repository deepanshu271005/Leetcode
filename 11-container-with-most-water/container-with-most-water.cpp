class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
cin.tie(NULL);
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