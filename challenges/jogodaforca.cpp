#include <iostream>
#include <vector>
#include <random>

namespace wordlist
{
std::vector<std::string> wordlist {
    "amizade", "amor", "infancia", "amada", "livro", "rosa", "principe",
    "janela", "amigo", "felicidade", "amiga", "cor",
    "chuva", "montanha", "viagem", "praia", "caminho",
    "tempo", "historia", "sabedoria", "brisa", "vento",
    "paz", "musica", "alegria", "noite", "luz",
    "sol", "lua", "estrela", "floresta", "neblina",
    "rosto", "sorriso", "olhar", "palavra", "abraço",
    "esperança", "sonho", "verdade", "verso", "riso",
    "coração", "segredo", "tempo", "futuro", "passado",
    "presente", "encanto", "misterio", "viola", "pintura",
    "cores", "cheiro", "comida", "memória", "jardim"
};
}

std::string getword()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, 56);
	int k = distrib(gen);
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
    int cont = 0;
    while(cont == 0)
    {
	std::cout << "Bem vindo ao Jogo da Forca!" << std::endl;
	std::cout << "Ganha se você acertar a palavra em até 5 tentativas. Bom jogo!" << std::endl;

	std::string word = getword();
	bool ver = guesstheword(word);
	if (ver == true)
	{
		std::cout << std::endl << "Ganhou!" << std::endl;
        std::cout << "Digite 1 para jogar novamente ou 0 para sair:" << std::endl;
        std::cin  >> ver;
        std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl << "Perdeu!" << std::endl;
        std::cout << "Digite 1 para jogar novamente ou 0 para sair:" << std::endl;
        std::cin  >> ver;
        std::cout << std::endl;
	}
    };
	return 0;
}
