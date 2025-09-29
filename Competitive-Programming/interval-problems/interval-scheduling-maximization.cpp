// Activity Selection Problem

// problem: given multiple intervals in a number line, get the max
// number of intervals you can place to the number line without overlap
// 
// simple greedy solution:
// sort the intervals by end time (and by start time to break ties).
// then, repeatedly check then allocate the next interval that starts
// after the last chosen one. this is the classic "activity selection"
// algorithm, used to maximize the number of non-overlapping tasks
// that can fit into a schedule.

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  if (!(std::cin >> n)) {
    return 0;
  }

  std::vector<std::pair<i64, i64>> intervals;
  intervals.reserve(n);

  for (int i = 0; i < n; ++i) {
    i64 s, e;
    std::cin >> s >> e;
    intervals.emplace_back(s, e);
  }

  // sort by end time (primary) then by start time (secondary)
  std::sort(intervals.begin(), intervals.end(),
            [](const auto &a, const auto &b) {
              if (a.second != b.second) {
                return a.second < b.second;
              }
              return a.first < b.first;
            });

  i64 last_end = LLONG_MIN; // end of last chosen interval
  int chosen = 0;

  for (auto [s, e] : intervals) {
    // strict no-touching rule: next start must be > last_end
    if (s > last_end) {
      ++chosen;
      last_end = e;
    }
    // if touching were allowed, use (s >= last_end) instead
  }

  std::cout << chosen << '\n';
  return 0;
}
