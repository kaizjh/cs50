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

-- I think this one is less important, so I mark here, and skip it for now
# | 297 | Littering took place at 16:36. No known witnesses.

-- Try to find more infomation from bakery_security_logs since the first clue we got from crime_scene_reports:
-- 295, 1 "Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery."
SELECT  *
FROM    bakery_security_logs
WHERE   year = 2023
AND     month = 7
AND     day = 28
AND     hour = 10
AND     minute = 15;

-- Nothing returns, bad

-- Try to find more infomation from interviews since the second clue we got from crime_scene_reports:
-- 295, 2 "Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery."
SELECT  id, transcript
FROM    interviews
WHERE   year = 2023
AND     month = 7
AND     day = 28
AND     transcript like '%bakery%';

| 161 | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

-- Check for 161

