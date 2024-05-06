# LeetCode_Practice

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
- ***Always check if the array or vector out of order, EVEN IF IN A WHILE OR IF.*
- The sequential order is also important.
