class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        '''
        count all occurances of characters in magazine
        check if we have sufficient characters in magazine
        that can make ransomNote
        '''
        cnt_magazine = Counter(magazine)
        # print(cnt_magazine)
        for c in ransomNote:
            if cnt_magazine[c] == 0:
                return False
            else :
                cnt_magazine[c] -= 1
        return True