
//Longest Substring Without Repeating Characters
// #include <iostream>
// #include <unordered_map>

// using namespace std;

// //这种方法的复杂度的有时会很高，最高能达到O(n*n)，但是由于使用了声明的数组来替代map，这保证了这道题目能过最大的测试
// //用例，但是下面那种方法使用unordered_map的方法就不能过最大测试用例了
// int lengthOfLongestSubstring(string s) {
// 	int len = s.length();
// 	if(len <= 1)
// 		return len;
// 	int myMap[256];
// 	memset(myMap, -1, sizeof(myMap));
// 	int tmp = 0;
// 	int maxLength = 0;
// 	for(int i = 0; i < len; i++) {
// 		if(myMap[s[i] - ' '] >= 0) {
// 			maxLength = max(maxLength, tmp);
// 			i = myMap[s[i] - ' '] + 1;
// 			tmp = 0;
// 			memset(myMap, -1, sizeof(myMap));
// 		}
// 		myMap[s[i] - ' '] = i;
// 		tmp++;
// 	}
// 	maxLength = max(maxLength, tmp);
// 	return maxLength;
// }

// int lengthOfLongestSubstring2(string s) {
//     int length = s.length();
//     if(length == 0)
//         return 0;
//     unordered_map<char, int> myMap;
//     int len = 0;
//     int maxV = 0;
//     for(int i = 0; i < length; i++, len++) {
//         if(myMap.find(s[i]) != myMap.end()) {
//             maxV = max(len, maxV);
//             i = myMap[s[i]] + 1;
//             len = 0;
//             myMap.clear();
//         }
//         myMap[s[i]] = i;
//     }
//     return max(len, maxV);
// }


// int main() {
// 	//abcabcbb    3
// 	//bbbbb       1
// 	//pwwkew      3
// 	//abba        2
// 	string s = "abba";
// 	int result = lengthOfLongestSubstring(s);
// 	cout<<result<<endl;
// 	return 0;
// }

//Longest Palindromic Substring
// #include <iostream>
// #include <vector>

// using namespace std;

// string longestPalindrome(string s) {
// 	int len = s.length();
// 	if(len <= 0)
// 		return s;
// 	bool dp[len][len];
// 	memset(dp, 0, sizeof(dp));
// 	int start = 0;
// 	int end = 0;
// 	int maxLength = -1;
// 	for(int i = 0; i < 2; i++) {
// 		for(int j = 0; j < len-i; j++) {
// 			dp[j][i+j] = (s[j] == s[i+j]) ? true : false;
// 			if(dp[j][i+j] == true && maxLength < i) {
// 				start = j;
// 				end = i+j;
// 				maxLength = i;
// 			}
// 		}
// 	}
// 	for(int i = 2; i < len; i++) {
// 		for(int j = 0; j < len-i; j++) {
// 			dp[j][i+j] = dp[j+1][i+j-1] && ((s[j] == s[i+j]) ? true : false);
// 			if(dp[j][i+j] == true && maxLength < i) {
// 				start = j;
// 				end = i+j;
// 				maxLength = i;
// 			}
// 		}
// 	}
// 	return s.substr(start, end-start+1);
// }

// int main() {
// 	string s = "";
// 	string result = longestPalindrome(s);
// 	cout<<result<<endl;
// 	return 0;
// }

//ZigZag Conversion
// #include <iostream>

// using namespace std;

// string convert(string s, int numRows) {
// 	int len = s.length();
// 	if(len <= 0 || numRows <= 1)
// 		return s;
// 	string result;
// 	int count = len/(2*numRows-2) + ((len % (2*numRows-2) == 0) ? 0 : 1);
// 	for(int i = 0; i < numRows; i++) {
// 		if(i == 0 || i == numRows-1) {
// 			int k = i;
// 			while(k < len) {
// 				result.push_back(s[k]);
// 				k = k + 2*numRows - 2;
// 			}
// 		} else {
// 			int k = i;
// 			while(k < len) {
// 				result.push_back(s[k]);
// 				k = k + 2*numRows - 2 - 2*i;
// 				if(k < len)
// 					result.push_back(s[k]);
// 				k = k + 2*i;
// 			}
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	string s = "PAYPALISHIRING";
// 	int numRows = 3;
// 	string result = convert(s, numRows);
// 	cout<<result<<endl;
// 	return 0;
// }

