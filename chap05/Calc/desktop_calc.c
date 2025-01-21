#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARS 100
#define MAX_VAR_NAME 100

// Token value enumeration
typedef enum {
    NAME, NUMBER, END, INC, DEC,
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
    PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
} Token_value;

Token_value curr_tok = PRINT;
double number_value;
char string_value[MAX_VAR_NAME];

double expr(int);
double term(int);
double error(const char*);
double prim(int);
Token_value get_token();

typedef struct {
    char name[MAX_VAR_NAME];
    double value;
} Variable;

Variable table[MAX_VARS];
int table_size = 0;

double expr(int get);
double term(int get);
double prim(int get);
Token_value get_token();

// Function to find variable in the table
double* find_var(char* name) {
    for (int i = 0; i < table_size; i++) {
        if (strcmp(table[i].name, name) == 0) {
            return &table[i].value;
        }
    }
    return NULL;
}

// Function to add a new variable
double* add_var(char* name) {
    if (table_size >= MAX_VARS) {
        error("too many variables");
        return NULL;
    }
    strcpy(table[table_size].name, name);
    table[table_size].value = 0;
    table_size++;
    return &table[table_size - 1].value;
}

double expr(int get) {
    double left = term(get);
    while (1) {
        switch (curr_tok) {
            case PLUS:
                left += term(1);
                break;
            case MINUS:
                left -= term(1);
                break;
            default:
                return left;
        }
    }
}

double term(int get) {
    double left = prim(get);
    while (1) {
        switch (curr_tok) {
            case MUL:
                left *= prim(1);
                break;
            case DIV:
                if (double d = prim(1)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}

double prim(int get) {
    if (get) get_token();

    switch (curr_tok) {
        case NUMBER: {
            double v = number_value;
            get_token();
            return v;
        }
        case NAME: {
            double* v = find_var(string_value);
            if (!v) {
                v = add_var(string_value);
            }
            get_token();
            if (curr_tok == ASSIGN)
                *v = expr(1);
            if (curr_tok == INC)
                (*v)++;
            if (curr_tok == DEC)
                (*v)--;
            return *v;
        }
        case INC:
            return prim(1) + 1;
        case DEC:
            return prim(1) - 1;
        case MINUS:
            return -prim(1);
        case LP: {
            double e = expr(1);
            if (curr_tok != RP) return error("')' expected");
            get_token();
            return e;
        }
        default:
            return error("primary expected");
    }
}

Token_value get_token() {
    char ch;

    do {
        if (scanf("%c", &ch) != 1) return curr_tok = END;
    } while (ch != '\n' && isspace(ch));

    switch (ch) {
        case ';':
        case '\n':
            return curr_tok = PRINT;
        case 0:
            return curr_tok = END;
        case '+': {
            char c;
            if (scanf("%c", &c) && c == '+')
                return curr_tok = INC;
            ungetc(c, stdin);
            return curr_tok = Token_value(ch);
        }
        case '-': {
            char c;
            if (scanf("%c", &c) && c == '-')
                return curr_tok = DEC;
            ungetc(c, stdin);
            return curr_tok = Token_value(ch);
        }
        case '*':
        case '/':
        case '(':
        case ')':
        case '=':
            return curr_tok = Token_value(ch);

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            ungetc(ch, stdin);
            if (scanf("%lf", &number_value) == 1)
                return curr_tok = NUMBER;
            break;

        default:
            if (isalpha(ch)) {
                string_value[0] = ch;
                int i = 1;
                while (scanf("%c", &ch) && isalnum(ch))
                    string_value[i++] = ch;
                string_value[i] = '\0';
                ungetc(ch, stdin);
                return curr_tok = NAME;
            }
            error("bad token");
            return curr_tok = PRINT;
    }
}

int no_of_errors;

double error(const char* s) {
    no_of_errors++;
    fprintf(stderr, "error: %s\n", s);
    return 1;
}

int main(int argc, char* argv[]) {
    table_size = 0;
    table[table_size++] = (Variable){"pi", 3.1415926535897932385};
    table[table_size++] = (Variable){"e", 2.718281828459045};

    while (1) {
        get_token();
        if (curr_tok == END) break;
        if (curr_tok == PRINT) continue;
        printf("%.2f\n", expr(0));
    }

    return no_of_errors;
}
