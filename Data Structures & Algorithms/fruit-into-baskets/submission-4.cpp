class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int left = 0;
        int max_fruits = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            count[fruits[right]]++;

            // Shrink window from the left until we have at most 2 distinct types
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                left++;
            }

            max_fruits = max(max_fruits, right - left + 1);
        }

        return max_fruits;
    }
};