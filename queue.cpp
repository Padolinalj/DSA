#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class TicketingSystem {
private:
    queue<pair<string, string>> customers; // Stores customer names and their ticket numbers
    int ticketCounter; // Generates unique ticket numbers

public:
    TicketingSystem() : ticketCounter(1) {}

    void addCustomer(const string& name) {
        string ticketNumber = to_string(ticketCounter);
        // Format ticket number to be three digits
        ticketNumber = string(3 - ticketNumber.length(), '0') + ticketNumber; 
        customers.push(make_pair(name, ticketNumber));
        cout << name << " added to the queue with Ticket #" << ticketNumber << endl;
        cout << "Queue size: " << customers.size() << endl;
        ticketCounter++;
    }

    void serveNext() {
        if (!customers.empty()) {
            auto frontCustomer = customers.front();
            cout << "Dequeue: " << frontCustomer.first << " received a ticket (Ticket #" << frontCustomer.second << ")" << endl;
            customers.pop();
            cout << "Queue size: " << customers.size() << endl;
            if (!customers.empty()) {
                auto nextCustomer = customers.front();
                cout << "Next in line: " << nextCustomer.first << " (Ticket #" << nextCustomer.second << ")" << endl;
            }
        } else {
            cout << "No customers in the queue." << endl;
        }
    }

    void findPosition(const string& identifier) {
        queue<pair<string, string>> tempQueue = customers;
        int position = 0;
        bool found = false;

        while (!tempQueue.empty()) {
            auto entry = tempQueue.front();
            tempQueue.pop();
            position++;
            if (entry.first == identifier || entry.second == identifier) {
                cout << entry.first << " is currently at position " << (position - 1) << " in the queue." << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No match found for the name or ticket number." << endl;
        }
    }
};

int main() {
    TicketingSystem system;
    int choice;
    string name;

    while (true) {
        cout << "\nWelcome to Olivia Rodrigo's Concert Ticketing System!" << endl;
        cout << "1. Enqueue a person" << endl;
        cout << "2. Check your position in the queue" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        
        // Input validation for option
        if (!(cin >> choice)) {
            cin.clear(); // Reset error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Please enter a valid number." << endl;
            continue;
        }

        cin.ignore(); // Clear the newline left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter the name: ";
                getline(cin, name); // Allow names with spaces
                system.addCustomer(name);
                break;
            case 2:
                cout << "Enter your name or ticket number: ";
                getline(cin, name); // Get user input for position checking
                system.findPosition(name);
                break;
            case 3:
                cout << "Thank you for using the ticketing system!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}