//String to Integer (atoi)
// #include <iostream>

// using namespace std;

// //需要处理的点：
// //1、字符为空
// //2、数字前有空格，需要跳过所有的空格，如果整个字符串都是空格，那就返回0
// //3、跳过所有的空格以后，需要处理正负号，所以需要用sign来标示正负号
// //4、字符串前面如果出现了不必要或多于的字符导致这个字符串不是数字，那就返回0，如“++123”、“+-123”、“a123”
// //5、字符串中间如果出现了不必要的字符，那就返回字符串前面计算的值，如“123b45”，那就返回123
// //6、如果数字大于INT_MAX或者是小于INT_MIN，那就返回INT_MAX或者INT_MIN

// int myAtoi(string str) {
// 	int len = str.length();
// 	if(len <= 0)
// 		return 0;
// 	int index = 0;
// 	int sign = 1;
// 	long long result = 0;
// 	//处理空格
// 	while(str[index] != '\0' && str[index] == ' ')
// 		index++;
// 	if(str[index] == '\0')
// 		return 0;
// 	//处理正负号
// 	if(str[index] == '-')
// 		sign = -1;
// 	if(str[index] == '-' || str[index] == '+')
// 		index++;

// 	while(str[index] != '\0') {
// 		if(str[index] >= '0' && str[index] <= '9') {
// 			//这种计算result的方法非常不错，将正负的情况作了统一
// 			result = result * 10 + sign * (str[index] - '0');
// 		} else {
// 			return result;
// 		}
// 	    if(result > INT_MAX || result < INT_MIN) {
// 	    	return (result > 0) ? INT_MAX : INT_MIN;
// 	    }
// 		index++;
// 	}
// 	return result;

// }

// int main() {
// 	string s = "2147483648";
// 	int result = myAtoi(s);
// 	cout<<result<<endl;
// 	return 0;
// }


//Integer to Roman
// #include <iostream>
// #include <vector>

// using namespace std;

// string intToRoman(int num) {
// 	//
// }

// int main() {
// 	//
// }

//Roman to Integer
// #include <iostream>
// #include <vector>

// using namespace std;

// string intToRoman(int num) {
// 	//
// }

// int main() {
// 	//
// }

//Longest Common Prefix
// #include <iostream>
// #include <vector>

// using namespace std;

// string longestCommonPrefix(vector<string>& strs) {
// 	string result;
// 	if(strs.size() <= 0)
// 		return result;
// 	int index = -1;
// 	int len = 0;
// 	for(int i = 0; i < strs.size(); i++) {
// 		if(len < strs[i].size()) {
// 			len = strs[i].size();
// 			index = i;
// 		}
// 	}
// 	//这个点需要注意，即strs中的元素为空字符串
// 	if(len <= 0)
// 		return result;
// 	bool flag;
// 	for(int i = 0; i < strs[index].size(); i++) {
// 		flag = true;
// 		for(int j = 0; j < strs.size(); j++) {
// 			if(strs[index][i] != strs[j][i]) {
// 				flag = false;
// 				break;
// 			}
// 		}
// 		if(flag) {
// 			result.push_back(strs[index][i]);
// 		} else {
// 			break;
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	vector<string> strs;
// 	strs.push_back("abc");
// 	strs.push_back("abdf");
// 	strs.push_back("aber");
// 	strs.push_back("abw");
// 	string result = longestCommonPrefix(strs);
// 	cout<<result<<endl;
// 	return 0;
// }

//Valid Parentheses
// #include <iostream>
// #include <stack>

// using namespace std;

// bool isValid(string s) {
// 	int len = s.length();
// 	if(len <= 0) {
// 		return true;
// 	}
// 	stack<char> st;
// 	for(int i = 0; i < len; i++) {
// 		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
// 			st.push(s[i]);
// 		else {
// 			if(st.empty()) {
// 				return false;
// 			} else {
// 				char tmp = st.top();
// 				if(s[i] == ')') {
// 					if(tmp == '(')
// 						st.pop();
// 					else
// 						return false;
// 				} else if(s[i] == '}') {
// 					if(tmp == '{')
// 						st.pop();
// 					else
// 						return false;
// 				} else {
// 					if(tmp == '[')
// 						st.pop();
// 					else
// 						return false;
// 				}
// 			}
// 		}
// 	}
// 	if(st.empty())
// 		return true;
// 	else
// 		return false;
// }

