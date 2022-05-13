class Solution {
    func permuteUnique(_ nums: [Int]) -> [[Int]] {
        var res = [[Int]](), path = [Int](), visited = [Bool](repeating: false, count: nums.count)
        dfs(&res, &path, nums.sorted(by: <), &visited)
        return res
    }
    private func dfs(_ res: inout [[Int]], _ path: inout [Int], _ nums: [Int], _ visited: inout [Bool]) {
        guard path.count != nums.count else { res.append(path); return }
        for n in 0..<nums.count {
            if visited[n] || (n > 0 && nums[n] == nums[n-1] && visited[n-1]) { continue }
            path.append(nums[n])
            visited[n] = true
            dfs(&res, &path, nums, &visited)
            visited[n] = false
            path.removeLast()
        }
    }
}