#ifndef _OBJ_UTILS_H
#define _OBJ_UTILS_H

/**
 * @brief allow to hold an object value or state that isn't set (nullable)
 * 
 * @tparam T type of object
 */
template <class T>
class nullable
{
    T vv;
    bool isnull;

public:
    /**
     * @brief construct a nullified obj representation 
     */
    nullable()
    {
        isnull = true;
    }

    /**
     * @brief construct a non nullified obj representation
     * 
     * @param v obj that will copied into this container
     */
    nullable(const T &v)
    {
        vv = v;
        isnull = false;
    }

    /**
     * @brief states if obj is present 
     */
    bool HasValue() const
    {
        return !isnull;
    }

    /**
     * @brief retrieve object value ( HasValue() must true )
     * 
     * @return T& 
     */
    const T &Value() const
    {
        if (isnull)
        {
            error("null nullable");
        }
        return vv;
    }
};

#endif
