%{
  #include <stdio.h>
  #include <string.h>
  #include "util.h"
  #include "memoria.h"

  char op_code[6];
  char rg[5];
  char imed[21];
  char data[32];

  memory mem;

  int ltableSize = 32;
  int instruction_ltableSize = 32;

  int instr_count = 0;
  int label_count = 0;

  int instr_label_count = 0;
  int data_count = 0;

  typedef struct label {
      char *lname;
      int pos;
  } label;

  typedef struct instruction_label{
      char *lname;
      int pos;
      int memBegin;
  } instruction_label;

  label *labelTable;
  instruction_label *instructionLabelTable;

%}

%union {
    char *op;
    char *r;
    char *l;
    int value;
}


%token ARQUITETURA
%token SOMADOR MULTIPLICADOR DIVISOR BUSCA_DE_INSTRUCOES BUFFER_DE_CARGA BUFFER_DE_ESCRITA
%token CICLOS
%token TEXTO
%token DOTDATA DOTTEXT
%token OPERATION_2R OPERATION_3R OPERATION_R_I OPERATION_R_L OPERATION_2R_I OPERATION_2R_L OPERATION_L
%token R
%token I
%token L L_DECLARATION
%token EOL
%token VALUE
%token DATATYPE
%token COMMA EQUAL COLON DOLLAR

%type<r> R
%type<op> OPERATION_2R OPERATION_3R OPERATION_R_I OPERATION_R_L OPERATION_2R_I OPERATION_2R_L OPERATION_L
%type<value> VALUE I imediate
%type<l> L label

%%

//all: program;

all:  ignoreblankline ARQUITETURA ignoreblankline
	architecture ignoreblankline
	CICLOS ignoreblankline
	cycles ignoreblankline
	TEXTO ignoreblankline
	DOTDATA ignoreblankline
	progdata ignoreblankline
	DOTTEXT ignoreblankline program;


architecture: SOMADOR EQUAL VALUE EOL
              MULTIPLICADOR EQUAL VALUE EOL
              DIVISOR EQUAL VALUE EOL
              BUSCA_DE_INSTRUCOES EQUAL VALUE EOL
              BUFFER_DE_CARGA EQUAL VALUE EOL
              BUFFER_DE_ESCRITA EQUAL VALUE EOL
              {
                somador = $3;
                multiplicador = $7;
                divisor = $11;
                busca_de_instrucoes = $15;
                buffer_de_carga = $19;
                buffer_de_escrita = $23;
                printf("somador = %d\n", $3);
                printf("multiplicador = %d\n", $7);
                printf("divisor = %d\n", $11);
                printf("busca_de_instrucoes = %d\n", $15);
                printf("buffer_de_carga = %d\n", $19);
                printf("buffer_de_escrita = %d\n", $23);
              }
            ;


cycles: /*nothing - default cycles*/
      | OPERATION_2R EQUAL VALUE EOL cycles  {printf("%s = %d\n", $1, $3); setCycles($1, $3);}
      | OPERATION_3R EQUAL VALUE EOL cycles  {printf("%s = %d\n", $1, $3); setCycles($1, $3);}
      | OPERATION_R_I EQUAL VALUE EOL cycles  {printf("%s = %d\n", $1, $3); setCycles($1, $3);}
      | OPERATION_R_L EQUAL VALUE EOL cycles  {printf("%s = %d\n", $1, $3); setCycles($1, $3);}
      | OPERATION_2R_I EQUAL VALUE EOL cycles  {printf("%s = %d\n", $1, $3); setCycles($1, $3);}
      | OPERATION_2R_L EQUAL VALUE EOL cycles  {printf("%s = %d\n", $1, $3); setCycles($1, $3);}
      | OPERATION_L EQUAL VALUE EOL cycles  {printf("%s = %d\n", $1, $3); setCycles($1, $3);}
      ;

label: L COLON{
        if(label_count >= ltableSize){
            ltableSize *= 2;
            labelTable = (label *) realloc(labelTable, ltableSize * sizeof(label));
        }
        labelTable[label_count].lname = $1;
        labelTable[label_count].pos = MAX_SIZE - instr_count - 1;
        label_count++;
     }
     ;

data: DATATYPE VALUE {
        dec_to_bin($2, data, 32);
        storeMemCell(mem, data, data_count, 0, 32, 1);
        data_count++;
      }
      ;

progdata:
        | data EOL progdata
        ;

