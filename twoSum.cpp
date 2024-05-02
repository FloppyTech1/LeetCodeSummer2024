class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices; // Create a hashmap to store the value and it's index
        for(int i = 0; i < nums.size(); i++){ // Loop over the array
            int num2 = target - nums[i]; // Calculate the difference between target and the current num

            if (numIndices.find(num2) != numIndices.end()) { // If the difference is found in the hashmap, return the indice of the difference and the current num
                return {numIndices[num2], i};
            }

            numIndices[nums[i]] = i; // Otherwise, append the num and it's index to the hashmap
        }

        return {};
    }
};
