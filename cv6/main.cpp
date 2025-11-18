#include <iostream>
#include <vector>
#include "shop.h"

int main(){
    CellPhone p = CellPhone("iphone", 10000);
    ShoppingCart cart = ShoppingCart();
    cart.addPhone(p, 2);
    std::cout << "celkova cena: " << cart.getTotalPrice() << "\n";
    return 0;
}