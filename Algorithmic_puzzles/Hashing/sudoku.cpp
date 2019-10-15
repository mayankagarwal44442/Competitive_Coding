int Solution::isValidSudoku(const vector<string> &A) {
    
    //try all rows
    
    
    for(int i = 0; i < A.size(); ++i)
    {
        vector<bool> arr(10, false);
        for(int j = 0; j < A[i].size(); ++j)
        {
            if(A[i][j] == '.') continue;
            if(arr[A[i][j] - '0']) return 0;
            arr[A[i][j] - '0'] = true;
        }
    }
    
    //try all columns
    for(int j = 0; j < A[0].size(); ++j)
    {
        vector<bool> arr(10, false);
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i][j] == '.') continue;
            if(arr[A[i][j] - '0']) return 0;
            arr[A[i][j] - '0'] = true;
        }
    }
    
    //try all 3*3 grids
    
    vector<pair<int,int>> init_coordinates = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    
    for(int i = 0; i < (A.size()/3); ++i)
    {
        for(int j = 0; j < (A[0].size()/3); ++j)
        {
            vector<bool> arr(10, false);
            for(pair<int,int> ele: init_coordinates)
            {
                if(A[ele.first+(i*3)][ele.second + (j*3)] == '.') continue;
                if(arr[A[ele.first+(i*3)][ele.second + (j*3)] - '0']) return 0;
                arr[A[ele.first+(i*3)][ele.second + (j*3)] - '0'] = true;
            }
        }
    }
    
    return 1;
    
}
