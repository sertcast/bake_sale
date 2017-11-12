//
//  num_of_sales.cpp
//  bake_sale
//
//  Created by Mert Kaya on 2017-11-12.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "num_of_sales.hpp"
#include <stdio.h>
#include <stdlib.h>

int get_length(char *strng){
    int i = 0;
    char *m_str = strng;
    while(*m_str != '\0'){
        m_str++;
        i++;
    }
    return i;
}
int get_tabs(char *strng){
    int len = get_length(strng);
    if(len / 8 >= 3){
        return 0;
    }else{
        return 3 - (len/8);
    }
}
int find_until_tabs(char *line){
    int num_tabs = 0;
    char *cp_line = line;
    while(*cp_line != '\t'){
        num_tabs++;
        cp_line++;
    }
    return num_tabs;
}
char *getString(char *string,int baslangic, int bitis){
    char *parca = (char*)malloc(bitis+1-baslangic*sizeof(char));
    int i;
    int a = 0;
    for(i = baslangic-1; i < bitis; i++){
        parca[a] = string[i];
        a++;
    }
    parca[a] = '\0';
    return parca;
}


