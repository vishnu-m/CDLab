%{
        int yylineno=0;
%}

%%
^(.*)\n printf("%4d\t%s", ++yylineno, yytext);
%%

int main(int argc, int argv[])
{
        yyin = fopen(argv[1], "r");
        yylex();
        fclose(yyin);
}