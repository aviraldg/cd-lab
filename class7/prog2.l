%x CMT

%%

<INITIAL>{
  \/\* {
    BEGIN(CMT);
    printf("%s", yytext);
  }

  \/\/[^\n]*\n  {
    printf("%s", yytext);
  }

  . {}
}

<CMT>{
  \*\/ {
    printf("%s", yytext);
    BEGIN(INITIAL);
  }

  . {
    printf("%s", yytext);
  }
}
