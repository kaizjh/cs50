+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       |
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+


+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |

SELECT *
FROM phone_calls
WHERE caller = '(389) 555-5198';

+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 57  | (389) 555-5198 | (368) 555-3561 | 2023 | 7     | 25  | 414      |
| 326 | (389) 555-5198 | (609) 555-5876 | 2023 | 7     | 29  | 397      |
+-----+----------------+----------------+------+-------+-----+----------+

SELECT *
FROM phone_calls
WHERE caller = '(367) 555-5533';

+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 9   | (367) 555-5533 | (113) 555-7544 | 2023 | 7     | 25  | 469      |
| 104 | (367) 555-5533 | (238) 555-5554 | 2023 | 7     | 26  | 84       |
| 122 | (367) 555-5533 | (660) 555-3095 | 2023 | 7     | 26  | 399      |
| 133 | (367) 555-5533 | (286) 555-0131 | 2023 | 7     | 26  | 444      |
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
| 236 | (367) 555-5533 | (344) 555-9601 | 2023 | 7     | 28  | 120      |
| 245 | (367) 555-5533 | (022) 555-4052 | 2023 | 7     | 28  | 241      |
| 285 | (367) 555-5533 | (704) 555-5790 | 2023 | 7     | 28  | 75       |
| 395 | (367) 555-5533 | (455) 555-5315 | 2023 | 7     | 30  | 31       |
| 418 | (367) 555-5533 | (841) 555-3728 | 2023 | 7     | 30  | 511      |
| 488 | (367) 555-5533 | (696) 555-9195 | 2023 | 7     | 31  | 261      |
+-----+----------------+----------------+------+-------+-----+----------+
