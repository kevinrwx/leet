
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

// //查找两个有序数组中第k大的数
// int findKthSortedArrays(vector<int>& nums1, int start1, int len1, vector<int>& nums2, int start2, int len2, int k) {
// 	if(len1 > len2)
// 		return findKthSortedArrays(nums2, start2, len2, nums1, start1, len1, k);
// 	if(len1 == 0)
// 		return nums2[start2 + k - 1];
// 	if(k == 1)
// 		return min(nums1[start1], nums2[start2]);
// 	int pa = min(k/2, len1);
// 	int pb = k - pa;
// 	if(nums1[start1 + pa - 1] == nums2[start2 + pb - 1])
// 		return nums1[start1 + pa - 1];
// 	else if(nums1[start1 + pa - 1] < nums2[start2 + pb - 1])
// 		return findKthSortedArrays(nums1, start1+pa, len1-pa, nums2, start2, len2, k-pa);
// 	else
// 		return findKthSortedArrays(nums1, start1, len1, nums2, start2+pb, len2-pb, k-pb);
// }
// //这道题目跟上一道题目很类似，都是要求中位数，我们的思路就是先求数组第k位的数，然后再转化成求中位数
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// 	int total = nums1.size() + nums2.size();
// 	if(total % 2 == 1) {
// 		return findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), total/2 + 1);
// 	} else {
// 		return (findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), total/2) + findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), total/2 + 1)) / 2.0;
// 	}
// }

// int main() {
// 	vector<int> nums1;
// 	nums1.push_back(1);
// 	nums1.push_back(3);
// 	nums1.push_back(5);
// 	nums1.push_back(7);
// 	vector<int> nums2;
// 	nums2.push_back(2);
// 	nums2.push_back(4);
// 	nums2.push_back(6);
// 	nums2.push_back(8);
// 	int k = 5;
// 	int result = findKthSortedArrays(nums1, 0, nums1.size(),  nums2, 0, nums2.size(), k);
// 	cout<<result<<endl;
// 	return 0;
// }


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



//Remove Duplicates from Sorted Array
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

// int removeDuplicates(vector<int>& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		return 0;
// 	int i = 1;
// 	int len = 0;
// 	while(i < size) {
// 		if(nums[len] != nums[i])
// 			nums[++len] = nums[i];
// 		i++;
// 	}
// 	return len+1;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(3);
// 	nums.push_back(3);
// 	nums.push_back(4);
// 	cout<<"len before: "<<nums.size()<<endl;
// 	int len = removeDuplicates(nums);
// 	cout<<"len after: "<<len<<endl;
// 	return 0;
// }

//Remove Element
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

// int removeElement(vector<int>& nums, int val) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		return 0;
// 	int i = 0;
// 	int len = 0;
// 	while(i < size) {
// 		if(nums[i] != val) {
// 			nums[len++] = nums[i];
// 		}
// 		i++;
// 	}
// 	return len;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(3);
// 	nums.push_back(2);
// 	nums.push_back(2);
// 	nums.push_back(3);
// 	// nums.push_back(3);
// 	// nums.push_back(4);
// 	int val = 2;
// 	cout<<"len before: "<<nums.size()<<endl;
// 	int len = removeElement(nums, val);
// 	cout<<"len after: "<<len<<endl;
// 	return 0;
// }

//Next Permutation
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

// void swap(int* x, int* y) {
// 	int tmp = *x;
// 	*x = *y;
// 	*y = tmp;
// }

// void reverse(vector<int>& nums, int left, int right) {
// 	if(left <= right) {
// 		int l = left;
// 		int r = right;
// 		while(l <= r) {
// 			swap(&nums[l++], &nums[r--]);
// 		}
// 	}
// }

// void nextPermutation(vector<int>& nums) {
// 	int length = nums.size();
// 	if(length <= 0)
// 		return ;
// 	int i = length - 2;
// 	while(i >= 0) {
// 		if(nums[i] < nums[i+1])
// 			break;
// 		i--;
// 	}
// 	int j = length - 1;
// 	while(j > i) {
// 		if(nums[j] > nums[i])
// 			break;
// 		j--;
// 	}
// 	if(i >= 0)
// 		swap(&nums[i], &nums[j]);
// 	reverse(nums, i+1, length-1);
// }

