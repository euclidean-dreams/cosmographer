#ifndef COSMOGRAPHER_MACROS_H
#define COSMOGRAPHER_MACROS_H

#define up std::unique_ptr
#define mkup std::make_unique
#define sp std::shared_ptr
#define mksp std::make_shared
#define mv move
#define vec std::vector
#define lst std::list
#define cast(type, object) static_cast<type>(object)


#define PARADIGM community->paradigm
#define CLOISTER PARADIGM->cloister

#endif //COSMOGRAPHER_MACROS_H