//
//  main.cpp
//  mektup
//
//  Created by Elessar Telcontar on 7.11.2019.
//  Copyright © 2019 Elessar Telcontar. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    for(int i=0;i<6;i++){
        for(int j=0;j<12;j++){
            if(i==0 ||i==5){
                printf("*");
            }
            else{
                if(j==i || j==11-i || j==0 || j==11){
                    printf("*");
                }
                else{
                    printf(" ");
                }
                
            }
            
        }
        printf("\n");
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<12;j++){
            if(i==0 ||i==5){
                printf("*");
            }
            else{
                if(j==(11/2)-i || j==(11/2+1)+i || j==0 || j==11){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
