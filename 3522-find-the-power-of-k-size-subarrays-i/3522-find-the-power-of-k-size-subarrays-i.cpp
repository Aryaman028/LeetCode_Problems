#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> q; 
        vector<int> res(n - k + 1, -1); // Result array initialized with -1
        int j = 0; // Index for the result array

        for (int i = 0; i < n; ++i) {
            // Start or extend the increasing sequence
            if (!q.empty() && nums[i] == q.back() + 1) {
                q.push_back(nums[i]);
            } else {
                q.clear(); // Reset the deque if the sequence breaks
                q.push_back(nums[i]);
            }

            // When the deque size becomes k, check if it's valid
            if (q.size() == k) {
                res[j++] = q.back(); // Store the maximum element (last in deque)
                q.pop_front(); // Slide the window by removing the first element
            } else if (q.size() < k && i >= k - 1) {
                res[j++] = -1; // For subarrays that fail the consecutive condition
            }
        }

        return res;
    }
};
