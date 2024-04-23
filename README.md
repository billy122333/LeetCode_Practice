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
