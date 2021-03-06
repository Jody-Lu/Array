#Simplify Path

**原題:** https://leetcode.com/problems/simplify-path/

**思路:**


1. 因為我們要分析的對象是 '/' 間的內容，故先用 split method 將 path 以 '/' 分開。
2. 接著將 split 的結果推到 stack 內去，因為**後進去的 "位置" 若遇到 ".." 要先被 pop 出來 (後進先出 LIFO)**，故選用 stack data structure。
3. 注意最後回傳的字串前要加 '/' 當開頭。



**舉例:** 以 "/a/./b/../../c/" 為例:

```
1. 先 split: path = ['', 'a', '.', 'b', '..', '..', 'c', '']
2. 遇到空白就跳過
3. 遇到 "位置" 就推到 stack 內
4. 遇到 '..'，先檢查 stack 是否為空。若非空，則 pop; 若空，則 continue
5. 遇到 '.'，則 continue
6. 時間複雜度為 O(n)
```

**代碼:**

```python
class Solution(object):
    def simplifyPath(self, path):
        path = path.split('/')
        stack = []

        for p in path:
            if p == '.':
                if stack: continue
            elif p == '..':
                if stack: stack.pop()
            elif p:
                stack.append(p)
        return '/' + '/'.join(stack)


sol = Solution()

assert sol.simplifyPath("/a/./b/../../c/") == "/c"
assert sol.simplifyPath("/../") == "/"
assert sol.simplifyPath("/home//foo/") == "/home/foo"
assert sol.simplifyPath("/abc/...") == "/abc/..."
assert sol.simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///") == "/e/f/g"
assert sol.simplifyPath("/../") == "/"
assert sol.simplifyPath("/ ../") == "/ .."
assert sol.simplifyPath("/.") == "/"

```