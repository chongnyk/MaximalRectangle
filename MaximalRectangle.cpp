class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int result = 0;
        vector<int> histogram(matrix[0].size());
        for(vector<char> row : matrix){
            for(int i = 0; i < row.size(); i++){
                histogram[i] = (row[i] == '0') ? 0 : histogram[i] + 1;
            }

            result = max(result, largestArea(histogram));
        }
        return result;
    }

    int largestArea(const vector<int>& heights){
        int result = 0;
        stack<int> stack;

        for(int i = 0; i <= heights.size(); i++){
            while(!stack.empty() && (i == heights.size() || heights[stack.top()] > heights[i])){
                int h = heights[stack.top()];
                stack.pop();
                int b = (stack.empty()) ? i : i - stack.top() - 1;
                result = max(result, h * b);
            }
            stack.push(i);
        }

        return result;
    }
};
