
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

// //这种思路是比较清晰的，先排序，然后对于排好序的每个元素，再用一次two sum，找到所有可能的结果，最后再去重
// //但是现在这种思路在leetcode上提交代码时会超时，因此对于重复元素需要跳过
// vector<vector<int> > threeSum(vector<int>& nums) {
// 	vector<vector<int> > result;
// 	int size = nums.size();
// 	if(size < 3)
// 		return result;
// 	sort(nums.begin(), nums.end());
// 	for(int i = 0; i < size-2; i++) {
// 		int j = i+1;
// 		int k = size-1;
// 		while(j < k) {
// 			int sum = nums[i] + nums[j] + nums[k];
// 			if(sum == 0) {
// 				vector<int> tmp;
// 				tmp.push_back(nums[i]);
// 				tmp.push_back(nums[j]);
// 				tmp.push_back(nums[k]);
// 				result.push_back(tmp);;
// 				j++;
// 				k--;
// 			} else if(sum < 0) {
// 				j++;
// 			} else {
// 				k--;
// 			}
// 		}
// 	}
// 	sort(result.begin(), result.end());
// 	result.erase(unique(result.begin(), result.end()), result.end());
// 	return result;
// }

// //对于跳过重复元素的思路需要注意
// vector<vector<int> > threeSum(vector<int>& nums) {
// 	vector<vector<int> > result;
// 	int size = nums.size();
// 	if(size < 3)
// 		return result;
// 	sort(nums.begin(), nums.end());
// 	for(int i = 0; i < size-2; i++) {
// 		int j = i+1;
// 		int k = size-1;
// 		while(j < k) {
// 			int sum = nums[i] + nums[j] + nums[k];
// 			if(sum == 0) {
// 				vector<int> tmp;
// 				tmp.push_back(nums[i]);
// 				tmp.push_back(nums[j]);
// 				tmp.push_back(nums[k]);
// 				result.push_back(tmp);;
// 				j++;
// 				k--;
// 				while(j < k && nums[j] == nums[j-1])
// 					j++;
// 				while(j < k && nums[k] == nums[k+1])
// 					k--;
// 			} else if(sum < 0) {
// 				j++;
// 			} else {
// 				k--;
// 			}
// 		}
// 		while(i < size-1 && nums[i] == nums[i+1])
// 			i++;
// 	}
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(-1);
// 	nums.push_back(0);
// 	nums.push_back(1);
// 	nums.push_back(0);
// 	// nums.push_back(2);
// 	// nums.push_back(-1);
// 	// nums.push_back(-4);
// 	vector<vector<int> > result = threeSum(nums);
// 	printVec(result);
// 	return 0;
// }

//3Sum Closest
// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// //这道题仍然借鉴了3sum那题的经验，只不过里面判断的思路相对简单，即sum比target小就把j++，sum比target大就把k--
// //同时对于更接近target值的结果做一下记录
// int threeSumClosest(vector<int>& nums, int target) {
// 	int result = 0;
// 	int size = nums.size();
// 	if(size < 3)
// 		return result;
// 	sort(nums.begin(), nums.end());
// 	int delta = INT_MAX;
// 	for(int i = 0; i < size-2; i++) {
// 		int j = i+1;
// 		int k = size-1;
// 		while(j < k) {
// 			int sum = nums[i]+nums[j]+nums[k];
// 			if(sum <= target) {
// 				if(target-sum <= delta) {
// 					delta = abs(sum - target);
// 					result = sum;
// 				}
// 				j++;
// 			} else {
// 				if(sum-target <= delta) {
// 					delta = abs(sum-target);
// 					result = sum;
// 				}
// 				k--;
// 			}
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(0);
// 	nums.push_back(2);
// 	nums.push_back(1);
// 	nums.push_back(-3);
// 	int target = 1;
// 	int result = threeSumClosest(nums, target);
// 	cout<<result<<endl;
// 	return 0;
// }


//4Sum
// #include <iostream>
// #include <vector>

// using namespace std;

// int threeSumClosest(vector<int>& nums, int target) {
// 	int result = 0;
// 	int size = nums.size();
// 	if(size < 3)
// 		return result;
// 	sort(nums.begin(), nums.end());
// 	int delta = INT_MAX;
// 	for(int i = 0; i < size-2; i++) {
// 		int j = i+1;
// 		int k = size-1;
// 		while(j < k) {
// 			int sum = nums[i]+nums[j]+nums[k];
// 			if(sum <= target) {
// 				if(target-sum <= delta) {
// 					delta = abs(sum - target);
// 					result = sum;
// 				}
// 				j++;
// 			} else {
// 				if(sum-target <= delta) {
// 					delta = abs(sum-target);
// 					result = sum;
// 				}
// 				k--;
// 			}
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(0);
// 	nums.push_back(2);
// 	nums.push_back(1);
// 	nums.push_back(-3);
// 	int target = 1;
// 	int result = threeSumClosest(nums, target);
// 	cout<<result<<endl;
// 	return 0;
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

