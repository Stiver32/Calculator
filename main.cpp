#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Helper function to validate numeric input
template <typename T>
void ValidateInput(T& value) {
    while (!(cin >> value) || value <= 0) {
        cout << "Invalid input. Please enter a positive value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// MATERIAL CLASS //
class Material {
public:
    string matName;
    double matCost;
    double matCount;

    Material(const string& name, double cost, double count)
        : matName(name), matCost(cost), matCount(count) {
    }
};

// ITEM CLASS //
class Item {
private:
    string itemName;
    double itemPrice;
    double itemAuctionCut;
    double itemTotal;
    int itemCount;

public:
    // Calculate profit for a crafted item
    double CraftedProfit() {
        vector<Material> materials;
        char addMoreMaterials = 'y';

        cout << "Enter crafted item name: ";
        cin >> itemName;

        cout << "Enter crafted item sell price: ";
        ValidateInput(itemPrice);

        cout << "Enter crafted item count: ";
        ValidateInput(itemCount);

        // Add materials
        while (addMoreMaterials == 'y' || addMoreMaterials == 'Y') {
            string matName;
            double matCost, matCount;

            cout << "Enter material name: ";
            cin >> matName;

            cout << "Enter material cost: ";
            ValidateInput(matCost);

            cout << "Enter material amount: ";
            ValidateInput(matCount);

            materials.emplace_back(matName, matCost, matCount);

            cout << "Add another material? (y/n): ";
            cin >> addMoreMaterials;
            while (addMoreMaterials != 'y' && addMoreMaterials != 'Y' && addMoreMaterials != 'n' && addMoreMaterials != 'N') {
                cout << "Invalid input. Please enter 'y' or 'n': ";
                cin >> addMoreMaterials;
            }
        }

        // Calculate total material cost
        double materialCost = 0.0;
        for (const Material& material : materials) {
            materialCost += material.matCost * material.matCount;
        }

        // Calculate profit
        itemAuctionCut = itemPrice * 0.06;
        itemTotal = (itemPrice - itemAuctionCut) * itemCount - materialCost;

        cout << "Crafted item profit: " << itemTotal << endl;
        return itemTotal;
    }

    void ItemProfit() {
        cout << "Enter item name: ";
        cin >> itemName;

        cout << "Enter item price: ";
        ValidateInput(itemPrice);

        cout << "Enter item count: ";
        ValidateInput(itemCount);

        itemAuctionCut = itemPrice * 0.06;
        itemTotal = (itemPrice - itemAuctionCut) * itemCount;

        cout << "You will receive: " << itemTotal << endl;
    }
};

// Function to calculate total material cost for a project
void CalculateMaterialCost() {
    vector<Material> materials;
    char addMoreMaterials = 'y';

    // Add materials
    while (addMoreMaterials == 'y' || addMoreMaterials == 'Y') {
        string matName;
        double matCost, matCount;

        cout << "Enter material name: ";
        cin >> matName;

        cout << "Enter material cost: ";
        ValidateInput(matCost);

        cout << "Enter material amount: ";
        ValidateInput(matCount);

        materials.emplace_back(matName, matCost, matCount);

        cout << "Add another material? (y/n): ";
        cin >> addMoreMaterials;
        while (addMoreMaterials != 'y' && addMoreMaterials != 'Y' && addMoreMaterials != 'n' && addMoreMaterials != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> addMoreMaterials;
        }
    }

    // Calculate total material cost
    double totalCost = 0.0;
    for (const Material& material : materials) {
        totalCost += material.matCost * material.matCount;
    }

    cout << "Total cost of all materials: " << totalCost << endl;
}

int main() {
    Item item;
    char choice;

    cout << "Auction Helper" << endl;

    do {
        cout << "\nPlease choose an option:" << endl;
        cout << "1. Calculate profit from auctioning an item." << endl;
        cout << "2. Calculate profit from auctioning a CRAFTED item." << endl;
        cout << "3. Calculate cost of materials for a project (materials only)." << endl;
        cout << "Q. Quit" << endl;
        cin >> choice;

        while (!cin || (choice != '1' && choice != '2' && choice != '3' && choice != 'q' && choice != 'Q')) {
            cout << "Invalid input. Please enter 1, 2, 3, or Q: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        switch (choice) {
        case '1':
            item.ItemProfit();
            break;
        case '2':
            item.CraftedProfit();
            break;
        case '3':
            CalculateMaterialCost();
            break;
        case 'q':
        case 'Q':
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (true);

    return 0;
}
