class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> types;
        int total = 0;
        int l = 0;

        for (int r = 0; r < fruits.size(); r++) {
            types[fruits[r]]++;

            // Shrink one-by-one until at most 2 distinct fruits remain
            while (types.size() > 2) {
                types[fruits[l]]--;
                if (types[fruits[l]] == 0) {
                    types.erase(fruits[l]);
                }
                l++;
            }

            total = max(total, r - l + 1);
        }

        return total;
    }
};