import os

os.system('lex lex.l')
os.system('yacc -d yacc.y')
os.system('gcc lex.yy.c y.tab.c -o output')
os.system('clear');
print('Start writing your program :\n')
os.system('./output')