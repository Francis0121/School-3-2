LEX_FILE = myc
YACC_FILE = myyacc
OUT_FILE = my

$(OUT_FILE): y.tab.c lex.yy.c
	gcc -o $(OUT_FILE) y.tab.c lex.yy.c -lfl
y.tab.c: $(YACC_FILE).y
	yacc -d $(YACC_FILE).y
lex.yy.c: $(LEX_FILE).l
	flex $(LEX_FILE).l
