#pragma once

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
	Little Joker,
	Big Joker
};


enum Suit {
	Spade,
	Diamond,
	Heart,
	Club
};


struct Card(){

	Card(Rank r,  Suit s)
	: rank(r), suit(s) {}


};

//Destructor
~Card(){}


void classification(){

	Card c {Ace, Spades};
