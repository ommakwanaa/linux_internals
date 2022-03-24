/*atm machine using structure*/


#include<stdio.h>  
#include <string.h> 
int acccheck();
int pincheck(int);
int menue(int);
struct banker{
    int id;      
    int pin;
    float bal;
    }e[5];  
int main( )    
{  //storing data//  
   e[1].id=101;
   e[1].pin=10;
   e[1].bal=1900.00;
   
   e[2].id=102;
   e[2].pin=11;
   e[2].bal=9000.00; 

   e[3].id=102;
   e[3].pin=12;
   e[3].bal=98000.00; 

   e[4].id=102;
   e[4].pin=13;
   e[4].bal=111000.00; 
   //end//
   
   printf( "\nWellcome to our bank\n");
   int  ret,ret2;
   ret = acccheck();
   if(ret == 0){
       printf("\n\nsomething went wrong");}
   else{
       ret2 = menue(ret);
       if(ret2 == 1000){
           printf("\n\nTHANKS FOR BANKING WITH US :) ");}}}

int menue(int acnum){
    int forcase = 0,minus=0,yesnoloop;
    int accno = acnum;
    menueagain:
    
    printf("\n\tSelect the option\n\n   1) Check Balance: 1\n   2) Widrawal Cash: 2\n   3) Deposit Cash: 3\n   4) Quit: 4\n");
    scanf("%d",&forcase);
    switch(forcase){
        case 1:
        printf("\n\t Check Balance");
        for(int i=0;i<6;i++){if(e[i].id==accno){printf("\n\nYOUR BALANCE IS: %f\n",e[i].bal);}}
        printf("\nFOR CONTINUE: 1\nFOR QUITING: 0\n");
        scanf("%d",&yesnoloop);
        if(yesnoloop == 1){goto menueagain;}
        else{return 1000;} 
        
        case 2:
        printf("\n\t Widrawal Cash");
        printf("\nENTER THE AMOUNT: ");
        scanf("%d",&minus);
        for(int i=0;i<6;i++){if(e[i].id==accno){printf("\n\nYOUR REMAINING BALANCE IS: %f\n",e[i].bal-minus);}e[i].bal=e[i].bal-minus;}
        printf("\nFOR CONTINUE: 1\nFOR QUITING: 0\n");
        scanf("%d",&yesnoloop);
        if(yesnoloop == 1){goto menueagain;}
        else{return 1000;} 
        
        case 3:
        printf("\n\t Deposit Cash");
        printf("\nENTER THE AMOUNT: ");
        scanf("%d",&minus);
        for(int i=0;i<6;i++){if(e[i].id==accno){printf("\n\nYOUR REMAINING BALANCE IS: %f\n",e[i].bal+minus);}e[i].bal=e[i].bal+minus;}
        printf("\nFOR CONTINUE: 1\nFOR QUITING: 0\n");
        scanf("%d",&yesnoloop);
        if(yesnoloop == 1){goto menueagain;}
        else{return 1000;}
        
        case 4:
        printf("Quiting");return 1000;
    }
    
}


int pincheck(int acnum){
    int pinno = 0,countpin = 3,i=0;
    int accno=acnum;
    pinagain:
    printf("\nEnter pin: \n");
    scanf("%d",&pinno);
    while(countpin != 0){
        for(int i=0;i<6;i++){
            if(e[i].id==accno && e[i].pin==pinno){
                return pinno;
                countpin = 0;}
            else{continue;}}
        countpin--;
        printf("\nINCORRECT PIN\nTRY LEFT: %d\n",countpin);
        if(countpin == 0){return 111;break;}
        goto pinagain;
    }}

int acccheck(){
    int pinret = 0,accno=0,countacc = 3,i=0;
    accagain:
    printf("\nEnter account number: \n");
    scanf("%d",&accno);
    while(countacc != 0){
        for(int i=0;i<6;i++){
            if(e[i].id==accno){
                pinret = pincheck(accno);
                if(pinret == 111){
                    printf("CARD BLOCKED\n");
                    return 0;}
                else{return accno;  }
                countacc = 0;}
            else{continue;}}
        countacc--;
        printf("\nINCORRECT ACCOUNT NUMBER\n");
        if(countacc == 0){printf("\nblock account no");break;}
        goto accagain;
    }return 0;}