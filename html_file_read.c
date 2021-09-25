
char *render(char *path)
{

    FILE *fp;
    char *buffer;
    
    fp = fopen(path, "r");
    if(fp==NULL)return "<html><h1>no file found</h1><html>";
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    buffer = (char *)calloc(1, size + 1);
    rewind(fp);
    if (1 != fread(buffer, size, 1, fp));
    fclose(fp);
    // while (fgets(buffer, 100, fp))
    //     printf("%s", buffer);

    //fscanf(fp , "%s",buffer);
    return buffer;
}

char * get_requested_path(char * buffer){
    char * runner ;
    runner = strtok (buffer,"\n");
    char * result ;
  while (runner!= NULL)
  {
 
    printf ("values is :%c\n",*runner);
    runner = strtok (NULL, "\n");
  }
   
   return NULL;
}