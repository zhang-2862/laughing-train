#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& nums, int target);

vector<int> searchRange(vector<int>& nums, int target) {
	int start = lowerBound(nums, target);
	if (start == nums.size() || nums[start] != target) {
		return{ -1,-1 };
	}
	else {
		int end = lowerBound(nums, target + 1) - 1;
		return{ start,end };
	}
}

int lowerBound(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size();
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}


int main() {

	int n;
	cin >> n;
	int val;
	vector<int>v;
	int target;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	cin >> target;
	v = searchRange(v, target);
	for (auto i : v) {
		cout << i << endl;
	}
	return 0;
}