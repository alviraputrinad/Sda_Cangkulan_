#include "cangkulan.h"
static AddressPlayer first;
AddressPlayer getFirst(){
	return first;
}
AddressPlayer CreateNodePlayer(Name name[]){
	AddressPlayer P;
	P=(AddressPlayer)malloc(sizeof(PlayerList));	
	strcpy((P)->playerName,name);
	(P)->nextPlayer=NULL;
	return P;
}
void InputData(Name name[]){
	printf("\nNama: ");
	gets(name);
}
void PlayerOrder(int totalPlayer,FirstPlayer FP){
	Name name[10];
	AddressPlayer Pnew[totalPlayer];
	int i,j;
	j=0;
	for(i=0;i<totalPlayer;i++){
		InputData(name);
		Pnew[i]=CreateNodePlayer(name);
	}
	for(i=0;i<totalPlayer;i++){
		j=i+1;
		if(j<totalPlayer){
		Pnew[i]->nextPlayer=Pnew[j];
		j++;
		}
		else{
			j=j-totalPlayer;
			Pnew[i]->nextPlayer=Pnew[j];
		}
	}
	first=FP.firstPlayer=Pnew[0];
}
void PrintfPlayer(){
	AddressPlayer first;
	int i;
	i=1;
	first= getFirst();
	do{
		printf("%d. %s",i,first->playerName);
		first=first->nextPlayer;
		i++;
	}while(first!=NULL);
	
}
void CreateCardList(){
	FirstCangkulan cards;
	int i,j;
	for(i=0;i<4;i++){
		for(j=1;j<=13;j++){
			if(i==0){
				strcpy(cards.Card[j].typeCard, "Hearts");
			}
			else if(i==1){
				strcpy(cards.Card[j].typeCard, "Spades");
			}
			else if(i==2){
				strcpy(cards.Card[j].typeCard, "Diamonds");
			}
			else{
				strcpy(cards.Card[j].typeCard, "Clubs");
			}
			cards.Card[j].cardValue = j;
		}
	}
}
void ShareCard(FirstPlayer FP,FirstCangkulan FC,int player){
	int i,j;
	AddressCard pHelp;
	int top = FC.top;
	for(i=0;i<player;i++){
		pHelp=FP.firstPlayer->MyCard.firstCard;
		for(j=0;j<7;j++){
			pHelp->Card=FC.Card[top];
			pHelp=pHelp->nextCard;
			top--;
		}
		pHelp=FP.firstPlayer->nextPlayer->MyCard.firstCard;
	}
}

void DisplayPlayerCard(FirstPlayer FP){
	AddressCard pHelp;
	pHelp = FP.firstPlayer->MyCard.firstCard;
	while(pHelp->nextCard != NULL){
		if(pHelp->Card.cardValue==1){
			printf("As ");
		}
		else if(pHelp->Card.cardValue==11){
			printf("Jack ");
		}
		else if(pHelp->Card.cardValue==12){
			printf("Queen ");
		}
		else if(pHelp->Card.cardValue==13){
			printf("King ");
		}
		printf("%s",pHelp->Card.typeCard);
		pHelp=pHelp->nextCard;
	}
}
