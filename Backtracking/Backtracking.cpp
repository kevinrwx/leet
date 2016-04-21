//Regular Expression Matching
// #include <iostream>
// #include <vector>

// using namespace std;

// //并非我我自己独立完成的，所以这道题目还需要再仔细看看
// bool matchHelper(string s, int i, string p, int j) {
// 	if(s[i] == '\0')
// 		return p[j] == '\0';
// 	if(p[j+1] != '*') {
// 		if((s[i] == p[j]) || (p[j] == '.' && s[i] != '\0'))
// 			return matchHelper(s, i+1, p, j+1);
// 		return false;
// 	} else {
// 		while((s[i] == p[j]) || (p[j] == '.' && s[i] != '\0')) {
// 			if(matchHelper(s, i, p, j+2))
// 				return true;
// 			i++;
// 		}
// 		return matchHelper(s, i, p, j+2);
// 	}
// }

// bool isMatch(string s, string p) {
// 	return matchHelper(s, 0, p, 0);
// }

// int main() {
// 	string s = "aa";
// 	string p = "a*";
// 	if(isMatch(s, p))
// 		cout<<"match"<<endl;
// 	else
// 		cout<<"not match"<<endl;
// 	return 0;
// }

//Letter Combinations of a Phone Number
// #include <iostream>
// #include <vector>

// using namespace std;

// void backtrack(vector<string>& result, string tmp, string digits, int index, string letters[]) {
// 	if(digits.length() == index) {
// 		result.push_back(tmp);
// 	} else {
// 		string candidates = letters[digits[index]-'1'];
// 		for(int i = 0; i < candidates.length(); i++) {
// 			tmp.push_back(candidates[i]);
// 			backtrack(result, tmp, digits, index+1, letters);
// 			tmp.pop_back();
// 		}
// 	}
// }

// vector<string> letterCombinations(string digits) {
// 	int len = digits.length();
// 	vector<string> result;
// 	if(len <= 0)
// 		return result;
// 	string tmp;
// 	string letters[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
// 	backtrack(result, tmp, digits, 0, letters);
// 	return result;
// }

// int main() {
// 	string digits = "23";
// 	vector<string> result = letterCombinations(digits);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<endl;
// 	return 0;
// }

//Generate Parentheses
// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// bool isParenthesis(string s) {
// 	stack<char> st;
// 	int len = s.length();
// 	if(len <= 0)
// 		return true;
// 	bool result = true;
// 	for(int i = 0; i < len; i++) {
// 		if(s[i] == '(')
// 			st.push(s[i]);
// 		else {
// 			if(st.empty() || st.top() != '(') {
// 				result = false;
// 				break;
// 			}
// 			st.pop();
// 		}
// 	}
// 	if(!st.empty())
// 		result = false;
// 	return result;
// }

// //这种方法是比较笨的方法，将所有的情况都进行了遍历，然后再判断每种情况是否符合题目要求
// void backtrack(vector<string>& result, string tmp, string candidates, int index, int n) {
// 	if(index == 2*n) {
// 		if(isParenthesis(tmp))
// 			result.push_back(tmp);
// 	} else {
// 		for(int i = 0; i < candidates.length(); i++) {
// 			tmp.push_back(candidates[i]);
// 			backtrack(result, tmp, candidates, index+1, n);
// 			tmp.pop_back();
// 		}
// 	}
// }

// vector<string> generateParenthesis(int n) {
// 	vector<string> result;
// 	if(n <= 0)
// 		return result;
// 	string tmp;
// 	string candidates = "()";
// 	backtrack(result, tmp, candidates, 0, n);
// 	return result;
// }

// 这种方法并没有完全按照回溯法的公式去做，但是仍然采用了回溯法的思想，可以作为特例进行记忆
// void backtrack(vector<string>& result, string tmp, int left, int right) {
// 	if(left == 0 && right == 0) {
// 		result.push_back(tmp);
// 	}
// 	if(left > 0) {
// 		tmp.push_back('(');
// 		backtrack(result, tmp, left-1, right);
// 		tmp.pop_back();
// 	}
// 	if(left < right) {
// 		tmp.push_back(')');
// 		backtrack(result, tmp, left, right-1);
// 		tmp.pop_back();
// 	}
// }

// vector<string> generateParenthesis(int n) {
// 	vector<string> result;
// 	if(n <= 0)
// 		return result;
// 	string tmp;
// 	backtrack(result, tmp, n, n);
// 	return result;
// }

