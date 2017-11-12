//
//  linked_products.hpp
//  bake_sale
//
//  Created by Mert Kaya on 2017-11-12.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef linked_products_hpp
#define linked_products_hpp

#include <stdio.h>
#include "product.hpp"
product *create_list(void);
void append_list(product *list, char *name);
void free_list(product *list);
product *search_product(product *list, char *name);
product *go_end(product* list);
#endif /* linked_products_hpp */
