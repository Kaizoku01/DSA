class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        # Sort the given array
        nums.sort()
        # Length of the array
        n = len(nums)
        # Closest value
        closest = nums[0] + nums[1] + nums[n - 1]
        # Loop for each element of the array
        for i in range(0, n - 2):
            # Left and right pointers
            j = i + 1
            k = n - 1
            # Loop for all other pairs
            while j < k:
                current_sum = nums[i] + nums[j] + nums[k]
                if current_sum <= target:
                    j += 1
                else:
                    k -= 1
                if abs(closest - target) > abs(current_sum - target):
                    closest = current_sum
        return closest