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
void shiftDecrypt(char encrypt[],char* message,int key);


int main(int argc, const char * argv[]) {
   
    while (1){
        char message[20],encrpytion[20],decrypt[20];
        int user_key;
        
        
        
        printf("Please enter the code you want to encrypt\n");  //Obtains a String from user to encrypt
        scanf("%19s",message);
        int key;
        shiftEncrypt(message, encrpytion,&key);                 //Calls Encrypt method
        
        
        printf("The Shift Key encryption is %s with key %i \n",encrpytion,key);
    
        
        printf("Please enter the CORRECT key for decryption. Wrong key would result in gibberish. \n");
        scanf("%i",&user_key);
        shiftDecrypt(encrpytion, decrypt, user_key);
        
        printf("Your decrpyted message is %s \n",decrypt);
        
    }
    
    
}

void shiftEncrypt(char message[],char * encrpt,int * key){
    
    char temp[20];
    int len = (int)strlen(message);
    
    srand((unsigned) time(NULL));
    int k = 1+(rand()%9);

    for (int i=0; i<len; i++) {
       temp[i] = message[i]+k;
        }
    
    strcpy(encrpt, temp);
    *key = k;
    
}

void shiftDecrypt(char encrypt[],char* message,int key){
    char temp[20];
    int len = (int)strlen(encrypt);
    for (int i=0; i<len; i++) {
        temp[i] = encrypt[i]- key;
        
    }
    strcpy(message, temp);
}
