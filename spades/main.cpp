//New file for game of spades

#include "card.hpp"
#include <iostream>


int main() {
	std::cout << "Demo for the card game of spades\n";
	
//  Card c{Ace, Spades};

  Rank r1 = King;
  Rank r2 = Queen;
  std::cout << (r1 == r2) << '\n';
  std::cout << (r1 < r2) << '\n';

}
