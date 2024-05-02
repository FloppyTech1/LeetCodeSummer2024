class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashS; // Create two hashmaps to store each character and it's occurences
        unordered_map<char, int> hashT;

        for(int i = 0; i < s.size(); i++){ // Loop over the string and count the occurences of each character
            auto check = hashS.find(s[i]);
            if (check != hashS.end()){
                hashS[s[i]] += 1;
            }
            else{
                hashS[s[i]] = 1;
            }
        }

        for(int i = 0; i < t.size(); i++){
            auto check = hashT.find(t[i]);
            if (check != hashT.end()){
                hashT[t[i]] += 1;
            }
            else{
                hashT[t[i]] = 1;
            }
        }

        if (hashS == hashT){ // Check if the maps are equal
            return true;
        }

        return false;

    }
};
