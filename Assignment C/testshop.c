#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct Product {
	char* name;
	double price;
};
 
struct ProductStock {
	struct Product product;
	int quantity;
};
 
struct Shop {
	double cash;
	struct ProductStock stock[20];
	int index;
};


 
struct Customer {
	char* name;
	double budget;
	struct ProductStock shoppingList[10];
	int index;
};
 
void printProduct(struct Product p)
{
	printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
	printf("-------------\n");
}
 
struct Shop createAndStockShop()
{
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
 
    fp = fopen("mppstock.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

	getline(&line, &len, fp);
	double cashInShop = atof(line);
	struct Shop shop = { cashInShop };
 
    while ((read = getline(&line, &len, fp)) != -1) {
		char *n = strtok(line, ",");
		char *p = strtok(NULL, ",");
		char *q = strtok(NULL, ",");
		int quantity = atoi(q); // takes a quantity and makes it into a whole number
		double price = atof(p); // takes a number and makes it into a float number
		char *name = malloc(sizeof(char) * 50); //allocating memory
		strcpy(name, n);
		struct Product product = { name, price };
		struct ProductStock stockItem = { product, quantity };
		shop.stock[shop.index++] = stockItem;
    }
 
	return shop;
}
 
void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cash);
	printf("--------------------------\n");
	for (int i = 0; i < s.index; i++)
	{
		struct Product product = s.stock[i].product;
        printProduct(product);
		printf("The shop has %d of the above\n", s.stock[i].quantity);
		printf("--------------------------\n");
	}
}

struct Customer customerOrder1()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
 
    fp = fopen("mppcustomer1.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

	read = getline(&line, &len, fp);
    char *a = strtok(line, ",");
    char *b = strtok(NULL, ",");
    char *cust1Name = malloc(sizeof(char) * 50);
    double cust1Budget = atof(b);
    strcpy(cust1Name, a); 
	struct Customer customer1 = { cust1Name, cust1Budget};
	printf("\n");
	printf("Customer name is: %s and they have: %.2f for their budget\n%s's Shopping List\n--------------------------\n", cust1Name, cust1Budget, cust1Name);
	

    while ((read = getline(&line, &len, fp)) != -1) {
		char *n = strtok(line, ",");
		char *q = strtok(NULL, ",");
		int quantity = atoi(q); // takes a quantity and makes it into a whole number
		    //double price = atof(p); // takes a number and makes it into a float number
		char *ProductStock = malloc(sizeof(char) * 50); //allocating memory
		strcpy(ProductStock, n);
		struct Product product = { ProductStock};
		struct ProductStock shoppingList = { product, quantity };
		customer1.shoppingList[customer1.index++] = shoppingList;
    	printf("%d %s\n", quantity, ProductStock);
	}        
	return customer1;
}

//void printCustomer(struct Customer customer1)
//{
	//printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", customer1.cust1Name, customer1.cust1budget);
	//printf("-------------\n");
	//for(int i = 0; i < c.index; i++)
//	{
	//	printProduct(customer1.shoppingList[i].product);
		//printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);
		//double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price;
		// ProductStock s = c.shoppingList[i];
		// Product p = s.product;
		// double cost = s.quantity * p.price;
		
		//printf("The cost to %s will be �%.2f\n", cust1Name, cost);
//	}
//}



struct Customer customerOrder2()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
 
    fp = fopen("mppcustomer2.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

	read = getline(&line, &len, fp);
    char *a = strtok(line, ",");
    char *b = strtok(NULL, ",");
    char *cust2Name = malloc(sizeof(char) * 50);
    double cust2Budget = atof(b);
    strcpy(cust2Name, a); 
	struct Customer customer2 = { cust2Name, cust2Budget};
	printf("\n");
    printf("Customer name is: %s and they have: %.2f for their budget\n%s's Shopping List\n--------------------------\n", cust2Name, cust2Budget, cust2Name);
	
    while ((read = getline(&line, &len, fp)) != -1) {
		    // TODO process remaining lines
            // printf("Retrieved line of length %zu:\n", read);
            // printf("%s IS A LINE", line);
		char *n = strtok(line, ",");
		    //char *p = strtok(NULL, ",");
		char *q = strtok(NULL, ",");
		int quantity = atoi(q); // takes a quantity and makes it into a whole number
		    //double price = atof(p); // takes a number and makes it into a float number
		char *ProductStock = malloc(sizeof(char) * 50); //allocating memory
		strcpy(ProductStock, n);
		struct Product product = { ProductStock};
		struct ProductStock shoppingList = { product, quantity };
		customer2.shoppingList[customer2.index++] = shoppingList;
        printf("%d %s\n", quantity, ProductStock);
	}        
	return customer2;
}

double findProductPrice(struct Shop s, char *n)
{
    for (int i = 0; i < s.index; i++)
	{
		struct Product product = s.stock[i].product;
        char *name = product.name;
        if (strcmp(name,n) == 0)
        {
            return product.price;
        }
	}
    return -1;
}

//double totalCostForCustomer1 = 0;
//	for(int i=0; i < 3; i++){
//		struct Product p = array[i].product;
//		double price = find(shop, p.name);
//		printf("The price of %s in the shop is %.2f\n", p.name, price);
//		double totalCostOfItem = array[i].quantity * price;
//		printf("You want %d of %s, that will cost you %.2f\n", array[i].quantity, p.name, totalCostOfItem);
//		totalCostForCustomer1 += totalCostOfItem;
//	}
//	printf("The total cost for the customer will be %.2f\n", totalCostForCustomer);
 
int main(void) 
{
 
	struct Shop shop = createAndStockShop();
	printShop(shop);

    struct Customer customer1 = customerOrder1();
	//printf("Customer name is: %s and they have: %.2f for their budget\n", customer1.name, customer1.budget);

    struct Customer customer2 = customerOrder2();
	//printf("Customer name is: %s and they have: %.2f for their budget\n", customer2.name, customer2.budget);
    
	// struct Product productA = { "Coke Can", 0.0 };
	// struct Product productB = { "Bin Bags", 0.0 };
	// struct Product productC = { "Spaghetti", 0.0 };
	// struct ProductStock StockA = { productA, 12};
	// struct ProductStock StockB = { productB, 5};
	// struct ProductStock StockC = { productC, 2};

	// struct ProductStock array[]= {StockA,StockB,StockC};

	// double totalCostForCustomer = 0;
	// for(int i=0; i<3; i++){
	// 	struct Product p= array[i].product;
	// 	double price = find(shop, p.name);
	// 	printf("The price of %s in the shop is %.2f\n", p.name, price);
	// 	double totalCostOfItem = array[i].quantity * price;
	// 	printf("You want %d of %s, that will cost you %.2f\n", array[i].quantity, p.name, totalCostOfItem);
	// 	totalCostForCustomer += totalCostOfItem;
	// }

	// printf("The total cost for the customer will be %.2f\n", totalCostForCustomer);

    //printCustomer(customer);

    //double price = findProductPrice(shop, "Coke Can");
    //printf("%.2f\n", price);
 
 
    return 0;
}