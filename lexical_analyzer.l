%{
        int COMMENT = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
"int" | float | char | double | while | for | struct | typedef | do | "if" | break | continue | void |
switch | return | else | goto {printf("\n\t%s is a keyword",yytext);}
%%

int main(int argc, char **argv)
{
FILE *file;
file=fopen("var.c","r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
yylex();
printf("\n");
return(0);
}
int yywrap()
{
return(1);
}