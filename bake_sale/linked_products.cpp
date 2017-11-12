//
//  linked_products.cpp
//  bake_sale
//
//  Created by Mert Kaya on 2017-11-12.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_products.hpp"
product* create_product(){
    product* the_product = (product*)malloc(sizeof(product));
    the_product->name = (char*)malloc(100*sizeof(char));
    the_product->next = NULL;
    the_product->prev = NULL;
    the_product->added_value = false;
    the_product->total_sales = 0;
    return the_product;
}
product *create_list(){
    product *the_list = create_product();
    return the_list;
}
product *go_end(product* list){
    product *current = list;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}
void append_list(product *list, char *name){
    product *end_product = go_end(list);
    if(list != NULL){
        if(end_product->added_value){
            product *new_type = create_product();
            strcpy(new_type->name, name);
            new_type->prev = end_product;
            end_product->next = new_type;
        }else{
            strcpy(end_product->name, name);
            end_product->added_value = true;
        }
    }
}
void free_list(product *list){
    product *end = go_end(list);
    while(end->prev != NULL){
        free(end->name);
        end = end->prev;
        free(end->next);
    }
    free(end->name);
    free(end);
}
product *search_product(product *list, char *name){
    product *current = list;
    while(current->next != NULL){
        if(strcmp(current->name, name) == 0){
            return current;
        }
        current = current->next;
    }
    if(strcmp(current->name, name) == 0){
        return current;
    }
    return NULL;
    
}

