#include <iostream>
#include <iomanip>
using namespace std;

// Recursive function to calculate discount based on price
double calculateDiscount(double price) {
    if (price < 50000) {
        return 0; // No discount for prices below 50000
    } else if (price >= 50000 && price <= 300000) {
        return 5 + calculateDiscount(price - 25000); // Discount increases by 5% for every 25000 increase from 50000 until 300000
    }else if (price > 300000) {
        return 50; // 50% discount for prices over 300000
    } else {
        return 5; // 5% discount for 50000
    }
}

int main() {
    int numberOfItems;

    // Input number of items
    cout << "Enter the number of items: ";
    cin >> numberOfItems;

    // Move dynamic array to store item prices
    double* itemPrices = new double[numberOfItems];

    // Input price for each item
    for (int i = 0; i < numberOfItems; i++) {
        cout << "Enter the price of item " << i + 1 << ": ";
        cin >> itemPrices[i];
    }

    double totalPriceAfterDiscount = 0;
    double discountAmount = 0;

    // Calculate discount and total price after discount
    for (int i = 0; i < numberOfItems; i++) {
        double discount = calculateDiscount(itemPrices[i]);
        double discountAmount = (discount / 100) * itemPrices[i];
        totalPriceAfterDiscount += itemPrices[i] - discountAmount;

        cout << fixed << setprecision(2);
        cout << "Discount for item " << i + 1 << ": ";
        if (discount > 0) {
            cout << discount << "%" << endl;
        } else {
            cout << "No discount" << endl;
        }
    }

    // Output total price after discount
    cout << "Total price after discount: " << fixed << setprecision(2) 
         << "Rp" << totalPriceAfterDiscount << endl;
    cout << setfill('-') << setw(35) << '-' << endl;

    // Option to calculate again
    int goAgain;
    cout << "Want to calculate another discount? (1 for yes, other for no)" << endl;
    cin >> goAgain;
    if (goAgain == 1) {
        cout << setfill('-') << setw(35) << '-' << endl;
        main();
    } else {
        cout << "---PROGRAM END" << setfill('-') << setw(55) << endl;
        cout << setfill(' ');
    }

    // Delete memory
    delete[] itemPrices;
    return 0;
}
