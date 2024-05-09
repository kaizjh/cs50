-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Try to find more infomation from crime_scene_reports since
-- "All you know is that the theft took place on July 28, 2023 and that it took place on Humphrey Street."
SELECT  id, description
FROM    crime_scene_reports
WHERE   street = 'Humphrey Street'
AND     year = 2023
AND     month = 7
AND     day = 28;

| 295 | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
        Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

        -- Check the descriptino 295, line 1, looking for more information
        SELECT  *
        FROM    bakery_security_logs
        WHERE   year = 2023
        AND     month = 7
        AND     day = 28
        AND     hour = 10
        AND     minute = 15;
        -- Nothing returns

        -- Check the description 295, line 2, looking for more information from the interviews
        SELECT  id, transcript
        FROM    interviews
        WHERE   year = 2023
        AND     month = 7
        AND     day = 28
        AND     transcript like '%bakery%';

        | 161 | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |

                -- Check the transcript 161, to get information about bakery parking lot, within ten minutes of the theft, which is 2023-7-28 10:15am
                SELECT *
                FROM    bakery_security_logs
                WHERE   year = 2023
                AND     month = 7
                AND     day = 28
                AND     hour = 10
                AND     minute <= 25
                AND     minute >= 5;

                +-----+------+-------+-----+------+--------+----------+---------------+
                | id  | year | month | day | hour | minute | activity | license_plate |
                +-----+------+-------+-----+------+--------+----------+---------------+
                | 258 | 2023 | 7     | 28  | 10   | 8      | entrance | R3G7486       |
                | 259 | 2023 | 7     | 28  | 10   | 14     | entrance | 13FNH73       |
                | 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
                | 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
                | 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
                | 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
                | 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
                | 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
                | 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
                | 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
                +-----+------+-------+-----+------+--------+----------+---------------+

                        -- I see some cars exit the parking lot within the 10 minutes of the theft, so I going to check these 'exit' cars
                        SELECT *
                        FROM    people
                        WHERE   license_plate IN(
                        SELECT  license_plate
                        FROM    bakery_security_logs
                        WHERE   year = 2023
                        AND     month = 7
                        AND     day = 28
                        AND     hour = 10
                        AND     minute <= 25
                        AND     minute >= 5
                        AND     activity = 'exit'
                        );

                        -- Here are the suspects
                        +--------+---------+----------------+-----------------+---------------+
                        |   id   |  name   |  phone_number  | passport_number | license_plate |
                        +--------+---------+----------------+-----------------+---------------+
                        | 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
                        | 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
                        | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
                        | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
                        | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
                        | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
                        | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
                        | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
                        +--------+---------+----------------+-----------------+---------------+

        | 162 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |'

                -- Check the transcript 161, looking for information about who withdrew many on Leggett Street 2023-7-28
                SELECT  *
                FROM    atm_transactions
                WHERE   atm_location = 'Leggett Street'
                AND     year = 2023
                AND     month = 7
                AND     day = 28
                AND     transaction_type = 'withdraw';

                +-----+----------------+------+-------+-----+----------------+------------------+--------+
                | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
                +-----+----------------+------+-------+-----+----------------+------------------+--------+
                | 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
                | 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
                | 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
                | 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
                | 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
                | 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
                | 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
                | 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
                +-----+----------------+------+-------+-----+----------------+------------------+--------+

                -- Check if there are suspects on the flight 36, also suspects exit at theft time, also suspects withdraw many the theft day morning
                SELECT  *
                FROM    people
                WHERE   license_plate IN(
                        SELECT  license_plate
                        FROM    bakery_security_logs
                        WHERE   year = 2023
                        AND     month = 7
                        AND     day = 28
                        AND     hour = 10
                        AND     minute <= 25
                        AND     minute >= 5
                        AND     activity = 'exit'

                        AND     passport_number IN(
                                SELECT  passport_number
                                FROM    passengers
                                WHERE   flight_id IN(
                                SELECT  id
                                FROM    flights
                                WHERE   year = 2023
                                AND     month = 7
                                AND     day = 29
                                AND     hour = 8
                                AND     minute = 20
                                )
                        )
                )
                AND     id      IN(
                        SELECT  person_id
                        FROM    bank_accounts
                        WHERE   account_number IN(
                                SELECT  account_number
                                FROM    atm_transactions
                                WHERE   atm_location = 'Leggett Street'
                                AND     year = 2023
                                AND     month = 7
                                AND     day = 28
                                AND     transaction_type = 'withdraw'
                        )
                );

                -- Here are two main suspects
                +--------+-------+----------------+-----------------+---------------+
                |   id   | name  |  phone_number  | passport_number | license_plate |
                +--------+-------+----------------+-----------------+---------------+
                | 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       |
                | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
                +--------+-------+----------------+-----------------+---------------+


        | 163 | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
                In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
                The thief then asked the person on the other end of the phone to purchase the flight ticket. |

                -- Check the transcript 163 line 2 for earliest flight on 2023-7-29
                SELECT      *
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

                        -- Check if there are 'parking lot suspects' on this flight, and get their personal information
                        SELECT  *
                        FROM    people
                        WHERE   license_plate IN(
                                SELECT  license_plate
                                FROM    bakery_security_logs
                                WHERE   year = 2023
                                AND     month = 7
                                AND     day = 28
                                AND     hour = 10
                                AND     minute <= 25
                                AND     minute >= 5
                                AND     activity = 'exit'

                                AND     passport_number IN(
                                        SELECT  passport_number
                                        FROM    passengers
                                        WHERE   flight_id IN(
                                        SELECT  id
                                        FROM    flights
                                        WHERE   year = 2023
                                        AND     month = 7
                                        AND     day = 29
                                        AND     hour = 8
                                        AND     minute = 20
                                        )
                                )
                        );

                        -- Here are the suspects on the flight 36
                        +--------+--------+----------------+-----------------+---------------+
                        |   id   |  name  |  phone_number  | passport_number | license_plate |
                        +--------+--------+----------------+-----------------+---------------+
                        | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
                        | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       |
                        | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
                        | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
                        +--------+--------+----------------+-----------------+---------------+


                        -- Then looking for the origin_airport of this flight
                        SELECT  *
                        FROM    airports
                        WHERE   id IN (
                                SELECT  origin_airport_id
                                FROM    flights
                                WHERE   year = 2023
                                AND     month = 7
                                AND     day = 29
                                AND     hour = 8
                                AND     minute = 20
                        );

                        +----+--------------+-----------------------------+------------+
                        | id | abbreviation |          full_name          |    city    |
                        +----+--------------+-----------------------------+------------+
                        | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
                        +----+--------------+-----------------------------+------------+

                        -- Then looking for the destination_airport of this flight
                        SELECT  *
                        FROM    airports
                        WHERE   id IN (
                                SELECT  destination_airport_id
                                FROM    flights
                                WHERE   year = 2023
                                AND     month = 7
                                AND     day = 29
                                AND     hour = 8
                                AND     minute = 20
                        );

                        +----+--------------+-------------------+---------------+
                        | id | abbreviation |     full_name     |     city      |
                        +----+--------------+-------------------+---------------+
                        | 4  | LGA          | LaGuardia Airport | New York City |
                        +----+--------------+-------------------+---------------+

                -- According to the transcript 163 line 1, and the main suspects from line 133's check, I am going to check this two suspects' phone_call information on theft day

                -- Check the first suspect, but returns nothing
                SELECT  *
                FROM    phone_calls
                WHERE   year = 2023
                AND     month = 7
                AND     day = 28
                AND     caller = '(389) 555-5198';

                -- Check the second suspect
                SELECT *
                FROM    phone_calls
                WHERE   year = 2023
                AND     month = 7
                AND     day = 28
                AND     caller = '(367) 555-5533';

                -- Returns:
                +-----+----------------+----------------+------+-------+-----+----------+
                | id  |     caller     |    receiver    | year | month | day | duration |
                +-----+----------------+----------------+------+-------+-----+----------+
                | 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
                | 236 | (367) 555-5533 | (344) 555-9601 | 2023 | 7     | 28  | 120      |
                | 245 | (367) 555-5533 | (022) 555-4052 | 2023 | 7     | 28  | 241      |
                | 285 | (367) 555-5533 | (704) 555-5790 | 2023 | 7     | 28  | 75       |
                +-----+----------------+----------------+------+-------+-----+----------+
                -- From this table, I have confirmed, finally, that the theft is Bruce, whose id is 686048





| 297 | Littering took place at 16:36. No known witnesses.

        SELECT  *
        FROM    bakery_security_logs
        WHERE   year = 2023
        AND     month = 7
        AND     day = 28
        AND     hour = 16
        AND     minute = 36;

        -- Nothing returns
