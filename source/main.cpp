// Main.cpp
// A quiz of assorted C++ things to practice my C++ coding and also
// test myself of it after!
#include<iostream>
#include<vector>
#include<string>
#include<ctime>

using namespace std;

// Function prototypes: //
// wrongAnswer: returns a random phrase for a wrong answer
void wrongAnswer(const vector<string>&);
// pickQuestion: choose a random question from the vector
int pickQuestion(const vector<string>&);
// checkAnswer: checks the user's answer to corresponding answer vector
bool checkAnswer(string&, string&);
// instructions: explains how to use the program
void instructions();
// checkQuestionsAsked: check the vector if the question has already been asked
bool checkQuestionAsked(const vector<short>&, short questionNum);



int main(){

  // the vectors which will contain the questions and answers
  vector<string> questions;
  vector<string> answers;

  // adding the questions and answers
  questions.push_back("How do you declare a vector? (say for strings; no variable name)");
  answers.push_back("vector<string>");

  questions.push_back("What function adds to the end of a vector?");
  answers.push_back("push_back()");

  questions.push_back("What goes in the __ ?: srand(_____<unsigned int>(time(0)))");
  answers.push_back("static_cast");

  // a vector containing all the phrases for when the user gets a wrong answer
  vector<string> vWrong;

  // adding the phrases
  vWrong.push_back("Sorry, wrong answer.");
  vWrong.push_back("Nope, incorrect.");
  vWrong.push_back("This ain't it, chief.");
  vWrong.push_back("Wrong again, bucko.");

  // keeps track of the questions asked by index number
  vector<short> questionsAsked;

  /*for(short i = 0; i < questions.size(); i++){
    cout << questions[i] << endl;
    cout << "Answer: " << answers[i] << endl;
  }*/

  short correctAnswers = 0;

  short numAsked = 0;
  while (numAsked != questions.size()){

    //short questionNum = pickQuestion(questions);

    srand(static_cast<short>(time(0)));
    short questionNum = (rand() % vWrong.size());

    if(checkQuestionAsked(questionsAsked, questionNum)){
      continue;
    }
    else {
      cout << questions[questionNum] << "\n";
      questionsAsked.push_back(questionNum);
      string userAnswer;
      cout << ">";
      cin >> userAnswer;
      string& rUserAns = userAnswer;
      string& rAnswer = answers[questionNum];
      if(checkAnswer(rAnswer, rUserAns)){
        cout << "\nThat's right!\n\n";
        ++correctAnswers;
      }
      else
        wrongAnswer(vWrong);

      ++numAsked;
    }
  }
  cout << "\nThat's the end of the quiz!";
  cout << "\nYou got " << correctAnswers << "/" << questions.size()
    << " right!\n";
  return 0;
}

void wrongAnswer(const vector<string>& vWrong){

  srand(static_cast<unsigned int>(time(0)));
  short i = (rand() % vWrong.size());

  cout << "\n" << vWrong[i] << "\n\n";
}

int pickQuestion(const vector<string>& questions){

  srand(static_cast<short>(time(0)));
  short i = (rand() % questions.size());

  cout << questions[i] << "\n";

  return i;

}

bool checkAnswer(string& answer, string& userAnswer){
  if(answer == userAnswer)
    return true;
  else
    return false;
}

void instructions(){
  cout << "\nThese are the instructions.\n\n";
}

bool checkQuestionAsked(const vector<short>& qAsked, short questionNum){

  for(short i = 0; i < qAsked.size(); ++i){
    if(qAsked[i] == questionNum)
      return true;
    else
      continue;
  }

  return false;
}
