| 163 | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
        In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
        The thief then asked the person on the other end of the phone to purchase the flight ticket. |

-- 
SELECT *
FROM        flights
WHERE       year = 2023
AND         month = 7
AND         day = 29
ORDER BY    hour, minute ASC
LIMIT 1;

+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+
