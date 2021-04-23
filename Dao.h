#ifndef DAO_H
#define DAO_H

/**
 * Provides a template for objects that communicate
 * with a database.
 *
 * @tparam 	T 	Type of the represented object.
 * @tparam 	S 	Type of primary key.
 */
template<class T, class S>
class Dao
{
public:
    virtual T get(S id) = 0;
    virtual void save(T t) = 0;
    virtual void update(T t) = 0;
};

#endif // DAO_H
