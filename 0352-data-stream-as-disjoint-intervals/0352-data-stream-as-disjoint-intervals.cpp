class SummaryRanges {
public:
    map<int, int> intervals;

    SummaryRanges() {
    }

    void addNum(int value) {
        auto it = intervals.upper_bound(value);

        int start = value, end = value;

        // Merge with previous interval
        if (it != intervals.begin()) {
            auto prev = it;
            --prev;

            if (prev->second >= value)
                return; // already covered

            if (prev->second + 1 == value) {
                start = prev->first;
                end = max(end, prev->second);
                intervals.erase(prev);
            }
        }

        // Merge with next interval
        if (it != intervals.end() && it->first - 1 == value) {
            end = it->second;
            intervals.erase(it);
        }

        intervals[start] = end;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (auto &p : intervals) {
            ans.push_back({p.first, p.second});
        }

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */