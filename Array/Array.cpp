
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

// //查找一个无序数组中第k大的数
// int partition(vector<int>& nums, int left, int right) {
// 	if(left < right) {
// 		int i = left;
// 		int j = right;
// 		int tmp = nums[i];
// 		while(i < j) {
// 			while(i < j && nums[i] < nums[j])
// 				j--;
// 			if(i < j)
// 				nums[i++] = nums[j];
// 			while(i < j && nums[i] < nums[j])
// 				i++;
// 			if(i < j)
// 				nums[j--] = nums[i];
// 		}
// 		nums[i] = tmp;
// 		return i;
// 	}
// 	return left;
// }

// int findKth(vector<int>& nums, int left, int right, int k) {
// 	if(k > 0 && k <= right-left+1) {
// 		int pos = partition(nums, left, right);
// 		if(pos - left == k - 1)
// 			return nums[pos];
// 		else if(pos - left > k - 1) {
// 			return findKth(nums, left, pos-1, k);
// 		} else {
// 			return findKth(nums, pos+1, right, k-pos+left-1);
// 		}
// 	}
// 	return INT_MAX;
// }

//查找两个有序数组中第k大的数
int findKthSortedArrays(vector<int>& nums1, int start1, int len1, vector<int>& nums2, int start2, int len2, int k) {
	if(len2 > len1)
		return findKthSortedArrays(nums2, start2, len2, nums1, start1, len1, k);
	if(len1 == 0)
		return nums2[start2 + k - 1];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int total = nums1.size() + nums2.size();
	if(total % 2 == 1) {
		return findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), total/2 + 1);
	} else {
		return (findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), total/2) + findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), total/2 + 1)) / 2.0;
	}
}

int main() {
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(3);
	nums1.push_back(5);
	nums1.push_back(7);
	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(4);
	nums2.push_back(6);
	nums2.push_back(8);
	// quickSort(nums, 0, nums.size() - 1);
	// printVec(nums);
	int k = 7;
	int result = findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), k);
	cout<<result<<endl;
	return 0;
}


//Container With Most Water
// #include <iostream>
// #include <vector>

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

// //这道题第二次做的时候还是没有想出来，看完题解才理解别人的做法
// //思路就是分别从两边开始遍历，如果height[l]小于height[r]，则l++
// //否则就r--，因为如果height[l]小于height[r]，那r-1、r-2等跟l围成的
// //面积一定小于r跟l围成的面积
// int maxArea(vector<int>& height) {
// 	int result = -1;
// 	if(height.size() <= 0)
// 		return result;
// 	int l = 0;
// 	int r = height.size() - 1;
// 	while(l < r) {
// 		if(height[l] < height[r]) {
// 			result = max(result, height[l] * (r - l));
// 			l++;
// 		} else {
// 			result = max(result, height[r] * (r - l));
// 			r--;
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(4);
// 	nums.push_back(3);
// 	nums.push_back(2);
// 	int result = maxArea(nums);
// 	cout<<result<<endl;
// 	return 0;
// }


//3Sum
// #include <iostream>
// #include <vector>

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

// vector<vector<int> > threeSum(vector<int>& nums) {
// 	//
// }

// int main() {
// 	//
// }














