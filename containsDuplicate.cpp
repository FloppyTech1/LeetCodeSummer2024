class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap; // Create a hashmap
        for (int i = 0; i < nums.size(); i++){ // iterate over the length of the array
            auto check = hashMap.find(nums[i]); // check if number is already in the hashmap
            if (check != hashMap.end()){ // check if element already exists in the hashmap
                return true;
            }
            else{
                hashMap[nums[i]] = 1; // add element to the hashmap
            }
        }
        return false;
    }
};
