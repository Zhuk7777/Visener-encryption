#include<iostream>
#include<string>

std::string getAppropriateWordLength(std::string word, int length)
{
	std::string newWord = "";
	for (int i = 0; i < length; i++)
		newWord += word[(i % word.length())];
	return newWord;
}

std::string encrypt(std::string key, std::string word)
{
	if (word.length() != key.length())
		key = getAppropriateWordLength(key, word.length());

	std::string code = "";
	for (int i = 0; i < word.length(); i++)
		code+= ((((word[i] - 'A') + (key[i] - 'A')) % 26)+ 'A');

	return code;
}

std::string decrypt(std::string key, std::string code)
{
	if (code.length() != key.length())
		key = getAppropriateWordLength(key, code.length());

	std::string word = "";
	for (int i=0;i<code.length(); i++)
		word+= ((((code[i] - 'A') + 26 - (key[i] - 'A')) % 26) + 'A');

	return word;
}

int main()
{
	std::string key = "BOARD";
	std::string word;

	std::cout << "Enter the word: ";
	std::cin >> word;

	word = encrypt(key, word);
	std::cout << "\nEncrypted word: " << word;

	word = decrypt(key, word);
	std::cout << "\nDeciphered word: " << word;

	return 0;
}