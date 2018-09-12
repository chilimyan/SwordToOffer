//
// Created by NewPan on 2018/9/12.
// Copyright (c) 2018 NewPan. All rights reserved.
//

#ifndef SWORDTOOFFER_REPLACESPACE_H
#define SWORDTOOFFER_REPLACESPACE_H

#import <iostream>

class ReplaceSpace {

public:
    /**
     最原始的方法，我们遍历一遍字符串，对字符中每一个空格，都用%20来替换，
     由于用%20替换空格会导致字符串长度的增加，因此需要注意
     从后往前遍历字符串
     每找到一个空格，需要将`' '`后面的字符串依次后移两位，预留出%20的空间
     |a| |b|c|
     |a| | | |b|c|
     |a|%|2|0|b|c|
     */
    void originReplaceSpace(char *str, int length) {
        int len = length;
        for (int i = length - 1; i >= 0; --i) {
            if(str[i] == ' ') {
                len += 2;
                int j = len - 1;
                for (j; j > i + 2; --j) {
                    str[j] = str[j - 2];
                }
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '\%';
                cout<<str<<endl;
            }
        }
        str[len] = '\0';
        cout<<str<<endl;
    }

    /**
     上面那个方法太暴力了，有没有什么更好的方法呢？
     我们的代码，主要消耗的时间在于，如果有多个空格， 那么每遇到一个空格就进行移位
     其实前面的移位是没必要的，因为如果再遇到空格，那么之前的移位全是无用功
     因此我们可以考虑**先遍历一遍字符串, 计数空格的数目**,
     我们知道了空格的数目，其实就是知道了替换后字符串的长度，那么只需要进行一次替换就可以了

     因为我们的工作变为:
      * 遍历一遍字符串， 统计字符出现的数目, 计算替换后的字符串长度
      * 再遍历一遍字符串，完成替换
     */
    void optimizeReplaceSpace(char *str, int length) {
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if(str[i] == ' ') {
                count++;
            }
        }
        if(count == 0) return;
        int len = length + 2 * count;
        for (int i = length - 1, j = len - 1; i >= 0, j >= 0;) {
            /**
        	 |a| |b|c|
     		 |a| | | |b|c|
     		 |a|%|2|0|b|c|
        	*/
            if(str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '\%';
                i--;
            }
            else {
                str[j--] = str[i--];
            }
            str[len] = '\0';
        }
        cout<<str<<endl;
    }
};

void replaceSpaceTest() {
    ReplaceSpace solu;
    char str[100] = "we are happy";
//    solu.originReplaceSpace(str, 12);
    solu.optimizeReplaceSpace(str, 12);
}


#endif //SWORDTOOFFER_REPLACESPACE_H
