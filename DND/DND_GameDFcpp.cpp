#include<iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // rand and srand
#include <windows.h> // used for sleep
#include <ctime>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

// Main classes to choose from.

struct Elf
{
	string name = " ";
	string race = "ElF";

	int level = 1;
	int EHealth = 100;
	int p_attack = rand() % 80 + 10;
	int m_attack = rand() % 90 + 10;

};

struct Dwarf
{
	string name = " ";
	string race = "Dwarf";

	int level = 1;
	int DHealth = 120;
	int p_attack = rand() % 100 + 10;
	int m_attack = rand() % 80 + 10;
};

struct Goblin
{
	string name = " ";
	string race = "Goblin";

	int level = 1;
	int GHealth = 100;
	int p_attack = rand() % 80 + 10;
	int m_attack = rand() % 70 + 10;
};

struct Human
{
	string name = " ";
	string race = "Human";

	int level = 1;
	int HHealth = 100;
	int p_attack = rand() % 80 + 10;
	int m_attack = rand() % 80 + 10;
};

struct Monster
{
	std::string name;
	int health = rand() % 150 + 100;
	int attackPower = rand() % 60 + 10;

};

//Functions to display character options
void showRaceoptions()
{
	std::cout << "What race is your character: \n";
	std::cout << "Elf \n";
	std::cout << "Dwarf \n";
	std::cout << "Golbin \n";
	std::cout << "Human \n";
}

void LoadingScreen()
{
	std::cout << ".";
	Sleep(650);
	std::cout << ".";
	Sleep(650);
	std::cout << ".";
	Sleep(650);
	std::cout << ".";
	Sleep(650);
	std::cout << ".";
	Sleep(650);
	std::cout << ".";
	Sleep(650);
	std::cout << ".\n";
	Sleep(750);
}

// Options to select a character ( why did I make a function? tbh according to videos on youtube and class it seemed best to store a dynamic choice.
int selectRace()
{
	int choice;
	do
	{
		std::cout << "What is the race of your hero: ";
		std::cin >> choice;
		if (choice < 1 || choice > 4)
		{
			std::cout << "Sorry but we don't have any characters in that range\n";
			Sleep(1000);
			std::cout << "Plese try again: ";
			std::cin >> choice;
		}
	} while (choice < 1 || choice > 4);

	return choice;
}
//Monster creation ( they are all stored in the one stuct to generate instead of listing them one by one) (remember this denzel)

Monster generateMonster()
{
	Monster monster;
	//Array of random monster names
	std::string monsternames[] = { "Behemoth", "Flan", "Cactuar", "Bahamut", "Goblin", "Orc", "Denzel", "JOE BIDEN" };
	srand(time(NULL));
	int index = rand() % 8;
	//randomly pick one of the names for the player to fight
	monster.name = monsternames[index];
	monster.health = rand() % 101 + 200; //Health between 100 and 300 I think
	monster.attackPower; // Monster attack power from 21 to uhh goodbye
	return monster;
}

// I don't know why I added this if condition maybe for dramatic effect??????????

int endorstart()
{
	char endorstart;
	do
	{
		std::cout << "Y/N: ";

		std::cin >> endorstart;
		endorstart = std::toupper(endorstart);
		if (endorstart == 'Y')
		{
			std::cout << "=]";
			Sleep(500);
		}
		else if (endorstart == 'N')
		{
			std::cout << "=[\n";
			Sleep(2000);
			std::cout << "Fine";
			exit(0);
		}
		else if (endorstart != 'Y' && endorstart != 'N' && endorstart != 'y' && endorstart != 'n')
		{
			std::cout << "Invalid Choice. Please enter Y or N\n";
			std::cin >> endorstart;
		}

	} while (endorstart != 'Y' && endorstart != 'N' && endorstart != 'y' && endorstart != 'n');

	return endorstart;
}

int main()

