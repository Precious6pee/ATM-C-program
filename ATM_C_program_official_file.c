#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exit_remark(int question_variable);
	
int main()
{
	char _question;
	int pass;
	char option_choice;
	float withdraw_amount;
	float option_choice_deposit;
	int option_choice_pin;
	int _finalDecision;
	
	int Pin = 1234;
	double balance = 2226000;

	printf("\n\n               *****Welcome to P-Pusher's' Bank*****\n\n        Would you like to login? ( Enter 1 (yes) / 2 (no) ) : ");
	//printf("        Would you like to login?  1 (yes) / 2 (no)  : ");
	scanf("%d", &_question);

	switch(_question)
	{
	case 1 :
		while(_question == 1)
		{
			break;
		}
	default :
		while(_question != 1)
		{
			exit_remark(_question);
		}	
	}
	
	bool flag = true;	
	while(flag = true)
	{
		char _pinAttempt = 3;
		while(_pinAttempt > 0)
		{
			printf("\n                        Enter PIN below\n                              ");
			scanf("%d", &pass);
			
			if(pass != Pin)
			{
				_pinAttempt -= 1;
				printf("\n!!!  invalid PIN......... you have %d attempts left\n", _pinAttempt);
				//break;
				if(_pinAttempt == 0)
				{
					printf("\a\n\n!!!!  You have locked yourself out...  Please call customer service\n\n\n\n");
					exit(0);
				}
			}
			else
			{
				break;
			}	
		}
			
		printf("\n\n1 : Withdraw                2 : Check balance\n3 : Deposit                 4 : Change PIN\n");
		printf("\nChoose the service  :  ");
		scanf("%d", &option_choice);
	
		switch(option_choice)
		{
		case 1 :
			printf("\nEnter the amount to withdraw :  MK ");
			scanf("%f", &withdraw_amount);
			if(withdraw_amount > balance ){
				printf("\n\n***Insufficient Funds***\n");
				break;
			}
			balance -= withdraw_amount;
			printf("\n\n****successfully****\nyour new balance is MK %.2lf\n", balance);
			break;
		case 2 :
			printf("\n\nyour balance is MK %.2lf \n", balance);
			break;
		case 3 :
			printf("\nEnter the amount to deposit : MK ");
			scanf("%f", &option_choice_deposit);
			balance = balance + option_choice_deposit;
			printf("\n\n***successfully***\nyour new balance is MK %.2lf\n", balance);
			break;
		case 4 :
			printf("\n\nEnter your new PIN  :  ");
			scanf("%d", &option_choice_pin);
			Pin = option_choice_pin;
			printf("\n****successfully****\n");
			break;
		default:
			printf("\n !!!!!Invalid Service\n");
			break;
		}
		
		printf("\nWould you like another service?  (Enter 1 (YES)  /  2 (NO) )  : ");
		scanf("%d", &_finalDecision);
		exit_remark(_finalDecision);

	}
	
	return 0;
}

void exit_remark(int question_variable)
{
	if(question_variable != 1)
	{
		printf("\n\n\n             Thank you for using P-Pusher's Bank...!!!!!\n\n\n");
		exit(0);
	}
}
