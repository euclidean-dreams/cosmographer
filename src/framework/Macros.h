#ifndef COSMOGRAPHER_MACROS_H
#define COSMOGRAPHER_MACROS_H

#define up std::unique_ptr
#define mkup std::make_unique
#define sp std::shared_ptr
#define mksp std::make_shared
#define mv move
#define vec std::vector
#define lst std::list
#define umap std::unordered_map
#define cast(type, object) static_cast<type>(object)


#define PARADIGM community->paradigm
#define CLOISTER PARADIGM->cloister
#define CONSTANTS CLOISTER->constants

#endif //COSMOGRAPHER_MACROS_H
