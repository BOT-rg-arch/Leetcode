#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    vector<int> firstRow = {1};
    vector<int> secondRow = {1, 1};
    ans.push_back(firstRow);
    if (numRows == 1)
    {
        return ans;
    }
    ans.push_back(secondRow);
    if (numRows == 2)
    {
        return ans;
    }
    vector<int> model = {1, 2, 1};
    ans.push_back(model);
    for (int i = 2; i <numRows-1; i++)
    {
        vector<int> newRow;
        for (int j = 0; j < model.size(); j++)
        {
            if (j == 0)
            {
                newRow.push_back(1);
            }
            else
            {
                newRow.push_back(model[j - 1] + model[j]);
            }
        }
        newRow.push_back(1);
        model = newRow;
        ans.push_back(model);
    }
    return ans;
}
int main()
{
    vector<vector<int>> ans = generate(5);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}