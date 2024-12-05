#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Person {
    public:
        string name;
        int ticket_number;

        Person(string name, int ticket_number) : name(name), ticket_number(ticket_number) {}
    };

    // function to format ticket numbers to a 3-digit string
    string formatTicketNumber(int ticket_number) {
        string formatted = to_string(ticket_number);
        while (formatted.length() < 3) {
            formatted = "0" + formatted; 
        }
        return formatted;
}

class Queue {
    private:
        queue<Person> personQueue;
        int ticket_counter = 1;

    public:
        // add or enqueue a person
        void enqueue(const string& name) {
            Person person(name, ticket_counter++);
            personQueue.push(person);
            cout << person.name << " added to the queue with Ticket #"
                << formatTicketNumber(person.ticket_number) << "\n";
            cout << "Queue size: " << personQueue.size() << "\n";
        }

        // remove or dequeue a person
        void dequeue() {
            if (!isEmpty()) {
                Person person = personQueue.front();
                personQueue.pop();
                cout << "\nAfter 1 minute..." << endl;
                cout << "Dequeue: " << person.name << " received a ticket (Ticket #"
                    << formatTicketNumber(person.ticket_number) << ")\n"; 
                cout << "Queue size: " << personQueue.size() << "\n";
                if (!isEmpty()) {
                    Person nextPerson = personQueue.front();
                    cout << "Next in line: " << nextPerson.name << " (Ticket #"
                        << formatTicketNumber(nextPerson.ticket_number) << ")\n"; 
                } else {
                    cout << "The queue is now empty.\n";
                }
            } else {
                cout << "The queue is empty. No one to dequeue.\n";
            }
        }

        // check if the queue is empty
        bool isEmpty() const {
            return personQueue.empty();
        }

        // check if a person's position in the queue is by name or ticket number
        void position(const string& input) const {
            if (isEmpty()) {
                cout << "The queue is empty. No one is currently in line.\n";
                return;
            }

            // Check if the input is a number or name
            if (isdigit(input[0])) {
                int ticket_number = stoi(input); 
                positionByTicketNumber(ticket_number);
            } else {
                positionByName(input);
            }
        }

        // method to find a person's position by name
        void positionByName(const string& name) const {
            int pos = 1;
            queue<Person> tempQueue = personQueue;
            while (!tempQueue.empty()) {
                if (tempQueue.front().name == name) {
                    cout << name << " is currently at position " << pos << " in the queue.\n";
                    return;
                }
                tempQueue.pop();
                pos++;
            }
            cout << name << " is not in the queue.\n";
        }

        // method to find a person's position by ticket number
        void positionByTicketNumber(int ticket_number) const {
            int pos = 1;
            queue<Person> tempQueue = personQueue;
            while (!tempQueue.empty()) {
                if (tempQueue.front().ticket_number == ticket_number) {
                    cout << "Ticket #" << formatTicketNumber(ticket_number)
                        << " is currently at position " << pos << " in the queue.\n";
                    return;
                }
                tempQueue.pop();
                pos++;
            }
            cout << "Ticket #" << formatTicketNumber(ticket_number)
                << " is not in the queue.\n";
        }
};

int main() {
    Queue ticketQueue;
    int choice;
    string input;

    auto lastDequeueTime = chrono::steady_clock::now();

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!\n" << endl;
    cout << "\t1. Enqueue a person" << endl;
    cout << "\t2. Check your position in the queue" << endl;
    cout << "\t3. Exit" << endl;

    while (true) {
        auto currentTime = chrono::steady_clock::now();
        auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - lastDequeueTime).count();

        if (elapsedTime >= 60) { 
            if (!ticketQueue.isEmpty()) {
                ticketQueue.dequeue();
                lastDequeueTime = currentTime;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }

        cout << "\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name: ";
                cin >> input;
                ticketQueue.enqueue(input);
                break;
            case 2:
                cout << "Enter your name or ticket number: ";
                cin >> input;
                ticketQueue.position(input);
                break;
            case 3:
                cout << "Exiting the system...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}