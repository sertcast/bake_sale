//
//  main.cpp
//  bake_sale
//
//  Created by Mert Kaya on 2017-11-12.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include <iostream>
#include "record_sales.hpp"
int main(int argc, const char * argv[]) {
    char *file = enter_sales();
    total_sales(file);
    return 0;
}
