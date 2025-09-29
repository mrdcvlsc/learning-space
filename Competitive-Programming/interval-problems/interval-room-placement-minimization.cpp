/*
Interval Partitioning

- Imagine there are 10 lectures, each with a fixed start and end time.
- Each lecture needs a lecture hall.
- there can only be one lecture in one lecture hall at the same time.
- you want to find the minimum number of lecture halls needed for scheduling all
lectures.
*/

#include <algorithm>
#include <iostream>
#include <queue>
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

  // sort by start time (earliest start first)
  std::sort(intervals.begin(), intervals.end(),
            [](const auto &a, const auto &b) {
              if (a.first != b.first) {
                return a.first < b.first;
              }
              return a.second < b.second;
            });

  // min-heap of end times (earliest finishing room at top)
  std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;

  for (const auto &iv : intervals) {
    i64 s = iv.first;
    i64 e = iv.second;

    // strict no-touching: require earliest_end < s to reuse a room
    if (!pq.empty()) {
      if (pq.top() < s) {
        // reuse the room that frees earliest
        pq.pop();
        pq.push(e);
      } else {
        // no room free in time, allocate a new room
        pq.push(e);
      }
    } else {
      // no rooms yet, allocate first room
      pq.push(e);
    }
  }

  // number of rooms needed is the number of end-times tracked
  std::cout << static_cast<int>(pq.size()) << '\n';
  return 0;
}
