/* rbd.x  
   Database program
*/ 
struct example {   
          int exfield1;
          char exfield2;  
}; 
program RBDPROG{
    version RDBVERS{
          int INICIALIZAR(void) = 1;
          int INSERE(string) = 2;
          int REMOVE(string) = 3; 
          int BUSCA(string) = 4; 
    } = 1; 
} = 0x30090949;
