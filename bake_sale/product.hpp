//
//  product.hpp
//  bake_sale
//
//  Created by Mert Kaya on 2017-11-12.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef product_hpp
#define product_hpp

#include <stdio.h>
#include <stdbool.h>
struct product{
    char *name;
    int total_sales;
    bool added_value;
    struct product *next, *prev;
};
typedef struct product product;
#endif /* product_hpp */
