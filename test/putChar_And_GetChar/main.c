#include <stdio.h>

typedef enum Allapot{
	szoveg,
	space,
	gondolatjel,
	vege
}Allapot;

int main(){
	char c;
	Allapot allapot = szoveg;
	while ((c = getchar()) != EOF){
		switch (allapot){
			case szoveg: 
				if (c == ' ') allapot = space;
				else putchar(c);
				break;
			case space: 
				if (c == ' ') putchar(' '); 
				else if (c == '-') allapot = gondolatjel; 
				else {putchar(' '); putchar(c);  allapot = szoveg; } break;
			case gondolatjel: 
				if (c == ' ') allapot = vege; break;
			case vege: 
				if (c == ' ') ;else if (c == '-') allapot = szoveg; else allapot = gondolatjel;
		}
	}
	return 0;
}
