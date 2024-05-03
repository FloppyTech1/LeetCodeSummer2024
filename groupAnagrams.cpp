class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sortedString; // Create a hashmap of string and vector string
        vector<vector<string>> result; // Create a vector string to store the result
        string currWord = " "; // Create an empty string to create a copy of the current word
        for(int i = 0; i < strs.size(); i++){ // Loop of the list of strings
            currWord = strs[i]; // Create a copy
            sort(currWord.begin(), currWord.end()); // Sort the string
            sortedString[currWord].push_back(strs[i]); // Add the string to the hashmap with the key being it's sorted self
        }

        for(const auto& pair : sortedString) { // Loop over the hashmap 
            result.push_back(pair.second); // Add each vector string from the hasmap into the result vector string
        }

        return result;
    }
};
