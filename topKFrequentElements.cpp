class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elements; // Hashmap to store occurences
        list<int> result; // List to store result
        for(int i = 0; i < nums.size(); i++){ // Loop over nums array
            elements[nums[i]] += 1; // Count occurences and store in hashmap
        }
        for(int i = 0; i < k; i++){ // Loop k times
            auto max = max_element(elements.begin(), elements.end(), [](const auto& a, const auto& b) {return a.second < b.second; }); // Find max value in hashmap
            result.push_back(max->first); // Append key value to result
            elements.erase(max); // Delete max
        }
        return vector<int>(result.begin(), result.end()); // Return result
    }
};
