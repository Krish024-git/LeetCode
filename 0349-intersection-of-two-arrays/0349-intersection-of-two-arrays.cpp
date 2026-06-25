class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
      unordered_set<int> s(n1.begin(), n1.end()), ans;

        for(int x : n2)
            if(s.count(x))
                ans.insert(x);

        return vector<int>(ans.begin(), ans.end()); 
    }
};