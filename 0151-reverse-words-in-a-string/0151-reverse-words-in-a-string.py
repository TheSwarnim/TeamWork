class Solution:
    def reverseWords(self, s: str) -> str:
        res = ""
        for subStr in reversed(s.split(' ')):
            if subStr != "":
                res += subStr + " "
        return res[:len(res)-1]