instruction:  OPERATION_2R R COMMA R
            {printf("%5s\tR\tR\n", $1);
                int p = MAX_SIZE - instr_count - 1;
                getInstructionOpcode($1, op_code);
                storeMemCell(mem, op_code, p, 0, 6, 0);
                getRegisterOpcode($2, rg);
                storeMemCell(mem, rg, p, 6, 11, 0);
                getRegisterOpcode($4, rg);
                storeMemCell(mem, rg, p, 11, 16, 0);
                instr_count++;
            }
            | OPERATION_3R R COMMA R COMMA R  {printf("%5s\tR\tR\tR\n", $1);
                getInstructionOpcode($1, op_code);
                storeMemCell(mem, op_code, MAX_SIZE - instr_count - 1, 0, 6, 0);
                getRegisterOpcode($2, rg);
                storeMemCell(mem, rg, MAX_SIZE - instr_count - 1, 6, 11, 0);
                getRegisterOpcode($4, rg);
                storeMemCell(mem, rg, MAX_SIZE - instr_count - 1, 11, 16, 0);
                getRegisterOpcode($6, rg);
                storeMemCell(mem, rg, MAX_SIZE - instr_count - 1, 16, 21, 0);
                instr_count++;
            }
            | OPERATION_R_I R COMMA imediate  {printf("%5s\tR\tI\n", $1);
                getInstructionOpcode($1, op_code);
                storeMemCell(mem, op_code, MAX_SIZE - instr_count - 1, 0, 6, 0);
                dec_to_bin($4, imed, 32 - 6);
                storeMemCell(mem, imed, MAX_SIZE - instr_count - 1, 6, 32, 1);
                instr_count++;
            }
            | OPERATION_R_L R COMMA L  {printf("%5s\tR\tL\n", $1);
                if(instr_label_count >= instruction_ltableSize){
                    instruction_ltableSize *= 2;
                    instructionLabelTable = (instruction_label *) realloc(instructionLabelTable, instruction_ltableSize * sizeof(instruction_label));
                }
                instructionLabelTable[instr_label_count].lname = $4;
                instructionLabelTable[instr_label_count].pos = MAX_SIZE - instr_count - 1;
                instructionLabelTable[instr_label_count].memBegin = 11;
                storeMemCell(mem, op_code, MAX_SIZE - instr_count - 1, 0, 6, 0);
                getRegisterOpcode($2, rg);
                storeMemCell(mem, rg, MAX_SIZE - instr_count - 1, 6, 11, 0);
                instr_count++;
                instr_label_count++;
            }
            | OPERATION_2R_I R COMMA R COMMA imediate  {printf("%5s\tR\tR\tI\n", $1);
                int p = MAX_SIZE - instr_count - 1;
                getInstructionOpcode($1, op_code);
                storeMemCell(mem, op_code, p, 0, 6, 0);
                getRegisterOpcode($2, rg);
                storeMemCell(mem, rg, p, 6, 11, 0);
                getRegisterOpcode($4, rg);
                storeMemCell(mem, rg, p, 11, 16, 0);
                dec_to_bin($6, imed, 16);
                storeMemCell(mem, imed, p, 16, 32, 1);
                instr_count++;
            }
            | OPERATION_2R_L R COMMA R COMMA L  {printf("%5s\tR\tR\tL\n", $1);
                if(instr_label_count >= instruction_ltableSize){
                    instruction_ltableSize *= 2;
                    instructionLabelTable = (instruction_label *) realloc(instructionLabelTable, instruction_ltableSize * sizeof(instruction_label));
                }
                instructionLabelTable[instr_label_count].lname = $6;
                instructionLabelTable[instr_label_count].pos = MAX_SIZE - instr_count - 1;
                instructionLabelTable[instr_label_count].memBegin = 16;
                getInstructionOpcode($1, op_code);
                storeMemCell(mem, op_code, MAX_SIZE - instr_count - 1, 0, 6, 0);
                getRegisterOpcode($2, rg);
                storeMemCell(mem, rg, MAX_SIZE - instr_count - 1, 6, 11, 0);
                getRegisterOpcode($4, rg);
                storeMemCell(mem, rg, MAX_SIZE - instr_count - 1, 11, 16, 0);
                instr_count++;
                instr_label_count++;
            }
            | OPERATION_L L  {printf("%5s\tL\n",$1);
                if(instr_label_count >= instruction_ltableSize){
                    instruction_ltableSize *= 2;
                    instructionLabelTable = (instruction_label *) realloc(instructionLabelTable, instruction_ltableSize * sizeof(instruction_label));
                }
                instructionLabelTable[instr_label_count].lname = $2;
                instructionLabelTable[instr_label_count].pos = MAX_SIZE - instr_count - 1;
                instructionLabelTable[instr_label_count].memBegin = 6;
                getInstructionOpcode($1, op_code);
                storeMemCell(mem, op_code, MAX_SIZE - instr_count - 1, 0, 6, 0);
                instr_count++;
                instr_label_count++;
            }
            ;

program: /*nothing*/
       | instruction EOL program
       | label EOL instruction EOL program
       ;

ignoreblankline:
                | EOL ignoreblankline
                ;

imediate: DOLLAR VALUE {$$ = $2}
%%

main(int argc, char **argv){
  FILE *f;
  mem = createMem();
  labelTable = (label *)malloc(ltableSize * sizeof(label));
  instructionLabelTable = (instruction_label *)malloc(instruction_ltableSize * sizeof(instruction_label));
  if(argc == 2){
    f = fopen(argv[1], "r");
    yyrestart(f);
  }
  yyparse();
  for (int i = 0; i < instr_label_count; i++){
    printf("INST [%d] requer LABEL [%s]\n", instructionLabelTable[i].pos, instructionLabelTable[i].lname);
  }
  for (int i = 0; i < label_count; i++){
    printf("LABEL [%s] no ADDR [%d]\n", labelTable[i].lname, labelTable[i].pos);
  }
  for(int i = 0; i < instr_label_count; i++){
      for(int j = 0; j < label_count; j++){
          if(!strcmp(instructionLabelTable[i].lname, labelTable[j].lname)){
              printf("posicao = %d\n", labelTable[j].pos);
              int size = 32 - instructionLabelTable[i].memBegin;
              char auxlabel[size];
              dec_to_bin(labelTable[j].pos, auxlabel, size);
              storeMemCell(mem, auxlabel, instructionLabelTable[i].pos, instructionLabelTable[i].memBegin, 32, 1);
          }
      }
  }
  printMem(mem);
  tomasulo();
}

yyerror(char *s){
  fprintf(stderr, "error: %s\n", s);
}
