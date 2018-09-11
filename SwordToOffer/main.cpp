//
//  main.cpp
//  algorithm
//
//  Created by NewPan on 2018/9/11.
//  Copyright © 2018 NewPan. All rights reserved.
//

#include <iostream>
#import "Solution.h"


int main(int argc, const char * argv[]) {
    
    int a1[] = { 1, 2, 8,   9, };
    int a2[] = { 2, 4, 9,  12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));
    
    Solution solu;
    cout << solu.findFromRightTop(array, 7) <<endl;
    
    return 0;
}
