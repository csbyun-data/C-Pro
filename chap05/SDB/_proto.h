/* cmd.c */
int db_parse(char *fmt, ... );
int db_to ( FILE **pfp , char *ext );

/* com.c */
int db_compile ( struct sel *slptr );
void db_fcode ( struct sel *slptr );

/* cre.c */
struct relation *db_rcreate ( char *rname );
int db_rcheader ( struct relation *rptr );
int db_rctuples ( struct relation *rptr , unsigned int tcnt );
int db_rcdone ( struct relation *rptr );
int db_rcattr ( struct relation *rptr , char *aname , int type , int size );

/* err.c */
const char *db_ertxt ( const int msg );

/* iex.c */
int db_import ( char *fmt , ...);
int db_export ( char *fmt , ...);
int db_squeeze ( char *fmt , ...);
int db_extract ( char *fmt , ...);

/* int.c */
int db_interpret ( struct sel *slptr );
int db_xstop ( void );
int db_xpush ( void );
int db_xand ( void );
int db_xor ( void );
int db_xnot ( void );
int db_xlss ( void );
int db_xleq ( void );
int db_xeql ( void );
int db_xgeq ( void );
int db_xgtr ( void );
int db_xneq ( void );

/* io.c */
struct scan *db_ropen (char *rname);
int db_rclose (struct scan *sptr);
int db_rcompress (struct scan *sptr);
int db_rfetch (struct scan *sptr);
int db_rupdate (struct scan *sptr);
int db_rdelete (struct scan *sptr);
int db_rstore (struct scan *sptr);
int db_rget (struct scan *sptr, unsigned int tnum);
int db_rput (struct scan *sptr, unsigned int tnum);
//int db_nerror (int errcode);
void* db_nerror (int errcode);
int db_ferror (int errcode);
int db_cvword (char bytes[2]);
void db_cvbytes(int word, char bytes[2]);
void db_rbegin(struct scan *sptr);

/* mth.c */
int db_cmp ( char *arg1 , char *arg2 );
void db_add ( char *result , char *arg1 , char *arg2 );
void db_sub ( char *result , char *arg1 , char *arg2 );

/* pcjunk.c */
char *alloc ( int n );
int getcx ( FILE *fp );

/* scn.c */
void db_sinit ( void );
void db_prompt ( const char *ip , const char *cp );
void db_scan(char *fmt, ... );

int db_flush ( void );
char *db_gline ( char *buf );
int db_ifile ( char *fname );
void db_kill ( void );
int db_token ( void );
int db_xtoken ( void );
int db_ntoken ( void );
int db_xntoken ( void );
int db_scmp ( const char *str1 , const char *str2 );
int db_sncmp ( const char *str1 , const char *str2 , int len );

/* sdb.c */
int main ( void );

/* sel.c */
struct sel *db_select(char* fmt, ... );
struct sel *db_retrieve ( char *fmt , ... );
void db_done ( struct sel *slptr );
int db_fetch ( struct sel *slptr );
int db_update ( struct sel *slptr );
int db_store ( struct sel *slptr );
int db_bind ( struct sel *slptr , char *rname , char *aname , char *avalue );
int db_get ( struct sel *slptr , char *rname , char *aname , char *avalue );
int db_put ( struct sel *slptr , char *rname , char *aname , char *avalue );
int db_sattr ( struct sel *slptr , char *rname , char *aname , int *ptype , char **pptr , int *plen );
void db_aget ( struct attribute *aptr , char *vptr , char *avalue );
void db_aput ( struct attribute *aptr , char *vptr , char *avalue );

/* srt.c */
int db_sort(char* fmt, ... );

/* tbl.c */
void db_thead ( FILE *fp , struct sel *slptr );
void db_tfoot ( FILE *fp , struct sel *slptr );
void db_tentry ( FILE *fp , struct sel *slptr );


