#include <stdio.h>
#include <string.h>
#include <conio.h>

isValidComment (char str[]){
	if (str[0]=='/' && str[1]=='/' && str[2]!='/'){
		return 1;
	}
	else if (str[0]=='/' && str[1]=='*' && str[strlen(str)-1]=='/' && str[strlen(str)-2]=='*'){
		return 2;
	}
	else {
		return 0;
	}
}

int main(){
	char str[1000];
	printf ("Enter any comment in C Programming language : ");
	scanf ("%[^\n]s",&str);
	if (isValidComment(str)==1){
		printf ("\n\'%s\' is a single line comment in C.", str);
	}
	else if (isValidComment(str)==2) {
		printf ("\n\'%s\' is a multi line comment in C.", str);
	}
	else {
		printf ("\n\'%s\' is not a comment in C.", str);
	}
	return 0;
}