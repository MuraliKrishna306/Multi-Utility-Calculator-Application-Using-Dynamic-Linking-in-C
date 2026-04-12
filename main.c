
#include<stdio.h>
#include<dlfcn.h>
#define NumberLength 33
#define NumberLenght2 65

char printMenu(void);
void Arithmatic(float a,float b);
void NumberSystems(char *Number1,char *Number2);
void Distance(void);
void Currency(void);
void Weight(void);

void *vp;

int main()
{
	char c, Number1[NumberLength], Number2[NumberLength];
	float value1, value2;

	c = printMenu();
	switch(c)
	{
	    case '0':		return 0;
    	case '1':		Arithmatic(value1,value2);			break;
    	case '2':		NumberSystems(Number1,Number2);		break;
    	case '3':		Distance();		    	            break;
    	case '4':		Currency();		                	break;
    	case '5':		Weight();	    		            break;
    	default:    	break;
	}
	return 1;
}

char printMenu(void)
{
	char i ;
	char menu[] = {" 1. Arithmatic Operations  \n 2. Number Systems  \n 3. Distance  \n 4. Curency  \n 5. Weight \n 0--> EXIT"};
Menu:
	puts(" Choose Option Below:\n --------------------------------------------------");
	puts(menu);
	i = getchar();
	if( ! (  i >= '0'  &&  i <= '5'  ) )
	{
		printf(" Invalid Option [ %d ]", i);
		goto Menu;
	}
	return i;
}

void Arithmatic(float a,float b)
{
	int choice , n = 0;
//	unsigned short int choice;
	char menu[] = {" 1. Addition \n 2. Subtraction \n 3.i Multiplication \n 4. Division \n 5. Modular \n 6. Power \n 7. Factorial (for first number)\n 0--> Exit"};
	float (*Arith[7])(float,float);
	vp = dlopen("./libarith.so",RTLD_LAZY);
	if( vp == NULL )
	{
		printf(" %s\n", dlerror());
		return ;
	}

	puts( menu );
Menu:	printf(" Enter Choice:");
	scanf("%d", &choice);
	printf(" Enter First Number:");
	scanf("%f", &a);
	if( choice != 7 )
	{
		printf(" Enter Second Number:");
		scanf("%f", &b);
	}
	if( choice == 0 )
		return ;
	else if( choice > 7 )
		goto Menu;

	Arith[0] = dlsym(vp,"add");
	Arith[1] = dlsym(vp,"sub");
	Arith[2] = dlsym(vp,"mul");
	Arith[3] = dlsym(vp,"divi");
	Arith[4] = dlsym(vp,"mod");
	Arith[5] = dlsym(vp,"power");
	Arith[6] = dlsym(vp,"factorial");

	if( Arith[choice-1] == NULL )
	{
		printf("%s\n", dlerror());
		return ;
	}
	if( choice == 4)
	    n = 3;
	printf(" Result= %.*f \n", n , Arith[choice-1](a,b));
}

