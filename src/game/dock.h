#ifndef DOCK_H
#define DOCK_H

#include <list/List.h>
#include <json/jsonserializable.h>
#include <QJsonArray>


class Dock : public JsonSerializable
{
public:
    static Dock *getInstance();

    void add(char letter);

    void remove(int index);

    List<char> *getLetters() const;
    void setLetters(List<char> *value);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

private:
    Dock();

    static Dock *instance;
    List<char> *letters;
};

#endif // DOCK_H
