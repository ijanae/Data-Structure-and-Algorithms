#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {

    std::sort(deck.begin(), deck.end()); 
    std::deque<int> dq;

    for (int i = deck.size() - 1; i >= 0; --i) {
        if (!dq.empty()) {
            dq.push_front(dq.back()); 
            dq.pop_back();
        }
        dq.push_front(deck[i]); 
    }

    return std::vector<int>(dq.begin(), dq.end());

}

int main() {
    std::cout << "deck = [17, 13, 11, 2, 3, 5, 7] \n";
    std::vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    std::cout << "Output: ";
    std::vector<int> result = deckRevealedIncreasing(deck);

    for (int card : result) {
        std::cout << card << " ";
    }

    return 0;

}