// int main() {
// 	int n = 3;
// 	vector<string> result = generateParenthesis(n);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<endl;
// 	return 0;
// }

//Sudoku Solver
// #include <iostream>
// #include <vector>

// using namespace std;

// void backtrack() {
// 	//
// }

// void solveSudoku(vector<vector<char> >& board) {
// 	if(board.size() <= 0 || board[0].size() <= 0)
// 		return ;
// 	int n = board.size();
// 	//
// }

// int main() {
// 	//
// }



//Combination Sum
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

// void backtrack(vector<vector<int> >& result, vector<int>& candidates, vector<int>& tmp, int target, int index) {
// 	if(target == 0) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = index; i < candidates.size(); i++) {
// 			if(target >= candidates[i]) {
// 				tmp.push_back(candidates[i]);
// 				backtrack(result, candidates, tmp, target-candidates[i], i);
// 				tmp.pop_back();
// 			}
// 		}
// 	}
// }

// vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
// 	vector<vector<int> > result;
// 	if(candidates.size() <= 0 || target <= 0)
// 		return result;
// 	vector<int> tmp;
// 	sort(candidates.begin(), candidates.end());
// 	backtrack(result, candidates, tmp, target, 0);
// 	return result;
// }

// int main() {
// 	vector<int> candidates;
// 	candidates.push_back(2);
// 	candidates.push_back(3);
// 	candidates.push_back(6);
// 	candidates.push_back(7);
// 	int target = 7;
// 	vector<vector<int> > result = combinationSum(candidates, target);
// 	printVec(result);
// 	return 0;
// }

//Combination Sum II
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

// void backtrack(vector<vector<int> >& result, vector<int>& candidates, vector<int>& tmp, int target, int index) {
// 	if(target == 0) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = index; i < candidates.size(); i++) {
// 			if(target >= candidates[i]) {
// 				tmp.push_back(candidates[i]);
// 				backtrack(result, candidates, tmp, target-candidates[i], i+1);
// 				tmp.pop_back();
// 				while(i < candidates.size()-1 && candidates[i] == candidates[i+1])
// 					i++;
// 			}
// 		}
// 	}
// }

// vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
// 	vector<vector<int> > result;
// 	if(candidates.size() <= 0 || target <= 0)
// 		return result;
// 	vector<int> tmp;
// 	sort(candidates.begin(), candidates.end());
// 	backtrack(result, candidates, tmp, target, 0);
// 	return result;
// }

// int main() {
// 	vector<int> candidates;
// 	candidates.push_back(10);
// 	candidates.push_back(1);
// 	candidates.push_back(2);
// 	candidates.push_back(7);
// 	candidates.push_back(6);
// 	candidates.push_back(1);
// 	candidates.push_back(5);
// 	int target = 8;
// 	vector<vector<int> > result = combinationSum2(candidates, target);
// 	printVec(result);
// 	return 0;
// }

//Wildcard Matching
// #include <iostream>
// #include <vector>

// using namespace std;

// void backtrack() {
// 	//
// }

// void solveSudoku(vector<vector<char> >& board) {
// 	//
// }

// int main() {
// 	//
// }


//Permutations
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

// void backtrack(vector<vector<int> >& result, vector<int>& nums, vector<bool>& flag, vector<int>& tmp) {
// 	if(tmp.size() == nums.size()) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = 0; i < nums.size(); i++) {
// 			if(flag[i] == false) {
// 				flag[i] = true;
// 				tmp.push_back(nums[i]);
// 				backtrack(result, nums, flag, tmp);
// 				tmp.pop_back();
// 				flag[i] = false;
// 			}
// 		}
// 	}
// }

// vector<vector<int> > permute(vector<int>& nums) {
// 	int len = nums.size();
// 	vector<vector<int> > result;
// 	if(len <= 0)
// 		return result;
// 	vector<int> tmp;
// 	vector<bool> flag(len, false);
// 	backtrack(result, nums, flag, tmp);
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(3);

// 	vector<vector<int> > result = permute(nums);
// 	printVec(result);
// 	return 0;
// }


//Permutations II
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

// void backtrack(vector<vector<int> >& result, vector<int>& nums, vector<bool>& flag, vector<int>& tmp) {
// 	if(tmp.size() == nums.size()) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = 0; i < nums.size(); i++) {
// 			if(flag[i] == false) {
// 				flag[i] = true;
// 				tmp.push_back(nums[i]);
// 				backtrack(result, nums, flag, tmp);
// 				tmp.pop_back();
// 				flag[i] = false;
// 				while(i < nums.size()-1 && nums[i] == nums[i+1])
// 					i++;
// 			}
// 		}
// 	}
// }

