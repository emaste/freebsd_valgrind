#include <stdio.h>                                                              
#include <elf.h>                                                                
                                                                                
/* /usr/include/x86/elf.h AT_* defs */                                          
                                                                                
typedef struct {                                                                
        const char *str_val;                                                    
        int type;                                                               
} Elf_AuxStr;                                                                   
                                                                                
Elf_AuxStr aux_map[AT_COUNT][2] = {                                                
        {"AT_NLL",      0},                                                     
        {"AT_IGNORE",   1},                                                     
        {"AT_EXECFD",   2},                                                     
        {"AT_PHDR",     3},                                                     
        {"AT_PHENT",    4},                                                     
        {"AT_PHNUM",    5},                                                     
        {"AT_PAGESZ",   6},                                                     
        {"AT_BASE",     7},                                                     
        {"AT_FLAGS",    8},                                                     
        {"AT_ENTRY",    9},                                                     
        {"AT_NOTELF",   10},                                                    
        {"AT_UID",      11},                                                    
        {"AT_EUID",     12},                                                    
        {"AT_GID",      13},                                                    
        {"AT_EGID",     14},                                                    
        {"AT_EXECPATH", 15},                                                    
        {"AT_CANARY",   16},                                                    
        {"AT_CANARYLEN", 17},                                                   
        {"AT_OSRELDATE", 18},                                                   
        {"AT_NCPUS",    19},                                                    
        {"AT_PAGESIZES", 20},                                                   
        {"AT_PAGESIZESLEN", 21},                                                
        {"AT_TIMEKEEP", 22},                                                    
        {"AT_STACKPROT", 23},
        {"AT_EHDRFLAGS", 24},
        {"AT_HWCAP", 25},
        {"AT_HWCAP4", 26},
//        {"AT_COUNT", 27},
                                                                                
};                                                                              
                                                                                
int main(int argc, char* argv[], char* envp[])                                      
{                                                                               
    Elf_Auxinfo *aux_info;                                                  
    Elf_Auxinfo *auxp;                                                      
    Elf_AuxStr *aux_str;                                                    
    while(*envp++ != NULL)
        ;
                                                                                
    for (auxp = (Elf_Auxinfo *)envp; auxp->a_type != AT_NULL; auxp++)       
    {                                                                       
        aux_str = aux_map[auxp->a_type];                                   
        fprintf(stderr, "val: %s int: %02d ptr: 0x%lx\n", aux_str->str_val, aux_str->type, auxp->a_un.a_val);
    }                                                                       
}
