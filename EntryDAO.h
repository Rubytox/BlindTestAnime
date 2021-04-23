#ifndef ENTRYDAO_H
#define ENTRYDAO_H

#include <string>

#include "Dao.h"
#include "Entry.h"

class EntryDAO : public virtual Dao<Entry, int>
{
private:
    EntryDAO() = default;

    inline static const std::string TABLE_NAME = "ENTRIES";

    static EntryDAO _instance;
    static EntryDAO& getInstance() noexcept;

public:
    Entry get(int id);
    void save(Entry entry);
    void update(Entry entry);
};

#endif // ENTRYDAO_H
