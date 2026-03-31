//number systems [binary , octal , decimal, hexadecimal ,user defined]

#define INT_MAX_DEC 10
#define INT_MAX_HEX 8
#define INT_MAX_OCT 11
#define INT_MAX_BIN 32

int Number_System[][1]={{0},{0},{0},{0}};

//String Operations

int String_Length(const char *p)
{
    int i=0;
    while(p[i++]);
    return i;
}

void StringRev(char *p)
{
    int i=0,j;
    for(i=0,    j=String_Length(p)-2; i<j ; i++,j--)
    {
        p[i]^=p[j]^=p[i]^=p[j];
    }
}

void StringCopy(char *p , const char *q)
{
    int i,j;
    j=String_Length(q);
    for(i=0;i<=j;i++)
    {
        p[i]=q[i];
    }
}

//Check and Confirm the input value

int Check_Decimal(const char *Num)
{
    int i=0;
    if(Num[0]=='-')
    {
        Num++;
//        i++;  //optional
    }
    while(Num[i])
    {
        if(!((Num[i]>='0' && Num[i]<='9') || Num[i]=='\n' ))
            return 0;
        i++;
    }
    if((String_Length(Num)-1)>INT_MAX_DEC)
    {
        return 0;
    }
    return 1;
}

int Check_Binary(const char *Num)
{
    int i=0;
    if(Num[0]=='-')
    {
        Num++;
//        i++;  //optional
    }
    while(Num[i])
    {
        if(!((Num[i]>='0' && Num[i]<='1') || Num[i]=='\n' ))
            return 0;
        i++;
    }
    if((String_Length(Num)-1)>INT_MAX_BIN)
    {
        return 0;
    }
    return 1;
}

int Check_Octal(const char *Num)
{
    int i=0;
    if(Num[0]=='-')
    {
        Num++;
//        i++;  //optional
    }
    while(Num[i])
    {
        if(!((Num[i]>='0' && Num[i]<='7') || Num[i]=='\n' ))
            return 0;
        i++;
    }
    if((String_Length(Num)-1)>INT_MAX_OCT)
    {
        return 0;
    }
    return 1;
}

int Check_HexaDecimal(const char *Num)
{
    int i=0;
    if(Num[0]=='-')
    {
        Num++;
//        i++;  //optional
    }
    while(Num[i])
    {
        if(!((Num[i]>='0' && Num[i]<='9') || (Num[i]>='a' && Num[i]<='f') ||( Num[i]>='A' && Num[i]<='F') || Num[i]=='\n' ))
            return 0;
        i++;
    }
    if((String_Length(Num)-1)>INT_MAX_HEX)
    {
        return 0;
    }
    return 1;
}

int Check_UserDefined(const char *Num,int n)
{
    int i=0 , Hex=0;
    if(Num[0]=='-')
    {
        Num++;
//        i++;  //optional
    }
    if(n>10 && n<37)
        Hex=1;
    while(Num[i])
    {
        if(Hex==0)
            if(!(Num[i]>='0' && Num[i]<=(48+n-1)))
            return 0;
        else if(Hex==1)
            if(!((Num[i]>='0' && Num[i]<='9') || (Num[i]>='a' && Num[i]<=(97+n-10-1)) || (Num[i]>='A' && Num[i]<=(65+n-10-1)) || Num[i]=='\n' ))
                return 0;
        i++;
    }
    return 1;
}

//A to I conversion

int UserDefined(const char *Num,int n)
{
   int Length , Number=0 , Sign=1;
   if(Num[0]=='-')
   {
       Sign=-1;
       Num++;
   }
   
   for(Length = String_Length(Num)-2 ; Length>=0 ; Length--)
   {
       if(Num[Length]>='0' && Num[Length]<='9')
            Number = (Number*n)+Num[Length]-48;
        else if(Num[Length]>='A' && Num[Length]<='F')
            Number = (Number*n)+Num[Length]-63+10;
        else if(Num[Length]>='a' && Num[Length]<='f')
            Number = (Number*n)+Num[Length]-97+10;
   }
   return Number*Sign;
}

int Decimal_Number(const char *Num)
{
    int Length , i=0 , Number=0 , Sign=1;
    if(Num[0]=='-')
    {
        Sign=-1;
        Num++;
    }
    
    for(Length = String_Length(Num)-2 ; i<=Length ; i++)
    {
        if(Num[i]=='\n')
            continue;
        Number = (Number*10)+Num[i]-48;
    }
    return Number*Sign;
}

int Binary_Number(const char *Num)
{
    int Length  , i=0 , Number=0 , Sign=1;
    
    if(Num[0]=='-')
    {
        Sign=-1;
        Num++;
    }
    for(Length = String_Length(Num)-2 ; i<=Length ; i++)
    {
        if(Num[i]=='\n')
            continue;
        Number = (Number*2)+Num[i]-48;
    }
    return Number*Sign;
}

int Octal_Number(const char *Num)
{
    int Length , i=0 , Number=0 , Sign=1;
    if(Num[0]=='-')
    {
        Sign=-1;
        Num++;
    }
    
    for(Length = String_Length(Num)-2 ; i<=Length ; i++)
    {
        if(Num[i]=='\n')
            continue;
        Number = (Number*8)+Num[i]-48;
    }
    return Number*Sign;
}

int HexaDecimal_Number(const char *Num)
{
    int Length , i=0 , Number=0, Sign=1;
    if(Num[0]=='-')
    {
        Sign=-1;
        Num++;
    }
    
    for(Length = String_Length(Num)-2 ; i<=Length ; i++)
    {
        if(Num[i]=='\n')
            continue;
        if(Num[i]>='0' && Num[i]<='9')
            Number = (Number*16)+Num[i]-48;
        else if(Num[i]>='A' && Num[i]<='F')
            Number = (Number*16)+Num[i]-63+10;
        else if(Num[i]>='a' && Num[i]<='f')
            Number = (Number*16)+Num[i]-97+10;
    }
    return Number;
}

