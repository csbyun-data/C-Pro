### A utility to split large text files into smaller files
* split large text files
  * [split.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/split.c)
  * [filnames.h](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/filnames.h)
  * [fnsplit.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/fnsplit.c)
  ```
  Boolean_T has_wild(char *pname);
  int       fnSplit(char *spec, char *drive, char *pname, char *path,
                    char *fname, char *name, char *ext);
  char     *fnMerge(char *spec, char *drive, char *pname, char *path,     
                    char *fname, char *name, char *ext) ;
  ```

  * [unix2dos.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/unix2dos.c)
