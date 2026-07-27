class Solution {
public:
    int maxProduct(vector<int>& nums) {
    // Check if the array has less than 2 elements
    if (nums.size() < 2) {
        cout << "Array must have at least two elements!" << endl;
        return -1; // Error code
    }

    // Sort the array in non-decreasing order
    sort(nums.begin(), nums.end());

    // The two largest elements will be at the end of the sorted array
    int max1 = nums[nums.size() - 1]; // Largest element
    int max2 = nums[nums.size() - 2]; // Second largest element

    // Calculate and return the maximum product
    return (max1 - 1) * (max2 - 1);
    }
};