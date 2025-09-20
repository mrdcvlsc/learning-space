#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Subscriber { // observer
public:
  virtual ~Subscriber() = default;                        // virtual dtor
  virtual void sendNotification(std::string const &) = 0; // pure virtual
};

class User : public Subscriber { // observer implementation
public:
  User() = default;

  void sendNotification(std::string const &notification) override {
    std::cout << notification << '\n';
  }
};

class Publisher { // subject
  std::vector<std::weak_ptr<Subscriber>> subscribers;

public:
  void subscribe(std::shared_ptr<Subscriber> const &subscriber) {
    subscribers.push_back(subscriber);
  }

  void notify(std::string const &message) {
    subscribers.erase(
        std::remove_if(subscribers.begin(), subscribers.end(),
                       [](auto const &wp) { return wp.expired(); }),
        subscribers.end());

    for (auto const &wp : subscribers) {
      if (auto subscriber = wp.lock()) {
        subscriber->sendNotification(message);
      }
    }
  }
};

int main() {
  Publisher twitch;

  auto user_1 = std::make_shared<User>();
  auto user_2 = std::make_shared<User>();
  auto user_3 = std::make_shared<User>();

  twitch.subscribe(user_1);
  twitch.subscribe(user_2);
  twitch.subscribe(user_3);

  twitch.notify("random notification message");
}
