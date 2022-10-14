def maximum(nums):
    def bigger(a, b):
        if a < b:
            return a
        return b
    
    if len(nums) == 1:
        return nums[0]
    
    nums.remove(bigger(nums[0], nums[1]))
 
    return maximum(nums)
