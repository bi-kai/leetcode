// 暴力方法，全部循环遍历
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

/* 一次性遍历 */

