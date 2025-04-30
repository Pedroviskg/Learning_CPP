//VERSÃO 2
#include <iostream>
#include <vector>
#include "Random.cpp"

namespace wordlist
{
std::vector<std::string> wordlist { "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };
}

std::string getword()
{
	int k = Random::get(0, 8);
	std::string word = wordlist::wordlist[k];
	return word;
}

bool guesstheword(std::string& word)
{
	int size_of_word      = word.size() - 1;
	int number_of_letters = 0;
	int counter = 0;
	bool ganhou = false;
	std::vector<char> complete(0);
	std::vector<char> charchose(1);
	std::vector<char> chances = {'_','+','+','+','+','+'};
	int k = 5;
	

	for (int i = 0; i <= size_of_word; i++)
	{
		complete.push_back('_');
	}
	std::cout << word << std::endl;

	while (counter <= 5)
	{
	int listchar = charchose.size();


	char getletter{};
	bool ver = false;
	bool finished = false;
	bool chose = false;

	std::cin >> getletter;
	for (int i = 0; i <= listchar; i++)
	{
		if (getletter == charchose[i])
		{
			chose = true;
			break;
		}
		if (i == listchar)
		{
		charchose.push_back(getletter);
		};
	}
	if (chose == true)
	{
		std::cout << "Letra já escolhida. Escolha outra." << std::endl;
	}
	else
	{
	for (int i = 0; i <= size_of_word; i++)
	{
		if (getletter == word[i])
		{
			complete[i]= getletter;
			ver = true;
		}
		if (i == size_of_word and ver == false)
		{
			chances[k] = getletter;
			k = k - 1;
		}

	}
	std::cout << "A palavra: ";
	for (int i = 0; i <= size_of_word; i++)
	{
		std::cout << complete[i];
	}
	std::cout << " ";
	for (int i = 1; i <= 5; i++)
	{
		std::cout << chances[i];
	}
	if (ver == false)
	{
	counter = counter + 1;
	}
	for (int i = 0; i <= size_of_word; i++)
	{
		if ('_' == complete[i])
		{
			finished = false;
			break;
		}
		if ('_' != complete[i])
		{
			finished = true;
		}
	}
	if (finished == true)
	{
		ganhou = true;
		break;
	}
	std::cout << std::endl;
	}
	}
return ganhou;
}





int main()
{
	std::cout << "Bem vindo ao Jogo da Forca!" << std::endl;
	std::cout << "Ganha se você acertar a palavra em até 5 tentativas. Bom jogo!";

	std::string word = getword();
	bool ver = guesstheword(word);
	if (ver == true)
	{
		std::cout << std::endl << "Ganhou!" << std::endl;
	}
	else
	{
		std::cout << std::endl << "Perdeu!" << std::endl;
	}
	return 0;
}