// vector<vector<int> > permuteUnique(vector<int>& nums) {
// 	int len = nums.size();
// 	vector<vector<int> > result;
// 	if(len <= 0)
// 		return result;
// 	vector<int> tmp;
// 	vector<bool> flag(len, false);
// 	sort(nums.begin(), nums.end());
// 	backtrack(result, nums, flag, tmp);
// 	return result;
// }

// int main() {
// 	vector<int> nums;
// 	nums.push_back(1);
// 	nums.push_back(1);
// 	nums.push_back(2);

// 	vector<vector<int> > result = permuteUnique(nums);
// 	printVec(result);
// 	return 0;
// }

//N-Queens
// #include <iostream>
// #include <vector>

// using namespace std;

// void printVec(vector<vector<string> >& result) {
// 	if(result.size() <= 0)
// 		cout<<"empty vector";
// 	else {
// 		for(int i = 0; i < result.size(); i++) {
// 			if(result[i].size() <= 0)
// 				cout<<"empty"<<endl;
// 			else {
// 				for(int j = 0; j < result[i].size(); j++)
// 					cout<<result[i][j]<<endl;
// 			}
// 			cout<<"========"<<endl;
// 		}
// 	}
// }

// bool is_collision(vector<string>& tmp, int x, int y) {
// 	for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--) {
// 		if(tmp[i][j] == 'Q')
// 			return true;
// 	}
// 	for(int i = x-1, j = y+1; i >= 0 && j < tmp.size(); i--, j++) {
// 		if(tmp[i][j] == 'Q')
// 			return true;
// 	}
// 	return false;
// }

// void backtrack(vector<vector<string> >& result, vector<string>& tmp, int k, vector<bool> candidates) {
// 	if(k == tmp.size()) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = 0; i < candidates.size(); i++) {
// 			if(candidates[i] == true || is_collision(tmp, k, i))
// 				continue;
// 			candidates[i] = true;
// 			tmp[k][i] = 'Q';
// 			backtrack(result, tmp, k+1, candidates);
// 			candidates[i] = false;
// 			tmp[k][i] = '.';
// 		}
// 	}
// }

// vector<vector<string> > solveNQueens(int n) {
// 	vector<vector<string> > result;
// 	if(n <= 0)
// 		return result;
// 	vector<string> tmp(n, string(n, '.'));
// 	vector<bool> candidates(n, false);
// 	backtrack(result, tmp, 0, candidates);
// 	return result;
// }

// int main() {
// 	int n = 4;
// 	vector<vector<string> > result = solveNQueens(n);
// 	printVec(result);
// 	return 0;
// }

//N-Queens II
// #include <iostream>
// #include <vector>

// using namespace std;

// void printVec(vector<vector<string> >& result) {
// 	if(result.size() <= 0)
// 		cout<<"empty vector";
// 	else {
// 		for(int i = 0; i < result.size(); i++) {
// 			if(result[i].size() <= 0)
// 				cout<<"empty"<<endl;
// 			else {
// 				for(int j = 0; j < result[i].size(); j++)
// 					cout<<result[i][j]<<endl;
// 			}
// 			cout<<"========"<<endl;
// 		}
// 	}
// }

// bool is_collision(vector<string>& tmp, int x, int y) {
// 	for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--) {
// 		if(tmp[i][j] == 'Q')
// 			return true;
// 	}
// 	for(int i = x-1, j = y+1; i >= 0 && j < tmp.size(); i--, j++) {
// 		if(tmp[i][j] == 'Q')
// 			return true;
// 	}
// 	return false;
// }

// void backtrack(int* count, vector<string>& tmp, int k, vector<bool>& candidates) {
// 	if(k == tmp.size()) {
// 		(*count) += 1;
// 	} else {
// 		for(int i = 0; i < candidates.size(); i++) {
// 			if(candidates[i] == true || is_collision(tmp, k, i))
// 				continue;
// 			tmp[k][i] = 'Q';
// 			candidates[i] = true;
// 			backtrack(count, tmp, k+1, candidates);
// 			tmp[k][i] = '.';
// 			candidates[i] = false;
// 		}
// 	}
// }

