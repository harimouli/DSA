class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        mod = [0] * value

        for val in nums:
            mod[val % value] += 1

        index = mod.index(min(mod))

        return mod[index] * value + index