// int main() {
// 	string str = "()[]{";
// 	bool result = isValid(str);
// 	if(result)
// 		cout<<"valid"<<endl;
// 	else
// 		cout<<"not valid"<<endl;
// 	return 0;
// }


//Implement strStr()
// #include <iostream>

// using namespace std;

// //这种方法是暴力解法，虽然这种方法也可以提交通过，但是这种方法的时间复杂度太高了，能达到O(m*n)，如果可以的话，最好还是用KMP算法
// int strStr(string haystack, string needle) {
// 	int m = haystack.length();
// 	int n = needle.length();
// 	for(int i = 0; i <= m-n; i++) {
// 		int j;
// 		for(j = 0; j < n; j++) {
// 			if(haystack[i+j] != needle[j])
// 				break;
// 		}
// 		if(j == n) {
// 			return i;
// 		}
// 	}
// 	return -1;
// }

// //使用KMP算法，待解决
// int strStr(string haystack, string needle) {
// 	//
// }

// int main() {
// 	string haystack = "aabcd";
// 	string needle = "ab";
// 	int index = strStr(haystack, needle);
// 	cout<<index<<endl;
// 	return 0;
// }

//Substring with Concatenation of All Words
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// //这种方法比较适合s的长度远大于words的个数的情况，因为只需要一次backtrack就可以将所有的words组合情况进行遍历
// //然后只需要遍历s，然后挨个查表就可以了，但是对于leetcode的情况，这种方法会超时
// void backtrack(unordered_map<string, bool>& myMap, vector<string>& words, vector<string>& tmp, vector<bool>& flag) {
// 	if(tmp.size() == words.size()) {
// 		string result;
// 		for(int i = 0; i < tmp.size(); i++)
// 			result += tmp[i];
// 		if(myMap.find(result) == myMap.end())
// 			myMap[result] = true;
// 	} else {
// 		for(int i = 0; i < words.size(); i++) {
// 			if(flag[i] == false) {
// 				flag[i] = true;
// 				tmp.push_back(words[i]);
// 				backtrack(myMap, words, tmp, flag);
// 				flag[i] = false;
// 				tmp.pop_back();
// 			}
// 		}
// 	}
// }

// vector<int> findSubstring(string s, vector<string>& words) {
// 	vector<int> result;
// 	int len = s.length();
// 	if(len <= 0 || words.size() <= 0)
// 		return result;
// 	unordered_map<string, bool> myMap;
// 	vector<string> tmp;
// 	vector<bool> flag(len, false);
// 	backtrack(myMap, words, tmp, flag);
// 	int m = words.size()*words[0].length();
// 	for(int i = 0; i <= len-m; i++) {
// 		if(myMap.find(s.substr(i, m)) != myMap.end())
// 			result.push_back(i);
// 	}
// 	return result;
// }

// //这种方法的思路也比较简单，就是使用一个map来存放words的个数，然后挨个遍历s的每个字符，当遍历所有words长度时
// //看是否能满足要求
// vector<int> findSubstring(string s, vector<string>& words) {
// 	vector<int> result;
// 	int len = s.length();
// 	if(len <= 0 || words.size() <= 0 || words[0].length() <= 0)
// 		return result;
// 	unordered_map<string, int> myMap;
// 	for(int i = 0; i < words.size(); i++) {
// 		myMap[words[i]]++;
// 	}
// 	int m = words[0].length();
// 	int n = words.size();
// 	for(int i = 0; i <= len-n*m; i++) {
// 		int j;
// 		for(j = 0; j < n; j++) {
// 			string tmp = s.substr(i+j*m, m);
// 			if(myMap.find(tmp) == myMap.end() || (myMap.find(tmp) != myMap.end() && myMap[tmp] <= 0))
// 				break;
// 			else {
// 				myMap[tmp]--;
// 			}
// 		}	
// 		if(j == n) {
// 			result.push_back(i);
// 		}
// 		//注意点，记得每次遍历完成时要将map清零，然后再重新将单词合计存放进去
// 		myMap.clear();
// 		for(int i = 0; i < words.size(); i++) {
// 			myMap[words[i]]++;
// 		}
// 	}
// 	return result;
// }

