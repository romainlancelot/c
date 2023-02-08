// Romain LANCELOT - 2ESGI A4


#define exit(ret) printf("> Exit function at line %d with value %s\n", __FUNCTION__, __LINE__, #ret); exit;
// START_FUNCTION prend le type de retour, le nom et les arguments de la fonction.
#define START_FUNCTION(ret, name, ...) \
    ret name(__VA_ARGS__) { \
        printf("# Definition of %s function %s(%s) in file \"%s\" at line %d\n", #ret, #name, #__VA_ARGS__, __FILE__, __LINE__); \
        printf("< Starting function %s :\n", #name); \

//  END_FUNCTION prend le retour de la fonction.
#define END_FUNCTION(ret) \
        if (ret == 0) { \
            printf("> Exit int function at line %d with value %s\n", __LINE__, #ret); \
        } else { \
            printf("> Ending function with return %s\n", #ret); \
            return ret; \
        } \
    }