// int totalNQueens(int n) {
// 	if(n <= 0)
// 		return 0;
// 	int count = 0;
// 	vector<bool> candidates(n, false);
// 	vector<string> tmp(n, string(n, '.'));
// 	backtrack(&count, tmp, 0, candidates);
// 	return count;
// }

// int main() {
// 	int n = 4;
// 	int result = totalNQueens(n);
// 	cout<<result<<endl;
// 	return 0;
// }

//Permutation Sequence
// #include <iostream>
// #include <vector>

// using namespace std;

// int getFactorial(int n) {
// 	if(n == 0)
// 		return 1;
// 	else
// 		return n * getFactorial(n-1);
// }

// void backtrack(vector<int>& tmp, vector<int>& nums, int k) {
// 	if(nums.size() == 1) {
// 		tmp.push_back(nums[0]);
// 	} else {
// 		int len = nums.size();
// 		int dividend = getFactorial(len-1);
// 		int index = k / dividend;
// 		k = k % dividend;
// 		tmp.push_back(nums[index]);
// 		nums.erase(nums.begin() + index);
// 		backtrack(tmp, nums, k);
// 	}
// }

// string getPermutation(int n, int k) {
// 	string result;
// 	vector<int> nums(n, 0);
// 	for(int i = 0; i < n; i++)
// 		nums[i] = i+1;
// 	vector<int> tmp;
// 	backtrack(tmp, nums, k-1);
// 	char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// 	for(int i = 0; i < tmp.size(); i++)
// 		result.push_back(ch[tmp[i]]);
// 	return result;
// }

// int main() {
// 	int n = 3;
// 	int k = 4;
// 	string result = getPermutation(n, k);
// 	cout<<result<<endl;
// 	return 0;
// }

// //Combinations
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

// void backtrack(vector<vector<int> >& result, vector<int>& tmp, int n, int k, int index) {
// 	if(k == tmp.size()) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = index; i <= n; i++) {
// 			tmp.push_back(i);
// 			backtrack(result, tmp, n, k, i+1);
// 			tmp.pop_back();
// 		}
// 	}
// }

// vector<vector<int> > combine(int n, int k) {
// 	vector<vector<int> > result;
// 	if(n <= 0 || k <= 0)
// 		return result;
// 	vector<int> tmp;
// 	backtrack(result, tmp, n, k, 1);
// 	return result;
// }

// int main() {
// 	int n = 4;
// 	int k = 2;
// 	vector<vector<int> > result = combine(n, k);
// 	printVec(result);
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

// void backtrack(vector<vector<int> >& result, vector<int>& tmp, vector<int>& nums, int index) {
// 	if(index == nums.size()) {
// 		return ;
// 	} else {
// 		for(int i = index; i < nums.size(); i++) {
// 			tmp.push_back(nums[i]);
// 			result.push_back(tmp);
// 			backtrack(result, tmp, nums, i+1);
// 			tmp.pop_back();
// 		}
// 	}
// }

// vector<vector<int> > subsets(vector<int>& nums) {
// 	vector<vector<int> > result;
// 	vector<int> tmp;
// 	result.push_back(tmp);
// 	if(nums.size() <= 0)
// 		return result;
// 	sort(nums.begin(), nums.end());
// 	backtrack(result, tmp, nums, 0);
// 	return result;
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

//Word Search
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


//Gray Code
// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// int string2int(string str) {
// 	int result = 0;
// 	int len = str.length();
// 	reverse(str.begin(), str.end());
// 	for(int i = 0; i < len; i++) {
// 		if(str[i] == '1')
// 			result += pow(2, i);
// 	}
// 	return result;
// }

// //这种方法是通过模拟格雷码的生成来产生格雷码的，这种方法比较复杂，不过较为通用
// vector<int> grayCode(int n) {
// 	vector<int> result;
// 	if(n <= 0) {
// 		result.push_back(0);
// 		return result;
// 	}
// 	vector<string> tmp;
// 	tmp.push_back("0");
// 	tmp.push_back("1");
// 	for(int i = 1; i < n; i++) {
// 		int len = tmp.size();
// 		for(int i = len-1; i >= 0; i--) {
// 			tmp.push_back(tmp[i]);
// 		}
// 		len = tmp.size();
// 		for(int i = 0; i < len/2; i++) {
// 			reverse(tmp[i].begin(), tmp[i].end());
// 			tmp[i].push_back('0');
// 			reverse(tmp[i].begin(), tmp[i].end());
// 		}
// 		for(int i = len/2; i < len; i++) {
// 			reverse(tmp[i].begin(), tmp[i].end());
// 			tmp[i].push_back('1');
// 			reverse(tmp[i].begin(), tmp[i].end());
// 		}
// 	}
// 	for(int i = 0; i < tmp.size(); i++) {
// 		result.push_back(string2int(tmp[i]));
// 	}
// 	return result;
// }

