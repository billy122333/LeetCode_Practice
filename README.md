# LeetCode_Practice

## Two pointer
#### 143. Reorder List
- Two pointer直接重新排列值
- 不用綁死在Node與Val上
## Sliding window
## Binary search
#### 378. Kth Smallest Element in a Sorted Matrix
- Binary search 的特殊應用
1. 先用binary search找出min max的中間值
2. 使用helper function 找出這個 mid 在這個matrix中的是第幾小的數字
3. 若helper 找到的 position
  - 大於要找的第K大的元素，代表target要再更小，所以max = mid。
  - 小於要找的第K大的元素，代表target要再更大，所以min = mid+1。
4. 一定要找到底，因為mid不一定存在於陣列中。
[解題參考](https://anj910.medium.com/leetcode-378-kth-smallest-element-in-a-sorted-matrix-%E4%B8%AD%E6%96%87-318d52f366af)

#### 1552. Magnetic Force Between Two Balls
1. 用BS找適合的間距，最小為0, 最大為陣列最大-最小
2. 使用helper function幫助確認這個間距是否放得下
## Hash
## Priority Queue -> heap
## Gready
## DP
### 53. Maximum Subarray
- DP設計須包含最後一個元素
### 55. Jump Game
- 須注意前幾項是否都可以由dp處理，否則需要一些額外處理
### 1143. Longest Common Subsequence
- 經典的二維矩陣dp
## stack
- 別忘了使用Stack當需要倒序的時候
## DFS
### 79. Word Search
- 很暴力的DFS

### 152. Maximum Product Subarray
- 特殊處理遇到負數時
- 使用float來避免overflow
  ![image](https://github.com/user-attachments/assets/f0e9d057-4299-4a9f-9d22-1073b4904c2c)

_________________________________
### 1648
![image](https://user-images.githubusercontent.com/75492436/155433701-31f06d09-bf95-4b08-95f9-f2dfc75f5eca.png)
```
//前項+後項(next lar + 1 並不是 next Largest)
orders >= 當前同加次數
gain = (current largest + next largest + 1) * (cur - next) / 2 * colors
orders < 當前同加次數
//使用餘數定理 Q = mx + r
x = orders/colors
r = orders%colors
gain = (cur + (cur - x) + 1)*(cur - (cur-x))/2 *colors + (cur-x)*r
```
### 417
#### thought:
- Check the end condition carefully when using recersion.
- The initialization of vector
```=cpp
vector<vector<bool>> Pacific(m, vector<bool>(n, false));
```

### 198
#### optimize
![image](https://github.com/billy122333/LeetCode_Practice/assets/75492436/04ff8d53-ef15-47ff-9acb-66625f76266f)
- a easy DP.

### 19

#### Thought
- Can new a point in front of the linked list.
- Be careful when returning, sometimes not just return the head.
```=cpp
return dummy->next;
```

### 211. Design Add and Search Words Data Structure

#### Thought
- Trie Tree to build a string search tree
- Use ASCLL Code to find the correct alphabet quickly.
- Use recursion.

### 165. Compare Version Numbers
- When encounter compare problem, can condiser **Two Pointer** first.
- **Always check if the array or vector out of order, EVEN IF IN A WHILE OR IF.*
- The sequential order in a while loop are also important.
```=cpp
# correct
while(s1_pt < s1 || s2_pt < s2){
# This would check the pointer first, so version1[s1_pt] will not be check when it is out of range 
  while(s1_pt < s1 && version1[s1_pt] != '.' ){
      num1 = 10*num1 + (version1[s1_pt] - '0');
      s1_pt++;
  }
}
# TLE ERROR
while(s1_pt < s1 || s2_pt < s2){
# This would not check the pointer first, so version1[s1_pt] will be out of range 
  while(version1[s1_pt] != '.' && s1_pt < s1){
      num1 = 10*num1 + (version1[s1_pt] - '0');
      s1_pt++;
  }
}
```

### 506. Relative Ranks
- Use priority queue and pair to get the fixed position for all the rank.
- initialize the vector fisrt.

### 2487. Remove Nodes From Linked List
- Monotonic stack or even stack is OK.
- Reverse the linked list.
```=cpp
ListNode *cur=head, *prev = nullptr;
while(cur!=nullptr){
  // 將current的下一個換成上一個node
  swap(cur->next , prev);
  // 換回來繼續下一個動作
  swap(cur, prev);
}
```

### 3075. Maximize Happiness of Selected Children
- Greedy

### 1863. Sum of All Subset XOR Totals
- Use backtracking to [include, exclude] the element into the subset.
### 78. subset
- Use backtracking to store all the subset.

### 1608. Special Array With X Elements Greater Than or Equal X
- 先倒序排列
- 第i個element就是第i-1大的
- 若 nums[m] > m 則有太多數字 比m大 需要找更大的m
- nums[m] < m 則是往m小的逼近去找是否有重複的數
- 最終return 若nums[m] > m 代表m要再大一點

### 2486 Append Characters to String to Make Subsequence
- 找A 要補多少字在最後才能包含B字串
- 標準的two pointer

### 1122. Relative Sort Array
- counting sort

### 945. Minimum Increment to Make Array Unique
- 只要sort以後就很簡單了

### 75. Sort Colors
- fill(start, end, fill_number);
- Counting sort.
