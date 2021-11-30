#ifndef UNIT_TEST

#include <number-utils.h>
#include <string-utils.h>
#include <slist.h>
#include <vector-utils.h>

void hr()
{
    for (int i = 0; i < 40; ++i)
        Serial.print('-');
    Serial.println();
}

void setup()
{
    Serial.begin(115200);
    delay(1000);
    Serial.println("START");

    Serial.println();
    Serial.println("TOSTR");
    hr();

#ifdef ARDUINO_ARCH_STM32

    // v (size=6) : {1.2, 3.4, 5.6, 7.8, 9.10, 11.12}
    {
        vector<double> v;
        FoldPushBack(v, 1.2, 3.4, 5.6, 7.8);
        FoldPushBack(v, 9.10, 11.12);

        Serial.print("v (size=");
        Serial.print(v.size());
        Serial.print(") : {");
        for (int i = 0; i < v.size(); ++i)
        {
            Serial.print(i > 0 ? ", " : "");
            Serial.print(tostr(v[i], 2).c_str());
        }
        Serial.println("}");
    }

    //
    // DOUBLE TO STRING
    //
    {
        Serial.println(tostr(1, 4, false).c_str()); // 1.0000
        Serial.println(tostr(0, 2).c_str());        // 0
        Serial.println(tostr(0, 2, false).c_str()); // 0.00

        Serial.println(tostr(1234.5678901234567, 4).c_str());  // 1234.5679
        Serial.println(tostr(-1234.5678901234567, 4).c_str()); // -1234.5679

        Serial.println(tostr(1234.5678901234567, 10).c_str());  // 1234.5678901235
        Serial.println(tostr(-1234.5678901234567, 10).c_str()); // -1234.5678901235

        Serial.println(tostr(1234.5678901234567e-8, 6).c_str());  // 0.000012
        Serial.println(tostr(-1234.5678901234567e-8, 6).c_str()); // -0.000012

        Serial.println(tostr(1234.5678901234567e100, 6).c_str());  // 1.234568e103
        Serial.println(tostr(-1234.5678901234567e100, 6).c_str()); // -1.234568e103

        Serial.println(tostr(1234.5678901234567e-100, 6).c_str());  // 1.234568e-97
        Serial.println(tostr(-1234.5678901234567e-100, 6).c_str()); // -1.234568e-97

        Serial.println(tostr(1).c_str());              // 1e0
        Serial.println(tostr(1e20).c_str());           // 1e20
        Serial.println(tostr(1e20, 4).c_str());        // 1e20
        Serial.println(tostr(1e20, 4, false).c_str()); // 1.0000e20
        Serial.println(tostr(1, 4, false).c_str());    // 1.0000
        Serial.println(tostr(1.01200).c_str());        // 1.012e0

        Serial.println(tostr(1234.5678, 0, false).c_str());     // 1235
        Serial.println(tostr(1234.5678, 1, false).c_str());     // 1234.6
        Serial.println(tostr(0.00012345678, 0, false).c_str()); // 0
        Serial.println(tostr(0.00012345678, 4, false).c_str()); // 0.0001
        Serial.println(tostr(0.00012345678, 8, false).c_str()); // 0.00012346

        Serial.println(tostr(400, 1, false).c_str()); // 400.0
        Serial.println(tostr(400, 1).c_str());        // 400
    }
#endif

    Serial.println();
    Serial.println("SIMPLE LINKED LIST");
    hr();

    //
    // SIMPLE LINKED LIST
    //
    {
        SList<int> lst;

        lst.Add(1);
        lst.Add(2);
        lst.Add(3);

        // lst[0] = 1
        // lst[1] = 2
        // lst[2] = 3

        int l = lst.Size();
        int i = 0;

        while (i < l)
        {
            Serial.print("lst[");
            Serial.print(i);
            Serial.print("] = ");
            Serial.println(lst.Get(i));
            ++i;
        }

        // more efficient walking nodes

        auto n = lst.GetNode(0);
        i = 0;
        while (n != NULL)
        {
            Serial.print("lst[");
            Serial.print(i);
            Serial.print("] = ");
            Serial.println(n->data);

            ++i;
            n = n->next;
        }
    }

    Serial.println();
    Serial.println("CRC");
    hr();

    {
        const char *str = "CURTIME 1629505672 2021-08-21T00:27:52Z";
        Serial.print("[");
        Serial.print(str);
        Serial.print("] into crc [");
        Serial.print(appendChecksum(str).c_str());
        Serial.println("]");

        Serial.print("valid = ");
        Serial.println(verifyChecksum("CURTIME 1629505672 2021-08-21T00:27:52Z58"));
    }

    //
    // STRING ( trim )
    // TODO: tests
    //
}

void loop()
{
}

#endif