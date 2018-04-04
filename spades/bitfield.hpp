//Start of bitfield card class

#include "shuffle.hpp"
#include <cassert>
#include <iosfwd>
#include <vector>


enum Rank {

	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};


enum Suit {
	Spades,
	Clubs,
	Diamonds,
	Hearts,
};

enum Largeness {
	Big, 
	Little,
};


class Card{
public:

	//Default constructor
	Card() = default;

	//The bitcard representation is 
	// jjssrrrr
	//Before the 2 high order bits were unused, here they are used


	Card(Rank r, Suit s, Largeness l)
	: bits((unsigned)s << 4 | (unsigned)r | (unsigned)l){}

	Rank get_rank() const {
		return(Rank)(0b001111 & bits);
	}

	Suit get_suit() const {
		return(Suit)((0b110000 & bits) >> 4);
	}

	Largeness get_size() const {
	//	return(Largeness)(1b000000 & bits); I'm not sure if this is right yet
	}

private:
	unsigned char bits;

};


using BitDeck = std::vector<Card>;

BitDeck get_bit_deck();

