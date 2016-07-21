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
