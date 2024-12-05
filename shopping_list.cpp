#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct shoppingList {
    vector<string> name;
    vector<vector<string>> item;
};

void displayProduct();

shoppingList product;

void addCategory() {
    string nameInput;
    
    cout << "\nAdd a category: ";
    getline (cin, nameInput);
    product.name.push_back(nameInput);
    
    vector<string> itemInput;
    char addMore;

    string items;
    cout << "Add an item: ";
    getline (cin, items);
    itemInput.push_back(items);
        
    do {
        cout << "Add more items? (y/n): ";
        cin >> addMore;
        cin.ignore();
        
        if (addMore == 'Y' || addMore == 'y') {
            cout << "Add an item: ";
            getline (cin, items);
            itemInput.push_back(items);
        } else if (addMore == 'N' || addMore == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter (y/n)." << endl;
        }
    } while (true);
    
    product.item.push_back(itemInput);
    displayProduct();
}

void emptyList () {
    cout << "Things to Buy:" << endl;
    cout << "\nYou have an empty list." << endl;
    
    while (true) {
        char choice;
        cout << "Do you want to add a category? (y/n): ";
        cin >> choice;
        cin.ignore();
    
        if (choice=='Y' || choice=='y') {
            addCategory();
            break;
        } else if (choice=='N' || choice=='n') {
            exit(0);
        } else {
            cout << "Invalid input. Please enter (y/n)." << endl;
        }
    } 
}

void displayProduct() {
    cout << "\nThings to Buy:" << endl;
    
    for (int i = 0; i < product.name.size(); i++) {
        cout << product.name[i] << ":" << endl;
        for (int j = 0; j < product.item[i].size(); j++) {
            cout << j + 1 << ". " << product.item[i][j] << endl;
        }    
        cout << endl;
    }
}

void editCategory() {
    cout << "\nYour shopping list categories:" << endl;
    for (int i = 0; i < product.name.size(); i++) {
        cout << i + 1 << ". " << product.name[i] << endl;
    }
    
    int category;
    while (true) {
        cout << "Choose a category to edit (enter the number): ";
        cin >> category;
        cout << endl;
        
        if (category < 1 || category > product.name.size()) {
            cout << "Invalid category number." << endl;
        } else {
            break;
        }
    }
    
    int c;
    cout << "Press 1 to edit category name." << endl;
    cout << "Press 2 to edit item name." << endl;
    cout << "Press 3 to add more items." << endl;
    cout << "Press 4 to delete an item." << endl;
    cout << "Press 5 to cancel." << endl;
    cout << "Enter your choice: ";
    cin >> c;
    cout << endl;
    
    switch (c) {
        case 1: { 
            string newName;
            
            cout << "Enter new name for category \"" << product.name[category - 1] << "\": ";
            cin.ignore(); 
            getline(cin, newName);
            product.name[category - 1] = newName;

            cout << "Category name updated successfully." << endl;
            displayProduct();
            break;
        }
        case 2: { 
            cout << "Items in " << product.name[category - 1] << ":" << endl;
            for (int i = 0; i < product.item[category - 1].size(); i++) {
                cout << i + 1 << ". " << product.item[category - 1][i] << endl;
            }

            int itemToEdit;
            while (true) {
                cout << "\nChoose an item to edit (enter the number): ";
                cin >> itemToEdit;

                if (itemToEdit < 1 || itemToEdit > product.item[category - 1].size()) {
                    cout << "Invalid item number." << endl;
                } else {
                    break;
                }
            }

            string newItemName;
            cout << "Enter new name for item \"" << product.item[category - 1][itemToEdit - 1] << "\": ";
            cin.ignore();
            getline(cin, newItemName);
            product.item[category - 1][itemToEdit - 1] = newItemName;

            cout << "Item name updated successfully." << endl;
            displayProduct();
            break;
        }
        case 3: {  
            string items;
            cout << "Add an item to " << product.name[category - 1] << ": ";
            cin.ignore();
            getline(cin, items);
            product.item[category - 1].push_back(items);

            char addMore;
            do {
                cout << "Add more items? (y/n): ";
                cin >> addMore;
                cin.ignore();
                
                if (addMore == 'Y' || addMore == 'y') {
                    cout << "Add an item: ";
                    getline (cin, items);
                    product.item[category - 1].push_back(items);
                } else if (addMore == 'N' || addMore == 'n') {
                    break;
                } else {
                    cout << "Invalid input. Please enter (y/n)." << endl;
                }
            } while (true);
            
            displayProduct();
            break;
        }
        case 4: {  
            cout << "Items in " << product.name[category - 1] << ":" << endl;
            for (int i = 0; i < product.item[category - 1].size(); i++) {
                cout << i + 1 << ". " << product.item[category - 1][i] << endl;
            }
            
            int itemToDelete;
            cout << "\nChoose an item to delete (enter the number): ";
            cin >> itemToDelete;
            
            if (itemToDelete > 0 && itemToDelete <= product.item[category - 1].size()) {
                product.item[category - 1].erase(product.item[category - 1].begin() + (itemToDelete - 1));
                cout << "Item deleted successfully." << endl;
            } else {
                cout << "Invalid item number." << endl;
            }
            
            displayProduct();
            break;
        }
        case 5:  
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}

void deleteCategory() {
    cout << "\nYour shopping list categories:" << endl;
    for (int i = 0; i < product.name.size(); i++) {
        cout << i + 1 << ". " << product.name[i] << endl;
    }
    
    int category;
    while (true) {
        cout << "Choose a category to delete (enter the number): ";
        cin >> category;
    
        if (category < 1 || category > product.name.size()) {
            cout << "Invalid category number." << endl;
        } else {
            break;
        }
    }
    
    char choice; 
    do {
        cout << "Are you sure you want to delete all lists for " << product.name[category - 1] << "? (y/n): ";
        cin >> choice;
        
        if (choice=='Y' || choice=='y') {
            product.name.erase(product.name.begin() + (category - 1)); 
            product.item.erase(product.item.begin() + (category - 1));
            cout << "Deletion successful." << endl;
            
            if (product.name.empty()) {
                cout << endl;
                emptyList();
            } else {  
                displayProduct();
            }
            
            break;
        } else if (choice=='N' || choice=='n') {
            cout << "Deletion Cancelled.";
            break;
        } else {
           cout << "Invalid input. Please enter (y/n)." << endl;
        }
    } while (true);
}

int main() {
    emptyList(); 

    int c;
    
    do {
        cout << "Press 1 to view the shopping list." << endl;
        cout << "Press 2 to add a category." << endl;
        cout << "Press 3 to edit a category." << endl;
        cout << "Press 4 to delete a category." << endl;
        cout << "Press 5 to exit the program." << endl;
    
        cout << "Enter your choice: ";
        cin >> c;
        cin.ignore();

        switch (c) {
            case 1:
                displayProduct();
                break;
            case 2:
                addCategory();
                break;
            case 3: 
                editCategory();
                break;
            case 4:
                deleteCategory();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid input. Choose number (1-5) only.\n" << endl;
        } 
    } while (true);
    
    return 0;
}