//
// Created by NewPan on 2018/9/12.
// Copyright (c) 2018 NewPan. All rights reserved.
//

#ifndef SWORDTOOFFER_PRINTLIST_H
#define SWORDTOOFFER_PRINTLIST_H

#import <iostream>
#import <vector>
#import <stack>

using namespace std;

struct ListNode {

public:
    int val;
    struct ListNode *next;
};

class PrintList {

public:
    /**
      ## 反转链表
      首先我们想到的就是**反转链表**了,如果把链表反转了，然后再返回头，这样再次遍历的时候就相当于从尾到头打印了。

      但是修改输入数据真的可行么？

      剑指Offer中为我们在面试中提出了如下小提示
        > 在面试时候，如果我们打算修改输入的数据，最好先问问面试官是不是允许修改
        > 通常打印只是一个只读操作，我们肯定不希望输入时候修改链表的内容


       ## 利用栈的后进先出特性
       单链表的遍历只能从前往后，但是需要从尾往头输出，这不是典型的"先进后出"么，那么我们可以用栈模拟输出
       每经过一个结点的时候，把该结点放到一个栈中。当遍历完整个链表后，再从栈顶开始逐个输出结点的值，此时输出的结点的顺序已经反转过来了。
     */
    vector<int> printListFromTailToHeadByStack(ListNode *head) {
        int count = 0;
        ListNode *node = head;
        stack<int> st;
        while(node != NULL) {
            st.push(node->val);
            count++;
            node = node->next;
        }

        vector<int> res(count);
        for (int i = 0; i < count; ++i) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }

    /**
      # 递归实现
        递归在本质上就是一个栈结构，于是很自然地想到用递归来实现。要实现反过来输出链表，每访问到一个结点的时候，先递归输出它后面的结点，再输出该结点自身，这样链表的输出结构就反过来了。

      算法流程如下
       只要当前节点不为NULL，也就是链表没到头，就一直递归
       在递归结束时，将元素压入
       这样当递归结束进行返回时，会将递归栈中的数据依次压入vector中，而压入的顺序就是栈中的顺序，即从尾到头
     */
    void __printListFromTailToHead(ListNode *node, vector<int> &res) {
        if(node != NULL) {
            res.push_back(node->val);
            __printListFromTailToHead(node->next, res);
        }
    }

    vector<int> printListFromTailToHeadByRecursion(ListNode *head) {
        vector<int> res;
        __printListFromTailToHead(head, res);
        return res;
    }
};

void printListTest() {
    ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;

    PrintList solution;
//    vector<int> res = solution.printListFromTailToHeadByStack(list);
    vector<int> res = solution.printListFromTailToHeadByRecursion(list);
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
}


#endif //SWORDTOOFFER_PRINTLIST_H