// //由于题目要求只能使用常数的空间，所以我们不能再额外开辟数组
// //所以我们的思路就是在index为i的位置上存放(i+1)大小的数
// int firstMissingPositive(vector<int>& nums) {
// 	int length = nums.size();
// 	if(length <= 0)
// 		return 1;
// 	int pos = 0;
// 	while(pos < length) {
// 		//循环条件要注意nums[pos] != nums[nums[pos] - 1]，因为有边界条件[1,1]
// 		if(nums[pos] != pos+1 && nums[pos] >= 1 && nums[pos] <= length && nums[pos] != nums[nums[pos] - 1])
// 			swap(&nums[pos], &nums[nums[pos] - 1]);
// 		else
// 			pos++;
// 	}
// 	for(int i = 0; i < length; i++)
// 		if(nums[i] != i+1) {
// 			return i+1;
// 		}
// 	return pos+1;
// }

// int main() {
// 	vector<int> nums;
// 	// nums.push_back(3);
// 	// nums.push_back(4);
// 	// nums.push_back(1);
// 	nums.push_back(1);
// 	int result = firstMissingPositive(nums);
// 	cout<<result<<endl;
// 	return 0;
// }


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

// //这次看题稍微有了点思路，但是还是不能完整的思考出来，还需要看原来的题解
// int trap(vector<int>& height) {
// 	int length = height.size();
// 	if(length <= 2)
// 		return 0;
// 	int maxId;
// 	int maximum = 0;
// 	int result = 0;
// 	for(int i = 0; i < length; i++) {
// 		if(height[i] >= maximum) {
// 			maxId = i;
// 			maximum = height[i];
// 		}
// 	}
// 	int left = height[0];
// 	for(int i = 0; i < maxId; i++) {
// 		if(left <= height[i])
// 			left = height[i];
// 		else
// 			result += (left - height[i]);
// 	}
// 	int right = height[length - 1];
// 	for(int i = length-1; i > maxId; i--) {
// 		if(right <= height[i])
// 			right = height[i];
// 		else
// 			result += (right - height[i]);
// 	}
// 	return result;
// }

// int main() {
// 	// 0,1,0,2,1,0,1,3,2,1,2,1
// 	vector<int> height;
// 	height.push_back(0);
// 	height.push_back(1);
// 	height.push_back(0);
// 	height.push_back(2);
// 	height.push_back(1);
// 	height.push_back(0);
// 	height.push_back(1);
// 	height.push_back(3);
// 	height.push_back(2);
// 	height.push_back(1);
// 	height.push_back(2);
// 	height.push_back(1);
// 	int result = trap(height);
// 	cout<<result<<endl;
// 	return 0;
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

// //这道题果真还是采用了我第一次的思想，就是在当前每一步能跳的最远距离中，根据下一步能跳的最远的距离来决定当前
// //这步要跳到哪里，所以主要根据cur、next两个变量来决定啥时候更新步数
// int jump(vector<int>& nums) {
// 	int size = nums.size();
// 	//由于只有一个元素时，系统的结果是0步，所以就在前面多加了这一步的判断
// 	if(size <= 1)
// 		return 0;
// 	int step = 0;
// 	int i = 0;
// 	//当前步能跳的最远距离
// 	int cur;
// 	//下一步能跳的最远距离
// 	int next;
// 	while(i < size) {
// 		cur = i + nums[i];
// 		if(cur >= size-1) {
// 			step++;
// 			break;
// 		}
// 		next = 0;
// 		int id = 0;
// 		for(int j = i+1; j <= cur; j++) {
// 			if(next < j + nums[j]) {
// 				next = j + nums[j];
// 				id = j;
// 			}
// 		}
// 		i = id;
// 		step++;
// 	}
// 	return step;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(2);
// 	nums.push_back(3);
// 	nums.push_back(1);
// 	nums.push_back(1);
// 	nums.push_back(4);

// 	int result = jump(nums);
// 	cout<<result<<endl;
// 	return 0;
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

// void printVec(vector<vector<bool> >& nums) {
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
// 	vector<vector<bool> >tmp(m, vector<bool>(n, false));
// 	int i, j, k, w, r;
// 	for(i = 0; i <= m/2; i++) {
// 		for(j = 0; j < n; j++) {
// 			if(tmp[i][j] == false) {
// 				tmp[i][j] = true;
// 				result.push_back(matrix[i][j]);
// 			}
// 		}
// 		for(k = 0; k < m; k++) {
// 			if(n-i-1 >= 0 && n-i-1 < n && tmp[k][n-i-1] == false) {
// 				tmp[k][n-i-1] = true;
// 				result.push_back(matrix[k][n-i-1]);
// 			}
// 		}
// 		for(w = n-1; w >= 0; w--) {
// 			if(m-i-1 >= 0 && m-i-1 < m && tmp[m-i-1][w] == false) {
// 				tmp[m-i-1][w] = true;
// 				result.push_back(matrix[m-i-1][w]);
// 			}
// 		}
// 		for(r = m-1; r >= 0; r--) {
// 			if(tmp[r][i] == false) {
// 				tmp[r][i] = true;
// 				result.push_back(matrix[r][i]);
// 			}
// 		}
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
// 	// printVec(matrix);
// 	vector<int> result = spiralOrder(matrix);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<" ";
// 	cout<<endl;
// 	return 0;
// }


//Jump Game
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

