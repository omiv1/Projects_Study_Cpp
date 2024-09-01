//
// Created by lukas on 08.01.2024.
//

#ifndef LAB11_ZPO_SKLEP_WAREHOUSE_H
#define LAB11_ZPO_SKLEP_WAREHOUSE_H


#include <iostream>
#include <memory>

class Warehouse {
private:
    std::string productName;
    int quantity;

public:
    Warehouse(const std::string& productName, int quantity);
    ~Warehouse();

    const std::string& getProductName() const;
    int getQuantity() const;
    void setProductName(const std::string& name);
    void setQuantity(int qty);
    void displayInfo() const;
};

#endif //LAB11_ZPO_SKLEP_WAREHOUSE_H
