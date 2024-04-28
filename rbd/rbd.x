/* rbd.x  
   especificação rpc para um programa de banco de dados  
   que oferece os procedimentos INSERE, REMOVE e BUSCA 
*/ 
struct example {            /* estrutura não usada, declarada para ilustrar como rpcgen */ 
          int exfield1;      /* constrói rotinas XDR para converter estruturas */ 
          char exfield2;  
}; 
program RBDPROG{           /* nome do programa remoto */ 
    version RDBVERS{       /* declaração da versão */ 
          int INICIALIZAR(void) = 1;   /* primeiro procedimento deste programa */ 
          int INSERE(string) = 2;      /* segundo procedimento deste programa */ 
          int REMOVE(string) = 3;      /* terceiro procedimento deste programa */ 
          int BUSCA(string) = 4;       /* quarto procedimento deste programa */ 
    } = 1;                /* definição da versão do programa */ 
} = 0x30090949;     /* número do programa remoto (deve ser único) */
