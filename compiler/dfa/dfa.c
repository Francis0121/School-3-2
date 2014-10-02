#include <stdio.h>

#define STATES	3 // number of states
#define SYMBOLS 2 // number of symbols

int ST_TAB[STATES][SYMBOLS] = {
	{1, 0}, // state P
	{2, 0}, // state q
	{2, 2}	// state r
};

void put_table(int tab[][SYMBOLS], int m, int n){
	int i;
	
	puts("State Transition Table");
	puts("\t0\t1");
	for(i=0; i<m; i++){
		printf("%c\t%c\t%c\n", 'A'+i, 'A'+tab[i][0], 'A'+tab[i][1]);
	}
}

int main(void){
	int ch; // input symobl
	int cur_state = 0; // start state
	
	put_table(ST_TAB, STATES, SYMBOLS);

	ch = getchar();
	while(ch != '\n'){
		cur_state = ST_TAB[cur_state][ch-'0'];
		if(cur_state < 0){
			puts("FAIL");
			return 0;
		}	
		ch = getchar();
	}

	if(cur_state == 2){
		puts("OK");
	}else{
		puts("FAIL");
	}
	
	return 0;
}
