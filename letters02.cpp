/******************************
* Рексиус Анастасия Никитовна *
* ПИ-221                      *
* Частота повторений          *
*******************************/


#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int arrayForOneLetter[200];
  fstream file;
  char letter;
	
  file.open("text.txt");
  if (!file) {
    cout << "Ошибка: файл не найден.";
	return 0;
  }
	
  for (int oneLetterIndex = 0; oneLetterIndex < 200; ++oneLetterIndex) {
	arrayForOneLetter[oneLetterIndex] = 0;
  }
  letter = file.get();
  while (letter != EOF) {
	letter = toupper(letter);
	++arrayForOneLetter[letter];
	letter = file.get();
  }
	
  cout << "Все однобуквенные повторения: " << endl;
  for (letter = 'A'; letter <= 'Z'; ++letter) {
	if (arrayForOneLetter[letter] > 1) {
	  cout << letter << ": " << arrayForOneLetter[letter] - 1 << "\n";
	}
  }
  

  int arrayForTwoLetters[200][200];
  fstream filec;
	
  filec.open("text.txt");
  if (!filec) {
	cout << "Ошибка: файл не найден.";
	return 0;
  }
	
  for (int firstIndex = 0; firstIndex < 200; ++firstIndex) {
	for (int secondIndex = 0; secondIndex < 200; ++secondIndex) {
	  arrayForTwoLetters[firstIndex][secondIndex] = 0;
	}
  }
	
  char firstLetter, secondLetter;
	
  firstLetter = filec.get();
  secondLetter = filec.get();
	
  while (secondLetter != EOF) {
	firstLetter = toupper(firstLetter);
	secondLetter = toupper(secondLetter);
	++arrayForTwoLetters[firstLetter][secondLetter];
	firstLetter = filec.get();
	secondLetter = filec.get();
  }
	
  cout << "Все двухбуквенные повторения: " << endl;
  for (firstLetter = 'A'; firstLetter <= 'Z'; ++firstLetter) {
    for (secondLetter = 'A'; secondLetter <= 'Z'; ++secondLetter) {
      if (arrayForTwoLetters[firstLetter][secondLetter] > 1) {
	      cout << firstLetter << secondLetter << ": " << arrayForTwoLetters[firstLetter][secondLetter] << "\n";
	  }
	}
  }
} 