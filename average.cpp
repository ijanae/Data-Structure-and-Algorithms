#include <iostream>
using namespace std;

int main() {
    int exam1, exam2, exam3;
    string result;
    
    cout << "Enter the score of Exam 1: ";
    cin >> exam1;
    cout << "Enter the score of Exam 2: ";
    cin >> exam2;
    cout << "Enter the score of Exam 3: ";
    cin >> exam3;
    
    float ave = (exam1+exam2+exam3) / 3.0;
    cout << "Average Score: " << ave << endl;
    
    if (ave>=70) {
        result = "Passed";
    } else {
        result = "Failed";
    }
    
    cout << "Result: " << result << endl;
    
    return 0;
}