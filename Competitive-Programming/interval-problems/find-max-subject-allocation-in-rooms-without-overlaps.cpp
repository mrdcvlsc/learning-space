/*
  Problem:
  ----------
  We are given n activities (each with a start and end time) and k classrooms.
  Each classroom can only host one activity at a time, and two activities cannot
  even touch (i.e., if one ends at time t and another starts at time t, they
  cannot be scheduled in the same room).

  Main Idea:
  ----------
  Similar to the single-line interval scheduling problem, we first sort all
  intervals by their end time (earliest finishing first).
  Then, for each interval, we try to assign it to the classroom whose current
  last end time is the greatest one that is still strictly less than the
  interval’s start time. This way we reuse classrooms as much as possible
  while maximizing the total number of scheduled tasks.
  in short : when reusing a room, pick the one that freed most recently
  but still before the task starts (largest end < start).

  Goal:
  ----------
  Find the maximum number of activities that can be scheduled across the k
  classrooms.

  Approach (Greedy with multiset):
  ----------
  1. Sort all activities by their end time (earliest finishing first).
  2. Maintain a multiset of end times for currently occupied classrooms.
     - Each element represents when a classroom becomes free.
  3. For each activity in sorted order:
     - Try to reuse a classroom whose last activity ends strictly before the
  start.
     - If none is available, open a new classroom if we still have fewer than k.
     - Otherwise, skip the activity.
  4. Count how many activities are successfully assigned.

  Complexity:
  ----------
  Sorting: O(n log n)
  Each assignment: O(log k) (multiset operations)
  Total: O(n log n)
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  if (!(std::cin >> n >> k)) {
    return 0;
  }

  std::vector<std::pair<ll, ll>> tasks;
  tasks.reserve(n);

  for (int i = 0; i < n; ++i) {
    ll start_time, end_time;
    std::cin >> start_time >> end_time;
    tasks.emplace_back(start_time, end_time);
  }

  // sort by end time (earliest finishing first)
  std::sort(tasks.begin(), tasks.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });

  std::multiset<ll> ends; // current classroom end times (sorted)
  int assigned = 0;

  for (const auto &t : tasks) {
    ll s = t.first;
    ll e = t.second;

    // find a classroom whose previous end time is strictly < s
    auto it = ends.lower_bound(s);

    if (it != ends.begin()) {
      --it;           // classroom found
      ends.erase(it); // reuse it
      ends.insert(e);
      ++assigned;
    } else if ((int)ends.size() < k) {
      // use an unused classroom
      ends.insert(e);
      ++assigned;
    }

    // otherwise: cannot schedule this task
  }

  std::cout << assigned << '\n';
  return 0;
}

// NOTE: std::multiset, and std::set iterate elements in ascending order
//  despite their structure could be red-black trees.