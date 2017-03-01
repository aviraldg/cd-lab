%{
int l = 0;
%}

%%

[^\n]*\n  {
  printf("%d %s", l++, yytext);
}
