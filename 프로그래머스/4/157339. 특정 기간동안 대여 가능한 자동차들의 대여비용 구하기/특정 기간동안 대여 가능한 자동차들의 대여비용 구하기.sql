WITH CAR_SALE AS (
    SELECT 
    	CAR_ID,
    	C.CAR_TYPE,
    	DISCOUNT_RATE,
    	ROUND(C.DAILY_FEE * (1 - DP.DISCOUNT_RATE / 100) * 30, 0) AS FEE
    FROM CAR_RENTAL_COMPANY_CAR C
    JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN DP
    ON C.CAR_TYPE = DP.CAR_TYPE
    WHERE C.CAR_TYPE IN ('SUV', '세단') AND DP.DURATION_TYPE = '30일 이상')

SELECT
    S.CAR_ID, 
    S.CAR_TYPE, 
    S.FEE
FROM CAR_SALE S
LEFT JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY RH
    ON S.CAR_ID = RH.CAR_ID 
       AND (RH.START_DATE <= DATE '2022-11-30' AND RH.END_DATE >= DATE '2022-11-01')
WHERE 
	S.FEE BETWEEN 500000 AND 1999999
    AND RH.CAR_ID IS NULL
ORDER BY FEE DESC, CAR_TYPE, CAR_ID DESC;