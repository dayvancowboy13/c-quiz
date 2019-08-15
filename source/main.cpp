// Main.cpp
// A quiz of assorted C++ things to practice my C++ coding and also
// test myself of it after!
#include<iostream>
#include<vector>
#include<string>
#include<ctime>

using namespace std;

// Function prototypes:
// wrongAnswer: returns a random phrase for a wrong answer
void wrongAnswer(const vector<string>&);
// pickQuestion: choose a random question from the vector
int pickQuestion();
// checkAnswer: checks the user's answer to corresponding answer vector
bool checkAnswer();
// instructions: explains how to use the program
void instructions();
// getAnswer: get user's answer to the question



int main(){
  vector<string> questions;
  vector<string> answers;


  questions.push_back("How do you declare a vector? (say for strings)");
  answers.push_back("vector<string> var;");

  vector<string> vWrong;
  //vector<string>::iterator iter;

  vWrong.push_back("Sorry, wrong answer.");
  vWrong.push_back("Nope, incorrect.");
  vWrong.push_back("This ain't it, chief.");

  /*for(short i = 0; i < questions.size(); i++){
    cout << questions[i] << endl;
    cout << "Answer: " << answers[i] << endl;
  }*/

  wrongAnswer(vWrong);


  return 0;
}

void wrongAnswer(const vector<string>& vWrong){
  srand(static_cast<unsigned int>(time(0)));
  short i = (rand() % vWrong.size());

  cout << vWrong[i];
  cout << "\n\n";
}
