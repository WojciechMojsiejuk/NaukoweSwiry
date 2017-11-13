char *funkcja_a(const char* napis)
{
  char *napis2 = (char*)malloc(sizeof(char)*(strlen(napis)+1));
  int i,j;
  for(i=0;i<=strlen(napis);i++)
  {
    if(islower(napis[i])
      napis2[i]=toupper(napis[i]);
    else
      napis2[i]=napis[i];
  }
  return napis2;
}
char *funkcja_b(const char* napis)
{
  int n=strlen(napis);
  char *napis3 = (char*)malloc(sizeof(char)*(n+1));
  int i,j;
  for(i=0;i<=n;i++)
  {
    napis3[i]=napis[n-1-i]
  }
  return napis3;
}
