#include <iostream>
using namespace std;
	struct Seat {
    	int seatNumber;
   		int roomNumber;
    	int rollNo;
    	string shift;
    	bool isAllocated;
		};

int main() {
    const int MAX = 50;
    Seat seats[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Classroom Seat Allocation System ---\n";
        cout << "1. Allocate Seat\n";
        cout << "2. View All Seats\n";
        cout << "3. Search Seat\n";
        cout << "4. Update Seat\n";
        cout << "5. Delete Seat\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count >= MAX) {
                cout << "Seat limit reached!\n";
                continue;
            }
            cout << "Enter Seat Number: ";
            cin >> seats[count].seatNumber;
            cout << "Enter Room Number: ";
            cin >> seats[count].roomNumber;
            cout << "Enter Student Roll No: ";
            cin >> seats[count].rollNo;
            cout << "Enter Shift (Morning/Evening): ";
            cin >> seats[count].shift;

            seats[count].isAllocated = true;
            count++;

            cout << "Seat allocated successfully.\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No records found."<<endl;
            }
            for (int i = 0; i < count; i++) {
                cout << "\nSeat No: " << seats[i].seatNumber;
                cout << "\nRoom No: " << seats[i].roomNumber;
                cout << "\nRoll No: " << seats[i].rollNo;
                cout << "\nShift: " << seats[i].shift;
                cout << "\nStatus: " 
                     << (seats[i].isAllocated ? "Allocated" : "Free") << endl;
            }
        }

        else if (choice == 3) {
            int searchSeat;
            cout << "Enter Seat Number to search: ";
            cin >> searchSeat;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (seats[i].seatNumber == searchSeat) {
                    cout << "Seat Found!\n";
                    cout << "Room: " << seats[i].roomNumber << endl;
                    cout << "Roll No: " << seats[i].rollNo << endl;
                    cout << "Shift: " << seats[i].shift << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Seat not found.\n";
        }

        else if (choice == 4) {
            int seatNo;
            cout << "Enter Seat Number to update: ";
            cin >> seatNo;

            bool updated = false;
            for (int i = 0; i < count; i++) {
                if (seats[i].seatNumber == seatNo) {
                    cout << "Enter New Roll No: ";
                    cin >> seats[i].rollNo;
                    cout << "Enter New Shift: ";
                    cin >> seats[i].shift;
                    updated = true;
                    cout << "Seat updated successfully.\n";
                    break;
                }
            }
            if (!updated)
                cout << "Seat not found.\n";
        }

        else if (choice == 5) {
            int seatNo;
            cout << "Enter Seat Number to delete: ";
            cin >> seatNo;

            bool deleted = false;
            for (int i = 0; i < count; i++) {
                if (seats[i].seatNumber == seatNo) {
                    for (int j = i; j < count - 1; j++) {
                        seats[j] = seats[j + 1];
                    }
                    count--;
                    deleted = true;
                    cout << "Seat deleted successfully.\n";
                    break;
                }
            }
            if (!deleted)
                cout << "Seat not found.\n";
        }

        else if (choice == 6) {
            cout << "Exiting program.\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice<6);

    return 0;
}