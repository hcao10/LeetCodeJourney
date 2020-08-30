/*557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
Haowei Cao
8/30/2020
*/

//思路：这道题可能使用Java比较好搞定：return Array.from(s).reverse().join('').split(' ').reverse().join(' ')
    //Java：
    // 先将s整个进行翻转
    // 再将翻转后的s按 空格 分割成由翻转后的各个单词组成的数组
    // 对数组进行翻转，调整单词的位置
    // 最后将数组用 空格 连接起来
    
//使用C++ 可以先寻找空格，反转，拼接：
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int length = s.length();
        int i = 0;
        while (i < length) {
            int start = i;
            while (i < length && s[i] != ' ') {
                i++;
            }
            for (int p = start; p < i; p++) {
                ret.push_back(s[start + i - 1 - p]);
            }
            while (i < length && s[i] == ' ') {
                i++;
                ret.push_back(' ');
            }
        }
        return ret;
    }
};

