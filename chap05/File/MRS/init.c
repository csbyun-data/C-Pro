void init() {
  FILE *fp = NULL;
  int status = 0;
  const char defaultUsername[] ="usr1\n";
  const char defaultPassword[] ="passwd1\n";
  sFileHeader fileHeaderInfo = {0};
  
  status = isFileExists(FILE_NAME);
  if(!status) {
    //create the binary file
    fp = fopen(FILE_NAME,"wb");
    if(fp != NULL) {
      //Copy default password
      strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
      strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
      fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
      fclose(fp);
    }
  }
}
