#ifndef ENTRYDAO_H
#define ENTRYDAO_H

#include <string>

#include "Dao.h"
#include "QEntry.h"
#include "ConnectionDB.h"

class QEntryDAO : public virtual Dao<QEntry, int>
{
private:
    QEntryDAO() = default;

    inline static const std::string TABLE_NAME = "ENTRIES";

    static QEntryDAO _instance;

public:
    static QEntryDAO& getInstance() noexcept;

    QEntry get(int id);
    void save(QEntry entry);
    void update(QEntry entry);
};

#endif // ENTRYDAO_H