// //这种方法是求格雷码的数学方法
// //二进制码转格雷码：从最右边一位起，依次将每一位与左边一位异或，作为对应格雷码在该位的值，对于最左边一位仍然要为0
// //转换成实际的数学写法就是将i异或上i/2，然后这样就能得到每一位的格雷码值了
// vector<int> grayCode(int n) {
// 	vector<int> result;
// 	int nSize = 1 << n;
// 	for(int i = 0; i < nSize; i++) {
// 		result.push_back((i>>1)^i);
// 	}
// 	return result;
// }

// int main() {
// 	int n = 3;
// 	vector<int> result = grayCode(n);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<" ";
// 	cout<<endl;
// 	return 0;
// }


//Restore IP Addresses
// #include <iostream>
// #include <vector>

// using namespace std;

// //对于使用回溯法的公式解决类似的问题，我已经比较熟悉了，但是这道题容易出错的点是isValid函数能否正确实现
// //特别需要注意的点就是在判断0时，只有“0”是合格的，而“00”等是不可以的
// bool isValid(string tmp) {
// 	if(tmp.at(0) == '0')
// 		return tmp == "0" ? true : false;
// 	int temp = atoi(tmp.c_str());
// 	if(temp <= 255 && temp > 0)
// 		return true;
// 	else
// 		return false;
// }

// void backtrack(vector<string>& result, string s, string tmp, int index, int k) {
// 	if(k == 4 && index == s.length()) {
// 		result.push_back(tmp.substr(0, tmp.length()-1));
// 	} else {
// 		for(int i = index; i < s.length(); i++) {
// 			if(isValid(s.substr(index, i-index+1))) {
// 				tmp.append(s.substr(index, i-index+1));
// 				tmp.push_back('.');
// 				backtrack(result, s, tmp, i+1, k+1);
// 				tmp.pop_back();
// 				tmp = tmp.substr(0, tmp.length()-i+index-1);
// 			}
// 		}
// 	}
// }

// vector<string> restoreIpAddresses(string s) {
// 	vector<string> result;
// 	int len = s.length();
// 	if(len <= 0 || len > 12)
// 		return result;
// 	string tmp;
// 	backtrack(result, s, tmp, 0, 0);
// 	return result;
// }

// int main() {
// 	string s = "010010";
// 	vector<string> result = restoreIpAddresses(s);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<endl;
// 	return 0;
// }

//Word Ladder II
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
// 	//
// }

// int main() {
// 	//
// }

//Palindrome Partitioning
// #include <iostream>
// #include <vector>

// using namespace std;

// bool isPalindrome(string str) {
// 	int len = str.length();
// 	if(len <= 0)
// 		return true;
// 	int i = 0;
// 	int j = len-1;
// 	while(i <= j) {
// 		if(str[i] == str[j]) {
// 			i++;
// 			j--;
// 		} else {
// 			return false;
// 		}
// 	}
// 	return true;
// }

// void backtrack(vector<vector<string> >& result, vector<string>& tmp, string s, int index) {
// 	if(index == s.length()) {
// 		result.push_back(tmp);
// 	} else {
// 		for(int i = index; i < s.length(); i++) {
// 			if(isPalindrome(s.substr(index, i-index+1))) {
// 				tmp.push_back(s.substr(index, i-index+1));
// 				backtrack(result, tmp, s, i+1);
// 				tmp.pop_back();
// 			}
// 		}
// 	}
// }

// vector<vector<string> > partition(string s) {
// 	vector<vector<string> > result;
// 	int len = s.length();
// 	if(len <= 0)
// 		return result;
// 	vector<string> tmp;
// 	backtrack(result, tmp, s, 0);
// 	return result;
// }

// int main() {
// 	string s = "aab";
// 	vector<vector<string> > result = partition(s);
// 	for(int i = 0; i < result.size(); i++) {
// 		for(int j = 0; j < result[i].size(); j++)
// 			cout<<result[i][j]<<" ";
// 		cout<<endl;
// 	}
// 	return 0;
// }

