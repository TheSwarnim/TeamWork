class Solution:
    def closeStrings(self, w1: str, w2: str) -> bool:
        c1, c2 = Counter(w1),  Counter(w2)
        # print(c1, c1.keys(), c1.values())
        # print(c2, c2.keys(), c2.values())
        return sorted(c2.values()) == sorted(c1.values()) and c1.keys() == c2.keys()