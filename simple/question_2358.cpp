/*
 * @lc app=leetcode.cn id=2358 lang=cpp
 *
 * [2358] 分组的最大数量
 *
 * https://leetcode.cn/problems/maximum-number-of-groups-entering-a-competition/description/
 *
 * algorithms
 * Medium (63.42%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 13.4K
 * Testcase Example:  '[10,6,12,7,3,5]'
 *
 * 给你一个正整数数组 grades ，表示大学中一些学生的成绩。你打算将 所有 学生分为一些 有序
 * 的非空分组，其中分组间的顺序满足以下全部条件：
 *
 *
 * 第 i 个分组中的学生总成绩 小于 第 (i + 1) 个分组中的学生总成绩，对所有组均成立（除了最后一组）。
 * 第 i 个分组中的学生总数 小于 第 (i + 1) 个分组中的学生总数，对所有组均成立（除了最后一组）。
 *
 *
 * 返回可以形成的 最大 组数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：grades = [10,6,12,7,3,5]
 * 输出：3
 * 解释：下面是形成 3 个分组的一种可行方法：
 * - 第 1 个分组的学生成绩为 grades = [12] ，总成绩：12 ，学生数：1
 * - 第 2 个分组的学生成绩为 grades = [6,7] ，总成绩：6 + 7 = 13 ，学生数：2
 * - 第 3 个分组的学生成绩为 grades = [10,3,5] ，总成绩：10 + 3 + 5 = 18 ，学生数：3
 * 可以证明无法形成超过 3 个分组。
 *
 *
 * 示例 2：
 *
 * 输入：grades = [8,8]
 * 输出：1
 * 解释：只能形成 1 个分组，因为如果要形成 2 个分组的话，会导致每个分组中的学生数目相等。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grades.length <= 10^5
 * 1 <= grades[i] <= 10^5
 *
 *
 */

// @lc code=start
	
// 1502分
class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int result = 0;
        int cur_need = 1;
        int s = grades.size();
        for (int i = 0; i < s; 0)
        {
            if ((s - i) >= cur_need)
            {
                result++;
                i += cur_need;
                cur_need++;
            }else
            {
                break;
            }
            
        }
        return result;
    }
};
// @lc code=end
