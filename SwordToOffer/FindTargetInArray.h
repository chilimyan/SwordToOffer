//
// Created by NewPan on 2018/9/11.
// Copyright (c) 2018 ___FULLUSERNAME___. All rights reserved.
//

#ifndef ALGORITHM_ARRAY_H
#define ALGORITHM_ARRAY_H

#import <iostream>
#import <vector>

using namespace std;

class FindTargetInArray {

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

void findTargetInArrayTest() {
    int a1[] = { 1, 2, 8,   9, };
    int a2[] = { 2, 4, 9,  12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };

    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    FindTargetInArray solu;
    cout << solu.findFromRightTop(array, 7) <<endl;
}

#endif //ALGORITHM_ARRAY_H
