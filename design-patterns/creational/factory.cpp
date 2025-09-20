// this is the original factory pattern by the GoF

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class IProduct {
public:
  virtual ~IProduct() = default;
  virtual void printProduct() const = 0;
};

class Product : public IProduct {
  int m_price;
  int m_rating;
  int m_product_id;
  std::string m_name;

public:
  Product(std::string name, int price, int rating, int product_id)
      : m_price(price), m_rating(rating), m_product_id(product_id),
        m_name(std::move(name)) {}

  void printProduct() const override {
    std::cout << "\n";
    std::cout << "Product Name : " << m_name << '\n';
    std::cout << "Price        : " << m_price << '\n';
    std::cout << "Rating       : " << m_rating << '\n';
    std::cout << "ID           : " << m_product_id << '\n';
  }
};

class IFactory {
public:
  virtual ~IFactory() = default;
  virtual std::unique_ptr<IProduct> createProduct() const = 0;
};

class ProductXFactory : public IFactory {
public:
  std::unique_ptr<IProduct> createProduct() const override {
    return std::make_unique<Product>("Product X", 55, 3, 878234);
  }
};

class ProductYFactory : public IFactory {
public:
  std::unique_ptr<IProduct> createProduct() const override {
    return std::make_unique<Product>("Product Y", 43, 2, 878774);
  }
};

int main() {
  // Client code that depends only on ProductFactory/Product interfaces

  std::cout << "GoF Factory Pattern example\n";

  // The client can hold factories via base type and create
  // products without knowing concrete product classes.

  std::vector<std::unique_ptr<IFactory>> factories;

  factories.push_back(std::make_unique<ProductXFactory>());
  factories.push_back(std::make_unique<ProductYFactory>());

  for (const auto &factory : factories) {
    auto product = factory->createProduct(); // returns unique_ptr<Product>
    product->printProduct();
  }

  // Alternatively, you can choose a factory dynamically (runtime)

  bool needX = true;

  std::unique_ptr<IFactory> chosenFactory;

  if (needX) {
    chosenFactory = std::make_unique<ProductXFactory>();
  } else {
    chosenFactory = std::make_unique<ProductYFactory>();
  }

  auto prod = chosenFactory->createProduct();
  prod->printProduct();

  return 0;
}
