#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> hashtable;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = hashtable.find(target - nums[i]);
		if (it != hashtable.end()) {
			return { it->second,i };
		}
		hashtable[nums[i]] = i;
	}
	return {};
}

int main() {
	int target;
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	cin >> target;
	vector<int> ret = twoSum(v, target);
	for (auto e : ret) {
		cout << e << endl;
	}
	return 0;
}