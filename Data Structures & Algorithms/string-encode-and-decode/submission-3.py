class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            length = len(s)
            res+=str(length)+","
        res+=":"
        for s in strs:
            res+=s
        print(res)
        return res

    def decode(self, s: str) -> List[str]:
        digit_len = 1
        str_lens = [];
        str_len = 0;
        for i in range(len(s)):
            if s[i] == ':':
                return self.restore(i+1, s, str_lens)
            if s[i] == ',':
                digit_len = 1;
                str_lens.append(str_len)
                str_len = 0
            else:
                str_len = str_len * 10 + int(s[i])
        return [""]

    def restore(self, index_str: int, s: str, str_lens: List[int]) -> List[str]:
        i_str_lens = 0
        ans = []
        i = index_str
        
        while i_str_lens  < len(str_lens):
            elem = ""
            l = str_lens[i_str_lens]
            i_str_lens+=1
            for k in range(l):
                if i >= len(s):
                    ans.append(elem)
                elem += s[i]
                i+=1
            ans.append(elem)
        return ans
            