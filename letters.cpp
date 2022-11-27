/******************************
* Рексиус Анастасия Никитовна *
* ПИ-221                      *
* Частота повторений          *
*******************************/


#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int oneLetter[200];
  fstream file;
  char letter;
	
  file.open("text.txt");
  if (!file) {
      cout << "Ошибка: файл не найден.";
	  return 0;
  }
	
  for (int oneLetterIndex = 0; oneLetterIndex < 200; ++oneLetterIndex) {
	  oneLetter[oneLetterIndex] = 0;
  }
  letter = file.get();
  while (letter != EOF) {
	  letter = toupper(letter);
	  ++oneLetter[letter];
	  letter = file.get();
  }
	
  cout << "Все однобуквенные повторения: " << endl;
  for (letter = 'A'; letter <= 'Z'; ++letter) {
	  if (oneLetter[letter]) {
		  cout << letter << ": " << oneLetter[letter] << "\n";
	  }
  }

  cout << "\n";

  int twoLetters[200][200];
  fstream filec;
	
  filec.open("text.txt");
  if (!filec) {
	  cout << "Ошибка: файл не найден.";
	  return 0;
  }
	
  for (int firstIndex = 0; firstIndex < 200; ++firstIndex) {
	  for (int secondIndex = 0; secondIndex < 200; ++secondIndex) {
		  twoLetters[firstIndex][secondIndex] = 0;
	  }
  }
	
  char firstLetter, secondLetter;
	
  firstLetter = filec.get();
  secondLetter = filec.get();
	
  while (secondLetter != EOF) {
	  firstLetter = toupper(firstLetter);
	  secondLetter = toupper(secondLetter);
	  ++twoLetters[firstLetter][secondLetter];
	  firstLetter = filec.get();
	  secondLetter = filec.get();
  }
	
  cout << "Все двухбуквенные повторения: " << endl;
  for (firstLetter = 'A'; firstLetter <= 'Z'; ++firstLetter) {
      for (secondLetter = 'A'; secondLetter <= 'Z'; ++secondLetter) {
        if (twoLetters[firstLetter][secondLetter]) {
	        cout << firstLetter << secondLetter << ": " << twoLetters[firstLetter][secondLetter] << "\n";
	    }
	  }
  }
} 