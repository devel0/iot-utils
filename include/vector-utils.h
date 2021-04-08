#ifndef _VECTOR_UTILS_H
#define _VECTOR_UTILS_H

#include <vector>

/**
 * @brief pushback to std::vector using c++17 folds ( https://en.cppreference.com/w/cpp/language/fold )
 *  
 * @param v vector
 * @param args items to add
 */
template <typename T, typename... Args>
void FoldPushBack(vector<T> &v, Args &&...args)
{
    (v.push_back(args), ...);
}

#endif
