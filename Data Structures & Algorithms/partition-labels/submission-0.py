class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last={} 
        for i,ch in enumerate(s): 
            last[ch]=i 
        ans=[] 
        start,end=0,0
        for i in range(len(s)): 
            ch=s[i] 
            end=max(end,last[ch]) 
            if i==end: 
                ans.append(end-start+1) 
                start,end=i+1,0 
        return ans

