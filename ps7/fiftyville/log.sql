-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Try to find more infomation from crime_scene_reports since
-- "All you know is that the theft took place on July 28, 2023 and that it took place on Humphrey Street."
SELECT  id, description
FROM    crime_scene_reports
WHERE   street = 'Humphrey Street'
AND     year = 2023
AND     month = 7
AND     day = 28;

295, Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
     Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
297, Littering took place at 16:36. No known witnesses.

-- Try to find more infomation from bakery_security_logs since the first clue we got from crime_scene_reports:
-- "Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery."
SELECT  *
FROM    bakery_security_logs
WHERE   year = 2023
AND     month = 7
AND     day = 28
AND     hour = 10
AND     minute = 15;

-- Nothing returns, bad

-- Try to find more infomation from bakery_security_logs since the first clue we got from crime_scene_reports:
