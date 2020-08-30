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
        if(s.empty() || s.length() == 1) return s;
        int start = 0, end = 0;
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i + 1] == ' ' || s[i + 1] == '\0')
            {
                end = i;
                while(end > start)
                {
                    // 循环交换start和end处的字符
                    swap(s[start], s[end]);
                    end --;
                    start ++;
                }
                // start和end都定位到下一个单词的首位
                start = i + 2;
                end = start;
            }
        }
        return s;
    }
    void swap(char &s, char &e)
    {
        // 注意s和e一定要用call by reference的方式传进来！否则改变不了
        char temp = s;
        s = e;
        e = temp;
    }
};






//官方答案：
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

class Solution {
public:
    string reverseWords(string s) {
        int startPoint = 0;
        string newString;
        int i, j,sLength,cutSize;
        string tempString;
        for( i = 0; i <s.size(); i++){
            if((s.at(i) == ' ' )||( i==s.size()-1)){
                if(i==(s.size()-1)){
                    sLength= i-startPoint;
                    cutSize = i-startPoint+1;
                }
                else{
                    sLength= i-startPoint -1;
                    cutSize = i-startPoint;
                }
                tempString = s.substr(startPoint,cutSize);

                for(j= sLength; j >=0; j--){
                    newString.push_back(tempString.at(j));
                }
                startPoint=i+1;
                tempString.clear();
                if(i!=s.size()-1){
                    newString.push_back(' ');
                }
            }
        }
        return newString;
    }
};