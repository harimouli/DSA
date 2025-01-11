class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        if(len(s) < k):
            return False
        sorted_s = sorted(s)
        odd_count = 0
        i = 0
        while i < len(sorted_s):
            char = sorted_s[i]
            count = 0
            while i < len(sorted_s) and sorted_s[i] == char:
                count += 1
                i += 1
            if(count % 2 == 1):
                odd_count += 1
        return odd_count <= k
