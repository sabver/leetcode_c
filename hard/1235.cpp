#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Data structure to store a Job
struct Job {
  int start, finish, profit;
  Job(int s, int f, int p) : start(s), finish(f), profit(p) {}
};

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    vector<Job> jobs;
    for (int i = 0; i < startTime.size(); i++) {
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);
    }
    sort(jobs.begin(), jobs.end(),
         [](Job &x, Job &y) { return x.finish < y.finish; });
    int n = jobs.size();
    vector<int> dp(n);
    dp[0] = jobs[0].profit;
    for (int i = 1; i < n; i++) {
      int index = findLastNonConflictingJob(jobs, i);
      int incl = jobs[i].profit;
      if (index != -1) {
        incl += dp[index];
      }
      dp[i] = max(dp[i - 1], incl);
    }
    return dp[n - 1];
  }
  int findLastNonConflictingJob(vector<Job> &jobs, int n) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (jobs[mid].finish <= jobs[n].start) {
        left = mid + 1;
        result = mid;
      } else {
        right = mid - 1;
      }
    }
    return result;
  }
};

int main() { Solution solution; }