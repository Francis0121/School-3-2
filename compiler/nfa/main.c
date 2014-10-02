#include <string.h>
#include <stdio.h>

// From NFA to DFA ( Data Structure )
#define STATES	256
#define SYMBOLS	20

int N_symbols; // number of input symbols
int NFA_states; // number of NFA states
char *NFAtab[STATES][SYMBOLS];

int DFA_states; // number of DFA states
int DFAtab[STATES][SYMBOLS];

void init_NFA_table(void);
void string_merge(char *, char *);
void get_next_state(char *, char *, char **, int, int);
int state_index(char *, char **, int*);
int nfa_to_dfa(char , int, int, int *);

int main(void){
	init_NFA_tables();
	DFA_states = nfa_to_dfa(NFAtab, NFA_states, N_symbols, DFAtab);
	put_DFA_table(DFAtab, DFA_states, N_symbols);
	return 0;
}

void init_NFA_table(void){
	NFAtab[0][0] = "12";
	NFAtab[0][1] = "13";
	NFAtab[1][0] = "12";
	NFAtab[1][1] = "13";
	NFAtab[2][0] = "4";
	NFAtab[2][1] = "";
	NFAtab[3][0] = "";
	NFAtab[3][1] = "4";
	NFAtab[4][0] = "4";
	NFAtab[4][1] = "4";

	NFA_states = 5;
	DFA_states = 0;
	N_symbols = 2;
}

void get_next_state(char *nextstates, char *cur_states, char *nfa[STATES][SYMBOLS], int n_nfa, int symbol){
	int i;
	char temp[STATES];
	
	temp[0] = '\0';
	for(i=0; i<strlen(cur_states); i++){
		string_merge(temp, nfa[cur_states[i]-'0'][symbol]);
	}
	strcpy(nextstates, temp);
}

int state_index(char *state, char statement[][STATES], int *pn){
	int i;
	
	if(!*state) return -1;	//no next state

	for(i=0; i<*pn; i++){
		if(!strcmp(state, statename[i])) return i;
	}
	strcpy(statename[i], state); // new state name
	return (*pn)++;
}

int nfa_to_dfa(char *nfa[STATES][SYMBOLS], int n_nfa, int n_sym, int dfa[][SYMBOLS]){
	char statenames[STATES][STATES];
	int i=0; // current index of DFA
	int n=1; // number of DFA states

	char nextstates[STATES];
	int j;
	
	strcpy(statename[0], "0");
	
	for(i=0; i<n; i++) { //for each DFA state
		for(j=0; j<n_sym; j++){
			get_next_state(nextstate, statename[i], nfa, n_nfa, j);
			dfa[i][j] = state_index(nextstate, statename, &n);
		}
	}
	return n; // number of DFA states
}

void put_DFA_tabl(int tab[][SYMBOLS], int nstates, int nsymbols)
	int i,j;

	puts("STATE TRANSITION TABLE");
	
	// input symbols : '0', '1', ...
	printf(" | ");
	for(i=0; i<nsymbols; i++){
		prtinf(" %c ", '0'+i);
	}
	printf("\n--------+--");
	for(i=0; i<nsymbols; i++){
		printf("----");
	}
	printf("\n");

	for(i=0; i<nstates; i++){
		printf(" %c | ", 'A'+i); //state
		for(j=0; j<nsymbols; j++)
			printf(" %c ", 'A'+tab[i][j]);
		printf("\n");
	}
}
