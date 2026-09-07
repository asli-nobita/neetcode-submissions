class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        queries = [(query, idx) for idx, query in enumerate(queries)]
        queries.sort() 
        intervals.sort()
        result = [0 for _ in range(len(queries))]
        pq = []
        j = 0
        for query, i in queries:
            while j < len(intervals) and intervals[j][0] <= query:
                heapq.heappush(pq, (intervals[j][1] - intervals[j][0] + 1, intervals[j][1]))
                j += 1
            while pq and pq[0][1] < query:
                heapq.heappop(pq)
            if pq:
                result[i] = pq[0][0]
            else:
                result[i] = -1
        return result
