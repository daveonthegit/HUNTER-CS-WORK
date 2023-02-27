#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left =0; int sum= 0;
        for (auto i:nums){
            sum+=i;
        }
        for (int i = 0; i<nums.size();i++) {
            left+=nums[i];
            sum-=nums[i];
            if (left==sum)
                return i;
        }
        return -1;
    }
};