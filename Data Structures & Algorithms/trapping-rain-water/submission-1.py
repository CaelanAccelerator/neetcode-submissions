class Solution:
    def trap(self, height: List[int]) -> int:
        lMax = 0
        vols = [0] * len(height) 
        for i in range(len(height)):
            lMax = max(lMax, height[i])
            vol = lMax - height[i]
            if vol < 0:
                continue
            vols[i] = vol
            lMax = max(lMax, height[i])
            

        rMax = 0
        for i in range(len(height) - 1, -1, -1):
            rMax = max(rMax, height[i])
            vol = rMax - height[i]
            if vol < 0:
                continue
            vols[i] = min(vol, vols[i])
            #print(vols[i])
            rMax = max(rMax, height[i])
        return sum(vols)
