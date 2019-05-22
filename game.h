#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "card.h"

using namespace std;

int dealer_score = 0;
int player_score = 0;
string choice;
bool play_again = true;
int times_played = 0;


void rules() {
  cout<< "This is a card game, and it will be you against me." << endl;
  cout << "I will draw 4 cards and separate them from the rest of the deck."  << endl;
  cout<< "You will then have four chances to earn points when you answer correctly," << endl;
  cout << "and each decision is ranked differently" << endl;
  cout << "Also to note.. ace will be considered with the value of 1." << endl;
  cout << endl;
  cout << "First, I will ask you what colour the card will be. (1 point)" <<  endl;
  cout << "Second, you will choose if the next card's value" << endl;
  cout << "will be higher or lower than the first card. (1 point)" << endl;
  cout << "Third, you will choose if the next card's value will" << endl;
  cout << "be in between or outside of the first two card's values. If you guess in between," <<endl;
  cout << "then the cards must be either equal to or clearly in between the two cards' values. If you choose outside, they must"<< endl;
  cout << "be clearly outside of the two cards' values. (5 points)" << endl;
  cout << "Lastly, you will try to guess the suit of the card. (10 points)" << endl;
  cout << endl;

  return;
}

int coin_flip() {
  cout << "It seems the two cards values are equal" << endl;
  cout << "Therefore, to be fair. We will flip a coin." << endl;
  cout << "I am heads and you are tails." << endl;

  int flip = rand() % 2;

  if (flip == 0) {
    cout << "The coin landed on heads." << endl;
    cout << "Tough luck. The point will be givin to me." << endl;
    dealer_score++;
  }
  if (flip == 1) {
    cout << "The coin landed on tails." << endl;
    cout << "The point will be given to you." << endl;
    player_score++;
  }
}

string winner() {
  if (dealer_score > player_score) return "I am the winner! Better luck next time!";
  else if (player_score > dealer_score) return "You won! Congratulations!";
  else return "It looks like a draw!";
}

void playAgain() {
  cout << "Would you like to play again? (y/n)" << endl;
  cin >> choice;
  cout << endl;

  while (choice != "y" || choice !="n") {
    if (choice == "y") {
      cout << "Let's continue then!" << endl;
      times_played++;
      return;
    }

    if (choice == "n") {
      cout << "I hope to see you again!" << endl;
      play_again = false;
      return;
    }
    else {
      cout << "I am not quite sure what you would like to do..use y for yes and n for no." << endl;
      cin >> choice;
    }
  }
}


