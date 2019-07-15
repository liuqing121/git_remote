class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        #左括号入栈，遇见右括号查看栈顶的字符是否是对应的左括号
        chardict={")":"(", "}":"{", "]":"["}   #右括号为key，左括号为value
        stack=[]
        for char in s:
            if char in chardict:
                topstack = stack.pop() if stack else '#'       #右括号在前面时，栈会为空的处理

                if topstack != chardict[char]:
                    return False
            else:
                stack.append(char)
        return not stack