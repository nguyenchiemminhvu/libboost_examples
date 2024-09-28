#include <iostream>
#include <string>
#include <boost/unordered_map.hpp>

class Inventory
{
public:
    void addProduct(const std::string& productName, int quantity)
    {
        inventory_[productName] += quantity;
    }

    void updateProduct(const std::string& productName, int quantity)
    {
        if (inventory_.find(productName) != inventory_.end())
        {
            inventory_[productName] += quantity;
        }
        else
        {
            std::cout << "Error: Product '" << productName << "' does not exist in inventory!" << std::endl;
        }
    }

    void displayInventory() const
    {
        std::cout << "Current Inventory:" << std::endl;
        for (const auto& item : inventory_)
        {
            std::cout << "Product: " << item.first << ", Quantity: " << item.second << std::endl;
        }
    }

    int getProductQuantity(const std::string& productName) const
    {
        auto it = inventory_.find(productName);
        if (it != inventory_.end())
        {
            return it->second;
        }
        return 0;
    }

private:
    boost::unordered_map<std::string, int> inventory_;
};

int main()
{
    Inventory inventory;

    inventory.addProduct("Apples", 50);
    inventory.addProduct("Bananas", 30);
    inventory.addProduct("Oranges", 20);
    
    inventory.updateProduct("Bananas", 10);
    inventory.updateProduct("Grapes", 5);

    inventory.displayInventory();

    std::string queryProduct = "Apples";
    std::cout << "Quantity of " << queryProduct << ": " 
              << inventory.getProductQuantity(queryProduct) << std::endl;

    return 0;
}
