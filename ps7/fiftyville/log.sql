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

        -- Check the descriptino 295, 1 "Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery."
        SELECT  *
        FROM    bakery_security_logs
        WHERE   year = 2023
        AND     month = 7
        AND     day = 28
        AND     hour = 10
        AND     minute = 15;
        -- Nothing returns

        -- Check the description 295, 2 "Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery."
        SELECT  id, transcript
        FROM    interviews
        WHERE   year = 2023
        AND     month = 7
        AND     day = 28
        AND     transcript like '%bakery%';

        | 161 | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |

                -- Check the transcript 161, to get information about bakery parking lot, within ten minutes of the theft, which is 2023-7-28 10:15am
                SELECT *
                FROM bakery_security_logs
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


        | 162 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
        | 163 | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |'



| 297 | Littering took place at 16:36. No known witnesses.

        SELECT *
        FROM bakery_security_logs
        WHERE   year = 2023
        AND     month = 7
        AND     day = 28
        AND     hour = 16
        AND     minute = 36;

        -- Nothing returns
