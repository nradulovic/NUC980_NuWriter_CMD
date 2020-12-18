
#ifndef NEW_WORLD__OPTIONAL_H_
#define NEW_WORLD__OPTIONAL_H_

#include "nw__bool.h"

struct nw__optional__indefinite
{
    nw__bool is_set;
};

inline void
nw__optional__initialize(struct nw__optional__indefinite * optional)
{
    optional->is_set = NW__FALSE;

inline nw__bool 
nw__optional__is_set(const struct nw__optional__indefinite * optional)
{
    return optional->is_set;
}

inline void
nw__optional__set(struct nw__optional__indefinite * optional)
{
    optional->is_set = NW__TRUE;
}

#define NW__OPTIONAL__DEFINITE(data_type)                                   \
    {                                                                       \
        struct nw__optional__indefinite indefinite;                         \
        data_type   data_value;                                             \
    }

#define NW__OPTIONAL__DEFINITE__INITIALIZE(optinal) \
    nw__optional__initialize(&(optional)->indefinite)

#define NW__OPTIONAL__DEFINITE__IS_SET(optional) \
    nw__optional__is_set(&(optional)->indefinite)

#define NW__OPTIONAL__DEFINITE__SET(optional, data) \
    do {    \
        (optional)->data_value = (data);\
        nw__optional__set(&(optional)->indefinite); \
    } while (0)

#define NW__OPTIONAL__DEFINITE__GET(optional, data) \
    do { \
        *(data) = (optional)->data_value; \
    } while (0)

#endif /* NEW_WORLD__OPTIONAL_H_ */
