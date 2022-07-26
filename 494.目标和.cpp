/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=20602
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (49.09%)
 * Likes:    1448
 * Dislikes: 0
 * Total Accepted:    297.2K
 * Total Submissions: 605.5K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 target 。
 *
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 *
 *
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 *
 *
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1], target = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start

// 前i个凑成j 的数量 x
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        target = abs(target);
        int sum = 0;
        for (int j : nums)
        {
            sum += j;
        }
        if (target > sum)
        {
            return 0;
        }

        // 正 + 负 = sum
        // 正 - 负 = target
        // 2正 = sum + target
        if ((sum + target) % 2 == 1)
        {
            return 0;
        }
        int need = (sum + target) / 2;
        vector<int> vi(need + 1);
        vi[0] = 1;
        for (int j : nums)
        {
            for (int amount = need; amount >= j; amount--)
            {
                vi[amount] += (vi[amount - j]);
            }
        }
        return vi[need];
    }
};
// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         target = abs(target);
//         int sum = 0;
//         for (int num : nums)
//         {
//             sum += num;
//         }
//         // 正 + 负 = sum
//         // 正 - 负 = target
//         // 正 = (sum + target)/2
//         if (sum < target || (sum + target) % 2 == 1)
//         {
//             return 0;
//         }
//         int need = (sum + target) / 2;
//         vector<int> vb(need + 1);
//         vb[0] = 1;
//         for (int num : nums)
//         {
//             for (int j = need; j >= num; j--)
//             {
//                 vb[j] += vb[j - num];
//             }
//         }
//         return vb[need];
//     }
// };
// @lc code=end

/*
// @lcpr case=start
// [7,9,3,8,0,2,4,8,3,9]\n0
// @lcpr case=end


// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
