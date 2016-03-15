
//Two Sum
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printVec(vector<int>& nums) {
	int size = nums.size();
	if(size <= 0)
		cout<<"empty vector";
	else {
		for(int i = 0; i < size; i++) {
			cout<<nums[i]<<" ";
		}
	}
	cout<<endl;
}

vector<int> twoSum(vector<int>& nums, int target) {
	int size = nums.size();
	vector<int> result;
	if(size <= 0)
		return result;
	map<int, int> myMap;
	for(int i = 0; i < size; i++) {
		myMap[nums[i]] = i;
	}
	for(int i = 0; i < size; i++) {
		if(myMap.find(target - nums[i]) != myMap.end() && myMap[target - nums[i]] != i) {
			result.push_back(i);
			result.push_back(myMap[target - nums[i]]);
			break;
		}
	}
	return result;
}

int main() {
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(0);
	int target = 0;
	vector<int> result = twoSum(nums, target);
	printVec(result);
	return 0;
}