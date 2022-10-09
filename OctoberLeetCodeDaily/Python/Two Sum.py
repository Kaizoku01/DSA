class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {}
        
        for i in range(len(nums)): 
            dif = target - nums[i] 
            
            if dif in hashMap:
                return [hashMap[dif], i]
            else:
                hashMap[nums[i]] = i
        return []
