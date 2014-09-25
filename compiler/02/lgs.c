/*
	(Language Generating System) for CFG.

	1. Smallest 'n' strings for given CFG are generated.
	2. Grammar is loaded from 'grammar.txt'.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 999

int top=0;
char *stack[MAX];

struct grammar {
	int nGS;
	char lhs[30];
	char rhs[30][5][10];
} CFG;	/* context-free grammar */

void push(char *s)
{
	if (top >= MAX-1) {
		puts("STACK OVERFLOW!");
		return;
	}

	stack[top] = (char *) malloc(strlen(s)+1);
	strcpy(stack[top++], s);
}

/*
	smallest sentential form is popped.
*/
char *pop()
{
	int i, k=0;
	char *p;

	for (i = 1; i < top; i++) {
		if (strlen(stack[k]) > strlen(stack[i]))
			k = i;
	}	/* k: index of the smallest sentential form */

	if (k != top-1) {
		p = stack[top-1];
		stack[top-1] = stack[k];
		stack[k] = p;
	}
	return stack[--top];
}

int is_stack_empty()
{
	return (top <= 0);
}

int load_CFG(struct grammar *cfg)
{
	FILE *fp;
	char line[999], *p=line;
	int i=0, j=0;
	char *fname = "grammar.txt";

	fp = fopen(fname, "r");
	if (!fp) { printf("File not found: <%s>.\n", fname); return 1; }

	while (fgets(line, 999, fp)) {
		if (line[0] == ';') continue;	/* ignore comments */
		line[strlen(line)-1] = '\0';	/* cut LF */

		if (j && cfg->lhs[i] != *p) {	/* next nonterminal? */
			i++;
			j = 0;
		}

		cfg->lhs[i] = *p;	/* LHS */
		if (line[5] == '@')	/* RHS */
			cfg->rhs[i][j++][0] = '@';	/* epsilon */
		else strcpy(cfg->rhs[i][j++], p+5);
		cfg->rhs[i][j][0] = '\0';
	}
	cfg->nGS = i+1;
	fclose(fp);

	return 0;
}

void print_CFG(struct grammar *cfg)
{
	int i, j;

	puts("Production Rules");
	for (i=0; i < cfg->nGS; i++) {
		for (j = 0; cfg->rhs[i][j][0]; j++) {
			printf("\t%d:%d %c -> %s\n", i, j, cfg->lhs[i], cfg->rhs[i][j]);
		}
	}
}

/*
	maximum 'n' strings are generated.
*/
int expand(struct grammar *cfg, char *s, int n)
{
	char *p=s;
	char *temp, *pt;	/* temp -- expanded string */
	int i, j;

	temp = (char *) malloc(strlen(s)+99);
	pt = temp;

	while (*p) {
		if (isupper(*p)) break;
		*pt++ = *p++;
	}	/* '*p' is a leftmost nonterminal */
	if (*p == '\0') {	/* no nonterminal */
		printf("%s\n", s);	/* terminal string */
		return n-1;
	}

	for (i=0; i < cfg->nGS; i++) {
		if (*p == cfg->lhs[i]) {
			for (j = 0; cfg->rhs[i][j][0]; j++) {
				*pt = '\0';
				if (cfg->rhs[i][j][0] != '@')
					strcat(pt, cfg->rhs[i][j]);
				strcat(pt, p+1);
				push(temp);
			}
		}
	}

	free(temp);
	return n;
}

int main()
{
	char *sform;
	char ss[2];
	int n=20;	/* max. 'n' strings are generated */

	if (load_CFG(&CFG)) return 1;
	print_CFG(&CFG);

	ss[0] = CFG.lhs[0]; ss[1] = '\0';
	push(ss);	/* initialize stack by start symbol */
	while (n && !is_stack_empty()) {
		sform = pop();
		n = expand(&CFG, sform, n);
		free(sform);
	}

	return 0;
}

