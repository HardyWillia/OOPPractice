#pragma once

#include <iostream>

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


enum Suit {
	Spades,
	Diamonds,
	Hearts,
	Clubs,
};


struct Card{
public:

	//Changed struct to implement bitfields for Practice 

	//Default constructor
	Card(){}

	Card(Rank r,  Suit s)
	: bits((unsigned)s << 4 | (unsigned)r) {}
    
	Rank get_rank() const {
		return(Rank)(0b001111 & bits);
	}

	Suit get_suit() const {
		return(Suit)((0b110000 & bits) >> 4); //have to shift back to keep unsigned format
	}
  
	//Copyable
		

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

private:
	unsigned char bits;
};