// //还有一种方法，即words的词典不变，每次只存放从s[i]开始，长度为words[0].length()*words.size()长度的单词
// //到map中，然后再判断是否满足情况
// vector<int> findSubstring(string s, vector<string>& words) {
// 	vector<int> result;
// 	int len = s.length();
// 	if(len <= 0 || words.size() <= 0 || words[0].length() <= 0)
// 		return result;
// 	unordered_map<string, int> myMap;
// 	for(int i = 0; i < words.size(); i++) {
// 		myMap[words[i]]++;
// 	}
// 	int m = words[0].length();
// 	int n = words.size();
// 	//
// 	return result;
// }

// int main() {
// 	vector<string> words;

// 	words.push_back("word");
// 	words.push_back("good");
// 	words.push_back("best");
// 	words.push_back("good");
// 	string s = "wordgoodgoodgoodbestword";
// 	vector<int> result = findSubstring(s, words);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<endl;
// 	return 0;
// }


//Longest Valid Parentheses
// #include <iostream>
// #include <vector>

// using namespace std;

// //这道题有两种解法，第一种是采用dp的方式，dp[i]代表从i到s.length()-1的最长的valid parenthese
// //则对于s[i]==')'，dp[i] = 0
// //对于s[i] == '('，则要看dp[i+1]，dp[i+1]代表的sequence肯定是以左括号开头，右括号结尾的，所以我们要看
// //j=i+1+dp[i+1]是否是右括号，如果是，则dp[i]=dp[i+1]+2，最后dp[i]还得再加上dp[j+1]，因为有((..))()()()这种情况
// int longestValidParentheses(string s) {
// 	int len = s.length();
// 	if(len <= 0)
// 		return 0;
// 	vector<int> dp(len, 0);
// 	int maxLength = 0;
// 	for(int i = len-2; i >= 0; i--) {
// 		int j;
// 		if(s[i] == '(') {
// 			j = i+1+dp[i+1];
// 			if(j < len && s[j] == ')') {
// 				dp[i] = dp[i+1] + 2;
// 				if(j+1 < len)
// 					dp[i] += dp[j+1];
// 			}
// 		}
// 		if(maxLength <= dp[i])
// 			maxLength = dp[i];
// 	}
// 	return maxLength;
// }

// //第二种是采用stack的方式
// // int longestValidParentheses(string s) {
// // 	int len = s.length();
// // 	if(len <= 0)
// // 		return 0;
// // 	//
// // }

// int main() {
// 	string s = ")()())";
// 	int result = longestValidParentheses(s);
// 	cout<<result<<endl;
// 	return 0; 
// }

//Count and Say
// #include <iostream>

// using namespace std;

// string intToString(int num) {
// 	string result;
// 	if(num == 0)
// 		return "0";
// 	char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// 	while(num > 0) {
// 		result.push_back(ch[num%10]);
// 		num /= 10;
// 	}
// 	reverse(result.begin(), result.end());
// 	return result;
// }

// string countOne(string str) {
// 	string result;
// 	int len = str.length();
// 	int num = 0;
// 	char ch = str[0];
// 	int index = 0;
// 	while(index < len) {
// 		if(str[index] == ch) {
// 			num++;
// 		} else {
// 			result.append(intToString(num));
// 			result.push_back(ch);
// 			ch = str[index];
// 			num = 1;
// 		}
// 		index++;
// 	}
// 	if(num > 0) {
// 		result.append(intToString(num));
// 		result.push_back(ch);
// 	}
// 	return result;
// }

// string countAndSay(int n) {
// 	string result;
// 	if(n <= 0)
// 		return result;
// 	result = "1";
// 	for(int i = 2; i <= n; i++) {
// 		result = countOne(result);
// 	}
// 	cout<<result<<endl;
// 	return result;
// }

// int main() {
// 	int n = 6;
// 	string result = countAndSay(n);
// 	return 0;
// }

//Multiply Strings
// #include <iostream>

// using namespace std;

// string multiply(string num1, string num2) {
// 	//
// }

