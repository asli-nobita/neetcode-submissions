class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        n = len(triplets)
        copy = [
            t for t in triplets if (t[0] <= target[0] and t[1] <= target[1] and t[2] <= target[2])
        ]
        for i in range(3):
            found = False
            for c in copy:
                if c[i] == target[i]:
                    found = True
                    break
            if not found:
                return False
        return True
