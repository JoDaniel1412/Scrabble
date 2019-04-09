#ifndef STRINGTOJSONTEST_H
#define STRINGTOJSONTEST_H

#include <QTest>
#include <json/jsonserializer.h>
#include <json/stringtojson.h>
#include "game/tile.h"
#include "list/List.h"

class StringToJsonTest : public QObject
{
    Q_OBJECT
public:
    StringToJsonTest();
    ~StringToJsonTest();

private slots:
    void test_tileJson();
    void test_boardJson();
};

#endif // STRINGTOJSONTEST_H
