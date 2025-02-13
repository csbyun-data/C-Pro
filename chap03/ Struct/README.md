### [snippets.org] reading and writing structures to a sequential file
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
