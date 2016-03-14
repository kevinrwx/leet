
//Linked list

//Add two numbers
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// 	if(l1 == NULL)
// 		return l2;
// 	if(l2 == NULL)
// 		return l1;
// 	ListNode* dummy = new ListNode(-1);
// 	ListNode* pNode = dummy;
// 	ListNode* pNode1 = l1;
// 	ListNode* pNode2 = l2;
// 	int tmp = 0;
// 	while(pNode1 != NULL && pNode2 != NULL) {
// 		pNode->next = new ListNode((pNode1->val + pNode2->val + tmp) % 10);
// 		tmp = (pNode1->val + pNode2->val + tmp) / 10;
// 		pNode1 = pNode1->next;
// 		pNode2 = pNode2->next; 
// 		pNode = pNode->next;
// 	}
// 	while(pNode1 != NULL) {
// 		pNode->next = new ListNode((pNode1->val + tmp) % 10);
// 		tmp = (pNode1->val + tmp) / 10;
// 		pNode1 = pNode1->next;
// 		pNode = pNode->next;
// 	}
// 	while(pNode2 != NULL) {
// 		pNode->next = new ListNode((pNode2->val + tmp) % 10);
// 		tmp = (pNode2->val + tmp) / 10;
// 		pNode2 = pNode2->next;
// 		pNode = pNode->next;
// 	}
// 	//这个点需要注意，最后容易剩余进位的数字没处理，corner case：l1:[5] l2[5] 
// 	if(tmp != 0)
// 		pNode->next = new ListNode(tmp);
// 	return dummy->next;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	else {
// 		ListNode* pNode = head;
// 		while(pNode != NULL) {
// 			cout<<pNode->val<<" ";
// 			pNode = pNode->next;
// 		}
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l1 = new ListNode(2);
// 	l1->next = new ListNode(4);
// 	l1->next->next = new ListNode(3);
// 	ListNode* l2 = new ListNode(5);
// 	l2->next = new ListNode(6);
// 	l2->next->next = new ListNode(4);
// 	ListNode* result = addTwoNumbers(l1, l2);
// 	printList(result);
// 	return 0;
// }

//Remove Nth Node From End of List
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// // 保证只遍历一遍的技巧是维持两个距离一直是N的指针，当最后一个指针指向结尾时，前一个指针就指向了需要删除节点的
// // 前一个节点
// ListNode* removeNthFromEnd(ListNode* head, int n) {
// 	if(head == NULL)
// 		return NULL;
// 	ListNode* dummy = new ListNode(-1);
// 	dummy->next = head;
// 	ListNode* pHead = dummy;
// 	ListNode* pTail = dummy;
// 	while(n-- > 0) {
// 		pHead = pHead->next;
// 	}
// 	while(pHead->next != NULL) {
// 		pHead = pHead->next;
// 		pTail = pTail->next;
// 	}
// 	pTail->next = pTail->next->next;
// 	return dummy->next;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	else {
// 		ListNode* pNode = head;
// 		while(pNode != NULL) {
// 			cout<<pNode->val<<" ";
// 			pNode = pNode->next;
// 		}
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* head = new ListNode(1);
// 	head->next = new ListNode(2);
// 	head->next->next = new ListNode(3);
// 	head->next->next->next = new ListNode(4);
// 	head->next->next->next->next = new ListNode(5);
// 	int n = 5;
// 	ListNode* result = removeNthFromEnd(head, n);
// 	printList(result);
// 	return 0;
// }

//Merge Two Sorted Lists
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
// 	if(l1 == NULL)
// 		return l2;
// 	if(l2 == NULL)
// 		return l1;
// 	ListNode* dummy = new ListNode(-1);
// 	ListNode* pNode1 = l1;
// 	ListNode* pNode2 = l2;
// 	ListNode* pNode = dummy;
// 	while(pNode1 != NULL && pNode2 != NULL) {
// 		if(pNode1->val <= pNode2->val) {
// 			pNode->next = pNode1;
// 			pNode1 = pNode1->next;
// 		} else {
// 			pNode->next = pNode2;
// 			pNode2 = pNode2->next;
// 		}
// 		pNode = pNode->next;
// 	}
// 	if(pNode1 != NULL) {
// 		pNode->next = pNode1;
// 	}
// 	if(pNode2 != NULL) {
// 		pNode->next = pNode2;
// 	}
// 	return dummy->next;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	else {
// 		ListNode* pNode = head;
// 		while(pNode != NULL) {
// 			cout<<pNode->val<<" ";
// 			pNode = pNode->next;
// 		}
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l1 = new ListNode(1);
// 	l1->next = new ListNode(4);
// 	l1->next->next = new ListNode(5);
// 	ListNode* l2 = new ListNode(2);
// 	l2->next = new ListNode(3);
// 	l2->next->next = new ListNode(6);
// 	ListNode* result = mergeTwoLists(l1, l2);
// 	printList(result);
// 	return 0;
// }

