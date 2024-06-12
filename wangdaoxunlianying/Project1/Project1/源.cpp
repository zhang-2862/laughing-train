#include <iostream>
#include <vector>
#include <unordered_set>
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

bool isHappy(int n) {
	if (n == 1) {
		return true;
	}
	unordered_set<int> us;
	while (us.find(n) != us.end() && n != 1) {
		us.insert(n);
		int sum = 0;
		while (n != 0) {
			int x = n % 10;
			sum += x * x;
			n /= 10;
		}
		n = sum;
	}
	if (n == 1) {
		return true;
	}
	else {
		return false;
	}
}
int main() {

	int n;
	cin >> n;
	if (isHappy(n)) {
		cout << "yes" << endl;
	}
	
	return 0;
}