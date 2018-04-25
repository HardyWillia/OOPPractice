/*Player information and initial characteristics
 ***Separated this function from intro.hpp to include more player characteristics later
*/

#ifndef PLAYER_H
#define PLAYER_H


struct Player {
public:

	int NumOfPlayers, i, level;
	char name[255];
	char gender[255];
	//boolean MorF;

	//Declare female and male titles
	std::string FemaleTitles[8] = {"Lady", "Baroness", "Countess", "Marquise", "Duchess", "Grand Duchess", 
					"Princess", "* H.R.H. Queen"};
	std::string MaleTitles[8] = {"Lord", "Baron", "Count", "Marquis", "Duke", "Grand Duke",
                                        "Prince", "* H.R.H. King"};

	virtual ~Player() = default;

	virtual void initplayer() { }
	virtual int profile() { }
};

struct PlayerProfile : public Player {
	
	int profile() {
		std::cout << "How many peple want to play? (1 to 6)\n";
		std::cin >> NumOfPlayers;

		if (NumOfPlayers < 1 || NumOfPlayers > 6){
			std::cout << "You do not have a sufficient number of players. Thanks for playing!\n\n";
			std::cin.ignore();
		} 
	
		std::cout << "What will be the difficulty of this game? \n 1. Apprentice \n";
		std::cout << " 2. Journeyman\n 3. Master\n 4. Grand Master\n\n Choose (1, 2, 3, or 4): ";
		std::cin >> level;
		
		if (level < 1)
		     level = 1;
		if(level > 4)
		     level = 4;
		
		//Used to make sure values entered were properly recorded		
		std::cout << "Your level is: " << level << ". You are playing with " << NumOfPlayers << " player(s)\n";

		
		//Loop to initialize players if number of players is greater than 1
		for(i = 0; i < NumOfPlayers; i++){
			std::cout << "\nWho is the ruler of Santa Paravia (city name here)?\n";
			std::cin >> name;

			std::cout << "Are you a man or a woman? (M or F)\n";
                	std::cin >> gender;
			
			if(gender[0] == 'm' || gender[0] == 'M')
				std::cout << "\n" << MaleTitles[0] << " " << name << "\n";
			else 
				std::cout << "\n" << FemaleTitles[0] << " " << name << "\n";	
		}
			
	
	}

	Player* p1;

};

struct InitializePlayer : public Player {
	
	void initplayer() {
		//p1 -> initplayer();

		//Initialize all variables for the first creation of player properties
		int Cathedral = 0;
		int Clergy = 5;
		int CustomsDuty = 25;
		int Difficulty = level;
		int GrainPrice = 25;
		int GrainReserve = 5000;
		int IncomeTax = 5;
		int Justice = 2;
		int Land = 10000;
		float LandPrice = 10.0;
		int Marketplace = 0;
		int Merchants = 25;
		int Mills = 0;
		int Nobles = 4;
		int OldTitle = 1; //may change this
		int Palace = 0;
		float PublicWorks = 1.0;
		int SalesTax = 10;
		int Serfs = 2000;
		int Soldiers = 25;
		int TitleNum = 1; //may change this
		int Treasury = 1000;
		bool isBankrupt = false;
		bool isDead = false;
		bool iWon = false;

		//Death condition
		int YearOfDeath = year + 20 + rand() % 36; 

		return;
	}
		
	int year;
	//int level;
	//int city;

};

#endif
