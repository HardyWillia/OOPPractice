#pragma once

#include <vector>
#include <iosfwd>

//An enum is 64 bits each, each rank is 4 bits
enum Rank {
	Two, //Special case since using the jokers. Is not used for Hearts and Diamonds
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
	Ace,
	Deuce,
	LJoker,
	BJoker,
};

//Each suit is 2 bits
enum Suit {
	Spades,
	Diamonds,
	Hearts,
	Clubs,
};

//Representation has this layout:
//
//   00ssrrrr (8 bits but only 6 are needed)
//
// where s is a suit bit and r is a rank bit


class Card{
public:

	//Changed struct to implement bitfields for Practice 

	//Default constructor, indeterminant
	//Card(){}

	//Better default constructor 
	Card() = default;

	Card(Rank r,  Suit s)
	: bits((unsigned)s << 4 | (unsigned)r) {}
    
	Rank get_rank() const {
		return(Rank)(0b001111 & bits);
	}

	Suit get_suit() const {
		return(Suit)((0b110000 & bits) >> 4); //have to shift back to keep unsigned format
	}
  
	//Copyable  --working on it 
			

	//Equality
	bool operator==(Card c) const {
		return bits == c.bits;
	}

	bool operator!=(Card c) const{
		return bits != c.bits;
	}

	//Ordering
	bool operator <=(Card c) const {
		return bits <= c.bits;
	}

	bool operator >=(Card c) const {
		return bits >= c.bits;
	}

	//Destructor
	~Card(){}

private:
	unsigned char bits;
};

// A deck is a sequence of cards
// This is called a type alias

//May be written like this:  typedef std::vector<Card> Deck;
using Deck = std::vector<Card>;


