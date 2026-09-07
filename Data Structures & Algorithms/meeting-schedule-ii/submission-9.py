"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        startTimes = [it.start for it in intervals]
        endTimes = [it.end for it in intervals]
        startTimes.sort()
        endTimes.sort()
        i, j = 0, 0
        n = len(intervals)
        res, rooms = 0, 0
        while i < n and j < n:
            if startTimes[i] < endTimes[j]:
                rooms += 1
                i += 1
            else:
                rooms -= 1
                j += 1
            res = max(res, rooms)
        return res