// int main() {
// 	//
// }

//Wildcard Matching
// #include <iostream>

// using namespace std;

// bool isMatch(string s, string p) {
// 	//
// }

// int main() {
// 	//
// }


//Group Anagrams
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// vector<vector<string> > groupAnagrams(vector<string>& strs) {
// 	vector<vector<string> > result;
// 	int size = strs.size();
// 	if(size <= 0)
// 		return result;
// 	unordered_map<string, vector<string> > myMap;
// 	for(int i = 0; i < strs.size(); i++) {
// 		string str = strs[i];
// 		sort(str. begin(), str.end());
// 		if(myMap.find(str) == myMap.end()) {
// 			vector<string> tmp;
// 			tmp.push_back(strs[i]);
// 			myMap[str] = tmp;
// 		} else {
// 			myMap[str].push_back(strs[i]);
// 		}
// 	}
// 	unordered_map<string, vector<string> >::iterator iter;
// 	for(iter = myMap.begin(); iter != myMap.end(); iter++) {
// 		vector<string> tmp = iter->second;
// 		sort(tmp.begin(), tmp.end());
// 		result.push_back(tmp);
// 	}
// 	return result;
// }

// int main() {
// 	vector<string> strs;
// 	strs.push_back("eat");
// 	strs.push_back("tea");
// 	strs.push_back("tan");
// 	strs.push_back("ate");
// 	strs.push_back("nat");
// 	strs.push_back("bat");
// 	vector<vector<string> > result = groupAnagrams(strs);
// 	for(int i = 0; i < result.size(); i++) {
// 		for(int j = 0; j < result[i].size(); j++)
// 			cout<<result[i][j]<<" ";
// 		cout<<endl;
// 	}
// 	return 0;
// }

//Length of Last Word
// #include <iostream>

// using namespace std;

// //记得去除最后的空格，从后面第一个不是空格的字符开始计数
// int lengthOfLastWord(string s) {
// 	int len = s.length();
// 	if(len <= 0)
// 		return 0;
// 	int i = len-1;
// 	int result = 0;
// 	while(i >= 0) {
// 		if(s[i] != ' ')
// 			break;
// 		i--;
// 	}
// 	while(i >= 0) {
// 		if(s[i] != ' ') {
// 			result++;
// 			i--;
// 		} else {
// 			break;
// 		}
// 	}
// 	return result;
// }

// int main() {
// 	string s = "Hello World ";
// 	int result = lengthOfLastWord(s);
// 	cout<<result<<endl;
// 	return 0;
// }

//Add Binary
// #include <iostream>

// using namespace std;

// string addBinary(string a, string b) {
// 	if(a.length() <= 0)
// 		return b;
// 	if(b.length() <= 0)
// 		return a;
// 	int lenA = a.length()-1;
// 	int lenB = b.length()-1;
// 	char ch[] = {'0', '1'};
// 	int num = 0;
// 	string result;
// 	while(lenA >= 0 && lenB >= 0) {
// 		num = num + (a[lenA] - '0') + (b[lenB] - '0');
// 		result.push_back(ch[num%2]);
// 		num /= 2;
// 		lenA--;
// 		lenB--;
// 	}
// 	while(lenA >= 0) {
// 		num = num + (a[lenA] - '0');
// 		result.push_back(ch[num%2]);
// 		num /= 2;
// 		lenA--;
// 	}
// 	while(lenB >= 0) {
// 		num = num + (b[lenB] - '0');
// 		result.push_back(ch[num%2]);
// 		num /= 2;
// 		lenB--;
// 	}
// 	if(num > 0) {
// 		result.push_back(ch[num]);
// 	}
// 	reverse(result.begin(), result.end());
// 	return result;
// }

// int main() {
// 	string a = "111";
// 	string b = "1";
// 	string result = addBinary(a, b);
// 	cout<<result<<endl;
// 	return 0;
// }

