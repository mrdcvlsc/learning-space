#include <algorithm>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ================= strategy abstract or interface =================

// in C++, there is no special keyword to define an interface like in
// other languages, in C++ if an "abstract class" only has
// "pure virtual functions" then it is an interface.

class FilterStrategy {
public:
  virtual ~FilterStrategy() = default; // virtual dtor
  virtual bool filter_condition(std::int16_t) const = 0;
};

// =========================== strategies ===========================

class FilterNegativeSamples : public FilterStrategy {
public:
  FilterNegativeSamples() = default;
  bool filter_condition(std::int16_t value) const override { return value < 0; }
};

class FilterEvenSamples : public FilterStrategy {
public:
  FilterEvenSamples() = default;
  bool filter_condition(std::int16_t value) const override {
    return value % 2 == 0;
  }
};

// ==================== class that use strategies ====================

class Samples : public std::vector<std::int16_t> {
public:
  Samples() : std::vector<std::int16_t>() {}
  Samples(std::vector<std::int16_t> const &samples)
      : std::vector<std::int16_t>(samples) {}

  Samples(std::initializer_list<std::int16_t> const &samples)
      : std::vector<std::int16_t>(samples) {}

  void printSamples() const {
    for (auto &sample : *this) {
      std::cout << sample << ' ';
    }

    std::cout << '\n';
  }

  void applyFilter(const FilterStrategy &filter_strategy) {
    std::vector<std::int16_t> new_samples;

    for (const auto &sample : *this) {
      if (!filter_strategy.filter_condition(sample)) {
        new_samples.push_back(sample);
      }
    }

    *this = new_samples;
  }
};

// ==================== main program ====================

int main() {
  Samples samples = {-3, 23, -21, 32, 55, 777, -69, 23, 11, -65};

  samples.printSamples();

  samples.applyFilter(FilterNegativeSamples());
  samples.printSamples();

  samples.applyFilter(FilterEvenSamples());
  samples.printSamples();
}

/* output:

-3 23 -21 32 55 777 -69 23 11 -65
23 32 55 777 23 11
23 55 777 23 11


*/