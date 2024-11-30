#include <iostream>
using namespace std;


bool checkIngredient(string ingredient);
void getIngredients(string ingredient);
bool preparePan();
bool cookEggs();
bool toastBread();
void serveBreakfast(string item1, string item2, string item3);
void cleanUpKitchen();
void displayError(string message);

int main() {
    bool eggsAvailable = checkIngredient("eggs");
    bool breadAvailable = checkIngredient("bread");
    bool waterAvailable = checkIngredient("water");
    bool isCooked = false;

    if (eggsAvailable && breadAvailable && waterAvailable) {
        getIngredients("eggs");
        getIngredients("bread");
        getIngredients("water");

        if (!preparePan()) {
            displayError("Error: Unable to prepare pan.");
            return 1; 
        }

        isCooked = cookEggs() && toastBread();
        if (!isCooked) {
            displayError("Error: Cooking failed.");
            return 1;
        }

        serveBreakfast("eggs", "bread", "water");

        cleanUpKitchen();
    } else {
        displayError("Error: Missing ingredients.");
        return 1;
    }

    return 0;
}


bool checkIngredient(string ingredient) {
    return true;
}

void getIngredients(string ingredient) {
    cout << "Getting " << ingredient << endl;
}

bool preparePan() {
    cout << "Pan is prepared." << endl;
    return true;
}

bool cookEggs() {
    cout << "Eggs are cooked." << endl;
    return true;
}

bool toastBread() {
    cout << "Bread is toasted." << endl;
    return true;
}

void serveBreakfast(string item1, string item2, string item3) {
    cout << "Serving " << item1 << ", " << item2 << ", and " << item3 << endl;
}

void cleanUpKitchen() {
    cout << "Kitchen is cleaned." << endl;
}

void displayError(string message) {
    cout << message << endl;
}