//I to A conversion

int AnyDecimal(int n,char *p,int base)
{
    int i=0;
    if(n<0)
    {
//        p[i++]='-';
        p[0]='-';
        p++;
        n=-n;
    }
    else if(n==0)
    {
        p[i++]=48;
    }
    while(n)
    {
        if((n%base)<10)
            p[i++]=(n%base)+48;
        else if((n%base)>9 &&((n%base)<36))
            p[i++]=(n%base)+65-10;
        else
            p[i++]=(n%base)+97-36;
    }
    return i;
}

int Binary(int n,char *p)
{
   int i=0;
   if(n<0)
    {
//        p[i++]='-';
        p[0]='-';
        p++;
        n=-n;
    }
    else if(n==0)
    {
        p[i++]=48;
    }
   while(n)
   {
       p[i++]=(n%2)+48;
       n/=2;
   }
   p[i]='\0';
   StringRev(p);
   return i;
}

int Decimal(int n,char *p)
{
    int i=0;
    if(n<0)
    {
//        p[i++]='-';
        p[0]='-';
        p++;
        n=-n;
    }
    else if(n==0)
    {
        p[i++]=48;
    }
    while(n)
    {
        p[i++]=(n%10)+48;
        n/=10;
    }
    p[i]='\0';
    StringRev(p);
    return i;
}

int Octal(int n,char *p)
{
    int i=0;
    if(n<0)
    {
//        p[i++]='-';
        p[0]='-';
        p++;
        n=-n;
    }
    else if(n==0)
    {
        p[i++]=48;
    }
    while(n)
    {
        p[i++]=(n%8)+48;
        n/=8;
    }
    p[i]='\0';
    StringRev(p);
    return i;
}

int HexaDecimal(int n, char *p)
{
    int i=0;
    if(n<0)
    {
//        p[i++]='-';
        p[0]='-';
        p++;
        n=-n;
    }
    else if(n==0)
    {
        p[i++]=48;
    }
    while(n)
    {
        if((n%16)<10)
            p[i++]=(n%16)+48;
        else if((n%16)>9)
            p[i++]=(n%16)+65-10;
        n/=16;
    }
    p[i]='\0';
    StringRev(p);
    return i;
}

//Decimal to Binary, Octal, HexaDecimal Conversion

int Decimal_to_Binary(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Decimal(Num)==0)
        return 0;
    Number = Decimal_Number(Num);
    Binary(Number,ConvertNum);
    return 1;
}

int Decimal_to_Octal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Decimal(Num)==0)
        return 0;
    Number = Decimal_Number(Num);
    Octal(Number,ConvertNum);
    return 1;
}

int Decimal_to_HexaDecimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Decimal(Num)==0)
        return 0;
    Number = Decimal_Number(Num);
    HexaDecimal(Number,ConvertNum);
    return 1;
}

int Decimal_to_Decimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Decimal(Num)==0)
        return 0;
    StringCopy(ConvertNum,Num);
    return 1;
}

//Binary to Decimal, Octal, HexaDecimal Conversion

int Binary_to_Decimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Binary(Num)==0)
        return 0;
    Number = Binary_Number(Num);
    Decimal(Number,ConvertNum);
    return 1;
}

int Binary_to_Octal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Binary(Num)==0)
        return 0;
    Number = Binary_Number(Num);
    Octal(Number,ConvertNum);
    return 1;
}

int Binary_to_HexaDecimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Binary(Num)==0)
        return 0;
    Number = Binary_Number(Num);
    HexaDecimal(Number,ConvertNum);
    return 1;
}

int Binary_to_Binary(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Binary(Num)==0)
        return 0;
    StringCopy(ConvertNum,Num);
    return 1;
}

//Octal to Binary, Decimal, Hexadecimal Conversion

int Octal_to_Binary(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Octal(Num)==0)
        return 0;
    Number = Octal_Number(Num);
    Binary(Number,ConvertNum);
    return 1;
}

int Octal_to_Decimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Octal(Num)==0)
        return 0;
    Number = Octal_Number(Num);
    Decimal(Number,ConvertNum);
    return 1;
}

int Octal_to_HexaDecimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Octal(Num)==0)
        return 0;
    Number = Octal_Number(Num);
    HexaDecimal(Number,ConvertNum);
    return 1;
}

int Octal_to_Octal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_Octal(Num)==0)
        return 0;
    StringCopy(ConvertNum,Num);
    return 1;
}

//Hexadecimal to Binary, Decimal, Octal Conversion

int HexaDecimal_to_Binary(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_HexaDecimal(Num)==0)
        return 0;
    Number = HexaDecimal_Number(Num);
    Binary(Number,ConvertNum);
    return 1;
}

int HexaDecimal_to_Decimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_HexaDecimal(Num)==0)
        return 0;
    Number = HexaDecimal_Number(Num);
    Decimal(Number,ConvertNum);
    return 1;
}

int HexaDecimal_to_Octal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_HexaDecimal(Num)==0)
        return 0;
    Number = HexaDecimal_Number(Num);
    Octal(Number,ConvertNum);
    return 1;
}

int HexaDecimal_to_HexaDecimal(const char *Num , char *ConvertNum)
{
    int Number;
    if(Check_HexaDecimal(Num)==0)
        return 0;
    StringCopy(ConvertNum,Num);
    return 1;
}
