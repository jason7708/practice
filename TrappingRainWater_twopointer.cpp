#include <utility>
#include <algorithm>
class Solution {
public:
    int trap(vector<int>& height) {
        //two pointers
        int maxleft = 0, maxright = 0;
        int left = 0, right = height.size()-1;
        int ans = 0;
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= maxleft) {
                    maxleft = height[left];
                }
                else {
                    ans += maxleft - height[left];
                }
                left++;
            }
            else {//height[right] < height[left]
                if(height[right] >= maxright) {
                    maxright = height[right];
                }
                else {
                    ans += maxright - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};