class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dr = [0, 1, 0, -1] 
        dc = [1, 0, -1, 0]
        m, n = len(grid), len(grid[0])
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    count += 1
                    # start bfs
                    q = deque()
                    grid[i][j] = "0"
                    q.append((i, j))
                    while q:
                        r, c = q.popleft()
                        for k in range(4):
                            nr, nc = r + dr[k], c + dc[k]
                            if (
                                nr >= 0
                                and nc >= 0
                                and nr < m
                                and nc < n
                                and grid[nr][nc] == "1"
                            ):
                                q.append((nr, nc))
                                grid[nr][nc] = "0"

        return count
