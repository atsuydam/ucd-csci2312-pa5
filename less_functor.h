//
// Created by atsuydam on 5/5/16.
//

#ifndef PROJECT_LESS_FUNCTOR_H
#define PROJECT_LESS_FUNCTOR_H
namespace CS2312 {

    template <typename T>
    class less {
    public:
        less () {}
        bool operator ()(const T &first, const T &second) {
            if (first < second) {
                return true;
            }
            return false;
        }
    };
}
#endif //PROJECT_LESS_FUNCTOR_H