{
	//LORE PT 1
	cout << "Game Master: \n";
	Sleep(1300);
	cout << "The adventurers are summoned to the small town of Oakwood by the desperate pleas of its residents. \n"; \
		Sleep(1300);
	cout << "Strange shadows have been sighted near the ancient Citadel of Arinthia, long abandoned and shrouded in mystery.\n";
	Sleep(1300);
	cout << "The townsfolk fear that dark forces have awakened within the citadel and threaten their home.\n";
	Sleep(1300);
	cout << "As the adventurers arrive in Oakwood, they are greeted by Mayor Thalia, who pleads for their help in investigating the source of the shadows. \n";
	Sleep(1300);
	cout << "Suddenly as if it was by sheer luck or a miracle there is a beam of light then you see a figure walking through\n";
	cout << "Will"; Sleep(700); cout << " You"; Sleep(700);  cout << " Head"; Sleep(700);  cout << " The"; Sleep(700);  cout << " Call!\n";
	endorstart();

	LoadingScreen();
	//Displaying characters and character selection.
	Elf elf;
	Dwarf dwarf;
	Goblin goblin;
	Human human;
	Monster monster;

	//Pre battle system values
	int playerHealth{};
	string playerName;
	int playerPAttack;
	int playerMAttack;
	int monsterHealth{};
	int playerChoice;
	int monsterAP = rand() % 10 + 40;


	//int monsterHP = monster.health;
	//int monsterAP = monster.attackPower;

	showRaceoptions();
	int choice = selectRace();

	switch (choice)
	{
	case 1:

		std::cout << "Enter your Elf's name: ";
		std::cin >> elf.name;
		playerName = elf.name;
		playerHealth = elf.EHealth;
		playerPAttack = elf.p_attack;
		playerMAttack = elf.m_attack;

		break;

	case 2:
		std::cout << "Enter your Dwarf's name: ";
		std::cin >> dwarf.name;
		playerName = dwarf.name;
		playerHealth = dwarf.DHealth;
		playerPAttack = dwarf.p_attack;
		playerMAttack = dwarf.m_attack;
		break;

	case 3:
		std::cout << "Enter your Goblin's name: ";
		std::cin >> goblin.name;
		playerName = goblin.name;
		playerHealth = goblin.GHealth;
		playerPAttack = goblin.p_attack;
		playerMAttack = goblin.m_attack;

		break;

	case 4:
		std::cout << "Enter your Human's name: ";
		std::cin >> human.name;
		playerName = human.name;
		playerHealth = human.HHealth;
		playerPAttack = human.p_attack;
		playerMAttack = human.m_attack;
		break;
	}
	int playerclass = choice;
	//Loading
	std::cout << "Creating Character";
	Sleep(800);

	LoadingScreen();

	std::cout << "Character Created\n";

	//LORE 2
	std::cout << "Upon reaching the outskirts of the citadel, you are greeted by an eerie silence, \n";
	Sleep(1300);
	std::cout << "Broken only by the occasional rustle of leaves and the distant sound of creaking stone. \n";
	Sleep(2000);

	//Battle system
	//Monster Initilizated
	monster = generateMonster();
	monsterHealth = monster.health;
	monsterAP = monster.attackPower;

	std::cout << "A wild " << monster.name << " appears! \n";
	Sleep(2000);
	std::cout << "Between you and " << monster.name << " woukd you win? \n";
	Sleep(1300);
	std::cout << playerName << ""; Sleep(1500);
	std::cout << ":Nah I'd win \n";
	Sleep(3000);
	while (playerHealth >= 0 && monsterHealth >= 0)
	{
		playerMAttack = rand() % 75 + 1;
		playerPAttack = rand() % 75 + 1;
		monsterAP = rand() & 60 + 10;

		std::cout << "Player Health: " << playerHealth << "      Monster Health: " << monsterHealth << "\n";
		Sleep(1100);
		cout << "1. P.Attack" << "\n";
		cout << "2. M.Attack" << "\n";

		cin >> playerChoice;

		switch (playerChoice)
		{
		case 1:
			//players physically attacking
			Sleep(1100);
			std::cout << playerName << " attacked ";
			monsterHealth -= playerPAttack;
			std::cout << playerPAttack << " damage!\n";
			break;
		case 2:
			//players magically attacking
			Sleep(1100);
			std::cout << playerName << " cast fireball ";
			monsterHealth -= playerMAttack;
			std::cout << playerMAttack << " damage!\n";
			break;

		default:
			cout << "Invalid choice\n";
			break;
		}


		int computerChoice = 1;
		switch (computerChoice)
		{
		case 1:
			Sleep(1100);
			std::cout << monster.name << " attacked dealing " << monsterAP << " damage  \n";
			playerHealth = playerHealth - monsterAP;

		}
	}
	if (monsterHealth <= 0)
	{
		Sleep(1500);
		cout << "You have successfully defeated " << monster.name << "\n";
		Sleep(1300);
		std::cout << "Game Master: \n";
		std::cout << "With " << monster.name << " defeated and the shadows dispelled, the adventurers emerge from the citadel victorious \n";
		Sleep(1300);
		std::cout << "their bravery celebrated by the grateful townsfolk of Oakwood.  \n";
		Sleep(1300);
		std::cout << "As they depart, the adventurers carry with them the knowledge that even in the darkest of places, heroes will always rise to the challenge.\n";
	}
	if (playerHealth <= 0)
	{
		Sleep(1500);
		std::cout << "In the end the great  " << playerName << "  was nothing but a fluke whom thought that they could gain wealth fame and power attempting this quest\n";
		Sleep(800);
		std::cout << "Also";
		Sleep(1300);
		LoadingScreen();
		std::cout << "Nah"; Sleep(2000);
		std::cout << " You'd lose\n";
		Sleep(1300);

	}
	if (monsterHealth && playerHealth == 0)
	{
		std::cout << "While there was a valuent effort from both  \n" << playerName << " and " << monster.name << " but in the end Denzel was the real winner";
	}

	std::ofstream outputFile("Status.txt");

	if (outputFile.is_open())
	{
		outputFile << "Here are your status for you adventure: \n";
		outputFile << "Player: " << playerName << "as" << playerclass << "\n";
		if (playerHealth <= 0)
		{
			outputFile << "While you tried your best to complete this quest you were without a shadow of a doubt a FRAUD!!\n";
		}
		if (monsterHealth <= 0)
		{
			outputFile << "Wait huh how did you win, I made it so that you weere supposed to die nooooo!!\n";
		}
		if (monsterHealth && playerHealth == 0)
		{
			std::cout << "While there was a valuent effort from both  \n" << playerName << " and " << monster.name << " but in the end Denzel was the real winner\n";
		}
		outputFile.close();
		std::cout << "Data stored in Status.txt\n";
	}

}