//Start of bitfield card class

#include <cassert>
#include <iosfwd>

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

	Card(Rank r, Suit s, Largeness l)
	: bits((unsigned)s << 4 | (unsigned)r | (unsigned)l){}

	Rank get_rank() const {
		return(Rank)(0b001111 & bits);
	}

	Suit get_suit() const {
		return(Suit)((0b110000 & bits) >> 4);
	}

	Largeness get_size() const {
	//	return(Largeness)(0b000000 & bits);
	}

private:
	unsigned char bits;



};

