class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        INF=1e9
        prices=[INF]*n 
        prices[src]=0 
        for i in range(k+1): 
            temp=prices.copy()
            for s,d,p in flights: 
                if prices[s]==INF: 
                    continue 
                if temp[d]>prices[s]+p: 
                    temp[d]=prices[s]+p 
            prices=temp 
        return -1 if prices[dst]==INF else prices[dst]