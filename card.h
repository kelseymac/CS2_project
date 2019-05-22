#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
  protected:
    int value;
    int suit;
    int colour;

  public:
    Card() {
      //13 values in card deck
      //4 suits - heart, diamond, spades, clubs
      value = 1 + rand() % 13;
      suit = rand() % 4;
      colour = rand() % 2;
    }

    string get_colour() {
      if (colour == 0) return "red";
      if (colour == 1) return "black";
    }

    string get_suit() {
      if (suit == 0) return "heart";
      if (suit == 1) return "spades";
      if (suit == 2) return "diamond";
      if (suit == 3) return "clubs";
    }

    string get_value_string() {
      if (value == 1) return "ace";
      if (value == 2) return "two";
      if (value == 3) return "three";
      if (value == 4) return "four";
      if (value == 5) return "five";
      if (value == 6) return "six";
      if (value == 7) return "seven";
      if (value == 8) return "eight";
      if (value == 9) return "nine";
      if (value == 10) return "ten";
      if (value == 11) return "jack";
      if (value == 12) return "queen";
      if (value == 13) return "king";
    }

      //create a map for card as string to the value it is worth
    int get_value_int() {
      if (value == 1) return 1;
      if (value == 2) return 2;
      if (value == 3) return 3;
      if (value == 4) return 4;
      if (value == 5) return 5;
      if (value == 6) return 6;
      if (value == 7) return 7;
      if (value == 8) return 8;
      if (value == 9) return 9;
      if (value == 10) return 10;
      if (value == 11) return 11;
      if (value == 12) return 12;
      if (value == 13) return 13;
      
    }
      
};
#endif
