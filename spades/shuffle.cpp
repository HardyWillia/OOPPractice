#include "bitfield.hpp"

int main() 
{

	//declares an empty vector
	Deck d0{};

	Card c {Ace, Spades}

	//declares a deck to be a sequence of cards
	//Explicitly declares what each card is
	Deck d1 {
		//Spades
		{Ace, Spades}, //Initializes a card object
		{Two, Spades},
		{Three, Spades},
		{Four, Spades},
		{Five, Spades},
		{Six, Spades},
		{Seven,Spades},
		{Eight, Spades},
		{Nine, Spades},
		{Ten, Spades},
		{Jack, Spades},
		{Queen, Spades},
		{King, Spades},


		//Clubs
	        {Ace, Clubs}, //Initializes a card object
                {Two, Clubs},
                {Three, Clubs},
                {Four, Clubs},
                {Five, Clubs},
                {Six, Clubs},
                {Seven, Clubs},
                {Eight, Clubs},
                {Nine, Clubs},
                {Ten, Clubs},
                {Jack, Clubs},
                {Queen, Clubs},
                {King, Clubs}

		//Diamonds
                {Ace, Diamonds}, //Initializes a card object
                {Two, Diamonds},
                {Three, Diamonds},
                {Four, Diamonds},
                {Five, Diamonds},
                {Six, Diamonds},
                {Seven, Diamonds},
                {Eight, Diamonds},
                {Nine, Diamonds},
                {Ten, Diamonds},
                {Jack, Diamonds},
                {Queen, Diamonds},
                {King, Diamonds},

		//Hearts
	        {Ace, Hearts}, //Initializes a card object
                {Two, Hearts},
                {Three, Hearts},
                {Four, Hearts},
                {Five, Hearts},
                {Six, Hearts},
                {Seven, Hearts},
                {Eight, Hearts},
                {Nine, Hearts},
                {Ten, Hearts},
                {Jack, Hearts},
                {Queen, Hearts},
                {King, Hearts},
		
	};

	//int n = rand(); //0...65535 (64K) //Wrong way now

	std::minstd_rand prng; //uniform random bit generator
	shuffle(d1.begin(), d1.end());

	#if 0
	//Dynamically initialize each card
	Deck d1(52);
	for(int s = Spades; s <=Hearts; ++s){
		for(int r = Ace; r <= King; ++r){
	             d1.push_back({static_rank<Rank>(r),
					static_suit<Suit>(s)});

	//Like above, but only one Card object is created. Forwards arguments to be
	// used as arguments to a constructor

	//Use this if creating an object requires dynamic allocation
		    // d1.emplace_back({static_rank<Rank>(r),
                      //                  static_suit<Suit>(s)});
		}
	}

}