//Word Break
// #include <iostream>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// bool wordBreak(string s, unordered_set<string>& wordDict) {
// 	int len = s.length();
// 	if(len <= 0 || wordDict.size() <= 0)
// 		return false;
// 	vector<bool> tmp(len+1, false);
// 	tmp[0] = true;
// 	for(int i = 1; i <= len; i++) {
// 		for(int j = 0; j < i; j++) {
// 			if(tmp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
// 				tmp[i] = true;
// 				break;
// 			}
// 		}
// 	}
// 	return tmp[len];
// }

// int main() {
// 	string s = "leetcode";
// 	unordered_set<string> wordDict;
// 	wordDict.insert("leet");
// 	wordDict.insert("code");
// 	if(wordBreak(s, wordDict))
// 		cout<<"true"<<endl;
// 	else
// 		cout<<"false"<<endl;

// 	return 0;
// }


//Word Break II
// #include <iostream>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// void backtrack(vector<string>& result, string s, unordered_set<string>& wordDict, vector<string>& tmp, vector<vector<bool> >&temp, int index) {
// 	if(index == s.length()) {
// 		string myResult;
// 		for(int i = 0; i < tmp.size(); i++) {
// 			myResult += tmp[i];
// 			myResult.push_back(' ');
// 		}
// 		result.push_back(myResult.substr(0, myResult.length()-1));
// 	} else {
// 		for(int i = index; i < s.length(); i++) {
// 			if(temp[index][i] == true) {
// 				tmp.push_back(s.substr(index, i-index+1));
// 				backtrack(result, s, wordDict, tmp, temp, i+1);
// 				tmp.pop_back();
// 			}
// 		}
// 	}
// }

// vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
// 	vector<string> result;
// 	int len = s.length();
// 	if(len <= 0 || wordDict.size() <= 0)
// 		return result;
// 	vector<vector<bool> > temp(len, vector<bool>(len, false));
// 	for(int i = 0; i < len; i++) {
// 		for(int j = i; j < len; j++) {
// 			if(wordDict.find(s.substr(i, j-i+1)) != wordDict.end()) {
// 				temp[i][j] = true;
// 			}
// 		}
// 	}
// 	for(int i = 0; i < len; i++) {
// 		for(int j = 0; j < len; j++) {
// 			cout<<temp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	vector<string> tmp;
// 	backtrack(result, s, wordDict, tmp, temp, 0);
// 	return result;
// }


//     // DFS遍历树，生成路径
//     void gen_path(string s, vector<vector<bool> >& prev,
//             int cur, vector<string>& path, vector<string>& result) {
//         if (cur == 0) {
//             string tmp;
//             for(int i = 0; i < path.size(); i++) {
//             	tmp.append(path[i]);
//             	tmp.push_back(' ');
//             }
//             tmp.erase(tmp.end() - 1);
//             result.push_back(tmp);
//         }
//         for (size_t i = 0; i < s.size(); ++i) {
//             if (prev[cur][i]) {
//                 path.push_back(s.substr(i, cur - i));
//                 gen_path(s, prev, i, path, result);
//                 path.pop_back();
//             }
//         }
//     }

//     vector<string> wordBreak(string s, unordered_set<string> &dict) {
//         // 长度为n的字符串有n+1个隔板
//         vector<bool> f(s.length() + 1, false);
//         // prev[i][j]为true，表示s[j, i)是一个合法单词，可以从j处切开
//         // 第一行未用
//         vector<vector<bool> > prev(s.length() + 1, vector<bool>(s.length()));
//         f[0] = true;
//         for (size_t i = 1; i <= s.length(); ++i) {
//             for (int j = i - 1; j >= 0; --j) {
//                 if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
//                     f[i] = true;
//                     prev[i][j] = true;
//                 }
//             }
//         }
//         for(int i = 0; i < prev.size(); i++) {
//         	for(int j = 0; j < prev[0].size(); j++)
//         		cout<<prev[i][j]<<" ";
//         	cout<<endl;
//         }


//         vector<string> result;
//         vector<string> path;
//         gen_path(s, prev, s.length(), path, result);
//         return result;

//     }

// int main() {
// 	string s = "catsanddog";
// 	unordered_set<string> wordDict;
// 	wordDict.insert("cat");
// 	wordDict.insert("cats");
// 	wordDict.insert("and");
// 	wordDict.insert("sand");
// 	wordDict.insert("dog");
// 	vector<string> result = wordBreak(s, wordDict);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<endl;
// 	return 0;
// }


// 0 0 1 1 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 1 
// 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 










