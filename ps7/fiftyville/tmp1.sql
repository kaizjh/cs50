SELECT *
FROM atm_transactions
WHERE   atm_location = 'Leggett Street'
AND     year = 2023
AND     month = 7
AND     day = 28
AND     transaction_type = 'withdraw';
