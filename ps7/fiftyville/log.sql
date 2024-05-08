-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT  id, description
FROM    crime_scene_reports
WHERE   street = 'Humphrey Street'
AND     year = 2023
AND     month = 7
AND     day = 28;
