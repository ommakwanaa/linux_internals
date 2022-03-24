/*pointer operation*/


#include<stdio.h>
int sort(int n, int* ptr){
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(*(ptr+j)< *(ptr +i)){
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = t;
			}	
		}
	}

	for(i=0;i<n;i++){
		printf("%d ", *(ptr+i));
	}
}

void main()
{

int x,y,*ptr_x,*ptr_y,temp,num;
   

printf("Enter the value of x and y\n");
scanf("%d%d", &x, &y);

ptr_x = &x;
ptr_y = &y;
printf("\n1) Address of x: %p and y: %p \n",ptr_x,ptr_y);
printf("\n2)Before Swapping x = %d y = %d", x, y);

temp = *ptr_y;
*ptr_y = *ptr_x;
*ptr_x = temp;

printf("     After Swapping x = %d y = %d\n", x, y);

printf("\n3) Address of x: %p Data of varrable x: %d \n",ptr_x,x);

num = *ptr_y + *ptr_x;
 
printf("\n4) Sum = %d\n", num);

int numArray[]={10,20,21,11,12,22};
int i, sum = 0;
int *ptr;
ptr = numArray;

for (i = 0; i < sizeof(numArray)/sizeof(int); i++) {
  sum = sum + *ptr;
  ptr++;
}


printf("\n5) The sum of array elements : %d\n", sum);
printf("\n6) The shorting of array {10,20,21,11,12,22} elements is : ");
sort(sizeof(numArray)/sizeof(int),numArray);
}