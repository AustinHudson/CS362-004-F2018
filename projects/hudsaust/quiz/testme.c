#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char randomChar[9];
    randomChar[0] = '[';
    randomChar[1] = '(';
    randomChar[2] = '{';
    randomChar[3] = ' ';
    randomChar[4] = 'a';
    randomChar[5] = 'x';
    randomChar[6] = '}';
    randomChar[7] = ')';
    randomChar[8] = ']';
  
    return randomChar[rand()%9];
}

char *inputString()
{

    int i ;
    char* randomString = malloc((6) * sizeof(char));

    char* seedString[5];
    seedString[0] = 'r';
    seedString[1] = 'e';
    seedString[2] = 's';
    seedString[3] = 't';
    
    for (i = 0; i < 5; i++){
      randomString[i] = seedString[rand()%4];
    }

    randomString[6] = '\0';


    return randomString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