void NumberSystems(char *Number1,char *Number2)
{
	unsigned short int Input1, Input2 ;
	int (*NumberSys[4][4])(const char *, char *);
	char *Arr[4] = { {"Decimal"} , {"Binary"} , {"HexaDecimal"} , {"Octal"} };
	vp = dlopen("./libnumsys.so", RTLD_LAZY);
	if( vp == NULL )
	{
		printf("%s\n", dlerror());
		return ;
	}
D1:
	puts(" Choose Number Type :");
	puts(" 1. Decimal \n 2. Binary \n 3. Hexadecimal\n 4. Octal \n 0--> EXTI");
	printf(" Enter Input Number Type:");
	scanf("%hu", &Input1);
	while( getchar() != '\n' );
	if( Input1 == 0 )
	{
		return;
	}
	else if( Input1 > 4 )
	{
		puts(" Invalid Input");
		goto D1;
	}
	printf(" Enter Number: ");
    fgets(Number1, NumberLength, stdin);
    Number1[NumberLength-1] = '\0';

	//	Decimal number conversion
	NumberSys[0][0] = dlsym(vp,"Decimal_to_Decimal");
	NumberSys[0][1] = dlsym(vp,"Decimal_to_Binary");
	NumberSys[0][2] = dlsym(vp,"Decimal_to_HexaDecimal");
	NumberSys[0][3] = dlsym(vp,"Decimal_to_Octal");

	// Binary number conversion
	NumberSys[1][0] = dlsym(vp,"Binary_to_Decimal");
	NumberSys[1][1] = dlsym(vp,"Binary_to_Binary");
	NumberSys[1][2] = dlsym(vp,"Binary_to_HexaDecimal");
	NumberSys[1][3] = dlsym(vp,"Binary_to_Octal");

	//	HexaDecimal number conversion
	NumberSys[2][0] = dlsym(vp,"HexaDecimal_to_Decimal");
	NumberSys[2][1] = dlsym(vp,"HexaDecimal_to_Binary");
	NumberSys[2][2] = dlsym(vp,"HexaDecimal_to_HexaDecimal");
	NumberSys[2][3] = dlsym(vp,"HexaDecimal_to_Octal");

	//	Octal number conversion
	NumberSys[3][0] = dlsym(vp,"Octal_to_Decimal");
	NumberSys[3][1] = dlsym(vp,"Octal_to_Binary");
	NumberSys[3][2] = dlsym(vp,"Octal_to_HexaDecimal");
	NumberSys[3][3] = dlsym(vp,"Octal_to_Octal");

D2:
	puts(" 1. Decimal \n 2. Binary \n 3. Hexadecimal\n 4. Octal  ");
	printf(" Enter Output Number Type:");
	scanf("%hu", &Input2);
	if(Input2>4 || Input2==0)
	{
		puts(" Invalid Input");
		goto D2;
	}
	if( NumberSys[Input1-1][Input2-1](Number1 , Number2) == 0 )
	{
		printf("Invalid Input 1: %s 2: %s\n",Number1 , Number2);
		goto D1;
	}
	else if( NumberSys[Input1-1][Input2-1](Number1 , Number2) )
	{
	    
		printf(" %s to %s Converted Successfully \n\n Result = %s\n",Arr[Input1-1],Arr[Input2-1],Number2);
	}
}

void Distance( void )
{
	char *Arr[7] = {{"Centi-Meter"} , {"Meter"} , {"Kilo-meter"} , {"Miles"} , {"Inches"} , {"Foot"} , {"Yards"}};
	int choice1 , value , choice2;
	float result , (*Dist)(float , int , int);
	vp=dlopen("./libdist.so", RTLD_LAZY);
	if( vp == NULL )
	{
		printf(" %s\n", dlerror());
		return ;
	}
D1:	puts(" 1. Centi-Meter \n 2. Meter \n 3. Kilo-meter \n 4. Miles \n 5. Inches \n 6. Foot \n 7. Yards \n 0--> EXIT");
	printf(" Enter Your Choice:");
	scanf("%d", &choice1);
	if( choice1 == 0 )
		return;
	if( choice1 > 8 )
	{
		puts(" Invalid Input");
		goto D1;
	}
	printf(" Enter Value in %s: ",Arr[choice1-1]);
	scanf("%d", &value);
	while( getchar() != '\n' );
D2:	puts(" 1. Centi-Meter \n 2. Meter \n 3. Kilo-meter \n 4. Miles \n 5. Inches \n 6. Foot \n 7. Yards ");
	printf(" Enter the required value of Your Choice:");
	scanf("%d", &choice2);
	if( choice2 == 0 )
		return;
	if( choice2 > 8 )
	{
		puts(" Invalid Input");
		goto D2;
	}
	Dist = dlsym(vp, "Distance_Conversion");
	if( Dist == NULL )
	{
		printf("%s\n", dlerror());
		return ;
	}
	result = Dist(value,choice1,choice2);
	printf(" The value from %s to %s is converted \n Result :%f\n" , Arr[choice1-1] , Arr[choice2-1] , result);
}

