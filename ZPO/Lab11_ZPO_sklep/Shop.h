//
// Created by lukas on 08.01.2024.
//

#ifndef LAB11_ZPO_SKLEP_SHOP_H
#define LAB11_ZPO_SKLEP_SHOP_H


#include <iostream>
#include <vector>
#include <memory>
#include "Warehouse.h"

class Shop {
private:
    std::string shopName;
    std::vector<std::shared_ptr<Warehouse>> warehouses;

public:
    Shop(const std::string& shopName);
    ~Shop();

    void addWarehouse(const std::shared_ptr<Warehouse>& warehouse);
    void sellProduct(const std::string& productName, int quantity);
    void displayWarehouses() const;
    void displayName() const;
};


#endif //LAB11_ZPO_SKLEP_SHOP_H
