#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_CHARS 1024
#include "scanner.h"

static char* strtoken(Token token) {
    switch (token.type) {
        // ���ַ�Token
    case TOKEN_LEFT_PAREN:      return "(";
    case TOKEN_RIGHT_PAREN:     return ")";
    case TOKEN_LEFT_BRACKET:    return "[";
    case TOKEN_RIGHT_BRACKET:   return "]";
    case TOKEN_LEFT_BRACE:      return "{";
    case TOKEN_RIGHT_BRACE:     return "}";
    case TOKEN_COMMA:           return ",";
    case TOKEN_DOT:             return ".";
    case TOKEN_SEMICOLON:       return ";";
    case TOKEN_TILDE:           return "~";
        // һ���ַ��������ַ���Token
    case TOKEN_PLUS:            return "+";
    case TOKEN_PLUS_PLUS:       return "++";
    case TOKEN_PLUS_EQUAL:      return "+=";
    case TOKEN_MINUS:           return "-";
    case TOKEN_MINUS_MINUS:     return "--";
    case TOKEN_MINUS_EQUAL:     return "-=";
    case TOKEN_MINUS_GREATER:   return "->";
    case TOKEN_STAR:            return "*";
    case TOKEN_STAR_EQUAL:      return "*=";
    case TOKEN_SLASH:           return "/";
    case TOKEN_SLASH_EQUAL:     return "/=";
    case TOKEN_PERCENT:         return "%";
    case TOKEN_PERCENT_EQUAL:   return "%=";
    case TOKEN_AMPER:           return "&";
    case TOKEN_AMPER_EQUAL:     return "&=";
    case TOKEN_AMPER_AMPER:     return "&&";
    case TOKEN_PIPE:            return "|";
    case TOKEN_PIPE_EQUAL:      return "|=";
    case TOKEN_PIPE_PIPE:       return "||";
    case TOKEN_HAT:             return "^";
    case TOKEN_HAT_EQUAL:       return "^=";
    case TOKEN_EQUAL:           return "=";
    case TOKEN_EQUAL_EQUAL:     return "==";
    case TOKEN_BANG:            return "!";
    case TOKEN_BANG_EQUAL:      return "!=";
    case TOKEN_LESS:            return "<";
    case TOKEN_LESS_EQUAL:      return "<=";
    case TOKEN_LESS_LESS:       return "<<";
    case TOKEN_GREATER:         return ">";
    case TOKEN_GREATER_EQUAL:   return ">=";
    case TOKEN_GREATER_GREATER: 	return ">>";
        // ����ֵ: ��ʶ��, �ַ�, �ַ���, ����
    case TOKEN_IDENTIFIER:      return "IDENTIFIER";
    case TOKEN_CHARACTER:       return "CHARACTER";
    case TOKEN_STRING:          return "STRING";
    case TOKEN_NUMBER:          return "NUMBER";
        // �ؼ���
    case TOKEN_SIGNED:          return "SIGNED";
    case TOKEN_UNSIGNED:        return "UNSIGNED";
    case TOKEN_CHAR:            return "CHAR";
    case TOKEN_SHORT:           return "SHORT";
    case TOKEN_INT:             return "INT";
    case TOKEN_LONG:            return "LONG";
    case TOKEN_FLOAT:           return "FLOAT";
    case TOKEN_DOUBLE:          return "DOUBLE";
    case TOKEN_STRUCT:          return "STRUCT";
    case TOKEN_UNION:           return "UNION";
    case TOKEN_ENUM:            return "ENUM";
    case TOKEN_VOID:            return "VOID";
    case TOKEN_IF:              return "IF";
    case TOKEN_ELSE:            return "ELSE";
    case TOKEN_SWITCH:          return "SWITCH";
    case TOKEN_CASE:            return "CASE";
    case TOKEN_DEFAULT:         return "DEFAULT";
    case TOKEN_WHILE:           return "WHILE";
    case TOKEN_DO:              return "DO";
    case TOKEN_FOR:             return "FOR";
    case TOKEN_BREAK:           return "BREAK";
    case TOKEN_CONTINUE:        return "CONTINUE";
    case TOKEN_RETURN:          return "RETURN";
    case TOKEN_GOTO:            return "GOTO";
    case TOKEN_CONST:           return "CONST";
    case TOKEN_SIZEOF:          return "SIZEOF";
    case TOKEN_TYPEDEF:         return "TYPEDEF";
        // ����Token
    case TOKEN_ERROR:           return "ERROR";
    case TOKEN_EOF:             return "EOF";
    }
}

static void run(const char* source) {
    initScanner(source);
    int line = -1;
    // ��ӡToken, ����TOKEN_EOFΪֹ
    for (;;) {
        Token token = scanToken();
        if (token.line != line) {
            printf("%4d ", token.line);
            line = token.line;
        } else {
            printf("   | ");
        }
        printf("%12s '%.*s'\n", strtoken(token), token.length, token.start);

        if (token.type == TOKEN_EOF) break;
    }
}

static void repl() {
    // ���û��������û�ÿ����һ�д��룬����һ�д��룬����������
    // repl��"read evaluate print loop"����д
    printf("Enter a line of code and press Enter.\n");
    char buffer[MAX_CHARS];
    while (fgets(buffer, MAX_CHARS, stdin) != NULL) {
        run(buffer);
    }
}

static char* readFile(const char* path) {
    // �û������ļ������������ļ������ݶ����ڴ棬����ĩβ���'\0'
    // ע��: ����Ӧ��ʹ�ö�̬�ڴ���䣬���Ӧ������ȷ���ļ��Ĵ�С��
    FILE* src = fopen(path, "rb");
    if (src == NULL) {
        fprintf(stderr, "Open %s failed.\n", path);
        return NULL;
    }
    // ���ļ�ָ���Ƶ�ĩβ
    fseek(src, 0L, SEEK_END);
    // ��ȡ�ļ��ֽڴ�С
    long file_size=ftell(src);
    rewind(src);
    // ������Ӧ��С�Ķ�̬�ڴ�ռ䣬��Ϊ'\0'Ԥ��һ���ַ���λ�Ŀռ�
    char* buffer = malloc(sizeof(char) * (file_size + 1));
    if (buffer == NULL) {
        fprintf(stderr, "malloc failed in readFile.\n");
        fclose(src);       // �ر��Ѵ򿪵���
        return NULL;
    }
    fread(buffer, 1, file_size, src);
    buffer[file_size] = '\0';
    fclose(src);
    return buffer;
}

static void runFile(const char* path) {
    // ����'.c'�ļ�:�û������ļ��������������ļ�������������
    char* content = readFile(path);
    run(content);
    free(content);
}

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        // ./scanner û�в���,����뽻��ʽ����
        repl();
    } else if (argc == 2) {
        // ./scanner file �����һ������,����������ļ�
        runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: scanner [path]\n");
        exit(1);
    }

    return 0;
}