#include <Wire.h>
#include "ds3231.h"

#define BUFF_MAX 128

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    DS3231_init(DS3231_INTCN);
}

void loop()
{
    char buff[BUFF_MAX];
    struct ts t;
    DS3231_get(&t);
    float temp = DS3231_get_treg();

    snprintf(buff, BUFF_MAX, "%d.%02d.%02d %02d:%02d:%02d  %.2fC",
             t.year, t.mon, t.mday, t.hour, t.min, t.sec, temp);
    Serial.println(buff);
    delay(5000);
}
