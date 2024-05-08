
| 161 | Sometime within ten minutes of the theft, I saw the thief get into a car
in the bakery parking lot and drive away. If you have security footage from the bakery parking lot,
you might want to look for cars that left the parking lot in that time frame.                                                          |

SELECT *
FROM bakery_security_logs
WHERE   year = 2023
AND     month = 7
AND     day = 28
AND     hour = 10
AND     minute < 25
AND     minute > 5
