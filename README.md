# RestoHub Documentation

## Overview

RestoHub is a simple restaurant management system written in C. It allows users to manage food items in a restaurant, including adding, updating, deleting, searching, and purchasing food items. The system also generates bills for purchased items with and without GST.

## Getting Started

### Prerequisites

- C compiler (e.g., GCC)

### Compiling the Program

To compile the program, use the following command:
```bash
gcc -o restohub restohub.c
```

### Running the Program

After compiling, run the executable:
```bash
./restohub
```

## Code Structure

### Data Structures

#### `Food_Center`

This structure stores details about food items.
```c
struct Food_Center {
    int id;
    char food_name[100];
    int price;
    char category[100];
};
```

#### `Purchased_Item`

This structure stores details about purchased food items.
```c
struct Purchased_Item {
    char food_item_name[90];
    int quantity;
};
```

### Global Variables

- `struct Food_Center *FC`: Pointer to the array of food items.
- `struct Purchased_Item *purchased_item`: Pointer to the array of purchased items.
- `int purchase_item_count`: Counter for the number of purchased items.
- `int food_item_capacity`: Capacity of the food items array.

### Functions

#### `void switchfunction()`

Displays the main menu and handles user input to call the appropriate functions.

#### `void InsertFoodDetails()`

Allows the user to insert food details. The user can add one or multiple food items at a time.

#### `void DisplayFood()`

Displays all the food items stored in the system.

#### `void UpdateFoodDetails()`

Allows the user to update food details either by ID or by name.

#### `void SearchFoodDetails()`

Allows the user to search for food items by ID, name, price range, or category.

#### `void DeleteFoodDetails()`

Allows the user to delete a food item by ID.

#### `void PurchaseFood()`

Handles the purchasing of food items by the user. It prompts the user to enter the food item name and quantity.

#### `void DisplayBill()`

Generates and displays the bill for the purchased items. The bill can be displayed with or without GST.

## Detailed Function Descriptions

### `void switchfunction()`

This function displays the main menu and prompts the user to choose an action. It uses a `do-while` loop to keep the menu active until the user decides to exit.

### `void InsertFoodDetails()`

This function allows the user to insert food details into the system. It has options to add a single food item or multiple food items at once. It ensures that the array of food items is dynamically resized if the capacity is exceeded.

### `void DisplayFood()`

This function iterates over the array of food items and displays the details of each item.

### `void UpdateFoodDetails()`

This function provides options to update food details by ID or by name. It searches for the food item and allows the user to modify the name, price, and category.

### `void SearchFoodDetails()`

This function provides multiple ways to search for food items, including by ID, name, price range, and category. It displays the details of the found items.

### `void DeleteFoodDetails()`

This function deletes a food item by ID. It searches for the item and sets its ID to 0, effectively removing it from the list.

### `void PurchaseFood()`

This function handles the purchasing of food items. It prompts the user to enter the food item name and quantity, and then stores these details in the purchased items array.

### `void DisplayBill()`

This function generates and displays the bill for the purchased items. It provides options to display the bill with or without GST. It calculates the total amount, including tax if applicable.

## Memory Management

The program dynamically allocates memory for food items and purchased items arrays using `malloc` and `realloc`. It ensures that the memory is freed at the end of the program using `free`.

## Error Handling

The program includes basic error handling for memory allocation failures and invalid user inputs.

## Conclusion

RestoHub is a straightforward restaurant management system designed to help manage food items and generate bills. It demonstrates the use of structures, dynamic memory allocation, and basic file handling in C.

For any issues or contributions, please open an issue or submit a pull request on GitHub.
