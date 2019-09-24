/* 【超时】暴力方法，全部循环遍历 */
//
// Created by b00278683 on 2019/9/24.
//

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if("" == s) return "";

        int maxLen = 1;
        stringstream stream;
        stream << s.at(0);
        string result = stream.str();

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); ++j) {
                string subStr = s.substr(i, j - i + 1);
                bool isPalindrome = judgePalindrome(subStr);
                if (isPalindrome && (j - i) >= maxLen) {
                    maxLen = j - i;
                    result = subStr;
                }
            }
        }
        return result;
    }

    bool judgePalindrome(string t) {
        bool isPalindrome = true;
        int halfLen = ceil((double) t.length() / 2);
        bool isEvenLen = halfLen != t.length() / 2 ? false : true; // 是否为偶数
        int loopLen = isEvenLen ? halfLen : (halfLen - 1);

        for (int i = 0; i < loopLen; ++i) {
            char near = t.at(i),
                    far = t.at(t.length() - i - 1);
            if (near != far) {
                isPalindrome = false;
                break;
            }
        }
        if (!loopLen) isPalindrome = false;
        return isPalindrome;
    }
};
// 遇到第45个用例超时："azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc"

/* 【】一次性遍历 */
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if ("" == s || s.length() == 1) return s;

        string longestStr = "";
        int maxLen = 1;

        for (int i = 0; i < s.length(); ++i) {
            int loopFlag = 1;
            int count = 1;

            while (loopFlag) {
                int beforePos = i - loopFlag < 0 ? -1 : (i - loopFlag);
                int afterPos = i + loopFlag >= s.length() ? -1 : (i + loopFlag);

                if (beforePos == -1 || afterPos == -1 ||
                    (s.at(beforePos) != s.at(afterPos) && s.at(afterPos) != s.at(i) &&
                     s.at(afterPos) != s.at(beforePos))) {
                    loopFlag = -1;
                    break;
                }

                if (s.at(beforePos) == s.at(afterPos)) {
                    loopFlag++;
                    count += 2;
                    if (count >= maxLen) {
                        maxLen = count;
                        longestStr = s.substr(beforePos, afterPos - beforePos + 1);
                    }
                } else if (s.at(beforePos) == s.at(i)) {
                    if (2 >= maxLen) {
                        maxLen = 2;
                        longestStr = s.substr(beforePos, 2);
                    }
                    loopFlag = -1;
                    break;
                } else if (s.at(afterPos) == s.at(i)) {
                    if (2 >= maxLen) {
                        maxLen = 2;
                        longestStr = s.substr(i, 2);
                    }
                    loopFlag = -1;
                    break;
                }
            }
        }
        return longestStr;
    }
};