//Merge k Sorted Lists
// #include <iostream>
// #include <vector>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// struct MinHeap {
// 	vector<ListNode*> vec;
// 	int size;
// 	MinHeap(vector<ListNode*>& x, int y) : vec(x), size(y) {}
// };

// void swap(ListNode** x, ListNode** y) {
// 	ListNode* tmp = *x;
// 	*x = *y;
// 	*y = tmp;
// }

// void MinHeapify(MinHeap* minHeap, int idx) {
// 	int smallest = idx;
// 	int left = (smallest << 1) + 1;
// 	int right = (smallest << 1) + 2;
// 	if(left < minHeap->size && minHeap->vec[left]->val < minHeap->vec[smallest]->val)
// 		smallest = left;
// 	if(right < minHeap->size && minHeap->vec[right]->val < minHeap->vec[smallest]->val)
// 		smallest = right;
// 	if(smallest != idx) {
// 		swap(&minHeap->vec[smallest], &minHeap->vec[idx]);
// 		MinHeapify(minHeap, smallest);
// 	}
// }

// MinHeap* buildAndCreateHeap(vector<ListNode*>& vec) {
// 	MinHeap* minHeap = new MinHeap(vec, vec.size());
// 	for(int i = (minHeap->size - 2)/2; i >= 0; i--) {
// 		MinHeapify(minHeap, i);
// 	}
// 	return minHeap;
// }

// ListNode* extractMin(MinHeap* minHeap) {
// 	if(minHeap->size <= 0)
// 		return NULL;
// 	else {
// 		ListNode* tmp = minHeap->vec[0];
// 		swap(&minHeap->vec[0], &minHeap->vec[minHeap->size-1]);
// 		minHeap->vec.pop_back();
// 		minHeap->size--;
// 		MinHeapify(minHeap, 0);
// 		return tmp;
// 	}
// }

// void insert(MinHeap* minHeap, ListNode* node) {
// 	minHeap->vec.push_back(node);
// 	minHeap->size++;
// 	int i = minHeap->size-1;
// 	while(i != 0 && minHeap->vec[i]->val < minHeap->vec[(i-1)/2]->val) {
// 		swap(&minHeap->vec[i], &minHeap->vec[(i-1)/2]);
// 		i = (i-1)/2;
// 	}
// }

// ListNode* mergeKLists(vector<ListNode*>& lists) {
// 	if(lists.size() == 0)
// 		return NULL;
// 	vector<ListNode*> vec;
// 	for(int i = 0; i < lists.size(); i++) {
// 		if(lists[i] != NULL)
// 			vec.push_back(lists[i]);
// 	}
// 	if(vec.size() == 0)
// 		return NULL;
// 	MinHeap* minHeap = buildAndCreateHeap(vec);
// 	ListNode* dummy = new ListNode(-1);
// 	ListNode* pNode = dummy;
// 	while(minHeap->size > 0) {
// 		ListNode* tmp = extractMin(minHeap);
// 		if(tmp->next != NULL)
// 			insert(minHeap, tmp->next);
// 		pNode->next = tmp;
// 		tmp->next = NULL;
// 		pNode = pNode->next;
// 	}
// 	return dummy->next;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	else {
// 		ListNode* pNode = head;
// 		while(pNode != NULL) {
// 			cout<<pNode->val<<" ";
// 			pNode = pNode->next;
// 		}
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l1 = new ListNode(1);
// 	l1->next = new ListNode(4);
// 	l1->next->next = new ListNode(5);
// 	ListNode* l2 = new ListNode(2);
// 	l2->next = new ListNode(3);
// 	l2->next->next = new ListNode(6);
// 	vector<ListNode*> lists;
// 	lists.push_back(l1);
// 	lists.push_back(l2);
// 	ListNode* result = mergeKLists(lists);
// 	printList(result);
// 	return 0;
// }

