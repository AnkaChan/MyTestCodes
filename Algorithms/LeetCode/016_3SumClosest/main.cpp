#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	static int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		if (nums.size() < 3) {
			return 0;
		}


		int valL, valM, valR;

		int closetSum = nums[0] + nums[1] + nums[2];

		for (int i = 0; i < nums.size() - 2; ++i) {
			int left = i, mid = i + 1, right = nums.size() - 1;

			valL = nums[left];
			/*if ( i > 0 && nums[i] == nums[i-1]){
			continue;
			}*/
			while (mid < right) {
				valM = nums[mid];
				valR = nums[right];

				if (target == valL + valM + valR) {
					return target;
				}

				if (abs(target - valL - valM - valR) < abs(target - closetSum)) {
					closetSum = valL + valM + valR;
				}

				if (target < valL + valM + valR) {
					//while (nums[mid] == valM && mid < right) ++mid;
					++mid;
				}
				else {
					//while (nums[right] == valR && right > mid) --right;
					--right;
				}
			}


		}
		return closetSum;
	}
};

int main() {
	vector<int> v = { 0,2,1,-3 };
	Solution::threeSumClosest(v, 1);
}