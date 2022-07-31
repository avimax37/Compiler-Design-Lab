#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void check_comment (char);
void block_comment ();
void single_comment ();

FILE *fp1, *fp2;

int main(){
	char c;
	fp1 = fopen ("file1.txt","r");
	fp2 = fopen ("MyNewFile.txt","w");
	while ((c=fgetc(fp1))!=EOF){
		check_comment (c);
	}
	fclose (fp1);
	fclose (fp2);
	return 0;
}

void check_comment (char c){
	char d;
	if (c == '/'){
		if ((d = fgetc(fp1))=='*'){
			block_comment();
		}
		else if (d == '/'){
			single_comment ();
		}
		else {
			fputc (c, fp2);
			fputc (d, fp2);
		}
	}
	else{
		fputc (c, fp2);
	}
}

void block_comment (){
	char d, e;
	while ((d = fgetc(fp1))!=EOF){
		if (d == '*'){
			e = fgetc (fp1);
			if (e == '/'){ 
				return;
			}
		}
	}
}

void single_comment (){
	char d, e;
	while ((d = fgetc(fp1))!=EOF){
		if (d == '\n'){
			fputc ('\n', fp2);
			return;
		}
	}
}