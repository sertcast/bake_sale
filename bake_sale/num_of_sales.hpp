//
//  num_of_sales.hpp
//  bake_sale
//
//  Created by Mert Kaya on 2017-11-12.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef num_of_sales_hpp
#define num_of_sales_hpp

#include "linked_products.hpp"
int get_tabs(char *strng);
int get_length(char *strng);
int find_until_tabs(char *line);
char *getString(char *string,int baslangic, int bitis);
#endif /* num_of_sales_hpp */
