// Program shows copying one text file from source location
// to any other location (destination), plus possibility of changing its name, 
// and also shows many language features in exception handling.
// This program should be run from the command prompt
 
#include<iostream>
#include<stdio.h>
#include<stdexcept>
 
using namespace std;
 
class PathError : public runtime_error 
{
    public:
        PathError(const char *x) : runtime_error(x)
    {}
};
 
// function to open source file for read
 
FILE* source (char* argvs[]) {
    FILE *in;
    //open source file for read
    if((in = fopen(argvs[1],"r"))==NULL)
    {
        throw PathError("attempted to open wrong input file path");//terminate function
    }
    return in;
}
 
//function to create destination file for writting
FILE* destination (char* argvs[]) {
    FILE *out;
    //open destination file for write
    if((out = fopen(argvs[2],"w")) == NULL)
    {
        throw PathError("attempted to open wrong output file path");//terminate function
    }
    return out;
}
 
int main(int argc, char *argv[])
{
    FILE *in, *out;
    bool flag = 1;
    int temp;
    while(argc == 3) {
        try {
            in = source( argv );
            out = destination( argv );
            argc = 0;
        } catch(PathError& PathError) {
            cerr <<"\nException occured: " << PathError.what() << endl;
            return -1;
        }
 
        while(!feof(in)) { //test for it is not end of input file
            temp = fgetc(in); //get char from (in)file
            if( temp != EOF) {
                fputc(temp,out);//put char to (out) file
            }
        }
        fclose(in);
        fclose(out);
        cout<<"\n\t 1 file copied.\n";
        flag = 0;
    }
  
    if( flag != 0 ) {
        cerr<<"\nWrong argument list!!!\n\n";
        return -1;
    }
    return 0;
}