//Swap Nodes in Pairs
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* swapPairs(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return head;
// 	ListNode* dummy = new ListNode(-1);
// 	dummy->next = head;
// 	ListNode* pNode = dummy; 
// 	while(pNode->next != NULL && pNode->next->next != NULL) {
// 		ListNode* tmp = pNode->next->next;
// 		pNode->next->next = tmp->next;
// 		tmp->next = pNode->next;
// 		pNode->next = tmp;
// 		pNode = pNode->next->next;
// 	}
// 	return dummy->next;
// }

// void printList(ListNode* node) {
// 	if(node == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = node;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* head = new ListNode(1);
// 	// head->next = new ListNode(2);
// 	// head->next->next = new ListNode(3);
// 	// head->next->next->next = new ListNode(4);
// 	printList(head);
// 	ListNode* result = swapPairs(head);
// 	printList(result);
// 	return 0;
// }


//Reverse Nodes in k-Group
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* reverseKGroup(ListNode* head, int k) {
// 	int n = 0;
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		n++;
// 		pNode = pNode->next;
// 	}
// 	if(head == NULL || n < k)
// 		return head;
// 	int times = n / k;
// 	ListNode* dummy = new ListNode(-1);
// 	dummy->next = head;
// 	pNode = dummy;
// 	ListNode* dummyNew = new ListNode(-1);
// 	ListNode* pHead = dummyNew;
// 	while(times-- > 0) {
// 		int count = k;
// 		while(count-- > 0) {
// 			ListNode* tmp = pNode->next;
// 			pNode = pNode->next;
// 			tmp->next = pHead->next;
// 			pHead->next = tmp;
// 		}
// 		pHead = pNode;
// 	}
// 	// if(pNode->next != NULL)
// 	// 	pHead->next = pNode->next;
// 	return dummyNew->next;
// }

// void printList(ListNode* node) {
// 	if(node == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = node;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(2);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(4);
// 	l->next->next->next->next = new ListNode(5);
// 	printList(l);
// 	int k = 2;
// 	ListNode* result = reverseKGroup(l, k);
// 	printList(result);
// 	return 0;
// }

//Rotate List
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// //增加判断条件好像能提高这道题的通过率
// ListNode* rotateRight(ListNode* head, int k) {
// 	if(head == NULL || k == 0)
// 		return head;
// 	ListNode* dummy = new ListNode(-1);
// 	dummy->next = head;
// 	ListNode* pNode = head;
// 	int n = 0;
// 	while(pNode != NULL) {
// 		pNode = pNode->next;
// 		n++;
// 	}
// 	k = k % n;
// 	if(k > 0) {
// 		ListNode* pHead = dummy;
// 		ListNode* pTail = dummy;
// 		while(k-- > 0) {
// 			pHead = pHead->next;
// 		}
// 		while(pHead->next != NULL) {
// 			pHead = pHead->next;
// 			pTail = pTail->next;
// 		}
// 		pHead->next = dummy->next;
// 		dummy->next = pTail->next;
// 		pTail->next = NULL;
// 	}
// 	return dummy->next;
// }

// void printList(ListNode* node) {
// 	if(node == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = node;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(2);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(4);
// 	l->next->next->next->next = new ListNode(5);
// 	printList(l);
// 	int k = 2;
// 	ListNode* result = rotateRight(l, k);
// 	printList(result);
// 	return 0;
// }

//Remove Duplicates from Sorted List II
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* deleteDuplicates(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return head;
// 	ListNode* dummy = new ListNode(-1);
// 	dummy->next = head;
// 	ListNode* pNode = dummy;
// 	while(pNode->next != NULL) {
// 		int count = 0;
// 		ListNode* qNode = pNode->next;
// 		//记得增加qNode不为空的判断条件，否则qNode会为空，导致判断条件qNode->val == pNode->next->val出问题
// 		while(qNode != NULL && qNode->val == pNode->next->val) {
// 			qNode = qNode->next;
// 			count++;
// 		}
// 		if(count <= 1)
// 			pNode = pNode->next;
// 		else
// 			pNode->next = qNode;
// 	}
// 	return dummy->next;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(1);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(5);
// 	l->next->next->next->next = new ListNode(5);
// 	printList(l);
// 	ListNode* result = deleteDuplicates(l);
// 	printList(result);
// 	return 0;
// }

//Remove Duplicates from Sorted List
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* deleteDuplicates(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return head;
// 	ListNode* dummy = new ListNode(-1);
// 	dummy->next = head;
// 	ListNode* pNode = head;
// 	while(pNode != NULL && pNode->next != NULL) {
// 		if(pNode->val == pNode->next->val)
// 			pNode->next = pNode->next->next;
// 		else
// 			pNode = pNode->next;
// 	}
// 	return dummy->next;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(1);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(4);
// 	l->next->next->next->next = new ListNode(5);
// 	printList(l);
// 	ListNode* result = deleteDuplicates(l);
// 	printList(result);
// 	return 0;
// }

//Partition List
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* partition(ListNode* head, int x) {
// 	if(head == NULL || head->next == NULL)
// 		return head;
// 	ListNode* small = new ListNode(-1);
// 	ListNode* large = new ListNode(-1);
// 	ListNode* pSmall = small;
// 	ListNode* pLarge = large;
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		ListNode* tmp = pNode->next;
// 		pNode->next = NULL;
// 		if(pNode->val < x) {
// 			pSmall->next = pNode;
// 			pSmall = pSmall->next;
// 		} else {
// 			pLarge->next = pNode;
// 			pLarge = pLarge->next;
// 		}
// 		pNode = tmp;
// 	}
// 	pSmall->next = large->next;
// 	return small->next;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(4);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(2);
// 	l->next->next->next->next = new ListNode(5);
// 	printList(l);
// 	int x = 3;
// 	ListNode* result = partition(l, x);
// 	printList(result);
// 	return 0;
// }

//Reverse Linked List II
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// ListNode* reverseBetween(ListNode* head, int m, int n) {
// 	if(head == NULL || (m == n))
// 		return head;
// 	ListNode* dummy = new ListNode(-1);
// 	dummy->next = head;
// 	ListNode* pNode = dummy;
// 	int count = 1;
// 	while(pNode->next != NULL && count < m) {
// 		pNode = pNode->next;
// 		count++;
// 	}
// 	ListNode* qNode = pNode->next;
// 	pNode->next = NULL;
// 	while(qNode != NULL && count <= n) {
// 		ListNode* tmp = qNode;
// 		qNode = qNode->next;
// 		tmp->next = pNode->next;
// 		pNode->next = tmp;
// 		count++;
// 	}
// 	while(pNode->next != NULL)
// 		pNode = pNode->next;
// 	pNode->next = qNode;
// 	return dummy->next;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(4);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(2);
// 	l->next->next->next->next = new ListNode(5);
// 	printList(l);
// 	int m = 2;
// 	int n = 4;
// 	ListNode* result = reverseBetween(l, m, n);
// 	printList(result);
// 	return 0;
// }

//Convert Sorted List to Binary Search Tree
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// //使用中递归
// TreeNode* buildTree(ListNode*& node, int start, int end) {
// 	if(start > end)
// 		return NULL;
// 	int mid = start + (end - start) / 2;
// 	TreeNode* left = buildTree(node, start, mid-1);
// 	TreeNode* root = new TreeNode(node->val);
// 	root->left = left;
// 	node = node->next;
// 	root->right = buildTree(node, mid+1, end);
// 	return root;
// }

// TreeNode* sortedListToBST(ListNode* head) {
// 	if(head == NULL)
// 		return NULL;
// 	int len = 0;
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		len++;
// 		pNode = pNode->next;
// 	}
// 	return buildTree(head, 0, len-1);
// }

// TreeNode* findMid(ListNode* start, ListNode* end) {
// 	if(start == end)
// 		return NULL;
// 	ListNode* mid = start;
// 	ListNode* probe = start;
// 	//这一步的快慢指针用得很漂亮，值得学习
// 	while(probe != end && probe->next != end) {
// 		mid = mid->next;
// 		probe = probe->next->next;
// 	}
// 	TreeNode* root = new TreeNode(mid->val);
// 	root->left = findMid(start, mid);
// 	root->right = findMid(mid->next, end);
// 	return root;
// }

// TreeNode* sortedListToBST(ListNode* head) {
// 	if(head == NULL)
// 		return NULL;
// 	TreeNode* root = findMid(head, NULL);
// 	return root;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// void inorderTraversal(TreeNode* root) {
// 	if(root != NULL) {
// 		inorderTraversal(root->left);
// 		cout<<root->val<<" ";
// 		inorderTraversal(root->right);
// 	}
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(2);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(4);
// 	l->next->next->next->next = new ListNode(5);
// 	printList(l);
// 	TreeNode* root = sortedListToBST(l);
// 	inorderTraversal(root);
// 	return 0;
// }

//copy list with random pointer
// #include <iostream>

// using namespace std;

// struct RandomListNode {
// 	int label;
// 	RandomListNode* next;
// 	RandomListNode* random;
// 	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
// };

// RandomListNode* copyRandomList(RandomListNode* head) {
// 	//
// }

// int main() {
// 	//
// }


//Linked List Cycle
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// bool hasCycle(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return false;
// 	ListNode* pSlow = head;
// 	ListNode* pFast = head;
// 	while(pFast != NULL && pFast->next != NULL) {
// 		pSlow = pSlow->next;
// 		pFast = pFast->next->next;
// 		if(pSlow == pFast) {
// 			return true;
// 		}
// 	}
// 	return false;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(2);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(4);
// 	l->next->next->next->next = new ListNode(5);
// 	l->next->next->next->next->next = l->next;
// 	if(hasCycle(l)) {
// 		cout<<"has cycle"<<endl;
// 	} else {
// 		cout<<"don't has cycle"<<endl;
// 	}
// 	return 0;
// }


//Linked List Cycle II
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// bool hasCycle(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return false;
// 	ListNode* pSlow = head;
// 	ListNode* pFast = head;
// 	while(pFast != NULL && pFast->next != NULL) {
// 		pSlow = pSlow->next;
// 		pFast = pFast->next->next;
// 		if(pSlow == pFast) {
// 			return true;
// 		}
// 	}
// 	return false;
// }

// ListNode* detectCycle(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return NULL;
// 	ListNode* pSlow = head;
// 	ListNode* pFast = head;
// 	bool flag = false;
// 	ListNode* result = NULL;
// 	while(pFast != NULL && pFast->next != NULL) {
// 		pSlow = pSlow->next;
// 		pFast = pFast->next->next;
// 		if(pSlow == pFast) {
// 			flag = true;
// 			break;
// 		}
// 	}
// 	//判断环起点的代码需要注意
// 	if(flag) {
// 		ListNode* pNode1 = head;
// 		int count1 = 0;
// 		while(pNode1 != pFast) {
// 			pNode1 = pNode1->next;
// 			count1++;
// 		}
// 		ListNode* pNode2 = pFast->next;
// 		int count2 = 0;
// 		while(pNode2 != pFast) {
// 			pNode2 = pNode2->next;
// 			count2++;
// 		}
// 		ListNode* pNode = (count1 > count2) ? head : pFast->next;
// 		ListNode* qNode = (count1 > count2) ? pFast->next : head;
// 		int count = (count1 > count2) ? (count1 - count2) : (count2 - count1);
// 		while(count > 0) {
// 			pNode = pNode->next;
// 			count--;
// 		}
// 		while(pNode != qNode) {
// 			pNode = pNode->next;
// 			qNode = qNode->next;
// 		}
// 		result = pNode;
// 	}
// 	return result;
// }

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(2);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(4);
// 	l->next->next->next->next = new ListNode(5);
// 	l->next->next->next->next->next = l->next;
// 	ListNode* result = detectCycle(l);
// 	cout<<result->val<<endl;
// 	return 0;
// }

//Reorder List
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// ListNode* reverse(ListNode* head) {
// 	if(head == NULL || head->next ==NULL)
// 		return head;
// 	ListNode* dummy = new ListNode(-1);
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		ListNode* tmp = pNode;
// 		pNode = pNode->next;
// 		tmp->next = dummy->next;
// 		dummy->next = tmp;
// 	}
// 	return dummy->next;
// }

// //思路比较简单，就是先用快慢指针将链表分为前后两段，然后将后一段链表翻转，最后再将链表拼接
// void reorderList(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return ;
// 	ListNode* pSlow = head;
// 	ListNode* pFast = head;
// 	while(pFast != NULL && pFast->next != NULL) {
// 		pSlow = pSlow->next;
// 		pFast = pFast->next->next;
// 	}
// 	ListNode* dummy = new ListNode(-1);
// 	ListNode* dummy1 = new ListNode(-1);
// 	ListNode* dummy2 = new ListNode(-1);
// 	dummy1->next = head;
// 	//翻转后半部分链表
// 	dummy2->next = reverse(pSlow->next);
// 	pSlow->next = NULL;
// 	ListNode* pNode = dummy;
// 	ListNode* pNode1 = dummy1->next;
// 	ListNode* pNode2 = dummy2->next;
// 	while(pNode1 != NULL && pNode2 != NULL) {
// 		ListNode* tmp = pNode1;
// 		pNode1 = pNode1->next;
// 		tmp->next = NULL;
// 		pNode->next = tmp;
// 		pNode = pNode->next;

// 		tmp = pNode2;
// 		pNode2 = pNode2->next;
// 		tmp->next = NULL;
// 		pNode->next = tmp;
// 		pNode = pNode->next;
// 	}
// 	if(pNode1 != NULL)
// 		pNode->next = pNode1;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(2);
// 	l->next->next = new ListNode(3);
// 	l->next->next->next = new ListNode(4);
// 	l->next->next->next->next = new ListNode(5);
// 	reorderList(l);
// 	printList(l);
// 	return 0;
// }


//Insertion Sort List
// #include <iostream>

// using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// void printList(ListNode* head) {
// 	if(head == NULL)
// 		cout<<"empty list";
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		cout<<pNode->val<<" ";
// 		pNode = pNode->next;
// 	}
// 	cout<<endl;
// }

// void insert(ListNode* head, ListNode* node) {
// 	if(head->next == NULL) {
// 		head->next = node;
// 		return ;
// 	} else {
// 		ListNode* pNode = head;
// 		while(pNode->next != NULL && pNode->next->val < node->val)
// 			pNode = pNode->next;
// 		node->next = pNode->next;
// 		pNode->next = node;
// 	}
// }

// //思路比较明确，但是要注意里面的细节问题，比如在链表中插入节点时
// ListNode* insertionSortList(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return head;
// 	ListNode* dummy = new ListNode(-1);
// 	ListNode* pNode = head;
// 	while(pNode != NULL) {
// 		ListNode* tmp = pNode;
// 		pNode = pNode->next;
// 		//要设定tmp的next为NULL
// 		tmp->next = NULL;
// 		insert(dummy, tmp);
// 	}
// 	return dummy->next;
// }

// int main() {
// 	ListNode* l = new ListNode(1);
// 	l->next = new ListNode(1);
// 	// l->next->next = new ListNode(2);
// 	// l->next->next->next = new ListNode(5);
// 	// l->next->next->next->next = new ListNode(4);
// 	printList(l);
// 	ListNode* result = insertionSortList(l);
// 	// printList(result);
// 	return 0;
// }


//Sort List
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
	if(head == NULL)
		cout<<"empty list";
	ListNode* pNode = head;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

void mergeList(ListNode* head1, ListNode* head2) {
	ListNode* dummy = new ListNode(-1);
	ListNode* pNode = dummy;
	ListNode* pNode1 = head1;
	ListNode* pNode2 = head2;
	while(pNode1 != NULL && pNode2 != NULL) {
		ListNode* tmp;
		if(pNode1->val <= pNode2->val) {
			tmp = pNode1;
			pNode1 = pNode1->next;
			tmp->next = pNode->next;
			pNode->next = tmp;
			pNode = pNode->next;
		} else {
			tmp = pNode2;
			pNode2 = pNode2->next;
			tmp->next = pNode->next;
			pNode->next = tmp;
			pNode = pNode->next;
		}
	}
	if(pNode1 != NULL)
		pNode->next = pNode1;
	if(pNode2 != NULL)
		pNode->next = pNode2;
	// return dummy->next;
}

void mergeSortList(ListNode* head) {
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* pSlow = head;
	ListNode* pFast = head;
	while(pFast != NULL && pFast->next != NULL) {
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	ListNode* tmp = pSlow->next;
	pSlow->next = NULL;
	ListNode* head1 = mergeSortList(head);
	ListNode* head2 = mergeSortList(tmp);
	mergeList(head1, head2);
}

ListNode* sortList(ListNode* head) {
	if(head == NULL || head->next == NULL)
		return head;
	return head;
}

int main() {
	ListNode* l = new ListNode(1);
	l->next = new ListNode(3);
	l->next->next = new ListNode(2);
	l->next->next->next = new ListNode(5);
	l->next->next->next->next = new ListNode(4);
	// ListNode* result = insertionSortList(l);
	// printList(result);
	ListNode* result = sortList(l);
	printList(result);
	return 0;
}