void playGame() {
  //if they want to play again, fun the program again
  while (play_again != false) {
    vector<Card> deck;
    for (int i=0; i<52; i++) {
      Card c;
      deck.push_back(c);
    } 

    if (times_played == 0) {
      cout << "Hello, I'm Tiberius. I am your dealer today." << endl;
      cout<< "Are you new to the game Higher or Lower? If so," << endl;
      cout<< "would you like me to explain the rules? (y/n)" << endl;
      cin >> choice;
      cout << endl;

      //user selected y or n for instructions ... or mistyped
      while (choice != "y" || choice != "n") {
        if (choice == "y") {
          cout << "Let me go over the rules with you." << endl;
          rules();
          break;
        }
        else if (choice == "n") {
          cout << "Alright, let's get started." << endl;
          break;
        }
        else {
          cout << "Try again, please. (y/n)" << endl;
          cin >> choice;
          cout << endl;
        }
      }
    }
    //I take 4 cards from deck and move them to play_pile
    random_shuffle(deck.begin(), deck.end());
    vector<Card> play_pile;
    for (int i=0; i<4; i++) {
      play_pile.push_back(deck.back());
      deck.pop_back();
    }

    // beginning of the player choices for cards
    // they choose if it is red or black
    cout << "Okay, the four cards are separated now." << endl;
    cout << "Is this card red or black? (r/b)" << endl;
    cin >> choice;
    cout << endl;

    //user selected colur and now we figure out the colour of the card
    while (choice != "r" || choice != "b") {
      if (choice == "r") {
        if (play_pile[0].get_colour() != "red") {
          cout << "I'm sorry, you have guessed the wrong colour." << endl;
          cout << "A point will be added to my score." << endl;
          dealer_score++;
          break;
        }

        else {
          cout << "You guessed correctly! Good job!" << endl;
          cout << "A point will be added to your score." << endl;
          player_score++;
          break;
        }
      }

      if (choice == "b") {
        if (play_pile[0].get_colour() != "black") {
          cout << "I'm sorry, you have guessed the wrong colour." << endl;
          cout << "A point will be added to my score." << endl;
          dealer_score++;
          break;
        }
        else {
          cout << "You guessed correctly! Good job!" << endl;
          cout << "A point will be added to your score." << endl;
          player_score++;
          break;
        }
      }
      else {
        cout << "Try again, please. (r/b)" << endl;
        cin >> choice;
        cout << endl;
      }

    } 

    //check card colour
    if (play_pile.empty() == false) {
      Card c = play_pile[0];
      cout << "The card colour was " << c.get_colour() << endl;
    }


    cout << "Your score: " << player_score << endl;
    cout << "My score: " << dealer_score << endl;
    cout << endl;

    //move onto the 2nd question and show their previous card value
    cout << "The first card's value is: ";

    //check 1st card value
    if (play_pile.empty() == false) {
      Card c = play_pile[0];
      cout << c.get_value_string() << endl;
    }

    cout << "Next question..is this card higher or lower than the first card? (h/l)" << endl;
    cin >> choice;
    cout << endl;

    //check their choice and compare the first and second cards
    while (choice != "h" || choice != "l") {
      Card cardone = play_pile[0]; // 1st card in deck
      Card cardtwo = play_pile[1]; // 2nd card in deck

      if (choice == "h") {
        if (cardtwo.get_value_int() > cardone.get_value_int()) {
          cout << "You guessed correctly! Nice work!" << endl;
          cout << "A point has been added to your score." << endl;
          player_score++;
          break;
        }

        if (cardtwo.get_value_int() == cardone.get_value_int()) {
          coin_flip();
          break;
        }

        else {
          cout << "I'm sorry. That choice was incorrect." << endl;
          cout << "I have added a point to my score." << endl;
          dealer_score++;
          break;
        }
      }

      if (choice == "l") {
        if (cardtwo.get_value_int() < cardone.get_value_int()) {
          cout << "You guessed correctly! Nice work!" << endl;
          cout << "A point has been added to your score." << endl;
          player_score++;
          break;
        }
        if (cardtwo.get_value_int() == cardone.get_value_int()) {
          coin_flip();
          break;
        }

        else {
          cout << "I'm sorry. That choice was incorrect." << endl;
          cout << "I have added a point to my score." << endl;
          dealer_score++;
          break;
        }
      }

      else {
        cout << "Try again, please. (h/l)" << endl;
        cin >> choice;
        cout << endl;
      }
    }

    //check 2nd card value 
    if (play_pile.empty() == false) {
      Card c = play_pile[1];
      cout << "The second card's value is: " << c.get_value_string() << endl;
    }

    cout << "Your score: " << player_score << endl;
    cout << "My score: " << dealer_score << endl;
    cout << endl;

    Card cardone = play_pile[0];
    Card cardtwo = play_pile[1];
    cout << "Here is the first card's value: " << cardone.get_value_string() << endl;
    cout << "And the second card's value: " << cardtwo.get_value_string() << endl;

    //move onto third question and show both cards values from before
    cout << "Now for the third question...is the third card's value" << endl;
    cout << "in between or outside of the other cards values? (i/o)" << endl;
    cin >> choice;
    cout << endl;

    //check their choice and compare the third cards value to the other two
    while (choice != "i" || choice != "o") {
      Card cardone = play_pile[0]; // 1st card in deck
      Card cardtwo = play_pile[1]; // 2nd card in deck
      Card cardthree = play_pile[2];

      //check immediately if the first two card values are equal, if so..break
      if (cardone.get_value_int() == cardtwo.get_value_int()) {
        break;
      }

      if (choice == "i") {
        if (cardone.get_value_int() < cardtwo.get_value_int()) {
          if (cardthree.get_value_int() >= cardone.get_value_int() && cardthree.get_value_int() <= cardtwo.get_value_int()) {
            cout << "You guessed correctly! Woohoo!" << endl;
            cout << "Five points has been added to your score" << endl;
            player_score=player_score + 5;
            break;
          }
          else {
            cout << "I'm sorry. That choice was incorrect." << endl;
            cout << "I have added five points to my score." << endl;
            dealer_score=dealer_score + 5;
            break;
          }
        }
        if (cardone.get_value_int() > cardtwo.get_value_int()) {
          if (cardthree.get_value_int() <= cardone.get_value_int() && cardthree.get_value_int() >= cardtwo.get_value_int()) {
            cout << "You guessed correctly! Woohoo!" << endl;
            cout << "Five points has been added to your score" << endl;
            player_score=player_score + 5;
            break;
          }
          else {
            cout << "I'm sorry. That choice was incorrect." << endl;
            cout << "I have added five points to my score." << endl;
            dealer_score=dealer_score + 5;
            break;
          }
        }
      }

      if (choice == "o") {
        if (cardone.get_value_int() < cardtwo.get_value_int()) {
          if (cardthree.get_value_int() < cardone.get_value_int() || cardthree.get_value_int() > cardtwo.get_value_int()) {
            cout << "You guessed correctly! Woohoo!" << endl;
            cout << "Five points has been added to your score" << endl;
            player_score=player_score + 5;
            break;
          }
          else {
            cout << "I'm sorry. That choice was incorrect." << endl;
            cout << "I have added five points to my score." << endl;
            dealer_score=dealer_score + 5;
            break;
          }
        }

        if (cardone.get_value_int() > cardtwo.get_value_int()) {
          if (cardthree.get_value_int() > cardone.get_value_int() || cardthree.get_value_int() < cardtwo.get_value_int()) {
            cout << "You guessed correctly! Woohoo!" << endl;
            cout << "Five points has been added to your score" << endl;
            player_score=player_score + 5;
            break;
          }
          else {
            cout << "I'm sorry. That choice was incorrect." << endl;
            cout << "I have added five points to my score." << endl;
            dealer_score=dealer_score + 5;
            break;
          }
        }

      }

      else {
        cout << "Try again, please. (i/o)" << endl;
        cin >> choice;
      }
    }

    //show third cards values
    if (play_pile.empty() == false) {
      Card c = play_pile[2];
      cout << "The third card's value was: " << c.get_value_string() << endl;
    }

    if (cardone.get_value_int() == cardtwo.get_value_int()) {
      cout << "I apologize for this inconvenience...looks like another coin flip is in place." << endl;
      coin_flip();
    }

    cout << "Your score: " << player_score << endl;
    cout << "My score: " << dealer_score << endl;
    cout << endl;

    cout << "Final question. What suit is the last card? (h/s/d/c)?" << endl;
    cin >> choice;
    cout << endl;

    //last loop to compare choice to the last card's suit
    while (choice != "h" || choice != "s" || choice != "d" || choice != "c") {
      if (choice == "h") {
        if (play_pile[3].get_suit() != "heart") {
          cout << "I'm sorry, you have guessed the wrong suit." << endl;
          cout << "Ten points will be added to my score." << endl;
          dealer_score=dealer_score + 10;
          break;
        }

        else {
          cout << "You guessed correctly! Good job!" << endl;
          cout << "Ten points will be added to your score." << endl;
          player_score=player_score + 10;
          break;
        }
      }

      if (choice == "s") {
        if (play_pile[3].get_suit() != "spades") {
          cout << "I'm sorry, you have guessed the wrong suit." << endl;
          cout << "Ten points will be added to my score." << endl;
          dealer_score=dealer_score+10;
          break;
        }
        else {
          cout << "You guessed correctly! Good job!" << endl;
          cout << "Ten points will be added to your score." << endl;
          player_score=player_score + 10;
          break;
        }
      }

      if (choice == "d") {
        if (play_pile[3].get_suit() != "diamond") {
          cout << "I'm sorry, you have guessed the wrong suit." << endl;
          cout << "Ten points will be added to my score." << endl;
          dealer_score=dealer_score+10;
          break;
        }
        else {
          cout << "You guessed correctly! Good job!" << endl;
          cout << "Ten points will be added to your score." << endl;
          player_score=player_score + 10;
          break;
        }
      }
      if (choice == "c") {
        if (play_pile[3].get_suit() != "clubs") {
          cout << "I'm sorry, you have guessed the wrong suit." << endl;
          cout << "Ten points will be added to my score." << endl;
          dealer_score=dealer_score+10;
          break;
        }
        else {
          cout << "You guessed correctly! Good job!" << endl;
          cout << "Ten points will be added to your score." << endl;
          player_score=player_score + 10;
          break;
        }
      }
      else {
        cout << "Try again, please. (h/s/d/c)" << endl;
        cin >> choice;
        cout << endl;
      }

    }

    if (play_pile.empty() == false) {
      Card c = play_pile[3];
      cout << "The card's suit was: " << c.get_suit() << endl;
    }

    cout << "Your score: " << player_score << endl;
    cout << "My score: " << dealer_score << endl;
    cout << endl;

    play_pile.clear();

    if (deck.empty() == false) {
      playAgain();
    }
    else {
      cout << "I'm sorry! Looks like we went through the whole deck!" << endl;
      cout << "The ending scores were:" << endl;
      cout << "You: " << player_score << endl;
      cout << "Me: " << dealer_score << endl;
      play_again = false;
      winner();
    }

  }
  return;
}



#endif