// int main() {
// 	vector<int> nums;
// 	// nums.push_back(3);
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	printVec(nums);
// 	nextPermutation(nums);
// 	printVec(nums);
// 	return 0;
// }

//Search in Rotated Sorted Array
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

// int search(vector<int>& nums, int target) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		return -1;
// 	int l = 0;
// 	int r = size - 1;
// 	int mid;
// 	while(l <= r) {
// 		mid = l + (r - l) / 2;
// 		if(nums[mid] == target)
// 			return mid;
// 		if(nums[mid] >= nums[l]) {
// 			if(target >= nums[l] && target < nums[mid])
// 				r = mid - 1;
// 			else
// 				l = mid + 1;
// 		} else {
// 			if(target > nums[mid] && target <= nums[r])
// 				l = mid + 1;
// 			else
// 				r = mid - 1;
// 		}
// 	}
// 	return -1;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(4);
// 	nums.push_back(5);
// 	nums.push_back(6);
// 	nums.push_back(7);
// 	nums.push_back(0);
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	int target = 2;
// 	int index = search(nums, target);
// 	cout<<"index: "<<index<<endl;
// 	return 0;
// }


//Search for a Range
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

// //这种二分查找求下界的方法值得学习和记忆
// int binarySearchLow(vector<int>& nums, int target) {
// 	int l = 0;
// 	int r = nums.size() - 1;
// 	int mid;
// 	int ans = -1;
// 	while(l <= r) {
// 		mid = l + (r - l) / 2;
// 		if(nums[mid] >= target) {
// 			r = mid - 1;
// 			if(nums[mid] == target)
// 				ans = mid;
// 		} else {
// 			l = mid + 1;
// 		}
// 	}
// 	return ans;
// }
// //这种二分查找求上界的方法值得学习和记忆
// int binarySearchHigh(vector<int>& nums, int target) {
// 	int l = 0;
// 	int r = nums.size() - 1;
// 	int mid;
// 	int ans = -1;
// 	while(l <= r) {
// 		mid = l + (r - l) / 2;
// 		if(nums[mid] <= target) {
// 			l = mid + 1;
// 			if(nums[mid] == target)
// 				ans = mid;
// 		} else {
// 			r = mid - 1;
// 		}
// 	}
// 	return ans;
// }

// vector<int> searchRange(vector<int>& nums, int target) {
// 	vector<int> result;
// 	int left = binarySearchLow(nums, target);
// 	int right = binarySearchHigh(nums, target);
// 	result.push_back(left);
// 	result.push_back(right);
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(5);
// 	nums.push_back(7);
// 	nums.push_back(7);
// 	nums.push_back(8);
// 	nums.push_back(8);
// 	nums.push_back(10);
// 	int target = 8;
// 	vector<int> result = searchRange(nums, target);
// 	printVec(result);
// 	return 0;
// }


//Search Insert Position
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

// int binarySearchGreater(vector<int>& nums, int target) {
// 	int l = 0;
// 	int r = nums.size() - 1;
// 	int mid;
// 	int ans = -1;
// 	while(l <= r) {
// 		mid = l + (r - l) / 2;
// 		if(nums[mid] < target) {
// 			l = mid + 1;
// 		} else {
// 			r = mid - 1;
// 			ans = mid;
// 		}
// 	}
// 	return ans;
// }

// int searchInsert(vector<int>& nums, int target) {
// 	if(target > nums[nums.size() - 1])
// 		return nums.size();
// 	int index = binarySearchGreater(nums, target);
// 	return index;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(3);
// 	nums.push_back(5);
// 	nums.push_back(6);
// 	int target = 0;
// 	int index = searchInsert(nums, target);
// 	cout<<index<<endl;
// 	return 0;
// }

