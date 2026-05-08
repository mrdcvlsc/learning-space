#include <array>
#include <chrono>
#include <iostream>
#include <utility>

using namespace std;

using i64 = int64_t;

template <typename T, size_t N> struct Grid {
  array<array<T, N>, N> grid{};
  size_t cnt = 0;

  Grid<T, N>() { grid[0][0] = 1; }

  void search(i64 x, i64 y) {
    if (x == N - 1 && y == N - 1) {
      if (grid[x][y] == N * N) {
        cnt++;
      }
      return;
    }

    array<pair<i64, i64>, 4> moves{
        make_pair(-1, 0), // x up
        make_pair(1, 0),  // x down
        make_pair(0, -1), // y left
        make_pair(0, 1),  // y right
    };

    for (const auto &[dx, dy] : moves) {
      i64 nx = x + dx;
      i64 ny = y + dy;

      if (nx >= N || nx < 0 || ny >= N || ny < 0) {
        continue;
      }

      if (grid[nx][ny] >= 1) {
        continue;
      }

      grid[nx][ny] = grid[x][y] + 1;
      search(nx, ny);
      grid[nx][ny] = 0;
    }
  }
};

int main() {
  constexpr size_t n = 7;
  Grid<size_t, n> grid;

  auto start = chrono::steady_clock::now();
  grid.grid[0][1] = 2;
  grid.search(0, 1);
  grid.cnt *= 2;
  auto end = chrono::steady_clock::now();

  auto dur1 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  auto dur2 = chrono::duration_cast<chrono::milliseconds>(end - start).count();
  auto dur3 = chrono::duration_cast<chrono::seconds>(end - start).count();
  auto dur4 = chrono::duration_cast<chrono::minutes>(end - start).count();

  cout << "answer : " << grid.cnt << '\n';
  cout << "took : " << dur4 << "m, " << dur3 << "s, " << dur2 << "ms, " << dur1 << "ns\n";

  return 0;
}

/*
answer : 111712
took : 0m, 37s, 37485ms, 37485578300ns
*/
