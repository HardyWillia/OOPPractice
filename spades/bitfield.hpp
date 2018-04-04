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

enum Color {
	Black, 
	Red,
};

class Card{
public:

	//Default constructor
	Card() = default;

	Card(Rank r, Suit s, Color c)
	: bits((unsigned)s << 4 | (unsigned)r | (unsigned)c){}

	Rank get_rank() const {
		return(Rank)(0b001111 & bits);
	}

	Suit get_suit() const {
		return(Suit)((0b110000 & bits) >> 4);
	}

	Color get_color() const {
	//	return(Color)(0b000000 & bits);
	}

private:
	unsigned char bits;



};

