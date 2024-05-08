 SELECT *
                        FROM people
                        WHERE license_plate IN(
                        SELECT license_plate
                        FROM bakery_security_logs
                        WHERE   year = 2023
                        AND     month = 7
                        AND     day = 28
                        AND     hour = 10
                        AND     minute <= 25
                        AND     minute >= 5
                        AND     activity = 'exit'
                        );


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
                        );
