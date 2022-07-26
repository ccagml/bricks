/*
 * @lc app=leetcode.cn id=2076 lang=cpp
 *
 * [2076] 处理含限制条件的好友请求
 *
 * https://leetcode.cn/problems/process-restricted-friend-requests/description/
 *
 * algorithms
 * Hard (50.34%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 6.4K
 * Testcase Example:  '3\n[[0,1]]\n[[0,2],[2,1]]'
 *
 * 给你一个整数 n ，表示网络上的用户数目。每个用户按从 0 到 n - 1 进行编号。
 *
 * 给你一个下标从 0 开始的二维整数数组 restrictions ，其中 restrictions[i] = [xi, yi] 意味着用户 xi 和用户
 * yi 不能 成为 朋友 ，不管是 直接 还是通过其他用户 间接 。
 *
 * 最初，用户里没有人是其他用户的朋友。给你一个下标从 0 开始的二维整数数组 requests 表示好友请求的列表，其中 requests[j] =
 * [uj, vj] 是用户 uj 和用户 vj 之间的一条好友请求。
 *
 * 如果 uj 和 vj 可以成为 朋友 ，那么好友请求将会 成功 。每个好友请求都会按列表中给出的顺序进行处理（即，requests[j] 会在
 * requests[j + 1] 前）。一旦请求成功，那么对所有未来的好友请求而言， uj 和 vj 将会 成为直接朋友 。
 *
 * 返回一个 布尔数组 result ，其中元素遵循此规则：如果第 j 个好友请求 成功 ，那么 result[j] 就是 true ；否则，为 false
 * 。
 *
 * 注意：如果 uj 和 vj 已经是直接朋友，那么他们之间的请求将仍然 成功 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
 * 输出：[true,false]
 * 解释：
 * 请求 0 ：用户 0 和 用户 2 可以成为朋友，所以他们成为直接朋友。
 * 请求 1 ：用户 2 和 用户 1 不能成为朋友，因为这会使 用户 0 和 用户 1 成为间接朋友 (1--2--0) 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, restrictions = [[0,1]], requests = [[1,2],[0,2]]
 * 输出：[true,false]
 * 解释：
 * 请求 0 ：用户 1 和 用户 2 可以成为朋友，所以他们成为直接朋友。
 * 请求 1 ：用户 0 和 用户 2 不能成为朋友，因为这会使 用户 0 和 用户 1 成为间接朋友 (0--2--1) 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 5, restrictions = [[0,1],[1,2],[2,3]], requests =
 * [[0,4],[1,2],[3,1],[3,4]]
 * 输出：[true,false,true,false]
 * 解释：
 * 请求 0 ：用户 0 和 用户 4 可以成为朋友，所以他们成为直接朋友。
 * 请求 1 ：用户 1 和 用户 2 不能成为朋友，因为他们之间存在限制。
 * 请求 2 ：用户 3 和 用户 1 可以成为朋友，所以他们成为直接朋友。
 * 请求 3 ：用户 3 和 用户 4 不能成为朋友，因为这会使 用户 0 和 用户 1 成为间接朋友 (0--4--3--1) 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 1000
 * 0 <= restrictions.length <= 1000
 * restrictions[i].length == 2
 * 0 <= xi, yi <= n - 1
 * xi != yi
 * 1 <= requests.length <= 1000
 * requests[j].length == 2
 * 0 <= uj, vj <= n - 1
 * uj != vj
 *
 *
 */

// @lc code=start
// 1.一开始想并查集
// 2.并查集的思路是对的
// 3.结果想 先处理restrictions 把 对应值+n 加到对方身上------这步不对
// 4.应该是直接处理requests的时候 检查每个restriction
// 5.然后并查集的模板写错了, 应该是 v_father[fa] = fb; v_father[fb] = fa; 这一步调了很久才看出来
class unionFind
{
public:
    vector<int> v_father;
    unionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            v_father.push_back(i);
        }
    }
    int get(int i)
    {
        if (v_father[i] == i)
        {
            return i;
        }
        v_father[i] = get(v_father[i]);
        return v_father[i];
    }
    void set(int a, int b)
    {
        int fa = get(a);
        int fb = get(b);
        if (fa > fb)
        {
            v_father[fa] = fb;
        }
        else if (fb > fa)
        {
            v_father[fb] = fa;
        }
    }
};
class Solution
{
public:
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        unionFind *uf = new unionFind(2 * n);
        // for (int i = 0; i < restrictions.size(); i++)
        // {
        //     int a = restrictions[i][0];
        //     int b = restrictions[i][1];
        //     uf->set(a, b + n);
        //     uf->set(b, a + n);
        // }
        int rn = requests.size();
        vector<bool> result(rn);
        for (int i = 0; i < requests.size(); i++)
        {
            int fa = uf->get(requests[i][0]);
            int fb = uf->get(requests[i][1]);
            int can = true;
            for (int ii = 0; ii < restrictions.size(); ii++)
            {

                int fra = uf->get(restrictions[ii][0]);
                int frb = uf->get(restrictions[ii][1]);
                if ((fa == fra && fb == frb) || (fa == frb && fb == fra))
                {
                    can = false;
                    break;
                }
            }
            if (!can)
            {
                result[i] = false;
            }
            else
            {
                uf->set(requests[i][0], requests[i][1]);
                result[i] = true;
            }
        }
        return result;
    }
};
// @lc code=end