//Text Justification
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<string> fullJustify(vector<string>& words, int maxWidth) {
// 	//
// }

// int main() {
// 	//
// }

//Simplify Path
// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// //思路就是用一个栈来额外存储两个‘/’中的字符串，如果字符串是"."的话，就不做任何处理，如果是".."的话，就要将栈里面的元素弹出一个
// string simplifyPath(string path) {
// 	int len = path.length();
// 	if(len <= 0)
// 		return path;
// 	stack<string> st;
// 	int indexB = 0;
// 	int indexF;
// 	string result;
// 	while(indexB < len) {
// 		indexF = indexB+1;
// 		while(indexF < len && path[indexF] != '/')
// 			indexF++;
// 		if(indexF-indexB-1 > 0) {
// 			string tmp = path.substr(indexB+1, indexF-indexB-1);
// 			if(tmp == ".") {
// 				// continue;
// 			} else if(tmp == "..") {
// 				if(!st.empty())
// 					st.pop();
// 			} else {
// 				st.push(tmp);
// 			}
// 		}
// 		indexB = indexF;
// 	}
// 	vector<string> tmp;
// 	while(!st.empty()) {
// 		tmp.push_back(st.top());
// 		st.pop();
// 	}
// 	result.push_back('/');
// 	for(int i = tmp.size()-1; i >= 0; i--) {
// 		result.append(tmp[i]);
// 		result.push_back('/');
// 	}
// 	return (result.length() > 1) ? result.substr(0, result.length()-1) : result;
// }

// int main() {
// 	// /a/./b/../../c/
// 	// /home/
// 	// /../
// 	// /home//foo/
// 	string str = "/../";
// 	string result = simplifyPath(str);
// 	cout<<result<<endl;
// 	return 0;
// }


//Edit Distance
// #include <iostream>
// #include <vector>

// using namespace std;

// int minDistance(string word1, string word2) {
// 	int row = word1.length() + 1;
// 	int col = word2.length() + 1;
// 	vector<vector<int> > result(row, vector<int>(col, 0));
// 	for(int i = 0; i < row; i++) {
// 		result[i][0] = i;
// 	}
// 	for(int j = 0; j < col; j++) {
// 		result[0][j] = j;
// 	}
// 	for(int i = 1; i < row; i++) {
// 		for(int j = 1; j < col; j++) {
// 			if(word1[i-1] == word2[j-1])
// 				result[i][j] = result[i-1][j-1];
// 			else
// 				result[i][j] = result[i-1][j-1] + 1;
// 			result[i][j] = min(result[i][j], min(result[i-1][j]+1, result[i][j-1]+1));
// 		}
// 	}
// 	return result[row-1][col-1];
// }

// int main() {
// 	string word1 = "foo";
// 	string word2 = "home";
// 	int result = minDistance(word1, word2);
// 	cout<<result<<endl;
// 	return 0;
// }


//Minimum Window Substring
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// string minWindow(string s, string t) {
// 	string result;
// 	if(s.length() <= 0 || t.length() <= 0)
// 		return result;
// 	int indexF = 0;
// 	int indexB = 0;
// 	int lenT = t.length();
// 	unordered_map<char, int> myMap;
// 	int start = 0;
// 	int end = 0;
// 	int count = 0;
// 	int minWindow = 0;
// 	for(int i = 0; i < lenT; i++)
// 		myMap[t[i]] = 0;
// 	while(indexF < s.length()) {
// 		if(myMap.find(s[indexF]) != myMap.end()) {
// 			count++;
// 			if(count == 1)
// 				start = indexF;
// 			if(count == lenT) {
// 				end = indexF;
// 				if(minWindow > end-start+1)
// 					minWindow = end-start+1;
// 			}
// 		}
// 	}
// }

// int main() {
// 	string s = "ADOBECODEBANC";
// 	string t = "ABC";
// 	string result = minWindow(s, t);
// 	cout<<result<<endl;
// 	return 0;
// }


//Scramble String
// #include <iostream>

// using namespace std;

// //这道题的思路是分别将s1和s2分成两部分，s11，s12，s21，s22，
// //如果满足(s11 ~ s21)&&(s12 ~ s22)或者(s11 ~ s22)&&(s12 ~ s21)，那结果就是true，否则就是false
// bool isScramble(string s1, string s2) {
// 	int l1 = s1.length();
// 	int l2 = s2.length();
// 	if(l1 != l2)
// 		return false;
// 	if(l1 == 1)
// 		return (s1 == s2);
// 	string st1 = s1;
// 	string st2 = s2;
// 	sort(st1.begin(), st1.end());
// 	sort(st2.begin(), st2.end());
// 	if(st1 != st2)
// 		return false;

// 	string s11, s12, s21, s22;
// 	bool result = false;
// 	for(int i = 1; i < l1 && !result; i++) {
// 		s11 = s1.substr(0, i);
// 		s12 = s1.substr(i, l1-i);
// 		s21 = s2.substr(0, i);
// 		s22 = s2.substr(i, l2-i);
// 		result = isScramble(s11, s21) && isScramble(s12, s22);
// 		if(result == false) {
// 			s21 = s2.substr(0, l2-i);
// 			s22 = s2.substr(l2-i, i);
// 			result = isScramble(s11, s22) && isScramble(s12, s21);
// 		}
// 	}
// 	return result;
// }

// //这道题还可以采用动态规划的方法解决
// bool isScramble(string s1, string s2) {
// 	//
// }

// int main() {
// 	string s1 = "great";
// 	string s2 = "rgtae";
// 	if(isScramble(s1, s2))
// 		cout<<"is scramble"<<endl;
// 	else
// 		cout<<"not scramble"<<endl;
// 	return 0;
// }


//Reverse Words in a String
// #include <iostream>
// #include <vector>

// using namespace std;

// //这道题的corner case是开头和结尾的空格，以及单词中间存在的空格，因此这道题先将每个单词划分开来并存放到vector中
// //然后再将单词拼接起来
// //其实这种题目有更常规的做法，那就是先整体进行翻转，然后再挨个单词进行翻转，不过这道题单词中间存在多于空格，并且要
// //消除这些空格，所以使用这种方法并不方便
// void reverseWords(string &s) {
// 	int len = s.length();
// 	if(len <= 0)
// 		return ;
// 	int i = 0;
// 	int j = 0;
// 	vector<string> vec;
// 	while(i < len) {
// 		while(i < len && s[i] == ' ')
// 			i++;
// 		j = i;
// 		while(j < len && s[j] != ' ')
// 			j++;
// 		if(j-i > 0)
// 			vec.push_back(s.substr(i, j-i));
// 		i = j;
// 	}
// 	s.clear();
// 	for(int i = vec.size()-1; i >= 0; i--) {
// 		s.append(vec[i]);
// 		s.push_back(' ');
// 	}
// 	s = s.substr(0, s.length()-1);
// }

// int main() {
// 	string s = "  the  sky is blue ";
// 	reverseWords(s);
// 	cout<<"."<<s<<".."<<endl;
// 	return 0;
// }


//Interleaving String
#include <iostream>

using namespace std;

//采用递归的方法会超时，所以要用dp来解决
// bool isInterleave(string s1, string s2, string s3) {
// 	if(s1.length() == 0)
// 		return s2==s3;
// 	if(s2.length() == 0)
// 		return s1==s3;
// 	if(s3.length() == 0)
// 		return s1.length() + s2.length() == 0;

// 	if(s1[0] == s3[0] && s2[0] != s3[0]) {
// 		return isInterleave(s1.substr(1), s2, s3.substr(1));
// 	} else if(s1[0] != s3[0] && s2[0] == s3[0]) {
// 		return isInterleave(s1, s2.substr(1), s3.substr(1));
// 	} else if(s1[0] == s3[0] && s2[0] == s3[0]) {
// 		return (isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1)));
// 	} else {
// 		return false;
// 	}
// }

bool isInterleave(string s1, string s2, string s3) {
	if(s1.length() == 0)
		return s2==s3;
	if(s2.length() == 0)
		return s1==s3;
	if(s3.length() == 0)
		return s1.length() + s2.length() == 0;

	if(s1[0] == s3[0] && s2[0] != s3[0]) {
		return isInterleave(s1.substr(1), s2, s3.substr(1));
	} else if(s1[0] != s3[0] && s2[0] == s3[0]) {
		return isInterleave(s1, s2.substr(1), s3.substr(1));
	} else if(s1[0] == s3[0] && s2[0] == s3[0]) {
		return (isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1)));
	} else {
		return false;
	}
}

int main() {
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";
	if(isInterleave(s1, s2, s3))
		cout<<"is Interleaving"<<endl;
	else
		cout<<"not Interleaving"<<endl;
	return 0;
}




















