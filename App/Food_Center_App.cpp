#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

//Functions Declarations
void switchfunction(); // Declaretion 
void InsertFoodDetails();
void  DisplayFood();
void UpdateFoodDetails();
void SearchFoodDetails();
void DeleteFoodDetails();
void PurchaseFood();
void DisplayBill();

//Structures 
	struct Food_Center 
	{
		int id;
		char food_name[100];
		int price;
		char category[100];
	};

    //struct Food_Center FC[100];
    struct Food_Center *FC = NULL;

	struct Purchased_Item
	{
		char food_item_name[90];
		int quantity;
	};
	
	struct Purchased_Item *purchased_item = NULL;
	int purchase_item_count = 0;
	int food_item_capacity = 0;

int main()
{	
	printf("\n\n How many food items capacity Do you want to add : ");
	scanf("%d",&food_item_capacity);
	FC = (struct Food_Center*)malloc(food_item_capacity * sizeof(struct Food_Center));
    purchased_item = (struct Purchased_Item*)malloc(food_item_capacity * sizeof(struct Purchased_Item));

    if (FC == NULL || purchased_item == NULL) {
        printf("\n Memory allocation failed\n");
        return 1;
    }
	printf("\n\n\t\t----- Welcome To RestoHub -----\n\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			
	switchfunction();	// Calling
	
	printf("\n\n\n Thank You..!! Visit Again......!");
	  
	free(FC);
    free(purchased_item);
    
	return 0;
}

	int ch;
	char ex;
	int item_count = 0;
	int one = 0;
	int flag = 0;
	int i = 0;

	//Function Defination
	void switchfunction()
	{	 
		int ch;
		char ex;
		
		do
		{
			printf("\n 1 : Insert Food Details ");
			printf("\n 2 : Display All Food Details ");
			printf("\n 3 : Update Food Details ");
			printf("\n 4 : Search Food Details  ");
			printf("\n 5 : Delete Food Details ");
			printf("\n 6 : Purchase Food ");
			printf("\n 7 : Display Bill ");
			printf("\n 8 : Exit /Close/ Logout ");
			
			printf("\n\n * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			
			printf("\n\n Enter your Choice : ");
			scanf("%d",&ch);

			
			switch(ch)
			{
				case 1:
					InsertFoodDetails();
				break;
				
				case 2:
					 DisplayFood();
				break;
				
				case 3:
					UpdateFoodDetails();
				break;
				
				case 4:
					SearchFoodDetails();
				break;
				
				case 5:
					DeleteFoodDetails();
				break;
				
				case 6:
					PurchaseFood();
				break;
				
				case 7:
					DisplayBill();
				break;
				
				case 8:
					return;
					//Write By - Shubham Suryawanshi Feb-2024	
						
				default:
				printf("\n\n INVALID INPUT : ");
				break;
			}
			
			printf("\n\n Do you want to continue with Food Center (Y/y for Yes) : ");
			scanf(" %c",&ex);
			
		
		}while(ex == 'y' || ex == 'Y');
	}

	void InsertFoodDetails()
	{
		printf("\n\n 1 : Add 1 Food Record at time ");
		printf("\n 2 : Add Multiple Food Record at time ");
		printf("\n 11 :  Back ");
		
		int ch;
		printf("\n\n Enter Choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{								
			case 1 : //Add 1 Food Record at time
			{																
				do
				{	
					if (item_count >= food_item_capacity) 
					{
	                    food_item_capacity *= 2;
	                    FC = (struct Food_Center*)realloc(FC, food_item_capacity * sizeof(struct Food_Center));
	                    if (FC == NULL) 
						{
	                        printf("\n Memory reallocation failed\n");
	                        exit(1);
	            		}
                	}									
					printf("\n\n Add Food : ");
					printf("\n Enter Id of food : ");
					printf("\n Enter Food Name : ");
					printf("\n Enter Food Price : ");
					printf("\n Enter Food Category : ");
					printf("\n\n");	
																									
					scanf("%d",&FC[i].id);
					
					_flushall();
					gets(FC[i].food_name);
					
					scanf("%d",&FC[i].price);
					
					_flushall();
					gets(FC[i].category);
					
					printf("\n");
					++i;
					++one;
				
					printf("\n\n Do you want to Add another Food (Y/y for Yes) : ");
					scanf(" %c",&ex);																						
				}while(ex == 'Y' || ex =='y');
				
			 break;	
			}//End Case 1
			
			case 2 : //Add Multiple Food Record at time
			{
				
				int item;
				printf("\n\n Add Food : ");
				printf("\n Enter Id of food : ");
				printf("\n Enter Food Name : ");
				printf("\n Enter Food Price : ");
				printf("\n Enter Food Category : ");
				printf("\n\n");	
				printf("\n\n How many items Do you want to add : ");
				scanf("%d",&item);
            	
				item_count = one + item;
				
				if (item_count >= food_item_capacity) 
				{
                    food_item_capacity *= 2;
                    FC = (struct Food_Center*)realloc(FC, food_item_capacity * sizeof(struct Food_Center));
                    if (FC == NULL) 
					{
                        printf("\n Memory reallocation failed\n");
                        exit(1);
            		}
            	}
				
				for(i=0;i<item_count;i++)
				{
					scanf("%d",&FC[i].id);
				
					_flushall();
					gets(FC[i].food_name);
					
					scanf("%d",&FC[i].price);
					
					_flushall();
					gets(FC[i].category);
					
					printf("\n");									
				}
					
			 break;
			}// End Case 2 : Add Multiple Food Record at time
			
			case 11: // Back
			{
				break;
			}
			
			default:
			{
				printf("\n\n INVALID INPUT........!!");
				break;
			}
																																						
		} // End - Switch Insert food
	}// End - Insert food function
	
	void DisplayFood()
	{
		printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - -");
		printf("\n\n Display Food item : ");				
		printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - -");
		item_count = item_count + one;
		for(i = 0; i<item_count;i++)
		{
			if(FC[i].id != 0)
			{
				printf("\n\n Food Id: %d",FC[i].id);
				printf("\n Food Name : %s",FC[i].food_name);
				printf("\n Food Price : %d",FC[i].price);
				printf("\n Food Category : %s\n",FC[i].category);
				printf("\n_________________________________________________");
			}
		}
		//printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - ");
	
	}// End Display food function
	
	void UpdateFoodDetails()
	{
		
		int update_by_id;
		char update_by_name[100];
		printf("\n\n Update Food Details ");
		
		do
		{
			
			printf("\n\n 1 : Update by Id ");
			printf("\n 2 : Update by Name ");
			printf("\n 11 :  Back ");
			
			printf("\n\n Enter your Choice : ");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1: // Update by Id 
					{
						
					printf("\n\n Update Food by Id ");
					
					printf("\n\n  Enter Id : ");
					scanf("%d",&update_by_id);
					flag = 0;
					for(i = 0; i<item_count;i++)
					{
						if(update_by_id == FC[i].id)
						{
							flag = 1;
							break;
						}
					}
					if(flag)	
					{
						printf("\n Update Food Name : ");
						printf("\n Update Food Price : ");
						printf("\n Update Food Category : ");
						printf("\n\n");

						_flushall();
						gets(FC[i].food_name);
						
						scanf("%d",&FC[i].price);
						
						_flushall();
						gets(FC[i].category);
						
						printf("\n");
					}
					else
					{
						printf("\n Food Id is not Avaible in Database....!!");
					}
					break;
					}// Update food End case 1
				
				case 2 : // Update Food by Name
					{
						printf("\n\n Update Food by Name ");
						
						printf("\n\n  Enter Name : ");
						_flushall();
						gets(update_by_name);
						
						flag = 0;
						for(i = 0; i<item_count;i++)
						{
							if(strcmp(update_by_name,FC[i].food_name) == 0)
							{
								flag = 1;
								break;
							}
						}
						if(flag)	
						{
							printf("\n Update Food Name : ");
							printf("\n Update Food Price : ");
							printf("\n Update Food Category : ");
							printf("\n\n");
	
							_flushall();
							gets(FC[i].food_name);
							
							scanf("%d",&FC[i].price);
							
							_flushall();
							gets(FC[i].category);
							
							printf("\n");
						}
						else
						{
							printf("\n Food Name is not Avaible in Database....!!");
						}
															
					break;
					}//Update food End case 2 //
					
				case 11: // Back
				{
					break;
				}
				
				default:
				{
					printf("\n\n INVALID INPUT.....!!");
					break;
				}// Update food End case Default
			}
			
			printf("\n Do you want to Update another Food (Y/y for Yes) : ");
			scanf(" %c",&ex);
			
		}while(ex == 'Y' || ex == 'y');
	 
	}//End Update Food Datails function
	
	void SearchFoodDetails()
	{
		// Variable for Searching Food
		int search_by_id;
		char search_by_name[100];
		char search_by_category[100];
		int search_by_Range;
		
		printf("\n\n Search Food Details : ");
		
		do
		{
			printf("\n\n 1 : Search Food by Id : ");
			printf("\n 2 : Search Food by Name : ");
			printf("\n 3 : Search Food by Price Range : ");
			printf("\n 4 : Search Food by Category : ");
			printf("\n 11 :  Back ");
			
			printf("\n\n Enter Choice for Search Food : ");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1 : // Search Food by Id
					{
						flag = 0;
						printf("\n\n Search Food By Id ");
						printf("\n\n Enter Food Id : ");
						scanf("%d",&search_by_id);
						int flag = 0;
						for(i = 0; i<item_count;i++)
						{
							if(search_by_id == FC[i].id)
							{
								flag = 1;
								break;
							}
						}
						if(flag)	
						{
							printf("\n\n Food Id: %d",FC[i].id);
							printf("\n Food Name : %s",FC[i].food_name);
							printf("\n Food Price : %d",FC[i].price);
							printf("\n Food Category : %s\n",FC[i].category);
						
							printf("\n");
						}
						else
						{
							printf("\n This Food Id is not Avaible in Database....!!");
						}
						
					 break;
					}// End Search Case 1
					
				case 2 : // Search Food by Name
					{
						flag = 0;
						printf("\n\n Search Food By Name ");
						printf("\n\n  Enter Food Name : ");
						_flushall();
						gets(search_by_name);
						int flag = 0;
						for(i = 0; i<item_count;i++)
						{
							if(strcmp(search_by_name,FC[i].food_name) == 0)
							{
								flag = 1;
								break;
							}
						}
						if(flag)	
						{
							printf("\n\n Food Id: %d",FC[i].id);
							printf("\n Food Name : %s",FC[i].food_name);
							printf("\n Food Price : %d",FC[i].price);
							printf("\n Food Category : %s\n",FC[i].category);																								
							printf("\n");
						}
						else
						{
							printf("\n Food Name is not Avaible in Database....!!");
						}
						
					 break;
					}// End Search Case 2
				
				case 3 : // Search Food by Price Range
					{
						printf("\n\n Search Food By Range ");
						
						printf("\n\n Enter Food Range : ");
						scanf("%d",&search_by_Range);
																
						for(i = 0; i<item_count;i++)
						{
							if(FC[i].price <= search_by_Range)
							{
								printf("\n\n Food Id: %d",FC[i].id);
								printf("\n Food Name : %s",FC[i].food_name);
								printf("\n Food Price : %d",FC[i].price);
								printf("\n Food Category : %s\n",FC[i].category);
								printf("\n_________________________________________________");														
							}
						}
						
					 break;
					}// End Search Case 3
				
				case 4 : // Search Food By Categoty
					{
						printf("\n\n Search Food By Categoty ");
						
						printf("\n\n  Enter Food Categoty : ");
						_flushall();
						gets(search_by_category);
						int flag = 0;
						for(i = 0; i<item_count;i++)
						{
							if(strcmp(search_by_category,FC[i].category) == 0)
							{
								printf("\n\n Food Id: %d",FC[i].id);
								printf("\n Food Name : %s",FC[i].food_name);
								printf("\n Food Price : %d",FC[i].price);
								printf("\n Food Category : %s\n",FC[i].category);
								printf("\n_________________________________________________");													
							}
						}
						
					 break;
					}// End Search Case 4
					
				case 11: // Back
				{
					break;
				}
				
				default :
				{
					printf("\n\n INVALID INPUT.....!!");		
				 break;
				}// End Search Case default
			}
			
			printf("\n\n Do you want to Search Another Food (Y/y for Yes) : ");
			scanf(" %c",&ex);
			
		}while(ex == 'Y' || ex == 'y');
		
	}// End  Search Food Details
	
	
	void DeleteFoodDetails()
	{
		flag = 0;
		printf("\n\n Food Details Delete By Id ");
		
		printf("\n\n 1 : Delete ");
		printf("\n 11 : Back ");
		
		printf("\n\n Enter Choice : ");									
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : 
			{
				int delete_by_id;
				printf("\n\n Enter Food Id : ");
				scanf("%d",&delete_by_id);
				
				for(i = 0; i<item_count;i++)
				{
					if(delete_by_id == FC[i].id)
					{
						flag = 1;
						break;
					}
				}
				
				if(flag)
				{
					for(i = 0; i<item_count;i++)
					{
						if(delete_by_id == FC[i].id)
						{
							struct Food_Center temp = FC[i];
							FC[i] = FC[1+i];
							FC[1+i] = temp;		
						}
					}
					FC[i].id = 0;
				}
				else
				{
					printf("\n\n Id is not avaible in database..........!!");
				}
			 break;
			} // End Delete Case
			
			case 11 :
			{
				break;
			} // End back Case
			
			default :
			{
				printf("\n\n INVALID INPUT.........!!");
			} // End Default Case
		}	//switch end							
	}// End Main - Food Details Delete By Id
	
	void PurchaseFood()
	{
		int QTY = 0;
		int i;							
		do
		{	
			flag = 0;									
			printf("\n\n Purchase Food : ");
			
			char purchase_food[100];
		
			printf("\n\n Enter Food Name : ");
			_flushall();
			gets(purchase_food);
			for(i = 0; i<item_count;i++)
			{
				if(strcmp(purchase_food,FC[i].food_name) == 0)
				{																								
					flag = 1;
					break;												
				}																				
			}
			if(flag)
			{
																												
				printf("\n\n Enter food Quntity : ");
				scanf("%d",&QTY);
				
				 if (purchase_item_count >= food_item_capacity) 
				 {
	                food_item_capacity *= 2;
	                purchased_item = (struct Purchased_Item*)realloc(purchased_item, food_item_capacity * sizeof(struct Purchased_Item));
	                if (purchased_item == NULL) 
					{
	                    printf("Memory reallocation failed\n");
	                    exit(1);
	                }
	             }
				
				strcpy(purchased_item[purchase_item_count].food_item_name, purchase_food);
				purchased_item[purchase_item_count].quantity = QTY;
				
				++purchase_item_count;												
			}
			else
			{
				printf("\n\n Food is not Availble in Database..........!!");
			}
		
				
			printf("\n\n Do you want to purchase another food (Y/y for Yes) : ");
			scanf(" %c",&ex);
			
		}while(ex == 'Y' || ex == 'y');
	}

	void DisplayBill()
	{
		printf("\n Bills ");
		printf("\n\n 1 : Bill without GST ");
		printf("\n 2 : Bill with GST ");
		printf("\n 11 :  Back ");
		
		printf("\n\n Enter choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{									
			case 1:  // Bill without GST
				{
					printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
					printf("\n\n----- Bill WithOut GST ");
					
					printf("\t\t\t----- RestoHub -----\t\t");
															
					time_t t = time(NULL);
					printf("\tDate : %s",ctime(&t));
					
					printf("____________________________________________________________________________________________________________________\n");	
				    
				    printf("\n\n\tID\t\tName\t\t\t\t\t\tPrice\t\tQuantity\tTotal\n\n");
				
				    double total_Bill = 0;
				    for (i = 0; i<purchase_item_count; i++)
					 {
					 		char foodName[100];
							strcpy(foodName,purchased_item[i].food_item_name);
					        int quantity = purchased_item[i].quantity;
					        
					         // Find the purchased item in the foodMenu
					        for (int j = 0; j<item_count; j++) 
					        {
					        	 if(strcmp(FC[j].food_name,foodName) == 0)
					        	 {									        	
					                int itemPrice = FC[j].price;
					                int itemTotal = itemPrice * quantity;
					                
					                printf("\n____________________________________________________________________________________________________________________\n\n");	
					
					                printf("\t%-5d\t%-50s\t%-15d\t%-15d\t%-7d\n", FC[j].id, FC[j].food_name, FC[j].price, quantity, itemTotal);
					
					                // Calculate total cost
					                total_Bill += itemTotal;
					                break;
								 }
							}												        
					 }
					printf("____________________________________________________________________________________________________________________\n");	
				    printf("\n\t \t\t\t\t\t\t\t\t\t\t Total \t\t%.2lf",total_Bill);
				    printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
				 break;
				}// End case 1 - Bill without GST
			
		
			case 2 : // Bill with GST
				{
					printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
					printf("\n\n----- Bill With GST ");
					
					printf("\t\t\t---- RestoHub -----\t\t");
															
					time_t t = time(NULL);
					printf("\tDate : %s",ctime(&t));
					
					printf("____________________________________________________________________________________________________________________\n");	
												        	
				    printf("\n\n\tID\t\tName\t\t\t\t\t\tPrice\t\tQuantity\tTotal\n\n");
				    				
				    double Total_Gst_Bill = 0;
				    for (i = 0; i<purchase_item_count; i++)
					 {
					 		char foodName[100];
							strcpy(foodName,purchased_item[i].food_item_name);
					        int quantity = purchased_item[i].quantity;
					        
					         // Find the purchased item in the foodMenu
					        for (int j = 0; j<item_count; j++) 
					        {
					        	 if(strcmp(FC[j].food_name,foodName) == 0)
					        	 {	
								 	printf("\n____________________________________________________________________________________________________________________\n\n");	
					                int itemPrice = FC[j].price;
					                int itemTotal = itemPrice * quantity;
								
					                printf("\t%-5d\t%-50s\t%-15d\t%-15d\t%-7d\n", FC[j].id, FC[j].food_name, FC[j].price, quantity, itemTotal);
									
					                // Calculate total bill
					                Total_Gst_Bill += itemTotal;
					                // Total_Gst_Bill = Total_Gst_Bill + itemTotal;
					                break;
								 }															 
							}												        
					 }												        
				
					int GST_per = 18;
					double tax_amount = (Total_Gst_Bill * GST_per) /100;
					printf("____________________________________________________________________________________________________________________\n");	
					
					printf("\n\t \t\t\t\t\t\t\t\t\t\t Sub Total\t%.2lf",Total_Gst_Bill);
					printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
					printf("\n\n\t \t\t\t\t\t\t\t\t\t\t TAX(%d%%)\t%.2lf",GST_per,tax_amount);
					printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
				
					Total_Gst_Bill = Total_Gst_Bill + tax_amount;
				    printf("\n\n\t \t\t\t\t\t\t\t\t\t\t Total\t\t%.2lf",Total_Gst_Bill);
				    
				 break;
				}// End Case 2 - Bill with GST
				
			case 11: // Back
			{
				break;
			}	
			
			default:
			{
				printf("\n INVALID INPUT............!!");
			 break;
			}//End Default Case of Bill
				
		}// End Switch of BILL
	}
