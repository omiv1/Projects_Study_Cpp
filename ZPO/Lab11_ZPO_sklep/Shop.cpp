//
// Created by lukas on 08.01.2024.
//

#include "Shop.h"

Shop::Shop(const std::string& shopName) : shopName(shopName) {
    std::cout << "Konstruktor sklepu: " << shopName << std::endl;
}

Shop::~Shop() {
    std::cout << "Destruktor sklepu: " << shopName << std::endl;
}

void Shop::addWarehouse(const std::shared_ptr<Warehouse>& warehouse) {
    warehouses.push_back(warehouse);
}

void Shop::sellProduct(const std::string& productName, int quantity) {
    for (const auto& warehouse : warehouses) {
        if (warehouse->getProductName() == productName) {
            int availableQuantity = warehouse->getQuantity();
            if (availableQuantity >= quantity) {
                warehouse->setQuantity(availableQuantity - quantity);
                std::cout << "Sprzedano " << quantity << " sztuk " << productName << " ze sklepu " << shopName << std::endl;
            } else {
                std::cout << "Niewystarczajaca ilosc towaru " << warehouse->getProductName() << " w sklepie " << shopName << std::endl;
            }
            return;
        }
    }

    std::cout << "Produkt " << productName << " nie zostal znaleziony w zadnym magazynie sklepu " << shopName << std::endl;
}

void Shop::displayWarehouses() const {
    std::cout << "Magazyny uzywane przez " << shopName << ":" << std::endl;
    for (const auto& warehouse : warehouses) {
        warehouse->displayInfo();
    }
}

void Shop::displayName() const {
    std::cout << "Sklep: " << shopName << std::endl;
}
