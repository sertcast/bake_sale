//
//  record_sales.cpp
//  bake_sale
//
//  Created by Mert Kaya on 2017-11-12.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "record_sales.hpp"
#include "num_of_sales.hpp"
using namespace std;
char *enter_sales(){
    char *file_num = (char*)malloc(1000*sizeof(char));
    cout << "enter number of file: ";
    cin >> file_num;
    char *file_name = (char*)malloc(1000*sizeof(char));
    char *file_name_adress = (char*)malloc(1000*sizeof(char));
    /****************/
    sprintf(file_name_adress, "/Users/mert/Desktop/bake_sale_%s.txt", file_num);//change /Users/mert/Desktop/ to the place you will save
    /****************/
     sprintf(file_name, "bake_sale_%s.txt", file_num);
    
    
    FILE *bake_sale = fopen(file_name_adress, "w");
    char *first = (char*)malloc(100*sizeof(char));
    char *second = (char*)malloc(100*sizeof(char));
    char *third = (char*)malloc(100*sizeof(char));
    char *date = (char*)malloc(100*sizeof(char));
    
    int quantity = 0;
    double paid = 0.0;
    double total = 0.0;
    int i = 0;
    int tabs;
    
    cout << "enter date: ";
    cin >> date;
    fprintf(bake_sale, "%s\n", date);
    cout << "quantity|product|customer_paid" << endl;
    while(strcmp(first, "quit") != 0){
        cin >> first >> second >> third;
        if(strcmp(first, "quit") == 0){
            break;
        }
        quantity = atoi(first);
        paid = atof(third);
        total += paid;
        tabs = get_tabs(second);
        
        fprintf(bake_sale, "%s", second);
        for(i = 0; i < tabs; i++){
            fprintf(bake_sale, "\t");
        }
        fprintf(bake_sale, "%d\t%.2lf\n", quantity, paid);
    }
    fprintf(bake_sale, "TOTAL:\t\t\t\t%.2lf\n\n", total);
    fclose(bake_sale);
    free(first);
    free(second);
    free(third);
    free(date);
    free(file_num);
    free(file_name_adress);
    return file_name;
}
void total_sales(char *file_name){
    char *line = (char*)malloc(1000*sizeof(char));
    char *date = (char*)malloc(1000*sizeof(char));
    char *first = (char*)malloc(1000*sizeof(char));
    char *second = (char*)malloc(1000*sizeof(char));
    
    int i, a, b, total = 0,len_first;
    product *list = create_list();
    char *file_name_adress = (char*)malloc(1000*sizeof(char));
    /****************/
    sprintf(file_name_adress, "/Users/mert/Desktop/%s", file_name);//change /Users/mert/Desktop/ to the place you will save
    /****************/
    FILE *bake_sale = fopen(file_name_adress, "r");
    fgets(line, 999, bake_sale);
    strcpy(date, line);
    char *cp_line, *part = (char*)malloc(1000*sizeof(char));
    while(!feof(bake_sale)){
        fgets(line, 999, bake_sale);
        if(strncmp(line, "TOTAL:", 6) != 0){
            cp_line = line;
            a = find_until_tabs(cp_line);
            first = getString(line, 1, a);
            cp_line += a;
            while(*cp_line == '\t'){
                cp_line++;
                a++;
            }
            b = find_until_tabs(cp_line) + a;
            second = getString(line, a+1, b);
            cp_line += b - a + 1;
            
            len_first = get_length(first);
            for(i = 0; i < len_first; i++){
                if(first[i] == '+'){
                    strcpy(part, getString(first, 1, i));
                    if(search_product(list, part) != NULL){
                        (search_product(list, part))->total_sales += atoi(second);
                        (search_product(list, part))->added_value = true;
                    }else{
                        append_list(list, part);
                        (go_end(list))->total_sales += atoi(second);
                        (search_product(list, part))->added_value = true;
                    }
                    strcpy(part, getString(first, i+2, len_first));
                    if(search_product(list, part) != NULL){
                        (search_product(list, part))->total_sales += atoi(second);
                    }else{
                        append_list(list, part);
                        (go_end(list))->total_sales += atoi(second);
                    }
                    break;
                }else if(i == len_first-1 && first[i+1] != '+'){
                    if(search_product(list, first) != NULL){
                        (search_product(list, first))->total_sales += atoi(second);
                        (search_product(list, first))->added_value = true;
                    }else{
                        append_list(list, first);
                        (go_end(list))->total_sales += atoi(second);
                        (go_end(list))->added_value = true;
                    }
                    break;
                }
            }
        }
    }
    fclose(bake_sale);
    free(first);
    free(second);
    char *file = (char*)malloc(1000*sizeof(char));
    sprintf(file, "/Users/mert/Desktop/total_sales:%s", file_name);
    
    FILE *totals = fopen(file, "w");
    product *current = list;
    int tabs = get_tabs(current->name);
    fprintf(totals, "%s", date);
    while(current->next != NULL){
        fprintf(totals, "%s", current->name);
        tabs = get_tabs(current->name);
        for(i = 0; i < tabs; i++){
            fprintf(totals, "\t");
        }
        fprintf(totals,"%d\n", current->total_sales);
        total += current->total_sales;
        current = current->next;
    }
    fprintf(totals, "\nTOTAL:");
    tabs = get_tabs("TOTAL:");
    for(i = 0; i < tabs; i++){
        fprintf(totals, "\t");
    }
    fprintf(totals,"%d\n\n", total);
    fclose(totals);
    free(date);
    free_list(list);
    free(part);
    free(line);
}
