//
//  main.c
//  ShiftKey
//
//  Created by Abhilash Pravinkumar on 2015-03-21.
//  Copyright (c) 2015 Abhilash Kumar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void shiftEncrypt(char message[],char * encrpt,int *bkey);
void shiftDecrypt(char encrypt[],char* message,int key)


int main(int argc, const char * argv[]) {
   
    while (1){
        char message[20];
        char encrpytion[20];
        char decrypt[20];
        
        
        printf("Please enter the code you want to encrypt\n");
        scanf("%19s",message);
        int key;
        shiftEncrypt(message, encrpytion,&key);
        
        
        printf("The Shift Key encryption is %s with key %i \n",encrpytion,key);
        // printf("Enter key to obtain original message \n");
        
        printf("Please enter the CORRECT key for decryption. Wrong key would result in gibberish. \n")
  
    }
    
    
}

void shiftEncrypt(char message[],char * encrpt,int * key){
    
    char temp[20];
    int len = (int)strlen(message);
    
    srand((unsigned) time(NULL));
    int k = rand()%10;

    for (int i=0; i<len; i++) {
       temp[i] = message[i]+k;
        
    }
    
    strcpy(encrpt, temp);
    *key = k;
    
}
