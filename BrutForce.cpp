#include <iostream>
#include <chrono>

std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // all characters to check
std::string password;


void userPassword()
{
	std::cout << "Enter the password to crack: ";
	
	std::cin >> password;
}



void BrutForce()
{
	// put as many "first letters" as letters in "password"
	std::string passwordToCheck(password.size(), characters.front());

	// check every combination of password
	int index_letters = 0; // index to search in "characters" string
	size_t lastLetter; // hold the position of the last letter of "characters" in the passwordToCheck

	auto start = std::chrono::steady_clock::now(); // start the chrono
	
	while (passwordToCheck != password)
	{
		passwordToCheck.back() = characters[index_letters]; // put the next letter
		index_letters++;

		lastLetter = passwordToCheck.find(characters.back()); // check if the last letter is reached
		
		while (lastLetter != std::string::npos) // if there is the last letter
		{
			passwordToCheck[lastLetter] = characters.front(); // put the first letter
			passwordToCheck[lastLetter - 1] = characters[characters.find(passwordToCheck[lastLetter - 1])+1]; // increase of one letter the previous letter
			lastLetter = passwordToCheck.find(characters.back()); // recheck another time
			index_letters = 0; 
		}
		
	}
	auto end = std::chrono::steady_clock::now(); // stop the chrono
	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << "time : " << elapsed_seconds.count() << " seconds";
	
}

int main()
{
	userPassword();
	BrutForce();

	return 0;
}