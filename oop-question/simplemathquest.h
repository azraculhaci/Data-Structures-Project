#ifndef _SIMPLEMATH_H
#define _SIMPLEMATH_H

class Question{
	
	public:
  		Question();   						// create a random question
		void Ask() const; 					// ask the question to user
		int  GetAnswer() const; 			//input and return user answer
		bool IsCorrect (int answer) const; 	//check if correct
		int CorrectAnswer() const;   		// return correct answer
             
	private:
		int myNum1;       // numbers used in question
		int myNum2;
		int myAnswer;	// store the answer
 };

#endif