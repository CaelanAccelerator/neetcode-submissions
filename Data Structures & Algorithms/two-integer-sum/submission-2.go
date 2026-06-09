func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i:= 0; i < len(nums); i++{
        v, ok := m[target - nums[i]]
        if ok {
            return []int{v, i}
        }
        m[nums[i]] = i
    }
    return []int{}
}
