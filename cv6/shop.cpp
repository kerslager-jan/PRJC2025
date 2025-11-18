#ifndef H_SHOP
#define H_SHOP
#include "shop.h"

CellPhone::CellPhone(const std::string& _name, int _price){
    name = _name;
    price = _price;
}

//copy constructor
CellPhone::CellPhone(const CellPhone& other){
    name = other.getName();
    price = other.getPrice();
}

// copy assignment
CellPhone& CellPhone::operator=(const CellPhone& other){
    //prevence kopie sebe sama
    if(this == &other){
        return *this;
    }

    name = other.getName();
    price = other.getPrice();
    return *this;
}

std::string CellPhone::getName() const {
    return name;
}

int CellPhone::getPrice() const {
    return price;
}

void CellPhone::setName(std::string _name){
    name = _name;
}

void CellPhone::setPrice(int _price){
    price = _price;
}

int CartItem::getQuantity() const {
    return quantity;
}

const CellPhone& CartItem::getPhone() const {
    return phone;
}

CartItem::CartItem(const CellPhone& _phone, int _quantity)
    : phone(_phone), quantity(_quantity)
{}

void ShoppingCart::addPhone(CellPhone& phone, int quantity){
    CartItem i = CartItem(phone, quantity);
    items.push_back(i);
}

int ShoppingCart::getTotalPrice() const {
    int sum = 0;
    for(const auto& i : items){
        sum += i.getPhone().getPrice() * i.getQuantity();
    }
    return sum;
}

ShoppingCart::ShoppingCart(){
    items = std::vector<CartItem>();
}

#endif