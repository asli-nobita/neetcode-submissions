class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        free = [i for i in range(n)]  # (freeAt,index) 
        heapq.heapify(free) 
        busy = []
        meetings.sort()
        nMeetings = [0 for i in range(n)]
        for start, end in meetings:
            while busy and busy[0][0] <= start: 
                _, idx = heapq.heappop(busy) 
                heapq.heappush(free, idx)
            if free: 
                idx = heapq.heappop(free) 
                heapq.heappush(busy, (end, idx))
                nMeetings[idx] += 1
            else:
                earliest, idx = heapq.heappop(busy)
                end = earliest + end - start
                heapq.heappush(busy, (end, idx))
                nMeetings[idx] += 1
        print(nMeetings)
        max_rooms = 0
        ans = -1
        for i in reversed(range(n)):
            if nMeetings[i] >= max_rooms:
                max_rooms = nMeetings[i]
                ans = i
        return ans
