#Basic Calculator I

**原題:** https://leetcode.com/problems/basic-calculator/

**思路:**

    1. 用一個 stack sign 來儲存當前遇到的符號，如果遇到 '+' 就推 +1 進去，若是 '-' 就推 -1
    2. 若是遇到左括號 '(' 就要看括號前一個符號是什麼: '-' 推 -1; '+' 推 +1，代表要加或減括號內的運算值。
    3. 遇到數字時，就用 res 把數字的值存起來。
    4. 若遇到右括號 ')' 就把當前的符號 pop 掉。


**Why Stack?**

**一個規律：**後面推進來的括號先算，這樣就有一種 LIFO 的感覺。

**舉例:** 若有一算式字串： (1+(4+5+2)-3) 依我的演算法，我會這樣算：
	 sign = [1, 1]
	 
	 1. '(': 推 +1 進入。 						sign = [1, 1, 1], res = 0 
	 2. '1': res += (+1) * 1，將 +1 pop 掉。 	sign = [1, 1], res = 1 
	 3. '+': 推 +1 進入 sign。 					sign = [1, 1, 1], res = 1
	 4. '(': 前一個符號是 '+' 推 +1 進入 sign。 	sign = [1, 1, 1, 1], res = 1
	 5. '4': res += (+1) * 4，將 +1 pop 掉。 	sign = [1, 1, 1], res = 5
	 6. '+': 推 +1 進入 sign。 					sign = [1, 1, 1, 1], res = 5
	 7. '5': res += (+1) * 5，將 +1 pop 掉。 	sign = [1, 1, 1], res = 10
	 8. '+': 推 +1 進入 sign。 					sign = [1, 1, 1, 1], res = 10
	 9. '2': res += (+1) * 2，將 +1 pop 掉。 	sign = [1, 1, 1], res = 12
	 10. ')': 將 +1 pop 掉。 				  sign = [1, 1], res = 12
	 11. '-': 推 -1 進入 sign。 				sign = [1, 1, -1], res= 12 
	 12. '3': res += (-1) * 3，將 -1 pop 掉。 	sign = [1, 1], res = 9 
	 13. ')': 將 +1 pop 掉。 					sign = [1], res = 9 


**代碼:**

```python
class Solution(object):
    def calculate(self, s):
        idx = 0
        res = 0
        sign = [1, 1]

        while idx < len(s):
            x = s[idx]
            if x.isdigit():
                start = idx
                while idx < len(s) and s[idx].isdigit(): idx += 1
                res += sign.pop() * int(s[start:idx])
                continue
            elif x in '(+-':
                sign.append(sign[-1] * (1, -1)[x == '-'])
            elif x == ')': sign.pop()
            idx += 1
        return res
```
