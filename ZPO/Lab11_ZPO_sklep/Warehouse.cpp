//
// Created by lukas on 08.01.2024.
//

#include "Warehouse.h"

Warehouse::Warehouse(const std::string& productName, int quantity)
        : productName(productName), quantity(quantity) {
    std::cout << "Konstruktor magazynu: " << productName << std::endl;
}

Warehouse::~Warehouse() {
    std::cout << "Destruktor magazynu: " << productName << std::endl;
}

const std::string& Warehouse::getProductName() const {
    return productName;
}

int Warehouse::getQuantity() const {
    return quantity;
}

void Warehouse::setProductName(const std::string& name) {
    productName = name;
}

void Warehouse::setQuantity(int qty) {
    quantity = qty;
}

void Warehouse::displayInfo() const {
    std::cout << "Magazyn: " << productName << ", Ilosc: " << quantity << std::endl;
}
