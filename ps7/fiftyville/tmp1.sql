SELECT *
FROM bakery_security_logs
WHERE   year = 2023
AND     month = 7
AND     day = 28
AND     hour = 10
AND     minute <= 25
AND     minute >= 5;
