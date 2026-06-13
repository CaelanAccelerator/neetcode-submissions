class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        st = []
        pair = [(p,s) for p, s in zip(position, speed)]
        pair.sort(reverse=True)


        for p,s in pair:
            st.append((target - p) /  s)
            if len(st) > 1 and st[-1] <= st[-2]:
                st.pop()

        return len(st)