void input(char);
char usernamr00(char,char);
void password00(char);


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

#define ENTER 13
#define TAB 9
#define BSKSPC 8


struct user
{
	char name[50];
	char email[100];
	char username[60];
	char password[50];
	char phonenumber[10];
	
};

void input(char ch[100])
{
	fgets(ch,100,stdin);
	ch[strlen(ch)-1]='\0';
	
}

char username00(char email[100], char username[60])
{
	for(int i=0;i<strlen(email);i++)
	if(email[i]=='@')
	break;
	else
	username[i]=email[i];
	
}


char password00(char pass[50]) 
{
	int i;
	char ch;
	while(true)
	{
		ch=getch();
		if(ch == ENTER||ch == TAB)
		{
			pass[i]='\0';
			break;
			
		}
		else if (ch == BSKSPC)
		{
		
		if(i>0)
		{
			i--;
			printf("\b \b");
			
		}
	}
		else
		{
			pass[i++]=ch;
			printf("* \b");
		}
			
	}
	
}




int main()
{
	FILE *fp;
	int choice,Userfound=0;
	system("color 0b");
	struct user u1;
	char password1[50];
	
	
	printf("\n\t\t \t \t \t************************** WELCOME TO E AUTHENTICATION SYSTEM *******************************\t\t\t\n");
	
	printf("\nPLEASE SELECT ANY OPERATION\n");
	printf("\n 1. SINGUP  ");
	printf("\n 2. LOGIN ");
	printf("\n 3. EXIT   ");
	
	printf("\n\n ENTER YOUR CHOICE: \n");
	scanf("%d",&choice);
	
	
	switch(choice)
	{
	
	case 1:
		fgetc(stdin);
		
		printf("\nPlease Enter your Name:\t");
		input(u1.name);
		
		printf("\nWeldone");
		printf("\nEnter your email:\t");
		input(u1.email);
		
		printf("\nGoing good");
		printf("\nEnter your Phone Number:\t");
		input(u1.phonenumber);
		
		printf("\nTremendous work Go on");
		printf("\nEnter your personal password:\t");
		
		input(u1.password);
		
		printf("\nEnter your password one more time\t");
		password00(password1);
		
		
		if(!strcmp(u1.password,password1))
		{
			username00(u1.email,u1.username);
		    printf("\n Your Password Matched");
		    
			
			
			fp=fopen("E Aunthenticate.txt","a+");
			fwrite(&u1,sizeof(struct user),1,fp);  
			
			if(fwrite!=0)
			{
			printf("\n\n USER REGISTRATION SUCCESS \n\n");
			printf("Your Username is %s\n ",u1.username);
			printf("Your Password is %s\n ",u1.password);
			getch();
			
		    }
		    
		       
			else
			printf("\n\n SORRY SOMETHING WENT WRONG:");
			fclose(fp);
				
		}
		else
		{
			printf("\nPassword do not Match");
			Beep(650,300);
		}
		
		
		
		break;
		
		
		
		
		
		case 2:
			
			char user_name[50];
                        char pword[50];
			
			struct user u2;
			
			fgetc(stdin);
			
			printf("Enter your Username:\t");
			input(user_name);
			
			printf("Enter your Password:\t");
			password00(pword);
		
			
			
			fp=fopen("E Aunthenticate.txt","r");
			while(fread(&u2,sizeof(struct user),1,fp));
			{
			
			
			if(!strcmp(u2.username,user_name))
			{
			     if(!strcmp(u2.password,pword))
			   {
			   	system("cls");
			   	printf("\n\t\t   *****WELCOME****    \t\t");
			   	printf("\n Welcome %s",u2.name);
			   	printf("\n Your Username is:\t\t %s",u2.username);
			   	printf("\n Your E-mail is: \t\t %s",u2.email);
			   	printf("\n Your Phone Number is: \t\t %s",u2.phonenumber);
			   	printf("\n\n\n\t You Have successfully logged in");
			   	Userfound=1;
			   }
			   
			   
			   
			   else
			   {
			   	printf("\n\n Invalid Password!\n");
			   	Beep(800,300);
			   	
		      }
			}
			else
			{
				printf("\n\n User not found\n");
			}
			
		}
			
			if(!Userfound)
			{
			printf("\n User not Registered!");
			Beep(800,300);
		    }
		      else
		    {
		    	printf("\n\t \t User Found :)\t ");
		    	getch();
				
			}
			
		    fclose(fp);
		    break;
		    
	        
		case 3:
			printf("\nThanks for your Time");
			
			exit(1);
			
			
			default:
				printf("You have pressed wrong key or you might have selected wrong option\n");
				printf("\a");
			
		
	}
	return 0;
	
}
	


