#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ExamTracker {
private:
    vector<int> times;
    vector<long long> prefixSum;

public:
    ExamTracker() = default;

    void record(int time, int score) {
        times.push_back(time);
        long long newSum = (prefixSum.empty() ? 0 : prefixSum.back()) + score;
        prefixSum.push_back(newSum);
    }

    long long totalScore(int startTime, int endTime) {
        auto l = lower_bound(times.begin(), times.end(), startTime);
        auto r = upper_bound(times.begin(), times.end(), endTime);

        if (l == times.end() || l >= r)
            return 0;

        int li = static_cast<int>(l - times.begin());
        int ri = static_cast<int>(r - times.begin() - 1);

        return prefixSum[ri] - (li == 0 ? 0 : prefixSum[li - 1]);
    }
};

int main() {
    ExamTracker examTracker;
    examTracker.record(1, 98);
    cout << examTracker.totalScore(1, 1) << endl; // 98
    examTracker.record(5, 99);
    cout << examTracker.totalScore(1, 3) << endl; // 98
    cout << examTracker.totalScore(1, 5) << endl; // 197
    cout << examTracker.totalScore(3, 4) << endl; // 0
    cout << examTracker.totalScore(2, 5) << endl; // 99
}
