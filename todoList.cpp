#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> to_do;
    string task;
    char choice;

    cout << "Your To-Do List is empty.\n" << endl;

    do {
        cout << "Add a task: ";
        getline (cin, task);
        to_do.push_back(task);

        cout << "Add another task? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    cout << "\nYour To-Do List:" << endl;
    for (int i = 0; i < to_do.size(); i++) {
        cout << i << ": " << to_do[i] << endl;
    }

    int num;
    cout << "\nMark a task completed by entering its number: ";
    cin >> num;

    if (num > 0 && num < to_do.size()) {
        cout << "Task \"" << to_do[num] << "\" marked as completed." << endl;
        to_do.erase(to_do.begin() + num);
    } else {
        cout << "Invalid task number." << endl;
    }

    cout << "\nUpdated To-Do List:" << endl;
    for (int i = 0; i < to_do.size(); i++) {
        cout << i << ": " << to_do[i] << endl;
    }

    return 0;
}