void Currency(void)
{
	vp = dlopen("./libcurr.so", RTLD_LAZY);
	if( vp == NULL )
	{
		printf("%s\n", dlerror());
		return ;
	}//INR         USD     EURO      JPY       GBP     AUD       CAD     CNY       AED
	char *Arr[9]= {{"INR"} , {"USD"} , {"EURO"} , {"JPY"} , {"GBP"} , {"AUD"} , {"CAD"} , {"CNY"} , {"AED"}};
	int choice1 , value , choice2;
	float result , (*Curr)(float , int , int) ;
	
C1:	puts(" 1. INR [INDIAN RUPEE] \n 2. USD[UNITED STATES] \n 3. EUR [EURO] \n 4. JPY [JAPANESE YEN] \n 5. GBP [BRITISH POUND STERLING] \n 6. AUD [AUSTRALIA] \n 7. CAD [CANADIAN DOLLAR] \n 8. CNY [CHINESE YUAN] \n 9. AED [DIRHAM-UAE]\n 0--> EXIT");
	printf(" Enter Your Choice:");
	scanf("%d", &choice1);
	if( choice1 == 0 )
		return;
	if( choice1 > 9 )
	{
		puts(" Invalid Input");
		goto C1;
	}
	printf(" Enter Value in %s:", Arr[choice1-1]);
	scanf("%d", &value);
C2:	puts(" 1. INR [INDIAN RUPEE] \n 2. USD[UNITED STATES] \n 3. EUR [EURO] \n 4. JPY [JAPANESE YEN] \n 5. GBP [BRITISH POUND STERLING] \n 6. AUD [AUSTRALIA] \n 7. CAD [CANADIAN DOLLAR] \n 8. CNY [CHINESE YUAN] \n 9. AED [DIRHAM-UAE] ");
	printf(" Enter the required value of Your Choice:");
	scanf("%d", &choice2);
	if( choice2 == 0 )
		return;
	if( choice2 > 10 )
	{
		puts(" Invalid Input");
		goto C2;
	}
	Curr = dlsym(vp, "Currency_conversion");
	if( Curr == NULL )
	{
		printf("%s\n", dlerror());
		return ;
	}
	result = Curr(value,choice1,choice2);
	printf(" The value from %s to %s is converted \n Result :%f\n",Arr[choice1-1],Arr[choice2-1],result);
}

void Weight(void)
{
	vp = dlopen("./libwght.so", RTLD_LAZY);
	if( vp == NULL )
	{
		printf("%s\n", dlerror());
		return ;
	}//KG      G           MG          Q               LB
	char Arr[5][4]= {{"KG"} , {"GMS"} , {"MG"} , {"Q"} , {"LB"} };
	int choice1,value,choice2;
	float result , (*Wght)(float , int , int);
	
W1:	puts(" 1. KG [KILO-GRAMS]\n 2.GMS  [GRAMS]\n 3. MG [MILLI-GRAMS]\n 4. Q  [QUINTAL]\n 5. LB [POUNDS] \n 0--> EXIT");
	printf(" Enter Your Choice:");
	scanf("%d", &choice1);
	if( choice1 == 0)
		return;
	if( choice1 > 5)
	{
		puts(" Invalid Input");
		goto W1;
	}
	printf(" Enter Value in %s:", Arr[choice1-1]);
	scanf("%d",&value);
W2:	puts(" 1. KG [KILO-GRAMS]\n 2. G  [GRAMS]\n 3. MG [MILLI-GRAMS]\n 4. Q  [QUINTAL]\n 5. LB [POUNDS]  ");
	printf(" Enter the required value of Your Choice:");
	scanf("%d", &choice2);
	if( choice2 == 0 )
		return;
	if( choice2 > 5 )
	{
		puts(" Invalid Input");
		goto W2;
	}
	Wght = dlsym(vp ,"Weight_Conversion");
	if( Wght == NULL )
	{
		printf("%s\n", dlerror());
		return ;
	}
	result = Wght(value,choice1,choice2);
	printf(" The value from %s to %s is converted \n Result :%f\n", Arr[choice1-1] , Arr[choice2-1] , result);
}
