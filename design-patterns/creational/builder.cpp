#include <iostream>
#include <string>
#include <utility>

class IProduct {
  int m_price{0};
  int m_rating{0};
  int m_product_id{0};
  std::string m_name;

public:
  IProduct() = default;
  IProduct(std::string name, int price, int rating, int product_id)
      : m_price(price), m_rating(rating), m_product_id(product_id),
        m_name(std::move(name)) {}

  void setName(std::string name) { this->m_name = std::move(name); }
  void setPrice(int price) { this->m_price = price; }
  void setRating(int rating) { this->m_rating = rating; }
  void setProductID(int product_id) { this->m_product_id = product_id; }

  void printProduct() const {
    std::cout << "\nProduct Name : " << m_name << '\n'
              << "Price        : " << m_price << '\n'
              << "Rating       : " << m_rating << '\n'
              << "ID           : " << m_product_id << '\n';
  }
};

class Builder {
  IProduct product;

public:
  Builder() = default;

  Builder &addName(std::string name) {
    product.setName(std::move(name));
    return *this;
  }

  Builder &addPrice(int price) {
    product.setPrice(price);
    return *this;
  }

  Builder &addRating(int rating) {
    product.setRating(rating);
    return *this;
  }

  Builder &addProductID(int id) {
    product.setProductID(id);
    return *this;
  }

  IProduct build() { return std::move(product); }
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