#include <iostream>
#include <memory>
#include "Warehouse.h"
#include "Shop.h"

int main() {
    std::vector<std::shared_ptr<Shop>> shops;

    auto warehouse1 = std::make_shared<Warehouse>("Ksiazki", 100);
    auto warehouse2 = std::make_shared<Warehouse>("Elektronika", 50);

    auto shop1 = std::make_shared<Shop>("Ksiegarnia");
    auto shop2 = std::make_shared<Shop>("Sklep Elektroniczny");

    shop1->addWarehouse(warehouse1);
    shop2->addWarehouse(warehouse2);

    shops.push_back(shop1);
    shops.push_back(shop2);

    for (const auto& shop : shops) {
        shop->displayName();
        shop->displayWarehouses();
    }

    shop1->sellProduct("Ksiazki", 30);
    shop2->sellProduct("Elektronika", 20);

    for (const auto& shop : shops) {
        shop->displayName();
        shop->displayWarehouses();
    }

    return 0;
}
