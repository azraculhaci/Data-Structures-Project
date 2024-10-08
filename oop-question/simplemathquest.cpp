#include <iostream>
#include "simplemathquest.h"
#include "randgen.h"
using namespace std;

Question::Question(){
	RandGen gen;
	myNum1 = gen.RandInt(1,100);
	myNum2 = gen.RandInt(1,100);
	myAnswer = myNum1 + myNum2;
}

void Question::Ask() const{
	cout << myNum1 << " + " << myNum2 << " = ";
}

bool Question::IsCorrect(int answer) const{
	return myAnswer == answer;
}

int Question::CorrectAnswer() const{
	return myAnswer;
}