#include <iostream>
#include "simplemathquest.h"
#include "prompt.h"
using namespace std;

int main(){
	int qNum = PromptRange("how many questions: ",1,5);
  	int k, ans, score =0;
  	
  	for(k=0; k < qNum; k++){   
		Question q;
		q.Ask();
		cin >> ans;
		if (q.IsCorrect(ans)){
   			cout << ans << " correct answer" << endl << endl;
   			score++;
 		}
 		else
   			cout << "Sorry, not correct. Correct answer was " <<      
								q.CorrectAnswer() << endl << endl;
  	}
  	
  	cout << "Score is " << score << " out of " << qNum 
  						<< " = " << double(score)/qNum * 100 << "%" << endl;

	return 0;
}