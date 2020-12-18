
#ifndef NEW_WORLD__RESULT_H_
#define NEW_WORLD__RESULT_H_

#include <stdint.h>

typedef uint32_t nw__result__error_t;

struct nw__result__indefinite
{
    nw__result__error_t error;    
};

inline nw__result__error_t
nw__result__get_error(const struct nw__result__indefinite * result)
{
    return result->error;
}

inline void
nw__result__set_error(
        struct nw__result__indefinite * result, 
        nw__result__error_t error)
{
    result->error = error;
}

#define NW__RESULT(data_type) \
    {                                                   \
        struct nw__result__indefinite indefinite;        \
        data_type data_value;           \
    }

#define NW__RESULT__ERROR(p_result) \
    nw__result__get_error(&(p_result)->indefinite)
    
#define NW__RESULT__DATA(p_result) \
    (p_result)->data_value

#define NW__RESULT__SET(p_result, value, error) \
    do { \
        (p_result)->data_value = (value); \
        nw__result__set_error(&(p_result)->indefinite, (error)); \
    } while (0)
    
    
#endif /* NEW_WORLD__RESULT_H_ */
