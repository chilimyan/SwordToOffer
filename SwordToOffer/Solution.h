//
// Created by NewPan on 2018/9/11.
// Copyright (c) 2018 ___FULLUSERNAME___. All rights reserved.
//

#ifndef ALGORITHM_ARRAY_H
#define ALGORITHM_ARRAY_H

#import <iostream>
#import <vector>

using namespace std;

class Solution {

public:
    bool findFromRightTop(vector<vector<int>> arr, int target) {
        cout<<"从右上角开始找."<<endl;
        int row = arr.size();
        int col = arr[0].size();
        if(row == 0 && col == 0) {
            return false;
        }

        for (int i = 0, j = col - 1; (i < row && i >= 0) && (j >= 0 && j < col);) {
            if(arr[i][j] == target) {
                return true;
            }
            else if(arr[i][j] > target) {
                cout<<"当前元素: "<<arr[i][j]<<", 找比当前元素小的, 只可能出现在前面 ←"<<endl;
                j--;
            }
            else {
                cout<<"当前元素: "<<arr[i][j]<<", 找比当前元素大的, 只可能出现在下面 ↓"<<endl;
                i++;
            }
        }
        return false;
    }

    bool findFromLeftBottom(vector<vector<int>> arr, int target) {
        cout<<"从左下角开始找."<<endl;
        int row = arr.size();
        int col = arr[0].size();
        if(row == 0 && col == 0) {
            return false;
        }
        for (int i = row - 1, j = 0; (i >= 0 && i < row) && (j >= 0 && j < col);) {
            if(arr[i][j] == target) {
                return true;
            }
            else if(arr[i][j] > target) {
                cout<<"当前元素: "<<arr[i][j]<<", 找比当前元素小的, 只可能出现在上面 ↑."<<endl;
                i--;
            }
            else {
                cout<<"当前元素: "<<arr[i][j]<<", 找比当前元素大的, 只可能出现在右面 →."<<endl;
                j++;
            }
        }
        return false;
    }
};

#endif //ALGORITHM_ARRAY_H
