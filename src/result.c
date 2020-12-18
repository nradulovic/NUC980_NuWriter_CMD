
#include "nw/result.h"


extern inline nw__result__error_t
nw__result__get_error(const struct nw__result__indefinite * result);

extern inline void
nw__result__set_error(
        struct nw__result__indefinite * result, 
        nw__result__error_t error);

