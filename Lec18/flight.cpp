/*The program employs a priority queue to efficiently manage the flights based on their departure times and ticket prices. Each flight is represented by its flight number, departure time, and ticket price.
The program offers the following options: Adding a flight, Booking a ticket, Viewing the next available flight, and Exit.*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct Flight {
    string flightNumber;
    int departureTime;
    double ticketPrice;

    bool operator<(const Flight& other) const {
        if (departureTime != other.departureTime)
            return departureTime > other.departureTime;
        return ticketPrice > other.ticketPrice;
    }
};

int main() {
    priority_queue<Flight> flightQueue; 
    while (true) {

        int choice;
        cin >> choice;

        if (choice == 1) {
            string flightNumber;
            cin.ignore();
            getline(cin, flightNumber);

            int departureTime;
            cin >> departureTime;
            double ticketPrice;
            cin >> ticketPrice;

            Flight flight = {flightNumber, departureTime, ticketPrice};
            flightQueue.push(flight);

            cout << "Flight added to the system." << endl;
        } else if (choice == 2) {
            if (flightQueue.empty()) {
                cout << "No flights available." << endl;
            } else {
                Flight nextFlight = flightQueue.top();
                flightQueue.pop();

                cout << "Booked ticket for flight: " << nextFlight.flightNumber << endl;
            }
        } else if (choice == 3) {
            if (flightQueue.empty()) {
                cout << "No flights available." << endl;
            } else {
                Flight nextFlight = flightQueue.top();
                cout << "Next available flight: " << nextFlight.flightNumber << endl;
            }
        } else if (choice == 4) {
            cout << "Exiting the application." << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
            cout << "Exiting the application." << endl;
            break;
        }
    }

    return 0;
}
