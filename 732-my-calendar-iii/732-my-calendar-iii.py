class MyCalendarThree:

    def __init__(self):
        self.li = []

    def book(self, start: int, end: int) -> int:
        bisect.insort(self.li, (start, 1))
        bisect.insort(self.li, (end, -1))
        
        res, cnt = 0, 0
        for pos, n in self.li:
            cnt += n
            res = max(res, cnt)
        
        return res

# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)