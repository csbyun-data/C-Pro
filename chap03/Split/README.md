### A utility to split large text files into smaller files
* [snippets.org] split large text files
  * [split.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/split.c)
  * [filnames.h](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/filnames.h)
  * [sniptype.h](https://github.com/csbyun-data/C-Pro/tree/main/chap03/Split/sniptype.h)
  * [fnsplit.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/fnsplit.c)
    ```
    Boolean_T has_wild(char *pname);
    int       fnSplit(char *spec, char *drive, char *pname, char *path,
                      char *fname, char *name, char *ext);
    char     *fnMerge(char *spec, char *drive, char *pname, char *path,     
                      char *fname, char *name, char *ext) ;
    ```

  * [unix2dos.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/unix2dos.c)
    ```
    char *unix2dos(char *path);
    char *dos2unix(char *path);
    ```
* [snippets.org] reading and writing structures to a  sequential file
   * Generic structure <> disk file manipulations
   ```
   Generic structure <> disk file manipulations. These functions
   form a basic template for reading and writing structures to a 
   sequential file. This template is probably most useful for files
   with 500 or less records and eliminates the need for a more 
   elaborate file handler such as C-Tree, DB-Vista, Mix etc.
   Routines to put data in the struct is out of scope here.
   Written by Lynn Nash 8/28/91 and donated to the public domain.
  ```
  * [structfil.c](https://github.com/vonj/snippets.org/blob/master/strucfil.c)
  * [structfil.h](https://github.com/vonj/snippets.org/blob/master/strucfil.h)


  
