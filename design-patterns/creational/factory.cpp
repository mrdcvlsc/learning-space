#include <iostream>

class Product {
  int price;
  int rating;
  int product_id;
  std::string name;

public:
  Product() : price(0), rating(0), product_id(0), name() {}

  Product(std::string name, int price, int rating, int product_id)
      : price(price), rating(rating), product_id(product_id), name(name) {}

  void setPrice(int price) { this->price = price; }
  void setRating(int rating) { this->rating = rating; }
  void setProductID(int product_id) { this->product_id = product_id; }
  void setName(std::string const &name) { this->name = name; }

  void printProduct() {
    std::cout << "\n";
    std::cout << "Product Name : " << name << '\n';
    std::cout << "Price        : " << price << '\n';
    std::cout << "Rating       : " << rating << '\n';
    std::cout << "ID           : " << product_id << '\n';
  }
};

class Factory {
public:
  Product createProductX() { return Product("Product X", 55, 3, 878234); }

  Product createProductY() { return Product("Product Y", 43, 2, 878774); }
};

int main() {
  std::cout << "creation pattern: factory\n";

  Factory main_factory;

  auto product_1 = main_factory.createProductX();
  auto product_2 = main_factory.createProductY();

  product_1.printProduct();
  product_2.printProduct();
}