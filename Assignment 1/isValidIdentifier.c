#include <stdio.h>
#include <string.h>
#include <conio.h>

int isValidIdentifier (char str[]){
	int i;
	if ((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z') || str[0] == '_'){
		for (i = 1; i <= strlen(str); i++){
			if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i] == '_' || (str[i]>='0' && str[i]<='9')){
				return 1;
			}
		}
	}
	else {
		return 0;
	}
}

int main(){
	char str[1000];
	printf ("Enter any identifier : ");
	scanf ("%[^\n]s",&str);
	if (isValidIdentifier(str)==1){
		printf ("%s is a valid identifier.", str);
	}
	else {
		printf ("%s is not a valid identifier.", str);
	}
	return 0;
}