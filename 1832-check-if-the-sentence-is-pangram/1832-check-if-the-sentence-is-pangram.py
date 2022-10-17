class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        # lst = [0]*26
        # for c in sentence:
        #     lst[ord(c) - ord('a')] += 1
        # return 0 not in lst
        return len(set(sentence)) == 26