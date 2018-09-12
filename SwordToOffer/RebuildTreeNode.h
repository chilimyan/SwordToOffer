//
// Created by NewPan on 2018/9/12.
// Copyright (c) 2018 NewPan. All rights reserved.
//

#ifndef SWORDTOOFFER_REBUILDTREENODE_H
#define SWORDTOOFFER_REBUILDTREENODE_H

#import <iostream>
#import <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
      this->val = val;
      left = NULL;
      right = NULL;
    }

    static void preOrder(TreeNode *node) {
        if(node == NULL) {
            return;
        }
        cout<<node->val<<endl;
        preOrder(node->left);
        preOrder(node->right);
    }

    static void inOrder(TreeNode *node) {
        if(node == NULL) {
            return;
        }
        cout<<node->val<<endl;
        inOrder(node->left);
        inOrder(node->right);
    }
};

class RebuildTreeNode {

public:
    struct TreeNode *rebuildBinaryTree(vector<int> pre, vector<int> in) {
        assert(pre.size() == in.size());
        assert(pre.size() != 0);
        int length = pre.size();
        int rootValue = pre[0];
        TreeNode *root = new TreeNode(rootValue);
        /// 在中序遍历中查找到根的位置
        int rootIndexOnInOrder = 0;
        for (int i = 0; i < in.size(); ++i) {
            if(in[i] == rootValue) {
                rootIndexOnInOrder = i;
                break;
            }
        }

        /// 区分左子树和右子树
        /// 中序遍历中, 根左边的就是左子数, 右边的就是右子树
        /// 前序遍历中, 根后面是先遍历左子树, 然后是右子树
        /// 首先确定左右子树的长度, 从中序遍历in中确定
        int leftLength = rootIndexOnInOrder;
        int rightLength = length - rootIndexOnInOrder - 1;
        vector<int> preLeft(leftLength), vector<int> inLeft(leftLength);
        vector<int> preLeft(rightLength), vector<int> inRight(rightLength);

    }
};


#endif //SWORDTOOFFER_REBUILDTREENODE_H
