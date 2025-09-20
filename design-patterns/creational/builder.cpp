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

class Builder {
  Product product;

public:
  Builder() : product() {}

  Builder addName(std::string const &name) {
    product.setName(name);
    return *this;
  }

  Builder addPrice(int price) {
    product.setPrice(price);
    return *this;
  }

  Builder addRating(int rating) {
    product.setRating(rating);
    return *this;
  }

  Builder addProductID(int id) {
    product.setProductID(id);
    return *this;
  }

  Product build() { return product; }
};

int main() {
  std::cout << "creation pattern: builder\n";

  auto product_1 = Builder()
                       .addProductID(873483)
                       .addName("Product A")
                       .addPrice(233)
                       .addRating(12)
                       .build();

  auto product_2 = Builder()
                       .addName("Product B")
                       .addRating(4)
                       .addPrice(122)
                       .addProductID(343)
                       .build();

  product_1.printProduct();
  product_2.printProduct();
}