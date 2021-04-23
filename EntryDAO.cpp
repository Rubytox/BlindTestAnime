#include "EntryDAO.h"

Entry EntryDAO::get(int id)
{
    return Entry("Renai Circulation", "Kana Hanazawa", "Bakemonogatari", 4, Entry::Type::OPENING, "C:\\Users\\cFAG\\Videos\\renai-circulation.mp4");
}

void EntryDAO::save(Entry entry)
{

}

void EntryDAO::update(Entry entry)
{

}

EntryDAO EntryDAO::_instance;
EntryDAO& EntryDAO::getInstance() noexcept
{
    return _instance;
}
