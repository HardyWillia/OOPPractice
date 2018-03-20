/*Changes introductory information and functions of the game
	* Initial instructions that are printed to the screen (PrintIntructions 
		* Make these mandatory maybe?
*/

#ifndef INTRODUCTION_H
#define INTRODUCTION_H

struct Introduction {
public:
	char instructions[4];
	
	void Intro() {
		std::cout << "Santa Paravia and Fiumaccio\n";
		std::cout << "\nWould you like instructions? (Y or N)\n";

		std::cin >> instructions;
		
		if(instructions[0] == 'y' || instructions[0] == 'Y'){

    			std::cout << "\n\nSanta Paravia and Fiumaccio\n\n";
    			std::cout <<"You are the ruler of a 15th century Italian city state.\n";
    			std::cout <<"If you rule well, you will receive higher titles. The\n";
    			std::cout <<"first player to become king or queen wins. Life expectancy\n";
    			std::cout <<"then was brief, so you may not live long enough to win.\n";
    			std::cout <<"The computer will draw a map of your state. The size\n";
    			std::cout <<"of the area in the wall grows as you buy more land. The\n";
    			std::cout <<"size of the guard tower in the upper left corner shows\n";
    			std::cout <<"the adequacy of your defenses. If it shrinks, equip more\n";
    			std::cout <<"soldiers! If the horse and plowman is touching the top of the wall,\n";
    			std::cout <<"all your land is in production. Otherwise you need more\n";
    			std::cout <<"serfs, who will migrate to your state if you distribute\n";
    			std::cout <<"more grain than the minimum demand. If you distribute less\n";
    			std::cout <<"grain, some of your people will starve, and you will have\n";
    			std::cout <<"a high death rate. High taxes raise money, but slow down\n";
    			std::cout <<"economic growth. (Press ENTER to begin game)\n\n\n";	
	
		std::cin.ignore();
		
		}
}

	//~Intro() {} --not using this properly yet


};

#endif
