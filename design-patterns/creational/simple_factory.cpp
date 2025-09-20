#include <iostream>

class IProduct {
  int m_price;
  int m_rating;
  int m_product_id;
  std::string m_name;

public:
  IProduct() : m_price(0), m_rating(0), m_product_id(0), m_name() {}

  IProduct(std::string name, int price, int rating, int product_id)
      : m_price(price), m_rating(rating), m_product_id(product_id),
        m_name(name) {}

  void setPrice(int price) { this->m_price = price; }
  void setRating(int rating) { this->m_rating = rating; }
  void setProductID(int product_id) { this->m_product_id = product_id; }
  void setName(std::string const &name) { this->m_name = name; }

  void printProduct() {
    std::cout << "\n";
    std::cout << "Product Name : " << m_name << '\n';
    std::cout << "Price        : " << m_price << '\n';
    std::cout << "Rating       : " << m_rating << '\n';
    std::cout << "ID           : " << m_product_id << '\n';
  }
};

enum struct ProductType { ProductX, ProductY };

class CommonSimpleFactory {
public:
  IProduct createProduct(ProductType product_type) {
    IProduct new_product;

    switch (product_type) {
    case ProductType::ProductX:
      new_product = IProduct("Product Yy", 21, 2, 13247);
      break;
    case ProductType::ProductY:
      new_product = IProduct("Product Xx", 75, 5, 123123);
      break;
    default:
      new_product = IProduct();
    }

    return new_product;
  }
};

class UncommonSimpleFactory {
public:
  IProduct createProductX() { return IProduct("Product X", 55, 3, 878234); }

  IProduct createProductY() { return IProduct("Product Y", 43, 2, 878774); }
};

int main() {
  std::cout << "creation pattern: simple factory\n";

  CommonSimpleFactory common_factory;
  UncommonSimpleFactory uncommon_factory;

  auto product_1_a = uncommon_factory.createProductX();
  auto product_2_a = uncommon_factory.createProductY();

  auto product_1_b = common_factory.createProduct(ProductType::ProductX);
  auto product_2_b = common_factory.createProduct(ProductType::ProductY);

  product_1_a.printProduct();
  product_2_a.printProduct();

  product_1_b.printProduct();
  product_2_b.printProduct();
}