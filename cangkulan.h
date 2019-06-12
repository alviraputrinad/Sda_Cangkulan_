#ifndef cangkulan_H
#define cangkulan_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef char Name;
typedef int Value;
typedef struct ListOfCard *AddressCard;
typedef struct Player *AddressPlayer;

typedef struct CardData{ //struct kartu
	Name typeCard[10];
	Value cardValue;
}CardDeck;

typedef struct FCangkulan{ //tumpukan kartu 1
	CardDeck Card[52];
	int top;
}FirstCangkulan;
typedef struct SCangkulan{ //tumpukan kartu 2
	CardDeck Card[52];
	int top;
}SecondCangkulan;

typedef struct ListOfCard{ // penghubung kartu yang dipegang oleh player
	CardDeck Card;
	AddressCard nextCard;
}CardList;

typedef struct { // kartu pertama yang dipegang player
	AddressCard firstCard;
}FirstCard;

typedef struct Player{ // Pemain
	Name playerName[10];
	FirstCard MyCard;
	AddressPlayer nextPlayer;
}PlayerList;
typedef struct {
	AddressPlayer firstPlayer;
}FirstPlayer;

void CreateCardList(); //Membuat tumpukan kartu
AddressPlayer CreateNodePlayer(Name name[]); // mereturn address node player yang baru dibuat
void PlayerOrder(int totalPlayer,FirstPlayer FP); //membuat urutan player
void ShareCard(); //Membagikan kartu
void SwapCard(); //Swap untuk modul random
void RandomizeCard(); //Acak kartu
void TakeCard(); //Ambil kartu di cangkulan
void PlayerCardEmpty();
void InputData(Name name[]);
void Play(); //sebagai papan permainan


//stack
bool ListEmpty(); //kalau stack nya kosong

//Display
void DisplayPlayerCard();
void DisplayPotentialCard();
void DisplayWastedCard();






#endif