// //这道题目的思路就是保持每一步都是最大的能移动步数，即保证局部最优
// bool canJump(vector<int>& nums) {
// 	int length = nums.size();
// 	if(length <= 0)
// 		return true;
// 	int step = nums[0];
// 	for(int i = 1; i < length; i++) {
// 		if(step > 0) {
// 			step = max(--step, nums[i]);
// 		} else {
// 			return false;
// 		}
// 	}
// 	return true;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(3);
// 	nums.push_back(2);
// 	nums.push_back(1);
// 	nums.push_back(0);
// 	nums.push_back(4);
// 	bool result = canJump(nums);
// 	if(result)
// 		cout<<"can jump"<<endl;
// 	else
// 		cout<<"can't jump"<<endl;
// 	return 0;
// }

// //Merge Intervals
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Interval {
// 	int start;
// 	int end;
// 	Interval() : start(0), end(0) {}
// 	Interval(int s, int e) : start(s), end(e) {}
// };

// void printInterval(vector<Interval>& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		cout<<"empty vector";
// 	else {
// 		for(int i = 0; i < size; i++) {
// 			cout<<nums[i].start<<" "<<nums[i].end<<endl;
// 		}
// 	}
// 	cout<<endl;
// }

// bool static cmp(Interval a, Interval b) {
// 	return a.start < b.start;
// }

// vector<Interval> merge(vector<Interval>& intervals) {
// 	vector<Interval> result;
// 	int length = intervals.size();
// 	if(length <= 0)
// 		return result;
// 	sort(intervals.begin(), intervals.end(), cmp);
// 	result.push_back(intervals[0]);
// 	for(int i = 1; i < length; i++) {
// 		int tmp = result.size();
// 		if(result[tmp - 1].end < intervals[i].start)
// 			result.push_back(intervals[i]);
// 		else if(result[tmp - 1].end >= intervals[i].start && result[tmp - 1].end < intervals[i].end) {
// 			result[tmp - 1].end = intervals[i].end;
// 		} else {
// 			//
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	vector<Interval> intervals;
// 	Interval* tmp1 = new Interval(1, 3);
// 	Interval* tmp2 = new Interval(2, 6);
// 	intervals.push_back(*tmp2);
// 	intervals.push_back(*tmp1);
// 	vector<Interval> result = merge(intervals);
// 	printInterval(result);
// 	return 0;
// }

//Insert Interval
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Interval {
// 	int start;
// 	int end;
// 	Interval() : start(0), end(0) {}
// 	Interval(int s, int e) : start(s), end(e) {}
// };

// void printInterval(vector<Interval>& nums) {
// 	int size = nums.size();
// 	if(size <= 0)
// 		cout<<"empty vector";
// 	else {
// 		for(int i = 0; i < size; i++) {
// 			cout<<nums[i].start<<" "<<nums[i].end<<endl;
// 		}
// 	}
// 	cout<<endl;
// }

// bool static cmp(Interval a, Interval b) {
// 	return a.start < b.start;
// }

// vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
// 	vector<Interval> result;
// 	int length = intervals.size();
// 	if(length <= 0)
// 		return result;
// 	sort(intervals.begin(), intervals.end(), cmp);

// 	return result;
// }

// int main() {
// 	vector<Interval> intervals;
// 	Interval* tmp1 = new Interval(1, 3);
// 	Interval* tmp2 = new Interval(2, 6);
// 	intervals.push_back(*tmp2);
// 	intervals.push_back(*tmp1);
// 	vector<Interval> result = merge(intervals);
// 	printInterval(result);
// 	return 0;
// }


//Spiral Matrix II
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

// vector<vector<int> > generateMatrix(int n) {
// 	//
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(3);
// 	nums.push_back(2);
// 	nums.push_back(1);
// 	nums.push_back(0);
// 	nums.push_back(4);
// 	bool result = canJump(nums);
// 	if(result)
// 		cout<<"can jump"<<endl;
// 	else
// 		cout<<"can't jump"<<endl;
// 	return 0;
// }


//Unique Paths
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

// int uniquePaths(int m, int n) {
// 	if(m <= 0 || n <= 0)
// 		return 0;
// 	vector<int> tmp(m, 1);
// 	for(int i = 1; i < n; i++) {
// 		for(int j = 1; j < m; j++) {
// 			tmp[j] += tmp[j-1];
// 		}
// 	}
// 	return tmp[m-1];
// }

// int main() {
// 	int m = 3;
// 	int n = 4;
// 	int result = uniquePaths(m, n);
// 	cout<<result<<endl;
// 	return 0;
// }

//Unique Paths II
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

// int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
// 	if(obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0)
// 		return 0;
// 	int n = obstacleGrid.size();
// 	int m = obstacleGrid[0].size();
// 	vector<vector<int> > tmp(n, vector<int>(m, 0));
// 	for(int i = 0; i < n; i++) {
// 		if(obstacleGrid[i][0] == 0)
// 			tmp[i][0] = 1;
// 		else
// 			break;
// 	}
// 	for(int j = 0; j < m; j++) {
// 		if(obstacleGrid[0][j] == 0)
// 			tmp[0][j] = 1;
// 		else
// 			break;
// 	}
// 	for(int i = 1; i < n; i++) {
// 		for(int j = 1; j < m; j++) {
// 			if(obstacleGrid[i][j] == 0)
// 				tmp[i][j] = tmp[i-1][j] + tmp[i][j-1];
// 			else
// 				tmp[i][j] = 0;
// 		}
// 	}
// 	return tmp[n-1][m-1];
// }

// int main() {
// 	vector<vector<int> > obstacleGrid;
// 	vector<int> tmp1;
// 	tmp1.push_back(0);
// 	tmp1.push_back(0);
// 	tmp1.push_back(0);
// 	vector<int> tmp2;
// 	tmp2.push_back(0);
// 	tmp2.push_back(1);
// 	tmp2.push_back(0);
// 	vector<int> tmp3;
// 	tmp3.push_back(0);
// 	tmp3.push_back(0);
// 	tmp3.push_back(0);
// 	obstacleGrid.push_back(tmp1);
// 	obstacleGrid.push_back(tmp2);
// 	obstacleGrid.push_back(tmp3);
// 	int result = uniquePathsWithObstacles(obstacleGrid);
// 	cout<<result<<endl;
// 	return 0;
// }

//Minimum Path Sum
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

// int minPathSum(vector<vector<int> >& grid) {
// 	if(grid.size() <= 0 || grid[0].size() <= 0)
// 		return 0;
// 	int m = grid.size();
// 	int n = grid[0].size();
// 	vector<int> tmp(n, 0);
// 	for(int j = 0; j < n; j++) {
// 		if(j != 0)
// 			tmp[j] = tmp[j-1] + grid[0][j];
// 		else
// 			tmp[j] = grid[0][0];
// 	}
// 	for(int i = 1; i < m; i++) {
// 		for(int j = 0; j < n; j++) {
// 			if(j != 0)
// 				tmp[j] = min(tmp[j-1], tmp[j]) + grid[i][j];
// 			else
// 				tmp[j] += grid[i][j];
// 		}
// 	}
// 	return tmp[n-1];
// }


// int main() {
// 	vector<vector<int> > grid;
// 	vector<int> tmp1;
// 	tmp1.push_back(1);
// 	tmp1.push_back(2);
// 	tmp1.push_back(3);
// 	vector<int> tmp2;
// 	tmp2.push_back(1);
// 	tmp2.push_back(2);
// 	tmp2.push_back(3);
// 	vector<int> tmp3;
// 	tmp3.push_back(1);
// 	tmp3.push_back(2);
// 	tmp3.push_back(3);
// 	grid.push_back(tmp1);
// 	grid.push_back(tmp2);
// 	grid.push_back(tmp3);
// 	int result = minPathSum(grid);
// 	cout<<result<<endl;
// 	return 0;
// }

//Plus One
// #include <iostream>
// #include <vector>
// #include <algorithm>

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

// //使用额外的空间来存储结果
// vector<int> plusOne(vector<int>& digits) {
// 	vector<int> result;
// 	int size = digits.size();
// 	if(size <= 0)
// 		return result;
// 	int tmp = 1;
// 	for(int i = size - 1; i >= 0; i--) {
// 		result.push_back((tmp+digits[i]) % 10);
// 		tmp = (tmp+digits[i]) / 10;
// 	}
// 	if(tmp != 0)
// 		result.push_back(tmp);
// 	reverse(result.begin(), result.end());
// 	return result;
// }

// //不适用额外的空间存储结果
// vector<int> plusOne(vector<int>& digits) {
// 	int size = digits.size();
// 	if(size <= 0)
// 		return digits;
// 	reverse(digits.begin(), digits.end());
// 	int flag = 1;
// 	for(int i = 0; i < size; i++) {
// 		int tmp = flag + digits[i];
// 		digits[i] = tmp % 10;
// 		flag = tmp / 10;
// 	}
// 	//要注意这点，记得最后要将最后进位的结果push到digits中
// 	if(flag != 0)
// 		digits.push_back(flag);
// 	reverse(digits.begin(), digits.end());
// 	return digits;
// }

// int main() {
// 	vector<int> digits;
// 	digits.push_back(1);
// 	digits.push_back(2);
// 	digits.push_back(3);
// 	vector<int> result = plusOne(digits);
// 	printVec(result);
// 	return 0;
// }


//Set Matrix Zeroes
// #include <iostream>
// #include <vector>
// #include <algorithm>

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

// //这种方法使用O(m+n)额外的空间，因此还有继续优化的空间
// void setZeroes(vector<vector<int> >& matrix) {
// 	if(matrix.size() <= 0 || matrix[0].size() <= 0)
// 		return ;
// 	int m = matrix.size();
// 	int n = matrix[0].size();
// 	vector<bool> row(m, true);
// 	vector<bool> col(n, true);
// 	for(int i = 0; i < m; i++) {
// 		for(int j = 0; j < n; j++) {
// 			if(matrix[i][j] == 0) {
// 				row[i] = false;
// 				col[j] = false;
// 			}
// 		}
// 	}
// 	for(int i = 0; i < m; i++) {
// 		if(row[i] == false) {
// 			for(int j = 0; j < n; j++)
// 				matrix[i][j] = 0;
// 		}
// 	}
// 	for(int i = 0; i < n; i++) {
// 		if(col[i] == false) {
// 			for(int j = 0; j < m; j++)
// 				matrix[j][i] = 0;
// 		}
// 	}
// }

// //这种方法并没有使用额外的空间，只是复用了第0行跟第0列的空间
// //不过对于由于matrix[0][0]只能表示一行或者是一列，因此需要额外申请空间来表示第0行跟第0列
// void setZeroes(vector<vector<int> >& matrix) {
// 	if(matrix.size() <= 0 || matrix[0].size() <= 0)
// 		return ;
// 	int m = matrix.size();
// 	int n = matrix[0].size();
// 	//代表第0行
// 	int row;
// 	//代表第0列
// 	int col;
// 	for(int i = 0; i < m; i++) {
// 		if(matrix[i][0] == 0) {
// 			col = 0;
// 			break;
// 		}
// 	}

// 	for(int j = 0; j < n; j++) {
// 		if(matrix[0][j] == 0) {
// 			row = 0;
// 			break;
// 		}
// 	}

// 	for(int i = 1; i < m; i++) {
// 		for(int j = 1; j < n; j++) {
// 			if(matrix[i][j] == 0) {
// 				matrix[0][j] = 0;
// 				matrix[i][0] = 0;
// 			}
// 		}
// 	}
// 	for(int i = 1; i < m; i++) {
// 		if(matrix[i][0] == 0) {
// 			for(int j = 1; j < n; j++)
// 				matrix[i][j] = 0;
// 		}
// 	}
// 	for(int i = 1; i < n; i++) {
// 		if(matrix[0][i] == 0) {
// 			for(int j = 1; j < m; j++)
// 				matrix[j][i] = 0;
// 		}
// 	}
// 	if(row == 0) {
// 		for(int i = 0; i < n; i++)
// 			matrix[0][i] = 0;
// 	}
// 	if(col == 0) {
// 		for(int i = 0; i < m; i++)
// 			matrix[i][0] = 0;
// 	}
// }

// int main() {
// 	// vector<int> digits;
// 	// digits.push_back(1);
// 	// digits.push_back(2);
// 	// digits.push_back(3);
// 	// vector<int> result = plusOne(digits);
// 	// printVec(result);
// 	return 0;
// }

//Search a 2D Matrix
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

// //刚开始没有看清这道题第二条性质，也就是每一行的第一个数要比上一行的第二个数大，只是简单以为行有序，列有序
// //因此没有在使用二分查找的方法时，想的比较复杂
// bool searchMatrix(vector<vector<int> >& matrix, int target) {
// 	if(matrix.size() <= 0 || matrix[0].size()<= 0)
// 		return false;
// 	//行 row
// 	int m = matrix.size();
// 	//列 col
// 	int n = matrix[0].size();
// 	int low = 0;
// 	int high = m * n - 1;
// 	int mid;
// 	while(low <= high) {
// 		mid = low + (high - low) / 2;
// 		if(matrix[mid / n][mid % n] == target) {
// 			return true;
// 		} else if(matrix[mid / n][mid % n] < target) {
// 			low = mid + 1;
// 		} else {
// 			high  = mid - 1;
// 		}
// 	}
// 	return false;
// }

// int main() {
// 	vector<vector<int> > matrix;
// 	vector<int> tmp1;
// 	tmp1.push_back(1);
// 	tmp1.push_back(3);
// 	tmp1.push_back(5);
// 	tmp1.push_back(7);
// 	vector<int> tmp2;
// 	tmp2.push_back(10);
// 	tmp2.push_back(11);
// 	tmp2.push_back(16);
// 	tmp2.push_back(20);
// 	vector<int> tmp3;
// 	tmp3.push_back(23);
// 	tmp3.push_back(30);
// 	tmp3.push_back(34);
// 	tmp3.push_back(50);
// 	matrix.push_back(tmp1);
// 	matrix.push_back(tmp2);
// 	matrix.push_back(tmp3);
// 	int target = 3;
// 	bool result = searchMatrix(matrix, target);
// 	if(result)
// 		cout<<"find target"<<endl;
// 	else
// 		cout<<"not find target"<<endl;
// 	return 0;
// }


//Sort Colors
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

// //这是采用基数排序的思路解决的，其实对于位数比较少的情况，可以不采用基数排序的方法
// void sortColors(vector<int>& nums) {
// 	int size = nums.size();
// 	if(size <= 1)
// 		return ;
// 	vector<int> count(3, 0);
// 	for(int i = 0; i < size; i++) {
// 		count[nums[i]]++;
// 	}
// 	for(int i = 1; i < count.size(); i++)
// 		count[i] += count[i-1];
// 	vector<int> tmp(size);
// 	for(int i = size-1; i >= 0; i--) {
// 		tmp[count[nums[i]] - 1] = nums[i];
// 		count[nums[i]]--;
// 	}
// 	for(int i = 0; i < size; i++)
// 		nums[i] = tmp[i];
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(2);
// 	nums.push_back(1);
// 	nums.push_back(0);
// 	nums.push_back(0);
// 	printVec(nums);
// 	sortColors(nums);
// 	printVec(nums);
// 	return 0;
// }

//Subsets
// #include <iostream>
// #include <vector>

// using namespace std;

// void printVec(vector<vector<int> >& nums) {
// 	if(nums.size() <= 0)
// 		cout<<"empty vector";
// 	else {
// 		for(int i = 0; i < nums.size(); i++) {
// 			if(nums[i].size() <= 0)
// 				cout<<"empty"<<endl;
// 			else {
// 				for(int j = 0; j < nums[i].size(); j++)
// 					cout<<nums[i][j]<<" ";
// 				cout<<endl;
// 			}
// 		}
// 	}
// }

// //这种方法比较传统，但是跟回溯法的公式很贴切，我觉得是解决子集问题的一个好方法
// void backtrack(vector<vector<int> >& result, vector<int>& nums, vector<bool>& flag, vector<bool>& tmp) {
// 	if(flag.size() == nums.size()) {
// 		vector<int> tmp;
// 		for(int i = 0; i < flag.size(); i++) {
// 			if(flag[i] == true) {
// 				tmp.push_back(nums[i]);
// 			}
// 		}
// 		result.push_back(tmp);
// 	} else {
// 		for(int j = 0; j < tmp.size(); j++) {
// 			flag.push_back(tmp[j]);
// 			backtrack(result, nums, flag, tmp);
// 			flag.pop_back();
// 		}
// 	}
// }

// vector<vector<int> > subsets(vector<int>& nums) {
// 	int size = nums.size();
// 	vector<vector<int> > result;
// 	if(size <= 0) {
// 		vector<int> tmp;
// 		result.push_back(tmp);
// 		return result;
// 	}
// 	vector<bool> flag;
// 	vector<bool> tmp;
// 	tmp.push_back(true);
// 	tmp.push_back(false);
// 	backtrack(result, nums, flag, tmp);
// 	return result;
// }

//第二种方法，算是回溯法公式的变形吧，比第一种思路要简单一些，这种思路可以很好的处理含有重复元素的子集问题
// void backtrack(vector<vector<int> >& result, vector<int>& nums, vector<int>& tmp, int k) {
// 	if(k == nums.size()) {
// 		return ;
// 	} else {
// 		for(int i = k; i < nums.size(); i++) {
// 			tmp.push_back(nums[i]);
// 			result.push_back(tmp);
// 			backtrack(result, nums, tmp, i+1);
// 			tmp.pop_back();
// 		}
// 	}
// }

// vector<vector<int> > subsets(vector<int>& nums) {
// 	int size = nums.size();
// 	vector<vector<int> > result;
// 	vector<int> tmp;
// 	result.push_back(tmp);
// 	if(size <= 0) {
// 		return result;
// 	}
// 	backtrack(result, nums, tmp, 0);
// 	return result;
// }

// //第三种方法，这种方法并没有完全按照backtrack公式的方式，说实话，这种思路也挺独特的，但是由于不能推广，所以只用了解
// vector<vector<int> > subsets(vector<int> &nums) {
// 	int length = nums.size();
// 	vector<vector<int> > results;
// 	if(length == 0)
// 		return results;
// 	vector<int> tmp;
// 	results.push_back(tmp);
// 	for(int i = 0; i < length; i++) {
// 		vector<vector<int> > tmpRes;
// 		for(int j = 0; j < results.size(); j++) {
// 			tmp = results[j];
// 			tmp.push_back(nums[i]);
// 			sort(tmp.begin(), tmp.end());
// 			tmpRes.push_back(tmp);
// 		}
// 		for(int k = 0; k < tmpRes.size(); k++) {
// 			results.push_back(tmpRes[k]);
// 		}
// 	}
// 	return results;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(3);
// 	vector<vector<int> > result = subsets(nums);
// 	printVec(result);
// 	return 0;
// }


// //Word Search
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<pair<int, int> > getCandinates(vector<vector<char> >& board, vector<vector<bool> >& flag, int x, int y, char ch) {
// 	vector<pair<int, int> > candinates;
// 	int m = board.size();
// 	int n = board[0].size();
// 	if(x-1 >= 0 && flag[x-1][y] == false && board[x-1][y] == ch)
// 		candinates.push_back(make_pair(x-1, y));
// 	if(x+1 < m && flag[x+1][y] == false && board[x+1][y] == ch)
// 		candinates.push_back(make_pair(x+1, y));
// 	if(y-1 >= 0 && flag[x][y-1] == false && board[x][y-1] == ch) 
// 		candinates.push_back(make_pair(x, y-1));
// 	if(y+1 < n && flag[x][y+1] == false && board[x][y+1] == ch)
// 		candinates.push_back(make_pair(x, y+1));
// 	return candinates;
// }

// //我发现自己第二次做这道题目时，还是继续延续了自己第一次的思路,但是由于少了提前结束部分的代码，导致这个答案
// //刚开始时并不能过最大测试用例
// void backtrack(vector<vector<char> >& board, vector<vector<bool> >& flag, vector<pair<int, int> >& candinates , int index, string word, bool* result) {
// 	if(index == word.length()-1) {
// 		*result = true;
// 		return ;
// 	} else {
// 		for(int i = 0; i < candinates.size(); i++) {
// 			vector<pair<int, int> > tmp = getCandinates(board, flag, candinates[i].first, candinates[i].second, word[index+1]);
// 			if(tmp.size() > 0) {
// 				flag[candinates[i].first][candinates[i].second] = true;
// 				backtrack(board, flag, tmp, index+1, word, result);
// 				//需要加上这个条件，即如果找到结果以后，就提前跳出循环，否则过不了最大测试用例
// 				if(*result == true)
// 					break;
// 				flag[candinates[i].first][candinates[i].second] = false;
// 			}
// 		}
// 	}
// }

// bool exist(vector<vector<char> >& board, string word) {
// 	int length = word.length();
// 	if(length <= 0 || board.size() <= 0 || board[0].size() <= 0)
// 		return false;
// 	int m = board.size();
// 	int n = board[0].size();
// 	vector<vector<bool> > flag(m, vector<bool>(n, false));
// 	bool result = false;
// 	vector<pair<int, int> > candinates;
// 	for(int i = 0; i < m; i++) {
// 		for(int j = 0; j < n; j++) {
// 			if(board[i][j] == word[0]) {
// 				candinates.push_back(make_pair(i, j));
// 			}
// 		}
// 	}
// 	if(candinates.size() <= 0)
// 		return false;
// 	backtrack(board, flag, candinates, 0, word, &result);
// 	return result;
// }

// int main() {
// 	vector<vector<char> > board;

// 	vector<char> tmp1;
// 	tmp1.push_back('A');
// 	tmp1.push_back('B');
// 	tmp1.push_back('C');
// 	tmp1.push_back('E');

// 	vector<char> tmp2;
// 	tmp2.push_back('S');
// 	tmp2.push_back('F');
// 	tmp2.push_back('C');
// 	tmp2.push_back('S');

// 	vector<char> tmp3;
// 	tmp3.push_back('A');
// 	tmp3.push_back('D');
// 	tmp3.push_back('E');
// 	tmp3.push_back('E');
	

// 	board.push_back(tmp1);
// 	board.push_back(tmp2);
// 	board.push_back(tmp3);

// 	string str = "AAB";
// 	bool isExist = exist(board, str);
// 	if(isExist)
// 		cout<<"exist"<<endl;
// 	else
// 		cout<<"not exist"<<endl;
// 	return 0;
// }


// //Remove Duplicates from Sorted Array II
// #include <iostream>
// #include <vector>

// using namespace std;

// //这道题是双指针的题目，每次循环时要先统计当前元素的个数，然后将前两个元素复制给后一个指针
// //代码写的比较烂，不想改了，能理解意思就行
// int removeDuplicates(vector<int>& nums) {
// 	int len = nums.size();
// 	if(len <= 2)
// 		return len;
// 	int index = 0;
// 	int i = 0;
// 	while(i < len) {
// 		int j = i;
// 		int count = 0;
// 		while(j < len && nums[j] == nums[i]) {
// 			j++;
// 			count++;
// 		}
// 		if(count <= 2) {
// 			for(int k = i; k < j; k++)
// 				nums[index++] = nums[k];
// 		} else {
// 			for(int k = i; k < i+2; k++)
// 				nums[index++] = nums[k];
// 		}
// 		i = j;
// 	}
// 	return index;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(1);
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(2);
// 	nums.push_back(3);

// 	int result = removeDuplicates(nums);
// 	cout<<result<<endl;
// 	return 0;
// }


// //Search in Rotated Sorted Array II
// #include <iostream>
// #include <vector>

// using namespace std;

// bool search(vector<int>& nums, int target) {
// 	//
// }

// int main() {
// 	//
// }


//Largest Rectangle in Histogram
// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// int largestRectangleArea(vector<int>& heights) {
// 	int len = heights.size();
// 	if(len <= 0)
// 		return 0;
// 	heights.push_back(0);
// 	stack<int> st;
// 	int result = 0;
// 	int i = 0;
// 	len = heights.size();
// 	while(i < len) {
// 		if(st.empty() || heights[st.top()] <= heights[i]) {
// 			st.push(i++);
// 		} else {
// 			int id = st.top();
// 			st.pop();
// 			result = max(result, heights[id] * (st.empty() ? i : (i - st.top() - 1)));
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	vector<int> heights;
// 	heights.push_back(2);
// 	heights.push_back(1);
// 	heights.push_back(5);
// 	heights.push_back(6);
// 	heights.push_back(2);
// 	heights.push_back(3);
// 	int result = largestRectangleArea(heights);
// 	cout<<result<<endl;
// 	return 0;
// }

//Maximal Rectangle
// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// int largestRectangleArea(vector<int>& heights) {
// 	if(heights.size() <= 0)
// 		return 0;
// 	heights.push_back(0);
// 	int len = heights.size();
// 	int i = 0;
// 	int result = 0;
// 	stack<int> st;
// 	while(i < len) {
// 		if(st.empty() || heights[st.top()] <= heights[i])
// 			st.push(i++);
// 		else {
// 			int tmp = st.top();
// 			st.pop();
// 			result = max(result, heights[tmp] * (st.empty() ? i : (i - st.top() - 1)));
// 		}
// 	}
// 	return result;
// }

// int maximalRectangle(vector<vector<char> >& matrix) {
// 	if(matrix.size() <= 0 || matrix[0].size() <= 0)
// 		return 0;
// 	int m = matrix.size();
// 	int n = matrix[0].size();
// 	int result = 0;
// 	vector<vector<int> > tmp(m, vector<int>(n, 0));
// 	for(int i = 0; i < n; i++) {
// 		if(matrix[0][i] == '0')
// 			tmp[0][i] = 0;
// 		else
// 			tmp[0][i] = 1;
// 	}
// 	for(int i = 1; i < m; i++) {
// 		for(int j = 0; j < n; j++) {
// 			if(matrix[i][j] == '0')
// 				tmp[i][j] = 0;
// 			else
// 				tmp[i][j] = tmp[i-1][j] + 1;
// 		}
// 	}
// 	for(int i = 0; i < m; i++) {
// 		result = max(result, largestRectangleArea(tmp[i]));
// 	}
// 	return result;
// }

// int main() {
// 	vector<vector<char> > matrix;
// 	vector<char> tmp1;
// 	tmp1.push_back('0');
// 	tmp1.push_back('1');
// 	tmp1.push_back('0');

// 	vector<char> tmp2;
// 	tmp2.push_back('1');
// 	tmp2.push_back('1');
// 	tmp2.push_back('1');

// 	vector<char> tmp3;
// 	tmp3.push_back('0');
// 	tmp3.push_back('1');
// 	tmp3.push_back('1');

// 	matrix.push_back(tmp1);
// 	matrix.push_back(tmp2);
// 	matrix.push_back(tmp3);
// 	int result = maximalRectangle(matrix);

// 	cout<<result<<endl;
// 	return 0;
// }

//Merge Sorted Array
// #include <iostream>
// #include <vector>

// using namespace std;

// //这种方式仍然需要O(m)d的额外空间
// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
// 	if(m <= 0) {
// 		for(int i = 0; i < n; i++)
// 			nums1[i] = nums2[i];
// 		return ;
// 	}
// 	if(n <= 0) {
// 		return ;
// 	}
// 	vector<int> tmp(m, 0);
// 	for(int i = 0; i < m; i++)
// 		tmp[i] = nums1[i];
// 	int i = 0;
// 	int j = 0;
// 	int index = 0;
// 	while(i < m && j < n) {
// 		if(tmp[i] <= nums2[j])
// 			nums1[index++] = tmp[i++];
// 		else 
// 			nums1[index++] = nums2[j++];
// 	}
// 	while(i < m) {
// 		nums1[index++] = tmp[i++];
// 	}
// 	while(j < n) {
// 		nums1[index++] = nums2[j++];
// 	}
// }

// //这种方法比较合适，从后往前进行遍历，所以并不需要额外的空间，而且代码比较简洁
// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
// 	int index = m+n-1;
// 	int i = m-1;
// 	int j = n-1;
// 	while(i >= 0 && j >= 0) {
// 		if(nums1[i] >= nums2[j])
// 			nums1[index] = nums1[i--];
// 		else
// 			nums1[index] = nums2[j--];
// 		index--;
// 	}
// 	while(i >= 0) {
// 		nums1[index--] = nums1[i--];
// 	}
// 	while(j >= 0) {
// 		nums1[index--] = nums2[j--];
// 	}
// }


// int main() {
// 	vector<int> nums1(10, 0);
// 	nums1[0] = 1;
// 	nums1[1] = 2;
// 	nums1[2] = 4;
// 	nums1[3] = 5;


// 	vector<int> nums2;
// 	nums2.push_back(3);
// 	nums2.push_back(6);
// 	nums2.push_back(7);
// 	nums2.push_back(8);
// 	nums2.push_back(9);
// 	nums2.push_back(10);

// 	merge(nums1, 4, nums2, 6);

// 	for(int i = 0; i < nums1.size(); i++)
// 		cout<<nums1[i]<<" ";
// 	cout<<endl;
// 	return 0;
// }

//Subsets II
// #include <iostream>
// #include <vector>

// using namespace std;

// void printVec(vector<vector<int> >& nums) {
// 	if(nums.size() <= 0)
// 		cout<<"empty vector";
// 	else {
// 		for(int i = 0; i < nums.size(); i++) {
// 			if(nums[i].size() <= 0)
// 				cout<<"empty"<<endl;
// 			else {
// 				for(int j = 0; j < nums[i].size(); j++)
// 					cout<<nums[i][j]<<" ";
// 				cout<<endl;
// 			}
// 		}
// 	}
// }

// //这种方法非常适合记忆，这种方法既仿照了回溯法的公式，但是又有一些小小的变形，非常适合这种有重复元素类型的题目
// void backtrack(vector<vector<int> >& result, vector<int>& nums, vector<int>& tmp, int index) {
// 	if(index == nums.size()) {
// 		return ;
// 	} else {
// 		for(int i = index; i < nums.size(); i++) {
// 			tmp.push_back(nums[i]);
// 			result.push_back(tmp);
// 			backtrack(result, nums, tmp, i+1);
// 			tmp.pop_back();
// 			//下面这两行代码保证了去除重复元素
// 			while(i < nums.size()-1 && nums[i] == nums[i+1])
// 				i++;
// 		}
// 	}
// }

// vector<vector<int> > subsetsWithDup(vector<int>& nums) {
// 	vector<vector<int> > result;
// 	vector<int> tmp;
// 	int len = nums.size();
// 	result.push_back(tmp);
// 	if(len <= 0) {
// 		return result;
// 	}
// 	sort(nums.begin(), nums.end());
// 	backtrack(result, nums, tmp, 0);
// 	return result;

// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(2);
// 	vector<vector<int> > result = subsetsWithDup(nums);
// 	printVec(result);
// 	return 0;
// }


//Construct Binary Tree from Preorder and Inorder Traversal
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right{NULL} {}
};

TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, ir) {
	if(pl > pr || il > ir)
		return NULL;
	TreeNode* root = new TreeNode(preorder[pl]);
	int index = 0;
	for(int i = il; i <= ir; i++)
		if(inorder[i] == preorder[pl])
			index = i;
	root->left = build(preorder, pl+1, pl+index-il, inorder, il, index-1);
	root->right = build(preorder, pr-ir+index+1, pr, inorder, index+1, ir);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return build(preorder, 0, preorder.siz()-1, inorder, 0, inorder.size()-1);
}

int main() {
	//
	return 0;
}


