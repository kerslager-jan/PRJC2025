#ifndef SHOP
#define SHOP
#include <string>
#include <vector>

class CellPhone{
public:
    //CellPhone();
    CellPhone(const CellPhone& other);
    CellPhone(const std::string& _name, int _price);
    CellPhone& operator=(const CellPhone& other);
    std::string getName() const;
    void setName(std::string _name);
    int getPrice() const;
    void setPrice(int _price);
private:
    std::string name;
    int price;
};

class CartItem{
public:
    CartItem(const CellPhone& _phone, int _quantity);
    int getQuantity() const;
    const CellPhone& getPhone() const;
private:
    CellPhone phone;
    int quantity;
};

class ShoppingCart{
public:
    int getTotalPrice() const;
    void addPhone(CellPhone& phone, int quantity);
    ShoppingCart();
    private:
    std::vector<CartItem> items;
};

#endif