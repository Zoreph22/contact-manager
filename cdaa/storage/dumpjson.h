#ifndef DUMPJSON_H
#define DUMPJSON_H

#include "idump.h"
#include "storage_global.h"

#include <QJsonArray>
#include <QJsonObject>

class STORAGE_EXPORT DumpJson : public IDump
{
public:
    DumpJson(QString filePath);
    ~DumpJson() {};

    void dumpAll(const ContactCollection &contacts) const;

private:
    void writeFile(const QByteArray & bytes) const;

    QJsonArray dumpContacts(const ContactCollection & contacts) const;
    QJsonArray dumpInteractions(const InteractionCollection & interactions) const;
    QJsonArray dumpTodos(const TodoCollection & todos) const;

    QJsonObject dumpContact(const ContactModel & contact) const;
    QJsonObject dumpInteraction(const InteractionModel & interaction) const;
    QJsonObject dumpTodo(const TodoModel &todo) const;
};

#endif // DUMPJSON_H