// //Combination Sum
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void printVec(vector<vector<int> >& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		cout<<"empty vector"<<endl;
// 	else {
// 		for(int i = 0; i < size; i++) {
// 			for(int j = 0; j < nums[i].size(); j++)
// 				cout<<nums[i][j]<<" ";
// 			cout<<endl;
// 		}
// 	}
// }

// void backtrack(vector<vector<int> >& result, vector<int>& tmp, vector<int>& candinates, int target, int index) {
// 	if(target == 0) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = index; i < candinates.size(); i++) {
// 			if(candinates[i] <= target) {
// 				tmp.push_back(candinates[i]);
// 				backtrack(result, tmp, candinates, target-candinates[i], i);
// 				tmp.pop_back();
// 			}
// 		}
// 	}
// }

// vector<vector<int> > combinationSum(vector<int>& candinates, int target) {
// 	vector<vector<int> > result;
// 	vector<int> tmp;
// 	int index = 0;
// 	if(candinates.size() <= 0 || target <= 0)
// 		return result;
// 	sort(candinates.begin(), candinates.end());
// 	backtrack(result, tmp, candinates, target, index);
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(2);
// 	nums.push_back(3);
// 	nums.push_back(6);
// 	nums.push_back(7);
// 	int target = 7;
// 	vector<vector<int> > result = combinationSum(nums, target);
// 	printVec(result);
// 	return 0;
// }


//Combination Sum II
// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// void printVec(vector<vector<int> >& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		cout<<"empty vector"<<endl;
// 	else {
// 		for(int i = 0; i < size; i++) {
// 			for(int j = 0; j < nums[i].size(); j++)
// 				cout<<nums[i][j]<<" ";
// 			cout<<endl;
// 		}
// 	}
// }

// void backtrack(set<vector<int> >& result, vector<int>& tmp, vector<int>& candinates, int target, int index) {
// 	if(target == 0) {
// 		result.insert(tmp);
// 	} else {
// 		for(int i = index; i < candinates.size(); i++) {
// 			if(candinates[i] <= target) {
// 				tmp.push_back(candinates[i]);
// 				backtrack(result, tmp, candinates, target-candinates[i], i+1);
// 				tmp.pop_back();
// 			}
// 		}
// 	}
// }

// vector<vector<int> > combinationSum2(vector<int>& candinates, int target) {
// 	set<vector<int> > res;
// 	vector<vector<int> > result;
// 	vector<int> tmp;
// 	int index = 0;
// 	if(candinates.size() <= 0 || target <= 0)
// 		return result;
// 	sort(candinates.begin(), candinates.end());
// 	backtrack(res, tmp, candinates, target, index);
// 	set<vector<int> >::iterator it;
// 	for(it = res.begin(); it != res.end(); it++) {
// 		result.push_back(*it);
// 	}
//  	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(10);
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(7);
// 	nums.push_back(6);
// 	nums.push_back(1);
// 	nums.push_back(5);
// 	int target = 8;
// 	vector<vector<int> > result = combinationSum2(nums, target);
// 	printVec(result);
// 	return 0;
// }

//First Missing Positive
#include <iostream>
#include <vector>

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

int firstMissingPositive(vector<int>& nums) {
	//
}

int main() {
	//
}


//Trapping Rain Water
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

// int trap(vector<int>& height) {
// 	//
// }

// int main() {
// 	//
// }



//Jump Game II
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

// int jump(vector<int>& nums) {
// 	//
// }

// int main() {
// 	//
// }


//Rotate Image
// #include <iostream>
// #include <vector>

// using namespace std;

// void printVec(vector<vector<int> >& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		cout<<"empty vector"<<endl;
// 	else {
// 		for(int i = 0; i < size; i++) {
// 			for(int j = 0; j < nums[i].size(); j++)
// 				cout<<nums[i][j]<<" ";
// 			cout<<endl;
// 		}
// 	}
// }

// void swap(int* x, int* y) {
// 	int tmp = *x;
// 	*x = *y;
// 	*y = tmp;
// }

// void rotate(vector<vector<int> >& matrix) {
// 	int n = matrix.size();
// 	for(int i = 0; i < n; i++) {
// 		for(int j = 0; j < n-i-1; j++) {
// 			swap(&matrix[i][j], &matrix[n-j-1][n-i-1]);
// 		}
// 	}
// 	for(int i = 0; i < n/2; i++) {
// 		vector<int> tmp = matrix[i];
// 		matrix[i] = matrix[n-i-1];
// 		matrix[n-i-1] = tmp;
// 	}
// }

// int main() {
// 	vector<vector<int> > matrix;
// 	vector<int> tmp1;
// 	tmp1.push_back(1);
// 	tmp1.push_back(2);
// 	tmp1.push_back(3);

// 	vector<int> tmp2;
// 	tmp2.push_back(4);
// 	tmp2.push_back(5);
// 	tmp2.push_back(6);

// 	vector<int> tmp3;
// 	tmp3.push_back(7);
// 	tmp3.push_back(8);
// 	tmp3.push_back(9);
// 	matrix.push_back(tmp1);
// 	matrix.push_back(tmp2);
// 	matrix.push_back(tmp3);
// 	rotate(matrix);
// 	return 0;
// }

//Maximum Subarray
// #include <iostream>
// #include <vector>
// #include <limits.h>

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

// //第一种o(n)复杂度的方法
// // int maxSubArray(vector<int>& nums) {
// // 	int length = nums.size();
// // 	if(length <= 0)
// // 		return 0;
// // 	int tmp = 0;
// // 	int maximum = INT_MIN;
// // 	for(int i = 0; i < length; i++) {
// // 		tmp = max(nums[i], tmp+nums[i]);
// // 		maximum = max(tmp, maximum);
// // 	}
// // 	return maximum;
// // }

// //使用divide and conquer的方法
// int maxSubArray(vector<int>& nums) {
// 	//
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(-2);
// 	nums.push_back(1);
// 	nums.push_back(-3);
// 	nums.push_back(4);
// 	nums.push_back(-1);
// 	nums.push_back(2);
// 	nums.push_back(1);
// 	nums.push_back(-5);
// 	nums.push_back(4);
// 	int result = maxSubArray(nums);
// 	cout<<result<<endl;
// 	return 0;
// }



//Spiral Matrix
// #include <iostream>
// #include <vector>

// using namespace std;

// void printVec(vector<vector<int> >& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		cout<<"empty vector"<<endl;
// 	else {
// 		for(int i = 0; i < size; i++) {
// 			for(int j = 0; j < nums[i].size(); j++)
// 				cout<<nums[i][j]<<" ";
// 			cout<<endl;
// 		}
// 	}
// }

// vector<int> spiralOrder(vector<vector<int> >& matrix) {
// 	vector<int> result;
// 	if(matrix.size() <= 0 || matrix[0].size() <= 0)
// 		return result;
// 	int m = matrix.size();
// 	int n = matrix[0].size();
// 	int i, j, k, w, x;
// 	for(i = 0; i < m/2; i++) {
// 		for(j = i; j < n-i; j++)
// 			result.push_back(matrix[i][j]);
// 		for(k = i+1; k < ; k++) 
// 			result.push_back(matrix[j][k]);
// 		for(w = m-1; w >= ; w--)
// 			result.push_back(matrix[][w]);
// 	}
// 	return result;
// }

// int main() {
// 	vector<vector<int> > matrix;
// 	vector<int> tmp1;
// 	tmp1.push_back(1);
// 	tmp1.push_back(2);
// 	tmp1.push_back(3);

// 	vector<int> tmp2;
// 	tmp2.push_back(4);
// 	tmp2.push_back(5);
// 	tmp2.push_back(6);

// 	vector<int> tmp3;
// 	tmp3.push_back(7);
// 	tmp3.push_back(8);
// 	tmp3.push_back(9);
// 	matrix.push_back(tmp1);
// 	matrix.push_back(tmp2);
// 	matrix.push_back(tmp3);
// 	printVec(matrix);
// 	return 0;
// }












