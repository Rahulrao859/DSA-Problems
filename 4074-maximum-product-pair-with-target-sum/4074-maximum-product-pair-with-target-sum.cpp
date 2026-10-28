class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        
        int maxProduct = INT_MIN;
        vector<int> ans = {-1,-1};

        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                if(i != j && nums[i] + nums[j] == target && nums[i]>nums[j]){
                    int product = nums[i] * nums[j];

                    if(product > maxProduct){
                        maxProduct = product;
                        ans = {i,j};
                    }
                }
            }
        }
        return ans;
    }
};