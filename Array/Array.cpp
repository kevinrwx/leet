
//Two Sum
// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;

// void printVec(vector<int>& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		cout<<"empty vector";
// 	else {
// 		for(int i = 0; i < size; i++) {
// 			cout<<nums[i]<<" ";
// 		}
// 	}
// 	cout<<endl;
// }

// //这道题目使用hashmap的时间复杂度是o(n)，空间复杂度也是O(n)
// //但是因为这道题目要求的是满足条件数字的index，所以不能用排序的方法解决
// //如果这道题目要求的是满足条件的数字，那么我们可以先排序，然后再从两头遍历
// vector<int> twoSum(vector<int>& nums, int target) {
// 	int size = nums.size();
// 	vector<int> result;
// 	if(size <= 0)
// 		return result;
// 	map<int, int> myMap;
// 	for(int i = 0; i < size; i++) {
// 		myMap[nums[i]] = i;
// 	}
// 	for(int i = 0; i < size; i++) {
// 		if(myMap.find(target - nums[i]) != myMap.end() && myMap[target - nums[i]] != i) {
// 			result.push_back(i);
// 			result.push_back(myMap[target - nums[i]]);
// 			break;
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(0);
// 	nums.push_back(4);
// 	nums.push_back(3);
// 	nums.push_back(0);
// 	int target = 0;
// 	vector<int> result = twoSum(nums, target);
// 	printVec(result);
// 	return 0;
// }

//Median of Two Sorted Arrays
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

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// 	//
// }

int partition(vector<int>& nums, int left, int right) {
	if(left < right) {
		int i = left;
		int j = right;
		int tmp = nums[i];
		while(i < j) {
			while(i < j && nums[i] < nums[j])
				j--;
			if(i < j)
				nums[i++] = nums[j];
			while(i < j && nums[i] < nums[j])
				i++;
			if(i < j)
				nums[j--] = nums[i];
		}
		nums[i] = tmp;
		return i;
	}
	return -1;
}

int findKth(vector<int>& nums, int k) {
	int left = 0;
	int right = nums.size() - 1;
	while(right - left > 1) {
		int index = partition(nums, left, right);
		int dist = index - left + 1;
		if(dist == k)
			return nums[k];
		else if(dist < k) {
			left = index + 1;
			k = k - dist;
		} else {
			right = index;
		}
	}
}

int findMedian(vector<int>& nums) {
	int size = nums.size();
	if(size <= 0)
		return -1;
	//
}

void quickSort(vector<int>& nums, int left, int right) {
	if(left < right) {
		int i = left;
		int j = right;
		int tmp = nums[i];
		while(i < j) {
			while(i < j && nums[i] < nums[j])
				j--;
			if(i < j)
				nums[i++] = nums[j];
			while(i < j && nums[i] < nums[j])
				i++;
			if(i < j)
				nums[j--] = nums[i];
		}
		nums[i] = tmp;
		quickSort(nums, left, i-1);
		quickSort(nums, i+1, right);
	}
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	quickSort(nums, 0, nums.size() - 1);
	printVec(nums);
	return 0;
}




















