 //This following code in C can be used as a bill generating software
 //IT can be used in the real world in generating the bill
 //Takes input from the customer to print the bill
 //Generates bills in the food counters and restaurants
 //Generates the bill by adding the gst to the amount sustracting the discount from the amount w.r.t the  amount of the bill 
 //Uses four different fuctions for bill generation

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double price[11] = {200,225,250,300,325,350,400,100,100,100,120};
double mealTaxPrices[11];
int ncustomers;


void printMeals();
void orderMeals();
double orderfromuser();

int main()
{
    char response = 'y';
    
     
     printMeals();
     while(response == 'y'|| response == 'Y')
    {
            printf("Please enter number of the number of customers  :");
            scanf("%d",&ncustomers);
            
            
                       
            orderMeals();
            
            printf("\nWould you like to continue(y/n):");
            scanf("\n%c",&response);
    }
  
 printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
 printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
   system("pause");
   return 0;
}

void printMeals()
{
     
      printf("\20*******************  WELCOME TO PIZZA PALACE **************************\20\n");
      printf(" \t\t MENU:-\20\n");
      printf(" \t\t MEALS\t\t\t\tPRICE:\n");
      printf(" \t\t \22*******************************\22\n");
      printf(" \t\t PIZZA'S\n");
      printf(" \t\t 1- MEXICAN VEG PIZZA\t\tRs 200\n");
      printf(" \t\t 2- CHEESY PESTO PIZZA\t\tRs 225\n");
      printf(" \t\t 3- TANDOORI PANEER PIZZA\tRs 250\n");
      printf(" \t\t 4- CHICKEN BAR-B-QUE PIZZA\tRs 300\n");
      printf(" \t\t 5- SPICY PEPPERONI PIZZA\tRs 325\n");
      printf(" \t\t 6- GARDEN FRESH PIZZA\t\tRs 350\n");
      printf(" \t\t 7- INDIAN HOT PIZZA\t\tRs 400\n");
      printf(" \t\t BEVERAGES\n");
      printf(" \t\t 8- COKE\t\t\tRs 100\n");
      printf(" \t\t 9- MINT LIME\t\t\tRs 100\n");
      printf(" \t\t 10- RED BULL\t\t\tRs 100\n");
      printf(" \t\t 11- CHOCHO CHIP\t\tRS 120\n");
      
      
      
      printf("\n");
}
void orderMeals()
{
	double totalprice;
	double allPayment,discount;
         printf("                      \t\t**** ORDER MENUE****\n");  
         
         
        totalprice =  orderfromuser();
        
		allPayment = totalprice  ;
        
     printf("\n \t\t     \22**************************************\22    \n");
     printf(" \t\t      ************** FINAL BILL **************         \n");
    
     printf(" \t\t\tCustomers:-\t\t\t%d\n",ncustomers);
     
   
     printf(" \t\t\tTotal bill\t\t\t%5.2f\n",allPayment );
      
	 
     
     if(allPayment < 300)
		 discount=((allPayment * 5)/100);
     else if(allPayment>= 300 && allPayment<500)
          discount=((allPayment * 10)/100);
     else if(allPayment>= 500 && allPayment<700)
          discount=((allPayment * 15)/100);
     else if(allPayment>= 700 && allPayment<1000)
          discount=((allPayment * 20)/100);
	 else 
		  discount= ((allPayment * 30)/100);
        printf(" \t\t\tDiscount:-\t\t\t%f\t\t\n",discount);  
       printf("\n \t\t     \22**************************************\22    \n");
          printf(" \t\t\tTotal bill after discount:-\t%5.2fRs\n",allPayment-discount);

}
double orderfromuser()
{
     int menuOption,i,amount;
      char response = 'y';
      double perperson = 0.0,total = 0.0;
      double tax = 9.0;
      if(ncustomers <=0)
		   printf("PLEASE ENTER A POSITIVE NUMBER");
	 
      for(i=0;i<ncustomers;i++)
     {
               printf("Please enter the order for customer %d\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("Please enter the option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>11)
							  {
								  printf("Sorry!! We don`t have this order \nagain! ");
								  continue;
							  }
                              printf("Please enter your amount of order:");
                              scanf("%d",&amount);
                              
                              
                           perperson = perperson + (amount * price[menuOption - 1] );
                              
                              printf("\nWould you like to add any thing else(y/n):");
                              scanf("\n%c",&response);
               
                              
                           
               }
               printf("\n");
               total += total +  perperson;
               perperson = 0.0;
               response = 'y';
     }
     
     return total + ((total * tax) / 100);
}

